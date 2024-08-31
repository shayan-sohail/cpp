#include <iostream>

/*
The [[deprecated]] attribute in C++14 allows developers to mark certain functions, classes, or other program elements as deprecated, signaling that they
should be avoided in future code. When a deprecated entity is used, the compiler generates a warning, helping developers gradually phase out old or obsolete
code without breaking existing functionality. This feature is particularly useful for maintaining backward compatibility while encouraging the adoption of
newer, preferred alternatives.
*/

// https://godbolt.org/z/9K4M9fGr8

// Marking a function as deprecated
[[deprecated("Use the newFunction() instead.")]]
void oldFunction() {
    std::cout << "This is the old function." << std::endl;
}

// Marking a class as deprecated
class [[deprecated("Use the NewClass instead.")]] OldClass {
public:
    void display() const {
        std::cout << "This is the OldClass." << std::endl;
    }
};

// Recommended replacement function
void newFunction() {
    std::cout << "This is the new function." << std::endl;
}

// New class that replaces OldClass
class NewClass {
public:
    void display() const {
        std::cout << "This is the NewClass." << std::endl;
    }
};

int main() {
    // Using the deprecated function
    // warning: 'void oldFunction()' is deprecated: Use the newFunction() instead. [-Wdeprecated-declarations]
    oldFunction(); // Compiler will generate a warning here

    // Using the deprecated class
    OldClass oldObj;
    oldObj.display(); // Compiler will generate a warning here

    // Using the new, recommended alternatives
    newFunction(); // No warnings
    NewClass newObj;
    newObj.display(); // No warnings

    return 0;
}
