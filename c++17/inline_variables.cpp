#include <iostream>

/*
The inline keyword was extended to variables, which means that an inline variable can be defined in multiple translation units without violating the One Definition Rule (ODR). Inline variables are especially useful for constants that need to be shared across multiple files. They ensure that the variable is treated as if it has a single definition, even though it might appear in multiple source files. This feature allows variables to be used in header files without causing linker errors.
*/

// https://godbolt.org/z/cdY6Tv3Ej

// Example 1: Defining an inline variable in a header-like scenario
inline constexpr int myInlineVariable = 42; // Inline variable can be used in multiple translation units

// Example 2: Using inline variable as a constant expression
class MyClass {
public:
    static inline int counter = 0; // Static inline variable
    void increment() {
        ++counter; // Modify the inline variable
    }
};

int main() {
    // Access and print inline variable
    std::cout << "Inline constant variable: " << myInlineVariable << "\n";

    // Working with inline static variable in a class
    MyClass obj1, obj2;
    obj1.increment();
    obj2.increment();
    
    // Both objects share the same static inline counter
    std::cout << "Counter value after increments: " << MyClass::counter << "\n";

    return 0;
}
