#include <iostream>
#include <map>

/*
    Splicing in C++17 allows efficient transfer of elements between maps and sets without the need for copying.
    It moves the elements directly, maintaining their keys and values as they were in the original container.

    - `map::extract()`: Removes an element from a map but keeps its value intact, returning a "node handle."
    - `map::insert()`: Inserts a node handle into another map.

    The advantage of this approach is efficiency. When splicing, no key-value pairs are re-allocated or copied.
*/

// https://godbolt.org/z/en6Ej1Kzz

int main() {
    // Example 1: Splicing elements between two maps
    std::map<int, std::string> sourceMap = {{1, "One"}, {2, "Two"}, {3, "Three"}};
    std::map<int, std::string> targetMap = {{4, "Four"}, {5, "Five"}};

    std::cout << "Before splicing:\n";
    std::cout << "Source map: ";
    for (const auto& [key, value] : sourceMap) {
        std::cout << "{" << key << ", " << value << "} ";
    }
    std::cout << "\nTarget map: ";
    for (const auto& [key, value] : targetMap) {
        std::cout << "{" << key << ", " << value << "} ";
    }
    std::cout << '\n';

    // Extract an element from the source map
    auto node = sourceMap.extract(2); // Extract key 2 (Two)

    // Insert the extracted element into the target map
    targetMap.insert(std::move(node));

    std::cout << "\nAfter splicing:\n";
    std::cout << "Source map: ";
    for (const auto& [key, value] : sourceMap) {
        std::cout << "{" << key << ", " << value << "} ";
    }
    std::cout << "\nTarget map: ";
    for (const auto& [key, value] : targetMap) {
        std::cout << "{" << key << ", " << value << "} ";
    }
    std::cout << '\n';

    return 0;
}
