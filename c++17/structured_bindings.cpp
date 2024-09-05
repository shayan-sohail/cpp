#include <iostream>
#include <tuple>
#include <array>

/*
Structured bindings enable developers to easily decompose and unpack tuples, structs, and arrays into individual named variables. This 
feature enhances code readability and simplifies working with multi-element objects by directly assigning their members to separate 
variables, rather than accessing them with indices or getters. Structured bindings make handling complex return types or composite 
data structures more intuitive and cleaner.
*/

// https://godbolt.org/z/GPfEzzcoY

int main() {
    // Example 1: Structured bindings with tuples
    std::tuple<int, double, std::string> myTuple(1, 2.5, "Hello");

    // Unpacking tuple into individual variables
    auto [intVal, doubleVal, strVal] = myTuple;

    // Output values of the unpacked variables
    std::cout << "Integer: " << intVal << "\n";
    std::cout << "Double: " << doubleVal << "\n";
    std::cout << "String: " << strVal << "\n";

    // Example 2: Structured bindings with arrays
    std::array<int, 3> myArray = {10, 20, 30};

    // Unpacking array into individual variables
    auto [a, b, c] = myArray;

    // Output values of the unpacked variables
    std::cout << "Array elements: " << a << ", " << b << ", " << c << "\n";

    // Example 3: Structured bindings with struct
    struct Person {
        std::string name;
        int age;
    };

    Person person = {"Alice", 30};

    // Unpacking struct into individual variables
    auto [personName, personAge] = person;

    // Output values of the unpacked struct members
    std::cout << "Name: " << personName << ", Age: " << personAge << "\n";

    return 0;
}
