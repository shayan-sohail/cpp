#include <iostream>
#include <vector>
#include <initializer_list>

/*
std::initializer_list enables you to pass a list of values to constructors or functions, providing a way to initialize
containers or custom classes with a simple {} syntax.
It simplifies the initialization of arrays, vectors, and other containers, and prevents issues like ambiguity in constructor overloads.*/

// https://godbolt.org/z/cf5bana3o 

class MyClass {
public:
    std::vector<int> data;

    // Constructor using initializer_list
    MyClass(std::initializer_list<int> values) : data(values) {}

    void print() const {
        for (int value : data) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    // Initializing a vector using initializer_list
    std::vector<int> vec = { 1, 2, 3, 4, 5 };

    // Initializing a custom class using initializer_list
    MyClass obj = { 10, 20, 30, 40, 50 };

    // Potential issue without initializer_list: Ambiguity in constructor overloads
    // Constructor overloads can be ambiguous with traditional initialization
    // MyClass obj2(10, 20); // Is this an initializer_list or two separate arguments?

    // Correct and clear initialization using initializer_list
    MyClass obj2 = { 10, 20 };

    // Output to verify results
    std::cout << "Vector elements: ";
    for (int n : vec) std::cout << n << " ";
    std::cout << std::endl;

    std::cout << "MyClass obj elements: ";
    obj.print();

    std::cout << "MyClass obj2 elements: ";
    obj2.print();

    return 0;
}
