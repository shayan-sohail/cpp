#include <iostream>
#include <cstddef> // for std::alignof
#include <cstdint>

/*
In C++11, alignof returns the alignment (in bytes) required for a type, which is crucial for optimizing memory access.
alignas allows specifying a custom alignment for a type or variable, which can be useful for aligning data to specific boundaries
(e.g., for performance reasons in low-level programming). Misaligned data can lead to inefficient memory access or hardware exceptions,
so controlling alignment is important in performance-critical or hardware-interfacing code.
*/

// https://godbolt.org/z/j7h3oY1ab

struct DefaultAligned {
    int a;
    double b;
};

struct CustomAligned {
    alignas(16) int a;  // Align 'a' to 16 bytes
    alignas(32) double b; // Align 'b' to 32 bytes
};

int main() {
    // Query alignment
    std::cout << "Alignment of int: " << alignof(int) << " bytes\n";
    std::cout << "Size of int: " << sizeof(int) << " bytes\n";
    std::cout << "Alignment of double: " << alignof(double) << " bytes\n";
    std::cout << "Size of double: " << sizeof(double) << " bytes\n";
    std::cout << "Alignment of DefaultAligned: " << alignof(DefaultAligned) << " bytes\n";
    std::cout << "Size of DefaultAligned: " << sizeof(DefaultAligned) << " bytes\n";
    std::cout << "Alignment of CustomAligned: " << alignof(CustomAligned) << " bytes\n";
    std::cout << "Size of CustomAligned: " << sizeof(CustomAligned) << " bytes\n";

    // Custom aligned variables
    alignas(128) double customAlignedDouble;
    alignas(64) int customAlignedInt;

    std::cout << "Alignment of customAlignedInt: " << alignof(customAlignedInt) << " bytes\n";
    std::cout << "Size of customAlignedInt: " << sizeof(customAlignedInt) << " bytes\n";
    std::cout << "Address of customAlignedInt: " << (uintptr_t)&customAlignedInt << " bytes\n";
    std::cout << "Alignment of customAlignedDouble: " << alignof(decltype(customAlignedDouble)) << " bytes\n";
    std::cout << "Size of customAlignedDouble: " << sizeof(customAlignedDouble) << " bytes\n";
    std::cout << "Address of customAlignedDouble: " << (uintptr_t)&customAlignedDouble << " bytes\n";

    return 0;
}
