#include <iostream>
#include <unordered_set>

/*
unordered_multiset is similar to unordered_set, but it allows multiple occurrences of the same element (duplicates). Elements in an
unordered_multiset are stored without any specific order, and the container offers fast insertion, deletion,
and lookup operations.
*/

// https://godbolt.org/z/xEWTP1fKG

int main() {
    // 1. Creating an unordered_multiset
    std::unordered_multiset<int> umultiset;

    // 2. Inserting elements (duplicates allowed)
    umultiset.insert(1);
    umultiset.insert(2);
    umultiset.insert(3);
    umultiset.insert(1); // Duplicate element

    // 3. Counting elements with a specific value
    std::cout << "Number of occurrences of 1: " << umultiset.count(1) << std::endl;

    // 4. Finding elements using equal_range()
    auto range = umultiset.equal_range(1);
    std::cout << "Elements equal to 1:" << std::endl;
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << *it << std::endl;
    }

    // 5. Iterating over all elements
    std::cout << "\nAll elements in the unordered_multiset:" << std::endl;
    for (const auto& elem : umultiset) {
        std::cout << elem << std::endl;
    }

    // 6. Erasing elements by value (removes all occurrences of the value)
    umultiset.erase(1);
    std::cout << "\nAfter erasing 1:" << std::endl;
    for (const auto& elem : umultiset) {
        std::cout << elem << std::endl;
    }

    return 0;
}
