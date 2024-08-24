#include <iostream>
#include <vector>
#include <string>
#include <map>

/*
Alias templates in C++11 allow you to create type aliases using templates.
They simplify the code and improve readability, especially when working with complex template instantiations.
Alias templates are declared using the using keyword.
*/

// https://godbolt.org/z/arrMYrjGM

// Traditional typedef (before C++11)
typedef std::vector<std::string> StringList;

// Alias template (C++11)
template <typename T>
using Vec = std::vector<T>;

// Alias template for a more complex type
template <typename Key, typename Value>
using Dict = std::map<Key, Value>;

int main() {
    // Using traditional typedef
    StringList names = { "Alice", "Bob", "Charlie" };
    for (const auto& name : names) {
        std::cout << name << std::endl;
    }

    // Using alias template
    Vec<int> numbers = { 1, 2, 3, 4, 5 };
    for (int number : numbers) {
        std::cout << number << std::endl;
    }

    // Using alias template for complex type
    Dict<std::string, int> ageMap = { {"Alice", 30}, {"Bob", 25}, {"Charlie", 35} };
    for (const auto& [name, age] : ageMap) {
        std::cout << name << " is " << age << " years old." << std::endl;
    }

    return 0;
}
