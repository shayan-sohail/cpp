#include <iostream>
#include <unordered_map>
#include <string>

/*
unordered_multimap is similar to unordered_map, but it allows multiple elements with the same key. This makes it suitable when you need to store duplicate
keys with different values. Elements in an unordered_multimap are stored in no particular order, and the container offers fast insertion, deletion, and
lookup operations.
*/

// https://godbolt.org/z/G9TnM98Tn

int main() {
    // 1. Creating an unordered_multimap
    std::unordered_multimap<std::string, int> umultimap;

    // 2. Inserting elements (multiple elements with the same key allowed)
    umultimap.insert({ "apple", 1 });
    umultimap.insert({ "banana", 2 });
    umultimap.insert({ "apple", 3 });  // Duplicate key "apple" with different value

    // 3. Counting elements with a specific key
    std::cout << "Number of elements with key 'apple': " << umultimap.count("apple") << std::endl;

    // 4. Finding elements with a specific key using equal_range()
    auto range = umultimap.equal_range("apple");
    std::cout << "Elements with key 'apple':" << std::endl;
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    // 5. Iterating over all elements
    std::cout << "\nAll elements in the unordered_multimap:" << std::endl;
    for (const auto& pair : umultimap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // 6. Erasing elements by key (removes all pairs with the key)
    umultimap.erase("apple");
    std::cout << "\nAfter erasing 'apple':" << std::endl;
    for (const auto& pair : umultimap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
