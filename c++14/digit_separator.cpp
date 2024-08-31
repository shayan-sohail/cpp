#include <iostream>

/*
In C++14, the introduction of digit separators using single quotes (') allows developers to format large numeric literals more readably, similar to
how commas are used in written numbers. This feature is particularly useful when working with large values in code, such as memory addresses, constants,
or large numerical datasets. The separator has no effect on the value but makes it easier to verify and understand the magnitude of the number at a glance.
*/
// https://godbolt.org/z/vqnPaErhs

int main() {
    // Using digit separators for readability
    long long largeNumber = 1'000'000'000; // One billion
    int hexNumber = 0xFF'FF'FF; // 16,777,215 in hexadecimal
    long double scientificNumber = 1.23e6'789; // Scientific notation with digit separator

    // Without digit separators
    long long largeNumberNoSep = 1000000000; // Same as largeNumber but less readable

    // Output the results
    std::cout << "Large Number with separator: " << largeNumber << std::endl;
    std::cout << "Large Number without separator: " << largeNumberNoSep << std::endl;
    std::cout << "Hexadecimal Number with separator: " << std::hex << hexNumber << std::endl;
    std::cout << "Scientific Number with separator: " << std::scientific << scientificNumber << std::endl;

    return 0;
}
