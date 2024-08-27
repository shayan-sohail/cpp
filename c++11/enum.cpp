#include <iostream>

/*
Strong type enums (also known as "scoped enums") are declared using the enum class or enum struct keyword.
They provide better type safety and scoping compared to traditional C++ enums.
*/

// https://godbolt.org/z/s11YWP39P

// Traditional enum (weakly typed)
enum Color {
    Red,
    Green,
    Blue
};

// Strongly typed enum (scoped enum)
enum class TrafficLight {
    Red,
    Yellow,
    Green
};

// Strongly typed enum with a specified underlying type
enum class ErrorCode : int {
    Success = 0,
    Warning = 1,
    Error = 2
};

int main() {
    // Traditional enum usage
    Color color = Green;
    std::cout << "Color value: " << color << std::endl;  // Implicit conversion to int

    // Scoped enum usage (no implicit conversion to int)
    TrafficLight light = TrafficLight::Red;

    // This will cause a compile-time error due to lack of implicit conversion
    // int lightValue = light;

    // Correct way to get the underlying value
    int lightValue = static_cast<int>(light);
    std::cout << "TrafficLight Red value: " << lightValue << std::endl;

    // Comparison operations (allowed)
    if (light == TrafficLight::Red) {
        std::cout << "The light is red." << std::endl;
    }

    // Specifying underlying type
    ErrorCode code = ErrorCode::Error;

    // Checking the value explicitly
    if (code == ErrorCode::Error) {
        std::cout << "An error occurred!" << std::endl;
    }

    // Using the underlying type directly
    int codeValue = static_cast<int>(code);
    std::cout << "Error code value: " << codeValue << std::endl;

    return 0;
}
