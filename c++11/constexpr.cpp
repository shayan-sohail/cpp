#include <iostream>

/*
The constexpr keyword indicates that a function or variable can be evaluated at compile time, which can lead to optimizations and guarantees that certain computations are known at compile time. For functions, all the code within the function must also be capable of compile-time evaluation. For variables, constexpr ensures they are immutable and known at compile time.
*/

// https://godbolt.org/z/K83q8xhWh

constexpr int square(int x) {
    return x * x;
}

class Circle {
public:
    constexpr Circle(double r) : radius(r) {}

    constexpr double area() const {
        return 3.141592653589793238 * radius * radius;
    }

private:
    double radius;
};

int main() {
    // constexpr variable
    constexpr int side = 5;
    constexpr int area = square(side);

    std::cout << "Area of square: " << area << std::endl;

    // constexpr object
    constexpr Circle c(10.0);
    constexpr double circleArea = c.area();

    std::cout << "Area of circle: " << circleArea << std::endl;

    // Potential issue without constexpr: Missing compile-time optimizations
    int runtime_value = 6;
    // int runtime_square = square(runtime_value); // Allowed but won't be constexpr since runtime_value is not constexpr

    return 0;
}
