#include <iostream>
#include <string>
#include <chrono>
#include <complex>

/*
User-defined literals in C++ allow developers to define custom suffixes for literals, making it possible to create objects of standard library types
directly from literal values. Introduced in C++11 and expanded in C++14, these literals enhance code readability and expressiveness by allowing operations
like creating std::string, std::chrono::duration, or std::complex objects directly from literal values. This feature is particularly useful when working
with units, custom types, or when you need to convert between types frequently. By defining user-defined literals, developers can avoid verbose
constructor calls, making the code cleaner and easier to understand.
*/

// https://godbolt.org/z/sMj3o5WbE

// User-defined literal for std::string
std::string operator"" _s(const char* str, std::size_t) {
    return std::string(str);
}

// User-defined literal for std::chrono::seconds
std::chrono::seconds operator"" _sec(unsigned long long s) {
    return std::chrono::seconds(s);
}

// User-defined literal for std::complex
std::complex<double> operator"" _i(long double imag) {
    return std::complex<double>(0.0, imag);
}

int main() {
    // Example 1: Creating std::string with user-defined literal
    std::string hello = "Hello, World!"_s;
    std::cout << hello << std::endl; // Output: Hello, World!

    // Example 2: Creating std::chrono::seconds with user-defined literal
    auto duration = 10_sec;
    std::cout << "Duration: " << duration.count() << " seconds" << std::endl; // Output: Duration: 10 seconds

    // Example 3: Creating std::complex with user-defined literal
    std::complex<double> c = 2.5_i;
    std::cout << "Complex number: " << c << std::endl; // Output: Complex number: (0,2.5)

    return 0;
}
