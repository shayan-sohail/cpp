#include <iostream>
#include <vector>
#include <algorithm>

/*
Lambda capture initializers in C++14 enhance lambda expressions by enabling you to initialize variables within the capture clause itself. This feature
allows more complex expressions and temporary objects to be captured, providing greater flexibility when working with lambdas. Instead of capturing an
existing variable, you can create and initialize a new one on the fly, which is especially useful when you need to capture a calculated value or an object
that should not exist outside the lambda's scope.
*/

// https://godbolt.org/z/EejbffG3h

int main() {
    // Regular variable
    int x = 10;

    // Lambda with capture initializer
    auto multiply = [factor = x + 5](int value) {
        // factor is initialized as x + 5, i.e., 15
        return value * factor;
        };

    std::cout << "Multiplication result: " << multiply(2) << std::endl; // Output: 30

    // Using lambda capture initializer in a standard algorithm
    std::vector<int> numbers = { 1, 2, 3, 4, 5 };
    int offset = 3;

    // Capture initializer to store the sum of offset and each element
    std::transform(numbers.begin(), numbers.end(), numbers.begin(), [sum = offset](int num) mutable {
        sum += num; // sum is mutable; it can be modified within the lambda
        return sum;
        });

    std::cout << "Transformed numbers: ";
    for (int num : numbers) {
        std::cout << num << " "; // Output: 4 6 9 13 18
    }
    std::cout << std::endl;

    return 0;
}
