#include <iostream>
#include <thread>
#include <future>
#include <chrono>

/*
std::promise: It is used by one thread to set a value that will be asynchronously retrieved by another thread.
std::future: It is used by the receiving thread to access the value (or exception) set by the std::promise.
These two classes are typically used together in scenarios where a result is computed in one thread and used in another, facilitating
communication and synchronization between threads.
*/

// https://godbolt.org/z/MvcMe9bK7

// Function to perform a task and set the result in the promise
void computeSquare(std::promise<int>&& promise, int x) {
    std::this_thread::sleep_for(std::chrono::seconds(1));  // Simulate some work
    int result = x * x;
    promise.set_value(result);  // Set the computed result
}

int main() {
    // Create a promise
    std::promise<int> promise;

    // Get the associated future
    std::future<int> future = promise.get_future();

    // Start a thread to compute the square of a number
    std::thread t(computeSquare, std::move(promise), 5);

    // Retrieve the result from the future (blocks until the result is available)
    std::cout << "Waiting for the result...\n";
    int result = future.get(); //Blocks the calling (main) thread until value is available
    std::cout << "The square of 5 is: " << result << std::endl;

    t.join();  // Wait for the thread to finish

    return 0;
}
