#include <iostream>
#include <vector>

/*
decltype(auto) combines the functionality of auto and decltype, offering more flexible type deduction by preserving references and qualifiers,
making it ideal for functions returning references, const objects, or when precise type preservation is necessary.
*/

// https://godbolt.org/z/3dKxnc6TG

int& getElement(std::vector<int>& vec, std::size_t index) {
    return vec[index]; // Return a reference to the element at the given index
}

decltype(auto) getElementWithDecltypeAuto(std::vector<int>& vec, std::size_t index) {
    // decltype(auto) deduces the return type as int& (reference) since getElement returns int&
    return getElement(vec, index);
}

decltype(auto) sum(int a, int b) {
    // decltype(auto) deduces the return type as int (value type) since the expression a + b results in an int
    return a + b;
}

int main() {
    std::vector<int> numbers = { 1, 2, 3, 4, 5 };

    // refElement is deduced as int& because decltype(auto) preserves the reference returned by getElementWithDecltypeAuto
    decltype(auto) refElement = getElementWithDecltypeAuto(numbers, 2);
    refElement = 10; // Modifies the original vector since refElement is a reference

    std::cout << "Modified element: " << numbers[2] << std::endl; // Output: 10

    // result is deduced as int because decltype(auto) deduces the return type based on the expression a + b
    decltype(auto) result = sum(3, 4);
    std::cout << "Sum: " << result << std::endl; // Output: 7

    return 0;
}
