#include <iostream>
#include <string_view>

/*
    `std::string_view` is a non-owning reference to a string introduced in C++17.
    It provides a lightweight, read-only view into a string, avoiding costly copies.
    
    Key Concepts:
    1. `std::string_view` does not manage memory and can refer to parts of strings.
    2. It is useful for performance-sensitive code that only needs to read a string.
    3. Avoid using `std::string_view` with temporary or short-lived objects, as it can result in dangling references.
    4. It works with both `std::string` and C-style strings.

    Benefits:
    - Faster than passing `std::string` if you don't need ownership.
    - No heap allocations are involved.
*/

// https://godbolt.org/z/svbTj3Mxd

// Example 1: Creating a string_view from a string literal
void printStringView(std::string_view sv) {
    std::cout << "String view: " << sv << "\n";  // Output: Hello, World!
}

int main() {
    // Creating a string_view from a string literal
    std::string_view sv1 = "Hello, World!";
    printStringView(sv1);

    // Example 2: Creating a string_view from std::string
    std::string str = "C++17 string_view";
    std::string_view sv2 = str;  // sv2 refers to the contents of str
    std::cout << "String view: " << sv2 << "\n";  // Output: C++17 string_view

    // Example 3: Substring view without copying
    std::string_view subView = sv2.substr(0, 4);  // Refers to "C++1"
    std::cout << "Substring view: " << subView << "\n";  // Output: C++1

    // Example 4: Working with C-style strings
    const char* cStr = "This is a C-string";
    std::string_view sv3(cStr, 4);  // Refers to the first 4 characters of cStr
    std::cout << "Partial view: " << sv3 << "\n";  // Output: This

    // Example 5: String_view does not own memory
    char tempStr[] = "Temporary string";
    std::string_view sv4(tempStr);  // Refers to tempStr
    std::cout << "Before modifying: " << sv4 << "\n";  // Output: Temporary string
    
    // Modifying the original string will reflect in string_view
    tempStr[0] = 'P';
    std::cout << "After modifying: " << sv4 << "\n";  // Output: Pemporary string

    return 0;
}
