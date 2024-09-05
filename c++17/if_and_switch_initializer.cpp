#include <iostream>

/*
In C++17, both 'if' and 'switch' statements allow initialization of variables
directly within the condition. This enhances readability and keeps the scope of
the initialized variables limited to the block of the 'if' or 'switch' statement.
*/

// https://godbolt.org/z/4G6xdPa74

// Example 1: 'if' with initializer
void checkNumber(int num) {
    if (int squared = num * num; squared > 100) {
        std::cout << "The square of " << num << " is greater than 100: " << squared << "\n";
    } else {
        std::cout << "The square of " << num << " is " << squared << "\n";
    }
}

// Example 2: 'switch' with initializer
void checkGrade(int score) {
    switch (char grade = (score > 90 ? 'A' : (score > 80 ? 'B' : (score > 70 ? 'C' : 'D'))); grade) {
        case 'A':
            std::cout << "Excellent! Grade: " << grade << "\n";
            break;
        case 'B':
            std::cout << "Good job! Grade: " << grade << "\n";
            break;
        case 'C':
            std::cout << "Fair. Grade: " << grade << "\n";
            break;
        default:
            std::cout << "Needs improvement. Grade: " << grade << "\n";
    }
}

int main() {
    // Using 'if' with initializer
    checkNumber(11);  // Output: The square of 11 is greater than 100: 121
    checkNumber(5);   // Output: The square of 5 is 25

    // Using 'switch' with initializer
    checkGrade(95);  // Output: Excellent! Grade: A
    checkGrade(85);  // Output: Good job! Grade: B
    checkGrade(65);  // Output: Needs improvement. Grade: D

    return 0;
}
