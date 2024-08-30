#include <iostream>
#include <thread>
#include <vector>

/*
std::thread is a C++11 feature that represents an independent thread of execution within a program.
You can create threads to run functions or callable objects concurrently, which is useful for tasks like parallel processing, asynchronous
I/O operations, or improving application responsiveness.
Threads can be managed, joined, or detached, and you can pass arguments to the thread function.
Proper synchronization (e.g., using std::mutex) is crucial when threads share data.
*/

// https://godbolt.org/z/d8fxd5snG

void printHello(int id) {
    std::cout << "Hello from thread " << id << std::endl;
}

int main() {
    // 1. Creating and Starting Threads
    std::thread t1(printHello, 1); // Start a thread running printHello(1)
    std::thread t2(printHello, 2); // Start another thread running printHello(2)

    // 2. Passing Lambda to Thread
    std::thread t3([](int x) { std::cout << "Lambda in thread " << x << std::endl; }, 3);

    // 3. Waiting for Threads to Finish (Joining)
    t1.join(); // Wait for t1 to finish
    t2.join(); // Wait for t2 to finish
    t3.join(); // Wait for t3 to finish

    // 4. Detaching a Thread (Runs Independently)
    std::thread t4([]() {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Detached thread finished." << std::endl;
        });
    t4.detach(); // Detach t4, it will run independently

    // 5. Creating Multiple Threads in a Loop
    std::vector<std::thread> threads;
    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(printHello, i + 4);
    }

    // Joining all the threads
    for (auto& t : threads) {
        t.join(); // Wait for each thread to finish
    }

    return 0;
}
