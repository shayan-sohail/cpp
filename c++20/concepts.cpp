#include <iostream>
#include <concepts>

/*
    Concepts help in specifying constraints for template parameters, ensuring that only certain types 
    (like `Integral`, `FloatingPoint`, etc.) can be used with templates. This makes templates more 
    robust by preventing misuse of types and producing clearer error messages.
*/

// Compiler Argument -std=c++20
// https://godbolt.org/z/qfTqvoahM

// Concept to check if a type is integral
template <typename T>
concept Integral = std::is_integral_v<T>;

// Example 1: Using a concept in a function template
void show(Integral auto val) {
    std::cout << "Integral value: " << val << "\n";
}

// Concept for floating-point types
template <typename T>
concept FloatingPoint = std::is_floating_point_v<T>;

void showFloat(FloatingPoint auto val) {
    std::cout << "Floating-point value: " << val << "\n";
}

// Example 3: Combining multiple concepts
template <typename T>
concept Number = Integral<T> || FloatingPoint<T>;

void showNumber(Number auto val) {
    std::cout << "Number: " << val << "\n";
}

int main() {
    show(42);                // Works: 42 is an integral type
    // show(42.5);           // Error: 42.5 is not an integral type

    showFloat(3.14);          // Works: 3.14 is a floating-point value
    // showFloat(10);        // Error: 10 is not a floating-point value

    showNumber(42);           // Works: 42 is a number (integral type)
    showNumber(3.14);         // Works: 3.14 is a number (floating-point)

    return 0;
}
