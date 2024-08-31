#include <iostream>
#include <string>

/*
C++14 introduced aggregate member initialization, which permits direct initialization of members of an aggregate (e.g., structs, arrays, and classes with
public data members and no constructors) within an initializer list. This feature simplifies the initialization process by allowing all members of an
aggregate to be initialized directly in one statement, leading to more concise and readable code. Aggregate member initialization also reduces the risk
of uninitialized members by providing a clear and explicit way to set values during object creation.
*/

// https://godbolt.org/z/fvf81q7d7

// Define a simple struct as an aggregate
struct Person {
    std::string name;
    int age;
    double height;
    bool isEmployed;
};

int main() {
    // Using aggregate member initialization
    Person person1 = { "Alice", 30, 5.7, true }; // All members are initialized directly

    // Partial initialization (rest members will be default-initialized)
    Person person2 = { "Bob", 25 }; // Providing default values manually

    // Access and print the members
    std::cout << "Person 1: " << person1.name << ", " << person1.age << " years old, "
        << person1.height << " feet tall, Employed: " << std::boolalpha << person1.isEmployed << std::endl;

    std::cout << "Person 2: " << person2.name << ", " << person2.age << " years old, "
        << person2.height << " feet tall, Employed: " << std::boolalpha << person2.isEmployed << std::endl;

    return 0;
}

