#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/*
Generic lambdas in C++14 extend the flexibility of lambdas by allowing the auto keyword in the parameter list. This feature lets the compiler deduce the
types of lambda parameters automatically, enabling the same lambda to work with different types of inputs. This is particularly useful for creating
generic, reusable code without having to specify explicit parameter types, making lambdas more powerful and versatile.
*/

// https://godbolt.org/z/1sh15va4b

int main() {
    // A generic lambda that works with different types of inputs
    auto print = [](auto value) {
        std::cout << value << std::endl;
        };

    // Using the generic lambda with different types
    print(10);            // integer
    print(3.14);          // double
    print("Hello, World"); // string

    // Generic lambda in a standard algorithm
    std::vector<int> numbers = { 1, 2, 3, 4, 5 };
    int factor = 2;

    std::transform(numbers.begin(), numbers.end(), numbers.begin(), [factor](auto num) {
        return num * factor; // Multiply each element by the factor
        });

    std::cout << "Transformed numbers: ";
    for (auto num : numbers) {
        print(num); // Print each transformed number
    }

    return 0;
}
