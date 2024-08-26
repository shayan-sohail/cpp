#include <iostream>

/*
In C++11, conversion operators can be marked with the explicit keyword to prevent them from being used implicitly.
This is particularly useful when a conversion might lead to unexpected behavior if automatically applied. By marking a conversion operator as explicit,
the programmer ensures that the conversion must be invoked explicitly in the code, thereby avoiding accidental type conversions that could
lead to bugs or undefined behavior.
*/

// https://godbolt.org/z/Gd3x95jsx

class Integer {
public:
    Integer(int value) : value_(value) {}

    // Explicit conversion operator to double
    explicit operator double() const {
        return static_cast<double>(value_);
    }

    // Implicit conversion operator to bool
    operator bool() const {
        return value_ != 0;
    }

private:
    int value_;
};

int main() {
    Integer num(10);

    //Implicit Conversion to bool
    bool x = num;

    // Explicit conversion to double
    double d = static_cast<double>(num); // Must use static_cast or explicit call
    std::cout << "Double value: " << d << std::endl;

    // This would be a compile-time error without explicit conversion:
    // double d2 = num;

    return 0;
}

