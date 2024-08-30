#include <iostream>
#include <memory>

/*
std::weak_ptr is designed to work alongside std::shared_ptr to prevent circular references, which can cause memory leaks by preventing objects from being properly destroyed.
A weak_ptr does not increase the reference count of the shared_ptr it references, meaning it doesn’t keep the object alive.
It can be used to check if the object has been destroyed and can be converted to a shared_ptr to access the object safely.
*/

// https://godbolt.org/z/Whnv15d66

class MyClass {
public:
    MyClass() { std::cout << "MyClass constructed.\n"; }
    ~MyClass() { std::cout << "MyClass destructed.\n"; }
    void greet() const { std::cout << "Hello from MyClass!\n"; }
};

int main() {
    std::shared_ptr<MyClass> sharedPtr = std::make_shared<MyClass>();

    // 1. Creating a weak_ptr from a shared_ptr
    std::weak_ptr<MyClass> weakPtr = sharedPtr;

    // 2. Checking if the weak_ptr is still valid (object still exists)
    if (auto tempPtr = weakPtr.lock()) {
        tempPtr->greet();  // Accessing the object via a temporary shared_ptr
    }
    else {
        std::cout << "The object has been destroyed.\n";
    }

    // 3. Resetting the shared_ptr, causing the object to be destroyed
    std::cout << sharedPtr.use_count() << std::endl;
    sharedPtr.reset();
    std::cout << sharedPtr.use_count() << std::endl;

    // 4. Checking weak_ptr again after the object is destroyed
    if (auto tempPtr = weakPtr.lock()) {
        tempPtr->greet();
    }
    else {
        std::cout << "The object has been destroyed.\n";
    }

    return 0;
}
