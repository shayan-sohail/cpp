#include <iostream>
#include <memory>
#include <vector>

/*
std::unique_ptr is a part of the C++ Standard Library and provides automatic memory management for dynamic objects.
It ensures that only one unique_ptr owns a given object at any time, preventing issues like double deletion.
unique_ptr cannot be copied but can be moved, allowing transfer of ownership to another unique_ptr.
It is a safer and more efficient alternative to raw pointers, especially in modern C++.
*/

class MyClass {
public:
    MyClass() { std::cout << "MyClass constructed.\n"; }
    ~MyClass() { std::cout << "MyClass destructed.\n"; }
    void greet() const { std::cout << "Hello from MyClass!\n"; }
};

// https://godbolt.org/z/4YW4G9xh3

int main() {
    // 1. Creating a unique_ptr
    std::unique_ptr<MyClass> ptr1(new MyClass());

    // Using make_unique (preferred way in C++14 and later)
    auto ptr2 = std::make_unique<MyClass>();

    // 2. Accessing the object through unique_ptr
    ptr1->greet();
    ptr2->greet();

    // 3. Transferring ownership with std::move
    std::unique_ptr<MyClass> ptr3 = std::move(ptr1);
    if (!ptr1) {
        std::cout << "ptr1 is now empty after move.\n";
    }
    ptr3->greet();

    // 4. Storing unique_ptr in a container
    std::vector<std::unique_ptr<MyClass>> vec;
    vec.push_back(std::make_unique<MyClass>());
    vec.push_back(std::make_unique<MyClass>());

    // 5. Returning a unique_ptr from a function
    auto createMyClass = []() -> std::unique_ptr<MyClass> {
        return std::make_unique<MyClass>();
        };

    std::unique_ptr<MyClass> ptr4 = createMyClass();
    ptr4->greet();

    // 6. Custom deleter
    auto customDeleter = [](MyClass* ptr) {
        std::cout << "Custom deleter called.\n";
        delete ptr;
        };
    std::unique_ptr<MyClass, decltype(customDeleter)> ptr5(new MyClass(), customDeleter);

    return 0;
}
