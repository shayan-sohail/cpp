#include <iostream>
#include <chrono>
#include <thread>

/*
std::chrono::duration: Represents a time interval, like seconds, milliseconds, etc.
std::chrono::time_point: Represents a specific point in time, often associated with a particular clock.
std::chrono::steady_clock, std::chrono::system_clock, std::chrono::high_resolution_clock: Different clocks used to measure time intervals,
with specific characteristics (e.g., steady, system, high-resolution).
*/

// https://godbolt.org/z/v48hMch55

int main() {
    using namespace std::chrono;

    // Measure the duration of an operation
    auto start = steady_clock::now();

    // Simulate some work
    std::this_thread::sleep_for(seconds(2));

    auto end = steady_clock::now();
    duration<double> elapsed = end - start;

    std::cout << "Elapsed time: " << elapsed.count() << " seconds\n";

    // Representing specific time durations
    duration<int, std::milli> duration_ms(5000);  // 5000 milliseconds or 5 seconds
    std::cout << "Duration in milliseconds: " << duration_ms.count() << " ms\n";

    // Working with time points
    time_point<system_clock> now = system_clock::now();
    std::time_t now_c = system_clock::to_time_t(now);
    std::cout << "Current time: " << std::ctime(&now_c);

    return 0;
}
