#include <iostream>
#include <coroutine>
#include <thread>
#include <chrono>

/*
Coroutines allow functions to pause execution and resume later, enabling simpler asynchronous programming and state machine creation.
std::coroutine_handle manages coroutine execution.
co_await is used to suspend execution, allowing the coroutine to be resumed later.
co_return is used to return a result from the coroutine.
std::suspend_always and std::suspend_never control whether the coroutine should suspend or continue.
*/

// -std=c++20
// https://godbolt.org/z/vdjx38Gs5

// Coroutine Task definition
struct Task {
    struct promise_type;
    using handle_type = std::coroutine_handle<promise_type>;

    struct promise_type {
        Task get_return_object() {
            return Task{handle_type::from_promise(*this)};
        }
        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }
        void return_void() {}
        void unhandled_exception() { std::terminate(); }
    };

    handle_type coro;
    explicit Task(handle_type h) : coro(h) {}
    ~Task() { if (coro) coro.destroy(); }

    void resume() { if (coro) coro.resume(); }
};

// Coroutine function that simulates an asynchronous operation
Task asyncOperation() {
    std::cout << "Starting asynchronous operation...\n";
    co_await std::suspend_always();  // Coroutine will suspend here
    std::cout << "Operation resumed after suspension.\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));  // Simulate delay
    std::cout << "Operation completed.\n";
}

// Coroutine that performs the initial asynchronous operation
Task performOperation() {
    std::cout << "Starting asynchronous operation...\n";
    co_await std::suspend_always();  // Coroutine will suspend here
    std::cout << "Operation resumed.\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));  // Simulate delay
    std::cout << "Operation completed.\n";
}

Task orchestrate() {
    auto operation = performOperation();  // Start the first coroutine
    std::cout << "orchestrate doing other work...\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));  // Simulate doing other work
    operation.resume();  // Resume the first coroutine
    co_return;  // Indicate completion of the orchestrator coroutine
}

int main() {
    auto task = asyncOperation();  // Start coroutine
    std::cout << "Main function doing other work...\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));  // Simulate doing other work
    std::cout << "Main function doing other work...\n";

    task.resume();  // Resume coroutine

    auto orchestrator = orchestrate();  // Start orchestrator coroutine
    orchestrator.resume();  // Resume the orchestrator coroutine to complete the operation
    return 0;
}
