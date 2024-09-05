#include <iostream>

/*
C++17 introduced the ability to define nested namespaces in a more concise way. 
Instead of opening and closing each namespace separately, you can define them 
in a single line using the `::` syntax. This improves code readability and simplifies
the declaration of deeply nested namespaces.
*/

// https://godbolt.org/z/c9nTWT8EW

// Traditional way (before C++17):
namespace outer {
    namespace inner {
        void greet() {
            std::cout << "Hello from traditional nested namespaces!\n";
        }
    }
}

// New C++17 way: Using :: syntax for nested namespaces
namespace outer::inner2 {
    void greet() {
        std::cout << "Hello from C++17 nested namespaces!\n";
    }
}

int main() {
    // Calling the traditional nested namespace function
    outer::inner::greet();

    // Calling the C++17 nested namespace function
    outer::inner2::greet();

    return 0;
}
