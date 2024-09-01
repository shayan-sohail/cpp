#include <iostream>
#include <map>
#include <string>
#include <set>

/*
In C++14, associative containers like std::map, std::set, and their unordered variants (std::unordered_map, std::unordered_set, etc.) introduced support
for heterogeneous lookup. This feature allows these containers to perform search operations using types other than the key type, without needing to convert
the search key to the container's key type. By enabling the use of different types for lookups, such as performing a search in a std::map<std::string, T>
using a const char*, this feature reduces the overhead of unnecessary conversions and can lead to more efficient and expressive code.
*/

// https://godbolt.org/z/vvGGhxf61

int main() {
    // Example 1: Heterogeneous lookup in std::map
    std::map<std::string, int> phoneBook = {
        {"Alice", 12345},
        {"Bob", 67890},
        {"Charlie", 11122}
    };

    // Lookup using std::string (same type as key)
    auto it1 = phoneBook.find("Alice"); // No conversion needed
    if (it1 != phoneBook.end()) {
        std::cout << "Alice's number: " << it1->second << std::endl;
    }

    // Lookup using const char* (different type than key)
    auto it2 = phoneBook.find("Bob"); // Implicit conversion or heterogeneous lookup
    if (it2 != phoneBook.end()) {
        std::cout << "Bob's number: " << it2->second << std::endl;
    }

    // Example 2: Heterogeneous lookup in std::set
    std::set<std::string> nameSet = { "Alice", "Bob", "Charlie" };

    // Lookup using std::string (same type as key)
    auto it3 = nameSet.find("Charlie"); // No conversion needed
    if (it3 != nameSet.end()) {
        std::cout << "Found: " << *it3 << std::endl;
    }

    // Lookup using const char* (different type than key)
    auto it4 = nameSet.find("Bob"); // Heterogeneous lookup avoids conversion
    if (it4 != nameSet.end()) {
        std::cout << "Found: " << *it4 << std::endl;
    }

    return 0;
}
