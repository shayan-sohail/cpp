#include <iostream>
#include <vector>
#include <utility>

/*
    C++17 introduced the ability for class templates to automatically deduce their template parameters 
    based on the arguments passed to their constructors. This feature is similar to how function templates 
    can deduce template arguments from the types of their parameters.
    
    With CTAD, you no longer need to specify template parameters explicitly for certain cases, making the code 
    cleaner and easier to maintain.
*/

// https://godbolt.org/z/MYcMKPf7d

// Example 1: Without CTAD (C++11/14 style)
template <typename T>
class Box {
public:
    T value;
    Box(T val) : value(val) {}
};

int main() {
    // C++11/14: Must specify the template argument explicitly
    Box<int> box1(42);
    std::cout << "Box1 value: " << box1.value << "\n";

    // Example 2: With CTAD (C++17 style)
    // Compiler deduces that T is `int` based on constructor argument
    Box box2(100); // Template argument deduced
    std::cout << "Box2 value: " << box2.value << "\n";

    // Example 3: CTAD with std::pair
    std::pair pair1(1, 2.5); // Automatically deduces std::pair<int, double>
    std::cout << "Pair: (" << pair1.first << ", " << pair1.second << ")\n";

    // Example 4: CTAD with std::vector
    std::vector vec = {1, 2, 3, 4, 5}; // Automatically deduces std::vector<int>
    std::cout << "Vector size: " << vec.size() << "\n";

    return 0;
}
