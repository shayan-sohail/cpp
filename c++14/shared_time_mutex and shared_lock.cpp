#include <iostream>
#include <shared_mutex>
#include <thread>
#include <vector>
#include <chrono>
#include <mutex>

/*
Introduced in C++14, std::shared_timed_mutex is a synchronization primitive that allows multiple threads to acquire a shared lock simultaneously,
enabling read-only access, while a unique lock (exclusive lock) is required for write operations. It also supports timed locking, where a thread can attempt
to acquire a lock within a specific time period. std::shared_lock is a helper class that manages shared ownership of a std::shared_timed_mutex. These tools
are particularly useful in scenarios where multiple threads need to read shared data concurrently, but only one thread can modify the data at a time, making
them ideal for improving performance in read-heavy multi-threaded applications.
*/

// https://godbolt.org/z/6TvTneec3

class SharedData {
public:
    void readData() const {
        std::shared_lock lock(mutex_); // Acquires a shared lock for reading
        std::cout << "Reading data: " << data_ << " by thread " << std::this_thread::get_id() << std::endl;
        // Simulate long read operation
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    void writeData(int value) {
        std::unique_lock lock(mutex_); // Acquires a unique lock for writing
        std::cout << "Writing data: " << value << " by thread " << std::this_thread::get_id() << std::endl;
        data_ = value;
        // Simulate long write operation
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

private:
    mutable std::shared_timed_mutex mutex_;
    int data_ = 0;
};

void reader(const SharedData& sharedData) {
    sharedData.readData();
}

void writer(SharedData& sharedData, int value) {
    sharedData.writeData(value);
}

int main() {
    SharedData sharedData;

    // Create a few reader threads
    std::vector<std::thread> threads;
    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(reader, std::ref(sharedData));
    }

    // Create a writer thread
    std::thread writerThread(writer, std::ref(sharedData), 42);

    // Join all threads
    for (auto& t : threads) {
        t.join();
    }
    writerThread.join();

    return 0;
}
