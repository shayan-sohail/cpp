#include <iostream>

/*
    C++17 introduced fold expressions to simplify the process of applying 
    binary operators to all elements of a parameter pack. There are four types:
    - Unary Left Fold: (... op pack)
    - Unary Right Fold: (pack op ...)
    - Binary Left Fold: (init op ... op pack)
    - Binary Right Fold: (pack op ... op init)
*/

// https://godbolt.org/z/xscjWWdMb

// Example 1: Unary Left Fold (Sum all elements)
template<typename... Args>
auto sum(Args... args) {
    return (... + args); // Expands to (arg1 + arg2 + ... + argN)
}

// Example 2: Unary Right Fold (Check if all are true)
template<typename... Args>
bool allTrue(Args... args) {
    return (args && ...); // Expands to (arg1 && arg2 && ... && argN)
}

// Example 3: Binary Left Fold (Multiply all elements starting from initial value)
template<typename... Args>
auto productWithInit(int init, Args... args) {
    return (init * ... * args); // Expands to (init * arg1 * arg2 * ... * argN)
}

// Example 4: Binary Right Fold (Subtract elements with initial value)
template<typename... Args>
auto subtractWithInit(int init, Args... args) {
    return (args - ... - init); // Expands to (arg1 - arg2 - ... - argN - init)
}

int main() {
    // Unary Left Fold
    std::cout << "Sum of 1, 2, 3: " << sum(1, 2, 3) << "\n";  // Output: 6

    // Unary Right Fold
    std::cout << "Are all true (true, true, false): " << allTrue(true, true, false) << "\n";  // Output: 0 (false)

    // Binary Left Fold
    std::cout << "Product with init value 2, elements (3, 4): " << productWithInit(2, 3, 4) << "\n";  // Output: 24

    // Binary Right Fold
    std::cout << "Subtract with init 5, elements (20, 10): " << subtractWithInit(5, 20, 10) << "\n";  // Output: 5

    return 0;
}
