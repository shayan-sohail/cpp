#include <iostream>

/*
In C++14, the restrictions on constexpr functions were relaxed, enabling a broader range of functions and expressions to be evaluated at compile-time.
Unlike C++11, which imposed stricter limitations, C++14 allows constexpr functions to include control structures like loops and conditional statements,
making them more powerful and flexible. This enhancement allows developers to write more complex and efficient compile-time code, contributing to
better performance and cleaner code.
*/

// https://godbolt.org/z/415KfhPjn

// C++11 constexpr function (strict limitations)
constexpr int factorialC11(int n) {
    return n <= 1 ? 1 : n * factorialC11(n - 1); // Only recursion allowed, no loops or local variables
}

// C++14 constexpr function (relaxed restrictions)
constexpr int factorialC14(int n) {
    int result = 1; // Local variables are allowed
    for (int i = 2; i <= n; ++i) {
        result *= i; // Loops are allowed
    }
    return result;
}

int main() {
    // Compile-time evaluation in C++14
    constexpr int fact5 = factorialC14(5); // Uses the C++14 version
    std::cout << "Factorial of 5 (C++14): " << fact5 << std::endl;

    // Compile-time evaluation in C++11
    constexpr int fact4 = factorialC11(4); // Uses the C++11 version
    std::cout << "Factorial of 4 (C++11): " << fact4 << std::endl;

    return 0;
}
