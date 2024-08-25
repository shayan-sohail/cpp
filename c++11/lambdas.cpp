#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

/*
Lambda expressions provide a concise way to define functions directly within the code, often used for short-lived operations like sorting, filtering, or passing simple functions as arguments. They can capture variables by value or reference and can be used anywhere a function object is required.
*/

// https://godbolt.org/z/94rMxbG4K

int main() {
    // Basic lambda expression with no captures
    auto add = [](int a, int b) {
        return a + b;
        };
    std::cout << "Add 5 and 3: " << add(5, 3) << std::endl;

    // Lambda with captures by value
    int factor = 2;
    auto multiply = [factor](int a) {
        return a * factor;
        };
    std::cout << "Multiply 4 by factor (2): " << multiply(4) << std::endl;

    // Lambda with captures by reference
    int sum = 0;
    auto add_to_sum = [&sum](int a) {
        sum += a;
        };
    add_to_sum(10);
    std::cout << "Sum after adding 10: " << sum << std::endl;

    // Lambda returning void
    auto print = [](int a) {
        std::cout << "Printing: " << a << std::endl;
        };
    print(100);

    // Lambda with parameters and a return type
    auto subtract = [](int a, int b) -> int {
        return a - b;
        };
    std::cout << "Subtract 8 from 12: " << subtract(12, 8) << std::endl;

    // Lambda used in std::sort with a container
    std::vector<int> numbers = { 4, 2, 5, 1, 3 };
    std::sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return a < b;
        });
    std::cout << "Sorted numbers: ";
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    // Lambda stored in std::function
    std::function<int(int, int)> divide = [](int a, int b) {
        return a / b;
        };
    std::cout << "Divide 10 by 2: " << divide(10, 2) << std::endl;

    // Potential issue without lambda expressions: Boilerplate for small functions
    struct AddStruct {
        int operator()(int a, int b) const {
            return a + b;
        }
    };
    AddStruct addStruct;
    std::cout << "Add using struct: " << addStruct(7, 3) << std::endl;

    return 0;
}
