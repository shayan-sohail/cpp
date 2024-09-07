#include <iostream>
#include <algorithm>
#include <vector>
#include <execution>
#include <numeric> // For std::iota
#include <random>
#include <chrono>

/*
    C++17 added support for parallel algorithms through the `<execution>` header.
    This allows many standard algorithms (like sort, transform, etc.) to be executed
    in parallel, improving performance on multi-core systems.

    Key Concepts:
    1. **Execution Policies**: Control how the algorithm is executed. There are three policies:
       - `std::execution::seq`: Sequential execution (default).
       - `std::execution::par`: Parallel execution.
       - `std::execution::par_unseq`: Parallel and vectorized execution (hardware-dependent).
    2. **Performance Boost**: By using parallel execution policies, the same algorithm can be sped up
       by utilizing multiple CPU cores.
    3. **Thread Safety**: Parallel algorithms ensure thread safety internally, so you don't need
       to worry about managing threads yourself.
*/

// https://godbolt.org/z/KG3MrnTqq

int main() {
    // Example 1: Parallel execution of std::sort using std::execution::par
    std::vector<int> data(1'000'000);
    
    // Fill the vector with increasing numbers
    std::iota(data.begin(), data.end(), 1);

    // Shuffle the data to make it unsorted
    std::shuffle(data.begin(), data.end(), std::mt19937{std::random_device{}()});

    auto start = std::chrono::high_resolution_clock::now();

    // Sorting using parallel execution policy
    std::sort(std::execution::par, data.begin(), data.end());

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    
    std::cout << "Parallel sort took: " << duration.count() << " seconds.\n";

    // Example 2: Parallel execution of std::transform
    std::vector<int> output(data.size());

    start = std::chrono::high_resolution_clock::now();

    // Apply a transformation using parallel execution
    std::transform(std::execution::par, data.begin(), data.end(), output.begin(), [](int x) {
        return x * 2;
    });

    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    
    std::cout << "Parallel transform took: " << duration.count() << " seconds.\n";

    return 0;
}
