#include <iostream>
#include <type_traits>

/*
    In C++17, exception specifications like `noexcept` are part of the type system, 
    which affects function overloading and type deduction. However, you cannot 
    overload functions based solely on the presence or absence of `noexcept`.

    This feature is mainly useful for distinguishing between callable objects 
    that may or may not throw exceptions, improving optimization and error 
    handling.

    We'll demonstrate how `noexcept` becomes part of the type system using 
    type traits to check the function type.
*/

// https://godbolt.org/z/TjejssrhE

// Example function without noexcept
void fooNoexcept() noexcept {
    std::cout << "Function with noexcept\n";
}

// Example function without noexcept
void foo() {
    std::cout << "Function without noexcept\n";
}

int main() {
    // Check if foo() and fooNoexcept() have the same type
    // Adding noexcept changes the function signature so it will return no
    bool are_same = std::is_same<decltype(foo), decltype(fooNoexcept)>::value;

    // Output whether the two functions have the same type
    std::cout << "Are the two functions of the same type? "
              << (are_same ? "Yes" : "No") << "\n";

    // Calling the functions
    foo();
    fooNoexcept();

    return 0;
}
