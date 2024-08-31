#include <iostream>

/*
In C++14, binary literals were introduced to allow developers to represent binary numbers more naturally using the 0b prefix. This feature simplifies
working with binary data, particularly in fields like systems programming, embedded systems, and bitwise operations. Instead of converting binary to
hexadecimal or decimal, developers can now write binary numbers directly, improving code readability and reducing the chances of errors.
*/

// https://godbolt.org/z/8Po3hzP75

int main() {
    // Using binary literals with the 0b prefix
    int a = 0b1010; // Equivalent to decimal 10
    int b = 0b1111'0000; // Equivalent to decimal 240, using the single quote for readability
    int c = 0b10000000; // Equivalent to decimal 128

    // Bitwise operations using binary literals
    int result = a & b; // AND operation between a and b
    int shifted = c >> 2; // Right shift operation on c by 2 bits

    // Output the results
    std::cout << "a (0b1010) = " << a << std::endl;
    std::cout << "b (0b1111'0000) = " << b << std::endl;
    std::cout << "c (0b10000000) = " << c << std::endl;
    std::cout << "a & b = " << result << std::endl; // Expected output: 0
    std::cout << "c >> 2 = " << shifted << std::endl; // Expected output: 32

    return 0;
}
