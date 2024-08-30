#include <iostream>
#include <thread>
#include <mutex>

/*
std::mutex is used to prevent race conditions by locking a section of code so that only one thread can execute it at a time.
When a thread locks a mutex, other threads attempting to lock it will block until the mutex is unlocked.
This is essential in multithreaded programs where shared data is accessed or modified by multiple threads.
*/

// https://godbolt.org/z/bYYM7KGW3

std::mutex mtx;  // 1. Create a global mutex

void printNumbers(int id) {
    for (int i = 0; i < 5; ++i) {
        //Mutex is inside the loop as each iteration is considered as critical section, 
        // mutex should be locked for minimal time
        std::lock_guard<std::mutex> lock(mtx);  // 2. Lock mutex before accessing shared data
        std::cout << "Thread " << id << " prints: " << i << std::endl;
        // Mutex is automatically released when lock goes out of scope
    }
}

int main() {
    // 3. Start multiple threads
    std::thread t1(printNumbers, 1);
    std::thread t2(printNumbers, 2);

    // 4. Join threads to main thread
    t1.join();
    t2.join();

    return 0;
}
