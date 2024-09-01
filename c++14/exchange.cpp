#include <iostream>
#include <utility> // std::exchange

/*
Introduced in C++14, std::exchange is a utility function that atomically swaps the value of a variable with a new value, returning the old value. This
function is particularly useful in situations where you need to update a variable's value while preserving its previous state, such as in resource
management, state transitions, or implementing move semantics. std::exchange simplifies these operations by providing a concise and clear way to perform
the exchange, reducing the likelihood of errors compared to manually swapping values.
*/

// https://godbolt.org/z/axT5WPK91

class Resource {
public:
    Resource(int id) : id_(id) {
        std::cout << "Resource acquired with ID: " << id_ << std::endl;
    }
    ~Resource() {
        std::cout << "Resource with ID " << id_ << " released." << std::endl;
    }

private:
    int id_;
};

int main() {
    // Example 1: Swapping values
    int x = 10;
    int y = std::exchange(x, 20); // x becomes 20, y becomes the old value of x (10)
    std::cout << "x: " << x << ", y: " << y << std::endl; // Output: x: 20, y: 10

    // Example 2: Resetting a pointer and retrieving the old one
    Resource* res = new Resource(1);
    Resource* oldRes = std::exchange(res, nullptr); // res is now nullptr, oldRes holds the previous Resource*
    delete oldRes; // Explicitly deleting the old resource

    // Example 3: Using std::exchange in a state transition
    enum class State { INIT, RUNNING, FINISHED };
    State currentState = State::INIT;
    State oldState = std::exchange(currentState, State::RUNNING); // Transition from INIT to RUNNING
    std::cout << "Old state: " << static_cast<int>(oldState) << ", New state: " << static_cast<int>(currentState) << std::endl; // Outputs: Old state: 0, New state: 1

    return 0;
}
