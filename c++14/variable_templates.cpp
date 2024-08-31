#include <iostream>

/*
C++14 introduced variable templates, which enable the definition of templated variables similarly to how function templates are defined. This feature allows
for variable templates that can be specialized for different data types, making it easier to create generic constants, configurations, or other shared
data structures that adapt based on type. Variable templates enhance code flexibility and reduce redundancy by allowing the same variable to be used
with different types while maintaining type safety.
*/

// https://godbolt.org/z/KfhvzPa4v

// Define a variable template for a constant value
template<typename T>
constexpr T pi = T(3.1415926535897932385); // Primary template

// Specialization for float
template<>
constexpr float pi<float> = 3.1415927f; // Specialized for float

// Variable template for computing powers of 2
template<typename T>
constexpr T powerOfTwo = T(2) * T(2); // Primary template for computing 2^2

// Specialization for integer types
template<>
constexpr int powerOfTwo<int> = 4; // 2^2 = 4 for integers

// Specialization for larger powers
template<>
constexpr int powerOfTwo<long> = 1024; // Specialized for long (2^10)

int main() {
    // Using the variable template with different types
    std::cout << "Value of pi<double>: " << pi<double> << std::endl; // Uses primary template
    std::cout << "Value of pi<float>: " << pi<float> << std::endl;   // Uses specialized version for float

    // Using the variable template for power of two
    std::cout << "Power of two (int): " << powerOfTwo<int> << std::endl;   // Uses specialized version for int
    std::cout << "Power of two (long): " << powerOfTwo<long> << std::endl; // Uses specialized version for long

    return 0;
}
