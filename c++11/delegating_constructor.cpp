#include <iostream>
#include <string>

/*
Delegating constructors are useful when multiple constructors share common initialization logic. Instead of repeating the same code
in each constructor, one constructor can delegate part or all of its initialization tasks to another constructor.
This approach reduces redundancy, making the code easier to maintain and less error-prone.
*/

// https://godbolt.org/z/acKrxzEsn

class Person {
public:
    // Constructor with all parameters
    Person(const std::string& name, int age, const std::string& job)
        : name_(name), age_(age), job_(job) {
        std::cout << "Person initialized with name, age, and job." << std::endl;
    }

    // Constructor with name and age, delegates to the main constructor
    Person(const std::string& name, int age)
        : Person(name, age, "Unknown") {
        std::cout << "Person initialized with name and age." << std::endl;
    }

    // Constructor with only name, delegates to the name and age constructor
    Person(const std::string& name)
        : Person(name, 0) {
        std::cout << "Person initialized with name only." << std::endl;
    }

    void printInfo() const {
        std::cout << "Name: " << name_ << ", Age: " << age_ << ", Job: " << job_ << std::endl;
    }

private:
    std::string name_;
    int age_;
    std::string job_;
};

int main() {
    Person person1("Alice", 30, "Engineer");
    person1.printInfo();  // Full initialization

    Person person2("Bob", 25);  // Delegates to the main constructor with a default job
    person2.printInfo();

    Person person3("Charlie");  // Delegates to the second constructor with a default age and job
    person3.printInfo();

    return 0;
}
