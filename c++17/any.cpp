#include <iostream>
#include <any>
#include <string>
#include <typeinfo>

/*
    `std::any` is a type-safe container for single values of any type introduced in C++17.
    It can store any type of value, and the type can be determined at runtime.

    Key Concepts:
    1. `std::any` can hold values of any type.
    2. Use `std::any_cast` to retrieve the value of a specific type.
    3. Check if `std::any` contains a value using `has_value()`.
    4. If you try to cast to an incorrect type using `std::any_cast`, it throws `std::bad_any_cast`.
*/

// https://godbolt.org/z/d5oz4qEv7

// Example: Using std::any to store different types of values

int main() {
    // Storing an integer in std::any
    std::any myValue = 42;  // Stores an int

    // Checking if std::any has a value
    if (myValue.has_value()) {
        // Retrieving the value with the correct type using std::any_cast
        try {
            int intValue = std::any_cast<int>(myValue);
            std::cout << "Integer value: " << intValue << "\n";  // Output: Integer value: 42
        } catch (const std::bad_any_cast& e) {
            std::cout << "Bad any_cast: " << e.what() << "\n";
        }
    }

    // Storing a string in the same std::any variable
    myValue = std::string("Hello, std::any!");  // Stores a std::string
    
    // Checking the stored type at runtime
    std::cout << "Type stored: " << myValue.type().name() << "\n";  // Output depends on compiler (std::string type)

    // Trying to retrieve it as an int will throw an exception
    try {
        int wrongTypeValue = std::any_cast<int>(myValue);  // Incorrect cast
    } catch (const std::bad_any_cast& e) {
        std::cout << "Error: " << e.what() << "\n";  // Output: Error: bad any_cast
    }

    // Correct cast to std::string
    try {
        std::string strValue = std::any_cast<std::string>(myValue);
        std::cout << "String value: " << strValue << "\n";  // Output: String value: Hello, std::any!
    } catch (const std::bad_any_cast& e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    return 0;
}
