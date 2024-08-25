#include <iostream>

/*
= default to instruct the compiler to generate a default implementation for special member functions (like constructors, destructors, or copy operators), and = delete to prevent the compiler from generating or using them. This gives you more control over the behavior of your classes, ensuring that only the functions you intend to be available are used, preventing accidental copies or moves.
*/

// https://godbolt.org/z/Go1qxsYq6

class MyClass {
public:
    MyClass() = default; // Default constructor explicitly defaulted

    MyClass(int val) : value(val) {}

    // Copy constructor is deleted, preventing copying
    MyClass(const MyClass&) = delete;

    // Move constructor is defaulted, allowing move operations
    MyClass(MyClass&&) = default;

    // Copy assignment operator is deleted
    MyClass& operator=(const MyClass&) = delete;

    // Move assignment operator is defaulted
    MyClass& operator=(MyClass&&) = default;

    void display() const {
        std::cout << "Value: " << value << std::endl;
    }

private:
    int value = 0;
};

int main() {
    MyClass obj1(10);
    obj1.display();

    // Attempt to copy obj1 (will result in a compile-time error)
    // MyClass obj2 = obj1; // Error: Copy constructor is deleted

    // Move obj1 to obj3 (allowed since move constructor is defaulted)
    MyClass obj3 = std::move(obj1);
    obj3.display();

    // Attempt to copy assign obj3 to another object (will result in a compile-time error)
    // obj3 = obj1; // Error: Copy assignment operator is deleted

    return 0;
}
