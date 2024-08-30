#include <iostream>
#include <tuple>
#include <string>

/*
std::tuple: Stores multiple values of different types in a single object.
std::make_tuple: Creates a tuple without specifying types.
std::get<N>: Accesses the Nth element in the tuple.
std::tie: Unpacks a tuple into individual variables.
std::tuple_size: Determines the number of elements in a tuple.
std::tuple_cat: Concatenates multiple tuples into a single tuple.
*/

// https://godbolt.org/z/qKPKqTqnK

int main() {
    // Create a tuple using std::make_tuple
    auto person = std::make_tuple("John Doe", 30, 72.5);

    // Access elements using std::get<N>
    std::cout << "Name: " << std::get<0>(person) << std::endl;
    std::cout << "Age: " << std::get<1>(person) << std::endl;
    std::cout << "Weight: " << std::get<2>(person) << " kg" << std::endl;

    // Modify an element in the tuple
    std::get<1>(person) = 31;
    std::cout << "Updated Age: " << std::get<1>(person) << std::endl;

    // Unpack the tuple using std::tie
    std::string name;
    int age;
    double weight;
    std::tie(name, age, weight) = person;

    std::cout << "Unpacked Name: " << name << std::endl;
    std::cout << "Unpacked Age: " << age << std::endl;
    std::cout << "Unpacked Weight: " << weight << " kg" << std::endl;

    // Create another tuple
    auto address = std::make_tuple("123 Main St", "New York", "NY");

    // Concatenate tuples using std::tuple_cat
    auto person_info = std::tuple_cat(person, address);

    // Access elements from the concatenated tuple
    std::cout << "Full Info: " << std::get<0>(person_info) << ", "
        << std::get<1>(person_info) << " years old, "
        << std::get<2>(person_info) << " kg, lives at "
        << std::get<3>(person_info) << ", "
        << std::get<4>(person_info) << ", "
        << std::get<5>(person_info) << std::endl;

    return 0;
}
