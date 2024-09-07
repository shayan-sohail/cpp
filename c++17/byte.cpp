#include <iostream>
#include <cstddef> // For std::byte

/*
    `std::byte` is introduced in C++17 to represent a single byte of data. 
    Unlike `char` or `unsigned char`, `std::byte` is not a character type, 
    making it ideal for low-level byte-oriented operations where type safety is important.

    Key Features:
    1. Provides type safety: Clearly indicates that you're working with raw bytes, 
       not characters or integers.
    2. Supports bitwise operations: `std::byte` supports bitwise operations, 
       such as AND, OR, and XOR.
    3. Cannot be directly used in arithmetic operations: This prevents accidental 
       misuse, unlike `char` or `unsigned char`.

    Benefits:
    - Ensures more readable and safe code when working with raw memory or binary data.
*/

// https://godbolt.org/z/PojcGjzEz

// Example: Working with std::byte
int main() {
    // Example 1: Initializing std::byte
    std::byte b1{0x1F}; // Initializes a byte with the hexadecimal value 0x1F
    std::byte b2 = std::byte{0x7A}; // Another way to initialize a byte

    std::cout << "b1: " << std::to_integer<int>(b1) << "\n";  // Output: 31 (0x1F in decimal)
    std::cout << "b2: " << std::to_integer<int>(b2) << "\n";  // Output: 122 (0x7A in decimal)

    // Example 2: Performing bitwise operations on std::byte
    std::byte result = b1 | b2; // Bitwise OR
    std::cout << "Result of b1 | b2: " << std::to_integer<int>(result) << "\n";  // Output: 127 (0x7F in decimal)

    // Example 3: Bitwise AND operation
    result = b1 & b2; 
    std::cout << "Result of b1 & b2: " << std::to_integer<int>(result) << "\n";  // Output: 26 (0x1A in decimal)

    // Example 4: Shifting bytes
    std::byte shifted = b1 << 2; // Shift bits of b1 left by 2
    std::cout << "b1 shifted left by 2: " << std::to_integer<int>(shifted) << "\n";  // Output: 124 (0x7C in decimal)

    return 0;
}
