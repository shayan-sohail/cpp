#include <iostream>
#include <vector>

/*
The decltype operator is used to determine the declared type of an expression.
It allows you to obtain the type of a variable, function, or expression at compile time, even if the type is complex or deduced.
decltype is a C++ language construct that determines the declared type of an expression at compile time.
It effectively replaces the placeholder decltype with the actual type of the expression, eliminating the need for manual type specification in certain contexts. This can lead to more concise and readable code, especially when dealing with complex types or template metaprogramming.
*/

// https://godbolt.org/z/z8Kboed69 

// Function Return Types:
auto get_value() -> decltype(10) {
    return 10;
}

decltype(10) get_valueX() {
    return 10;
}

// Expression Evaluation:
int x = 10;
const double& y = 5.5;

// Variable Declarations:
decltype(x) z = 20; // z is of type int
decltype(y) w = 10; // w is of type const double&

auto func() -> decltype(x + y) {
    return x + y;
}

// Template Metaprogramming:
template <typename T, typename U>
auto add(T a, U b) -> decltype(b) {
    return a + b;
}

int main()
{
    std::cout << func() << std::endl; //15.5
    std::cout << add(5, 3.14) << std::endl; // 8.14 as decltype(3.14) = double
}