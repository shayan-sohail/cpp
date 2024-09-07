#include <iostream>
#include <functional> // For std::invoke

/*
    `std::invoke` is a utility that allows you to call any callable object (like a function, a lambda,
    a member function, or a functor) in a uniform way. It simplifies the process of invoking these 
    callable objects, particularly when dealing with member function pointers or member data pointers.

    Key Features:
    - Can invoke regular functions, member functions, and callable objects (like lambdas).
    - Works with member pointers, making it easier to call member functions on objects.
*/

// https://godbolt.org/z/z9sf5WTd7

class MyClass {
public:
    void memberFunction(int x) {
        std::cout << "Member function called with value: " << x << '\n';
    }
};

void freeFunction(int x) {
    std::cout << "Free function called with value: " << x << '\n';
}

int main() {
    MyClass obj;

    // Example 1: Invoking a free function
    std::invoke(freeFunction, 42); // Calls freeFunction(42)

    // Example 2: Invoking a member function
    std::invoke(&MyClass::memberFunction, obj, 100); // Calls obj.memberFunction(100)

    // Example 3: Invoking a lambda
    auto lambda = [](int x) {
        std::cout << "Lambda called with value: " << x << '\n';
    };
    std::invoke(lambda, 5); // Calls lambda(5)

    return 0;
}
