#include <iostream>
#include <unordered_map>
#include <string>

/*
unordered_map is part of the C++ Standard Library, introduced with C++11, and is used to store unique key-value pairs where keys are used to look up values efficiently. The keys are hashed into buckets to optimize search times. Unlike std::map, the elements in an unordered_map are not stored in any particular order. It provides average constant-time complexity (O(1)) for insertion, deletion, and access operations, making it highly efficient for large datasets where order doesn't matter.
*/


// https://godbolt.org/z/baKdfoW9b

int main() {
    // 1. Creating an unordered_map
    std::unordered_map<std::string, int> ageMap;

    // 2. Inserting elements using insert()
    ageMap.insert({ "John", 25 });
    ageMap.insert({ "Alice", 30 });

    // 3. Inserting elements using operator[]
    ageMap["Bob"] = 22;
    ageMap["Diana"] = 27;

    // 4. Accessing elements using operator[]
    std::cout << "John's age: " << ageMap["John"] << std::endl;

    // 5. Accessing elements using at()
    std::cout << "Alice's age: " << ageMap.at("Alice") << std::endl;

    // 6. Checking for a key using find()
    if (ageMap.find("Bob") != ageMap.end()) {
        std::cout << "Bob is in the map." << std::endl;
    }

    // 7. Checking if map is empty
    if (!ageMap.empty()) {
        std::cout << "The map is not empty." << std::endl;
    }

    // 8. Getting the size of the map
    std::cout << "The map contains " << ageMap.size() << " elements." << std::endl;

    // 9. Removing an element using erase()
    ageMap.erase("Diana");
    std::cout << "Diana removed. Size now: " << ageMap.size() << std::endl;

    // 10. Iterating over all elements
    for (const auto& pair : ageMap) {
        std::cout << pair.first << " is " << pair.second << " years old." << std::endl;
    }

    // 11. Clearing the map
    ageMap.clear();
    std::cout << "Map cleared. Size now: " << ageMap.size() << std::endl;

    // 12. Bucket count and bucket size
    /*
    A bucket in an unordered_map can hold one or more elements (key-value pairs). When an element is inserted, a hash function determines the bucket
    in which the element will be placed. The number of buckets (bucket_count) influences the distribution of elements, affecting the performance
    of operations like insertion and lookup.
    */
    std::cout << "Number of buckets: " << ageMap.bucket_count() << std::endl;

    // 13. Load factor
    /*
    The load factor is calculated as size() / bucket_count(), where size() is the number of elements in the unordered_map. A high load factor indicates t
    hat many elements are being stored in each bucket, which can lead to increased collisions and slower performance. Conversely, a low load
    factor means elements are more evenly spread out, but this could lead to inefficient memory usage.
    */
    std::cout << "Load factor: " << ageMap.load_factor() << std::endl;

    // 14. Rehashing the map
    /*
    When you call rehash(n), the unordered_map adjusts the number of buckets to ensure that bucket_count() is at least n. This operation may involve
    reassigning elements to new buckets according to their hash values. Rehashing is typically done to maintain an optimal load factor, especially
    after a large number of insertions, or when the load factor exceeds a certain threshold.
    */
    ageMap.rehash(50);
    std::cout << "Number of buckets after rehashing: " << ageMap.bucket_count() << std::endl;

    // 15. Reserving space in the map
    ageMap.reserve(100);
    std::cout << "Number of buckets after reserving: " << ageMap.bucket_count() << std::endl;

    return 0;
}
