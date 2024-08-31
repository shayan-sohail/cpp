#include <iostream>
#include <vector>
#include <string>

/*
Auto Return Type Deduction: If a function's return type is declared as auto, the compiler deduces the return type from the return statement(s) in the function.
Benefits: Reduces redundancy, especially when dealing with complex return types or when return types depend on template parameters. It also improves readability and maintainability.
Restrictions: All return statements in the function must yield the same type, or the function should only have one return statement.
*/

// https://godbolt.org/z/383Pha9xb

// Function with a single return type
auto add(int a, int b) {
    return a + b; // Compiler deduces return type as int
}

// Function returning a vector
auto createVector(int n) {
    std::vector<int> v;
    for (int i = 0; i < n; ++i) {
        v.push_back(i);
    }
    return v; // Compiler deduces return type as std::vector<int>
}

// Function returning consistent  types based on conditions
auto conditionalReturn(bool flag) {
    if (flag) {
        return std::string("Hello"); // Consistently return std::string
    }
    else {
        return std::string("World"); // Consistently return std::string
    }
    // Both return statements now return the same type: std::string
}

// Function template with return type dependent on the template parameter
template <typename T>
auto multiply(T a, T b) {
    return a * b; // Compiler deduces return type based on the template argument
}

// Example of how return type deduction fails
// auto mixedReturn(bool flag) {
//     if (flag) {
//         return 1; // int
//     } else {
//         return 1.0; // double
//     }
//     // Error: Inconsistent return types
// }

int main() {
    // Test add function
    std::cout << "Addition: " << add(2, 3) << std::endl;

    // Test createVector function
    auto vec = createVector(5);
    std::cout << "Vector elements: ";
    for (auto el : vec) {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    // Test conditionalReturn function
    std::cout << "Conditional Return: " << conditionalReturn(true) << std::endl;

    // Test multiply template function
    std::cout << "Multiplication: " << multiply(3, 4) << std::endl;
    std::cout << "Multiplication (double): " << multiply(3.5, 2.0) << std::endl;

    return 0;
}
