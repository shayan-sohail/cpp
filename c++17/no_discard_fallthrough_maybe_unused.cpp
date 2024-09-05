#include <iostream>

/*
    [[nodiscard]], [[fallthrough]], and [[maybe_unused]] are attributes introduced in C++17 to give compilers additional information 
    about the intent of the programmer, thus enhancing code safety and clarity.

    1. [[nodiscard]]: Marks the return value of a function as important, warning the user if it's ignored.
    2. [[fallthrough]]: Used in switch statements to indicate intentional fallthrough between case labels.
    3. [[maybe_unused]]: Used to avoid warnings about unused variables or parameters.
*/

// https://godbolt.org/z/nsGP74G1P

// Example 1: [[nodiscard]]
// This function returns a status code that should not be ignored
[[nodiscard]] int getStatus() {
    return 1; // Return a status
}

// Example 2: [[fallthrough]]
void processValue(int value) {
    switch (value) {
        case 1:
            std::cout << "Processing value 1\n";
            [[fallthrough]]; // Intentional fallthrough to case 2
        case 2:
            std::cout << "Processing value 2\n";
            break;
        default:
            std::cout << "Default processing\n";
            break;
    }
}

// Example 3: [[maybe_unused]]
void processUnused([[maybe_unused]] int unusedParam) {
    // Function logic doesn't use the parameter, but no warning will be issued.
    std::cout << "This function doesn't use the parameter, but it's okay.\n";
}

int main() {
    // [[nodiscard]] example:
    // Warning if the return value is ignored
    [[maybe_unused]] int status = getStatus(); // Use it to avoid warnings
    // Uncommenting the next line will give a warning for discarding the nodiscard return value.
    // getStatus(); // This would raise a warning

    // [[fallthrough]] example:
    processValue(1); // Intentional fallthrough from case 1 to case 2

    // [[maybe_unused]] example:
    processUnused(42); // No warning for unused parameter

    return 0;
}
