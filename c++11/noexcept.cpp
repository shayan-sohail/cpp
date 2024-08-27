#include <iostream>

/*
The noexcept keyword is used to indicate that a function does not throw any exceptions. Declaring a function as noexcept allows the compiler
to perform certain optimizations, such as avoiding the overhead associated with exception handling. Additionally, it provides stronger
guarantees about the function's behavior, which can be particularly important in contexts like move constructors, where exception safety
is critical.
*/

// https://godbolt.org/z/118Y97eWd

void mayThrow() {
    throw std::runtime_error("This function may throw");
}

void noThrow() noexcept {
    std::cout << "This function is guaranteed not to throw." << std::endl;
}

int main() {
    // Example of noexcept function
    try {
        noThrow();
        // mayThrow(); // Uncommenting this line will cause a runtime exception
    }
    catch (...) {
        std::cout << "Caught an exception." << std::endl;
    }

    // noexcept is evaluated at compile time
    std::cout << "Is noThrow noexcept? " << noexcept(noThrow()) << std::endl;
    std::cout << "Is mayThrow noexcept? " << noexcept(mayThrow()) << std::endl;

    return 0;
}
