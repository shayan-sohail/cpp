#include <iostream>
#include <vector>

/*The auto keyword is used to automatically deduce the type of a variable from its initializer.
This means you no longer need to explicitly specify the type of a variable, making your code more concise and readable.
1) Deduction from Initializer
2) Deduction from Function Return Value
3) Deduction from Lambda Expressions
4) Deduction from Template Parameters
5) Declaring Iterators*/

// https://godbolt.org/z/M1198d3xE

std::vector<int> getNumbers() {
    return { 1, 2, 3 };
}

template <typename T, typename U>
T add(T a, U b) {
    return a + b;
}

int main()
{
    // Deduction from Initializer:
    int x = 10;
    auto y = x; // y is also of type int

    // Deduction from Function Return Value:
    auto numbers = getNumbers();

    // Deduction from Lambda Expressions:
    auto myLambda = [](int a, int b) { return a + b; };
    int result = myLambda(3, 5); // result is of type int

    // Deduction from Template Parameters:
    auto sum = add(3.14, 5); // sum is of type double

    // Declaring Iterators:
    std::vector<int> myVector = { 1, 2, 3 };
    for (auto it = myVector.begin(); it != myVector.end(); ++it) {
        std::cout << *it << " ";
    }
}