#include <iostream>
#include <type_traits>
#include <cstddef>

/*
nullptr is a special value that represents the null pointer.
It is distinct from the integer value 0 and the macro NULL, which are used in older C code.
nullptr is designed to be more type-safe and expressive when working with pointers.
*/
// https://godbolt.org/z/d4T5Y4v7M

void process_data(int* data) {
    if (data != nullptr) {
        std::cout << "Processing data: " << *data << std::endl;
    }
    else {
        std::cout << "Data is null" << std::endl;
    }
}

template <typename T>
void process_pointer(T* ptr) {
    if (ptr != nullptr) {
        std::cout << "Processing pointer: " << *ptr << std::endl;
    }
    else {
        std::cout << "Pointer is null" << std::endl;
    }
}


int* find_element(int value) {
    auto element_not_found = true;
    // ... (implementation of find_element)
    if (element_not_found) {
        return nullptr;
    }
    return new int();
}

// 10. Function overloading
void process_data(std::nullptr_t) {
    std::cout << "Processing null data" << std::endl;
}

int main() {
    // 1. Initializing pointers
    int* ptr = nullptr;

    // 2. Checking for null pointers
    if (ptr != nullptr) {
        std::cout << "Pointer is not null" << std::endl;
    }
    else {
        std::cout << "Pointer is null" << std::endl;
    }

    // 3. Function arguments
    process_data(ptr);
    process_data(nullptr);


    // 4. Template arguments
    process_pointer<int>(ptr);
    process_pointer<int>(nullptr);


    // 5. Function return values
    int* result = find_element(5);
    if (result != nullptr) {
        std::cout << "Found element: " << *result << std::endl;
    }
    else {
        std::cout << "Element not found" << std::endl;
    }

    // 6. Null pointer constants
    constexpr int* null_int_ptr = nullptr;
    constexpr double* null_double_ptr = nullptr;

    // 7. Null pointer comparisons
    if (ptr == null_int_ptr) {
        std::cout << "ptr is null" << std::endl;
    }

    std::nullptr_t null_ptr = nullptr;

    // 8. Check if a type is std::nullptr_t
    if constexpr (std::is_same_v<std::nullptr_t, decltype(null_ptr)>) {
        std::cout << "null_ptr is a std::nullptr_t" << std::endl;
    }
    else {
        std::cout << "null_ptr is not a std::nullptr_t" << std::endl;
    }

    return 0;
}