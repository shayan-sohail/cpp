#include <iostream>
#include <optional>
#include <string>

/*
    `std::optional` is a wrapper type introduced in C++17 that represents optional (nullable) values.
    It can either hold a value or represent the absence of a value.

    Key Concepts:
    1. `std::optional<T>` can be empty, or it can hold a value of type `T`.
    2. You can check if an `optional` has a value using `has_value()` or by converting it to `bool`.
    3. Access the value using `value()`, but calling `value()` on an empty `optional` will throw an exception.
    4. Use `value_or(default_value)` to provide a fallback when the `optional` is empty.
*/

// https://godbolt.org/z/oqrq1cavn

// Example: Using std::optional to represent optional values

// Function that returns an optional string
std::optional<std::string> getUsername(bool valid) {
    if (valid) {
        return std::string("JohnDoe");  // Return a valid username
    }
    return std::nullopt;  // Return empty optional if invalid
}

int main() {
    // Case 1: Username is valid
    std::optional<std::string> username = getUsername(true);
    
    // Check if the optional contains a value
    if (username.has_value()) {
        std::cout << "Username is: " << username.value() << "\n";  // Output: Username is: JohnDoe
    } else {
        std::cout << "No username provided.\n";
    }

    // Case 2: Username is invalid
    username = getUsername(false);
    
    // Using the value_or method to provide a default value
    std::cout << "Username is: " << username.value_or("Guest") << "\n";  // Output: Username is: Guest

    // Using optional as a boolean
    if (username) {
        std::cout << "Valid username: " << *username << "\n";
    } else {
        std::cout << "Username is empty.\n";  // Output: Username is empty.
    }

    return 0;
}
