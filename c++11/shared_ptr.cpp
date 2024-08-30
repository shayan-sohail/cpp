#include <iostream>
#include <memory>
#include <vector>

/*
std::shared_ptr allows multiple shared_ptr instances to own the same object, keeping a reference count to ensure the object is destroyed when the
last shared_ptr goes out of scope.
It provides a safer and easier way to handle shared ownership compared to raw pointers, especially in complex data structures or multi-threaded environments.
shared_ptr supports custom deleters, weak references (using std::weak_ptr), and can be used with arrays or other resources that require shared management.
*/

// https://godbolt.org/z/rEMf44EG6

class MyClass {
public:
    MyClass() { std::cout << "MyClass constructed.\n"; }
    ~MyClass() { std::cout << "MyClass destructed.\n"; }
    void greet() const { std::cout << "Hello from MyClass!\n"; }
};

int main() {
    // 1. Basic Usage of shared_ptr
    std::shared_ptr<MyClass> ptr1(new MyClass());

    // Using make_shared (preferred way)
    auto ptr2 = std::make_shared<MyClass>();

    // 2. Shared Ownership
    std::shared_ptr<MyClass> ptr3 = ptr2; // ptr2 and ptr3 share ownership of the same object
    std::cout << "Shared count: " << ptr2.use_count() << std::endl;

    // 3. Resetting a shared_ptr
    ptr2.reset(); // ptr2 no longer owns the object
    std::cout << "Shared count after reset: " << ptr3.use_count() << std::endl;

    // 4. Transferring Ownership to a Container
    std::vector<std::shared_ptr<MyClass>> vec;
    vec.push_back(ptr3); // vec now shares ownership
    std::cout << "Shared count after pushing to vector: " << ptr3.use_count() << std::endl;

    // 5. Returning shared_ptr from a function
    auto createMyClass = []() -> std::shared_ptr<MyClass> {
        return std::make_shared<MyClass>();
        };

    std::shared_ptr<MyClass> ptr4 = createMyClass();
    ptr4->greet();

    // 6. Custom Deleter
    auto customDeleter = [](MyClass* ptr) {
        std::cout << "Custom deleter called.\n";
        delete ptr;
        };
    std::shared_ptr<MyClass> ptr5(new MyClass(), customDeleter);

    // 7. weak_ptr Usage
    std::weak_ptr<MyClass> weakPtr = ptr3;
    if (auto sharedPtr = weakPtr.lock()) { // Check if the object still exists
        sharedPtr->greet();
    }

    return 0;
}
