#include <iostream>
#include <type_traits>

/*
Trailing return type is useful when the return type depends on the function's parameters or when using auto to simplify the syntax. It also enables cleaner syntax when working with complex return types, especially in template programming or when the return type is lengthy or involves type deduction.
*/

// https://godbolt.org/z/bK7cd9rM9

// Function with trailing return type
auto add(int a, int b) -> int {
    return a + b;
}

// Function where return type depends on template parameter
template<typename T1, typename T2>
auto multiply(T1 a, T2 b) -> decltype(a* b) {
    return a * b;
}

// Function returning a lambda using trailing return type
auto getLambda() -> auto(*)(int, int) -> int {
    return [](int x, int y) {
        return x + y;
        };
}

// Function returning a lambda using trailing return type
auto getLambda1() -> int(*)(int, int) {
    return [](int x, int y) {
        return x + y;
        };
}

// Function returning a lambda using trailing return type
auto getLambda2() -> auto(*)(int, int) -> decltype(add(5, 3)) {
    return [](int x, int y) {
        return x + y;
        };
}

int main() {
    std::cout << "Add 3 and 4: " << add(3, 4) << std::endl;

    std::cout << "Multiply 2.5 and 4: " << multiply(2.5, 4) << std::endl;

    // Using lambda returned by function
    auto lambda = getLambda2();
    std::cout << "Lambda result: " << lambda(5, 7) << std::endl;

    return 0;
}
