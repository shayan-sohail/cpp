#include <iostream>
#include <vector>

/*
Rvalue references, denoted by &&, are a type of reference that can bind to rvalues (temporary objects).
They enable move semantics, allowing resources to be transferred from one object to another without copying, which improves performance, especially in resource-intensive applications.
Lvalues refer to objects with a persistent state (e.g., variables), while rvalues refer to temporary objects or expressions
that do not have a persistent state (e.g., the result of a function or a literal).
*/

// https://godbolt.org/z/qzzaE9sTh

class Resource {
public:
    Resource() {
        data = new int[100]; // Allocate some resources
        std::cout << "Resource acquired!" << std::endl;
    }

    ~Resource() {
        delete[] data; // Clean up the resources
        std::cout << "Resource destroyed!" << std::endl;
    }

    // Copy constructor (called when copying an object)
    Resource(const Resource& other) {
        data = new int[100];
        std::copy(other.data, other.data + 100, data);
        std::cout << "Resource copied!" << std::endl;
    }

    // Move constructor (called when moving an object)
    Resource(Resource&& other) noexcept {
        data = other.data;  // Transfer ownership of resources
        other.data = nullptr; // Nullify the source object's pointer
        std::cout << "Resource moved!" << std::endl;
    }

    // Copy assignment operator
    Resource& operator=(const Resource& other) {
        if (this != &other) {
            delete[] data; // Clean up existing resources
            data = new int[100];
            std::copy(other.data, other.data + 100, data);
            std::cout << "Resource copied via assignment!" << std::endl;
        }
        return *this;
    }

    // Move assignment operator
    Resource& operator=(Resource&& other) noexcept {
        if (this != &other) {
            delete[] data; // Clean up existing resources
            data = other.data; // Transfer ownership
            other.data = nullptr; // Nullify the source object's pointer
            std::cout << "Resource moved via assignment!" << std::endl;
        }
        return *this;
    }

private:
    int* data;
};

int main() {
    Resource res1;              // Resource acquired
    Resource res2 = res1;       // Copy constructor is called, resource copied
    Resource res3 = std::move(res1); // Move constructor is called, resource moved

    res2 = res3;                // Copy assignment operator, resource copied via assignment
    res3 = std::move(res2);     // Move assignment operator, resource moved via assignment

    std::vector<Resource> vec;
    vec.push_back(Resource());  // Move constructor is called, resource moved

    return 0;
}
