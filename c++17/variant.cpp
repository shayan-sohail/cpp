#include <iostream>
#include <variant>
#include <string>

/*
    `std::variant` is a type-safe union introduced in C++17 that can hold one value from a predefined set of types.
    It provides a safer alternative to traditional unions by ensuring type correctness and preventing errors.

    Key Concepts:
    1. `std::variant` can hold a value from multiple types, but only one at a time.
    2. You can use `std::get<T>()` or `std::get<index>()` to retrieve the value, but calling the wrong type will throw an exception.
    3. `std::visit()` applies a visitor (functor) to operate on the currently held value regardless of its type.
*/

// https://godbolt.org/z/KaPhMqjbq

// Example: Creating and using a std::variant

// Define a std::variant that can hold an int, a float, or a std::string
std::variant<int, float, std::string> myVariant;

void printVariantValue(const std::variant<int, float, std::string>& var) {
    // std::visit is used to apply a lambda to the value held by the variant
    std::visit([](auto&& arg) {
        std::cout << "The value of the variant is: " << arg << "\n";
    }, var);
}

int main() {
    // Assign an int to the variant
    myVariant = 42;
    printVariantValue(myVariant); // Output: The value of the variant is: 42

    // Assign a float to the variant
    myVariant = 3.14f;
    printVariantValue(myVariant); // Output: The value of the variant is: 3.14

    // Assign a std::string to the variant
    myVariant = std::string("Hello, Variant!");
    printVariantValue(myVariant); // Output: The value of the variant is: Hello, Variant!

    // Using std::get to retrieve a specific type (std::string in this case)
    if (std::holds_alternative<std::string>(myVariant)) {
        std::string strValue = std::get<std::string>(myVariant);
        std::cout << "Extracted string value: " << strValue << "\n"; // Output: Extracted string value: Hello, Variant!
    }

    // std::get_if returns a pointer to the value if it exists, or nullptr if it does not
    if (auto intPtr = std::get_if<int>(&myVariant)) {
        std::cout << "Integer value is: " << *intPtr << "\n";
    } else {
        std::cout << "Currently not holding an integer.\n";
    }

    return 0;
}
