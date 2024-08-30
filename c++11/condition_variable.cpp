#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

/*
std::condition_variable is used to block a thread until another thread notifies it that a specific condition has been satisfied.
It works with std::unique_lock<std::mutex> to manage the waiting and notification process.
Typical usage involves one or more threads waiting for a condition, while another thread signals (or notifies) them when the condition is met,
allowing them to proceed.
*/
std::mutex mtx;                         // Mutex for critical section
std::condition_variable cv;             // Condition variable
bool ready = false;                     // Shared variable to indicate the condition

// https://godbolt.org/z/K8qqTrqEo

/*
When cv.notify_all() is called, all waiting threads (e.g., t1, t2, t3) wake up.

Each thread tries to re-acquire the mutex immediately after waking up. However, only one thread can hold the mutex at a time.

Suppose t1 re-acquires the mutex first. It enters the critical section, executes, and releases the mutex.
Then, t2 will acquire the mutex, execute, and release it.
Finally, t3 will do the same.

The critical section (printing the thread ID in this example) is executed by only one thread at a time, preventing race conditions.
*/

void printId(int id) {
    std::unique_lock<std::mutex> lock(mtx);   // Lock the mutex,
    cv.wait(lock, [] { return ready; });      // Wait until 'ready' is true

    // Critical section: execute once notified
    std::cout << "Thread " << id << " is running\n";
}

void setReady() {
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate work
    {
        std::lock_guard<std::mutex> lock(mtx);  // Lock the mutex to modify 'ready'
        ready = true;                           // Set the condition
    }
    cv.notify_all();  // Notify all waiting threads that the condition is met
}

int main() {
    std::thread t1(printId, 1);
    std::thread t2(printId, 2);
    std::thread t3(printId, 3);

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::thread t4(setReady);  // Thread to set the condition

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}
