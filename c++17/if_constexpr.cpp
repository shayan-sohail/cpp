#include <iostream>
#include <type_traits>

/*
constexpr if is a feature introduced in C++17 that enables branching at compile time based on constant expressions. Unlike regular if statements, constexpr if allows the compiler to entirely discard unused code paths, providing a way to write more optimized and flexible code. This is especially useful in template programming, where different implementations are required based on template parameters, but the unused code should not be instantiated. It leads to more efficient compilation and avoids errors in irrelevant code branches.
*/

// https://godbolt.org/z/8xd39vEoK

// Example: Using constexpr if for different data types
template<typename T>
void printType(T value) {
    if constexpr (std::is_integral_v<T>) {
        std::cout << value << " is an integral type.\n";
    } else if constexpr (std::is_floating_point_v<T>) {
        std::cout << value << " is a floating-point type.\n";
    } else {
        std::cout << value << " is of unknown type.\n";
    }
}

int main() {
    printType(42);           // Integral type
    printType(3.14);         // Floating-point type
    printType("Hello");      // Unknown type (const char*)

    return 0;
}
