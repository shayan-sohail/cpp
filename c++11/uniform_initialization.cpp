#include <iostream>
#include <vector>

/*
Uniform initialization ensures that variables are initialized consistently using {}, helping to avoid common pitfalls such as
accidental narrowing conversions (where data is lost when converting from one type to another) and confusing function
declarations with variable initializations, known as the most vexing parse e.g MyClass obj1(10, 20); & MyClass obj2{10, 20};.
*/
// A function that might look like an initialization (most vexing parse)
class MyClass {
public:
    int x, y;
    MyClass(int a, int b) : x(a), y(b) {}
};

// https://godbolt.org/z/d84n6sxTT 

int main() {
    // Narrowing conversion issue (without uniform initialization)
    double pi = 3.14;
    int truncatedPi = pi; // This is allowed, but data loss occurs

    // Prevent narrowing conversion (with uniform initialization)
    // int safePi{pi}; // Uncommenting this line will cause a compile-time error

    // Most vexing parse issue (without uniform initialization)
    MyClass obj1(1, 2);  // Is this a variable declaration or a function declaration?

    // Correct initialization (with uniform initialization)
    MyClass obj2{ 1, 2 };  // Clearly an object, not a function declaration

    // Initialization of a vector using uniform initialization
    std::vector<int> vec{ 1, 2, 3, 4, 5 };

    // Output to verify results
    std::cout << "Truncated Pi: " << truncatedPi << std::endl;
    std::cout << "Object obj2 values: x = " << obj2.x << ", y = " << obj2.y << std::endl;
    std::cout << "Vector elements: ";
    for (int n : vec) std::cout << n << " ";
    std::cout << std::endl;

    return 0;
}
