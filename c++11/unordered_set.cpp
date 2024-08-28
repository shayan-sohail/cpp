#include <iostream>
#include <unordered_set>
#include <string>

/*
unordered_set is similar to unordered_map, but it only stores keys without associated values. The elements in an unordered_set must be unique, and
like unordered_map, it provides average constant-time complexity (O(1)) for insertion, deletion, and access operations due to its underlying hash
table structure.
*/

// https://godbolt.org/z/qfEYGxWGs

int main() {
    // 1. Creating an unordered_set
    std::unordered_set<std::string> nameSet;

    // 2. Inserting elements using insert()
    nameSet.insert("John");
    nameSet.insert("Alice");

    // 3. Inserting elements using emplace()
    nameSet.emplace("Bob"); // more efficient if constructing elements in-place

    // 4. Checking for an element using find()
    if (nameSet.find("John") != nameSet.end()) {
        std::cout << "John is in the set." << std::endl;
    }

    // 5. Checking for existence using count()
    if (nameSet.count("Alice")) {
        std::cout << "Alice is in the set." << std::endl;
    }

    // 6. Checking if the set is empty
    if (!nameSet.empty()) {
        std::cout << "The set is not empty." << std::endl;
    }

    // 7. Getting the size of the set
    std::cout << "The set contains " << nameSet.size() << " elements." << std::endl;

    // 8. Removing an element using erase()
    nameSet.erase("Bob");
    std::cout << "Bob removed. Size now: " << nameSet.size() << std::endl;

    // 9. Iterating over all elements
    for (const auto& name : nameSet) {
        std::cout << name << " is in the set." << std::endl;
    }

    // 10. Clearing the set
    nameSet.clear();
    std::cout << "Set cleared. Size now: " << nameSet.size() << std::endl;

    // 11. Bucket count and bucket size
    std::cout << "Number of buckets: " << nameSet.bucket_count() << std::endl;

    // 12. Load factor
    std::cout << "Load factor: " << nameSet.load_factor() << std::endl;

    // 13. Rehashing the set
    nameSet.rehash(50);
    std::cout << "Number of buckets after rehashing: " << nameSet.bucket_count() << std::endl;

    // 14. Reserving space in the set
    nameSet.reserve(100);
    std::cout << "Number of buckets after reserving: " << nameSet.bucket_count() << std::endl;

    return 0;
}
