#include <iostream>
#include <initializer_list>

/*
    C++17 improves `auto` type deduction when working with braced-init-lists. 
    Prior to C++17, when using `auto` with a braced-init-list, the compiler would 
    deduce the type as `std::initializer_list<T>`. With C++17, `auto` can deduce 
    more accurate types depending on the context, avoiding unnecessary conversion to 
    `std::initializer_list<T>`.

    This enhancement allows `auto` to be more flexible and intuitive when handling 
    initializer lists.
*/

// https://godbolt.org/z/oTT5avccf

int main() {
    // Example 1: Pre-C++17 behavior
    auto x1 = {1, 2, 3}; // Deduces as std::initializer_list<int>
    std::cout << "Type of x1 (std::initializer_list): " << *x1.begin() << "\n";

    // Example 2: Improved C++17 behavior
    auto x2 = {1}; // Deduces as `std::initializer_list<int>` instead of `int`
    std::cout << "Type of x2 (initializer list with one element): " << *x2.begin() << "\n";

    // Example 3: Deducing as an int using parentheses
    auto y = (1); // Deduces as `int`
    std::cout << "Type of y (int): " << y << "\n";

    // Example 4: Deduction with a braced-init-list for direct initialization
    auto z = {2, 4, 6}; // Deduces as `std::initializer_list<int>`
    std::cout << "Type of z (initializer list): " << *z.begin() << "\n";

    return 0;
}
