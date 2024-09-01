#include <iostream>
#include <memory>
#include <vector>

/*
The std::make_unique function in C++14 simplifies the creation of std::unique_ptr instances. It provides a safer alternative to using new directly by
ensuring that the memory is correctly allocated and managed, preventing potential memory leaks and enhancing exception safety. This function constructs an
object and returns a std::unique_ptr to it, making the code more concise and less error-prone. Additionally, it eliminates the need to specify the
type explicitly when creating the smart pointer, as it is deduced automatically from the arguments passed to std::make_unique.
*/

// https://godbolt.org/z/KMT1cG81b

class MyClass {
public:
    int value;
    MyClass(int v) : value(v) {
        std::cout << "MyClass constructed with value: " << value << std::endl;
    }
    ~MyClass() {
        std::cout << "MyClass with value " << value << " is being destroyed." << std::endl;
    }
    void display() const {
        std::cout << "Value: " << value << std::endl;
    }
};

int main() {
    // Creating a unique_ptr using std::make_unique
    std::unique_ptr<MyClass> ptr1 = std::make_unique<MyClass>(10);
    ptr1->display(); // Output: Value: 10

    // Example of std::make_unique with an array
    auto arrPtr = std::make_unique<int[]>(5); // Creates an array of 5 integers
    for (int i = 0; i < 5; ++i) {
        arrPtr[i] = i * 2;
        std::cout << "arrPtr[" << i << "] = " << arrPtr[i] << std::endl; // Outputs: 0, 2, 4, 6, 8
    }

    // Using std::make_unique in a container
    std::vector<std::unique_ptr<MyClass>> vec;
    vec.push_back(std::make_unique<MyClass>(20));
    vec.push_back(std::make_unique<MyClass>(30));

    for (const auto& item : vec) {
        item->display(); // Outputs: Value: 20, Value: 30
    }

    return 0; // All unique_ptrs automatically release their memory here
}
