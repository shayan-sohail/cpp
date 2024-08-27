#include <type_traits>

/*
static_assert is a compile-time assertion mechanism that checks a given condition during compilation. If the condition is false, the compilation fails with a specified error message. This feature is particularly useful for enforcing type constraints, verifying constants, and ensuring that certain assumptions hold true before the code is allowed to compile. It helps catch errors early in the development process, before runtime.
*/

// https://godbolt.org/z/E8s35TYzn

template<typename T>
class DataContainer {
    static_assert(std::is_integral<T>::value, "DataContainer requires an integral type.");

public:
    DataContainer(T value) : data_(value) {}

    T getData() const { return data_; }

private:
    T data_;
};

int main() {
    DataContainer<int> intContainer(42); // Compiles successfully
    // DataContainer<double> doubleContainer(3.14); // Compilation fails: static assertion failed

    return 0;
}
