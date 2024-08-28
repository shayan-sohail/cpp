#include <iostream>
#include <array>
#include <algorithm>

/*
std::array is a part of the C++ Standard Library introduced in C++11. It is a wrapper around a static array, offering array-like behavior with the
added benefits of standard container functions. It is type-safe, supports iterators, and has a fixed size determined at compile time, meaning the size cannot
be changed during runtime. std::array offers better performance compared to dynamic containers like std::vector, as it avoids dynamic memory allocation.
*/

// https://godbolt.org/z/jjMjcM7Ke

int main() {
    // 1. Creating a std::array of size 5
    std::array<int, 5> arr = { 1, 2, 3, 4, 5 };

    // 2. Accessing elements using operator[]
    std::cout << "Element at index 2: " << arr[2] << std::endl;

    // 3. Using at() method to access elements with bounds checking
    std::cout << "Element at index 3: " << arr.at(3) << std::endl;

    // 4. Iterating over the elements using a range-based for loop
    std::cout << "Elements in the array:" << std::endl;
    for (const auto& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // 5. Getting the size of the array
    std::cout << "Array size: " << arr.size() << std::endl;

    // 6. Filling the array with a specific value
    arr.fill(10);
    std::cout << "Array after filling with 10:" << std::endl;
    for (const auto& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // 7. Sorting the array (although it's already sorted)
    std::sort(arr.begin(), arr.end());
    std::cout << "Array after sorting:" << std::endl;
    for (const auto& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
