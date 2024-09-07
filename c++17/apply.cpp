#include <iostream>
#include <tuple>
#include <functional> // For std::apply

/*
    `std::apply` takes a callable object (like a function, lambda, or functor) and a tuple,
    and applies the tuple elements as arguments to the callable. It effectively "unpacks" the tuple
    and forwards its elements to the function as individual arguments.

    Key Features:
    - It can apply functions to tuple elements, automatically handling the unpacking of tuples.
    - Makes it easier to work with functions that require multiple arguments when your data is stored in a tuple.
*/

// https://godbolt.org/z/WoMvx7n4Y

int add(int a, int b, int c) {
    return a + b + c;
}

int main() {
    // Example 1: Applying a tuple to a function
    std::tuple<int, int, int> myTuple(1, 2, 3);

    // Apply the function `add` to the elements of `myTuple`
    int result = std::apply(add, myTuple); // Equivalent to calling add(1, 2, 3)
    std::cout << "Sum of tuple elements: " << result << '\n';

    // Example 2: Using `std::apply` with a lambda
    auto lambda = [](int x, int y) {
        return x * y;
    };
    std::tuple<int, int> tuple2(4, 5);

    int product = std::apply(lambda, tuple2); // Equivalent to calling lambda(4, 5)
    std::cout << "Product of tuple elements: " << product << '\n';

    return 0;
}
