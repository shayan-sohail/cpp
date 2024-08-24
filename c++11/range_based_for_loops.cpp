#include <iostream>
#include <vector>
#include <array>

/*
The range-based for loop simplifies iteration by automatically handling the traversal of containers like arrays, vectors,
and other iterable objects. This reduces boilerplate code and minimizes the chances of errors related to iterators or loop boundaries.
*/

// https://godbolt.org/z/o4deMqnar

int main() {
    // Initialize a vector and an array
    std::vector<int> vec = { 1, 2, 3, 4, 5 };
    std::array<int, 5> arr = { 10, 20, 30, 40, 50 };

    // Range-based for loop for vector
    std::cout << "Vector elements: ";
    for (int value : vec) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Range-based for loop for array
    std::cout << "Array elements: ";
    for (int value : arr) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Potential issue without range-based for loops: Errors in iterator or index handling
    // Traditional loop might introduce errors in boundaries or iterator usage
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << "Vector element " << i << ": " << vec[i] << std::endl;
    }

    return 0;
}
