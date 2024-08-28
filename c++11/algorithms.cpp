#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // for std::iota
#include <iterator> // for std::back_inserter

/*
C++11 added new algorithms such as std::all_of, std::any_of, std::none_of, std::copy_n, std::iota, and std::move. These algorithms provide more concise
and expressive ways to work with ranges of elements. These algorithms can be particularly useful in scenarios where you need to check conditions across a range,
generate sequences, or move elements
efficiently.
*/

// https://godbolt.org/z/nq3vqMraT

int main() {
    std::vector<int> vec = { 1, 2, 3, 4, 5 };

    // 1. std::all_of: Check if all elements satisfy a condition
    bool all_positive = std::all_of(vec.begin(), vec.end(), [](int i) { return i > 0; });
    std::cout << "All elements are positive: " << std::boolalpha << all_positive << std::endl; //true

    // 2. std::any_of: Check if any element satisfies a condition
    bool any_even = std::any_of(vec.begin(), vec.end(), [](int i) { return i % 2 == 0; });
    std::cout << "There is at least one even number: " << std::boolalpha << any_even << std::endl; //true

    // 3. std::none_of: Check if no elements satisfy a condition
    bool none_negative = std::none_of(vec.begin(), vec.end(), [](int i) { return i < 0; });
    std::cout << "No elements are negative: " << std::boolalpha << none_negative << std::endl; //true

    // 4. std::copy_n: Copy a specific number of elements
    std::vector<int> copied_vec(3);
    std::copy_n(vec.begin(), 3, copied_vec.begin());
    std::cout << "First 3 elements copied: ";
    for (int i : copied_vec) std::cout << i << " ";
    std::cout << std::endl;

    // 5. std::iota: Fill a range with sequentially increasing values
    std::vector<int> seq_vec(5);
    std::iota(seq_vec.begin(), seq_vec.end(), 10);
    std::cout << "Sequentially filled vector: ";
    for (int i : seq_vec) std::cout << i << " "; // 10, 11, 12, 13, 14
    std::cout << std::endl;

    // 6. std::move: Move elements from one container to another
    std::vector<int> move_target;
    move_target.reserve(vec.size());
    std::move(vec.begin(), vec.end(), std::back_inserter(move_target));
    std::cout << "Vector after move: ";
    for (int i : move_target) std::cout << i << " ";
    std::cout << std::endl;
    std::cout << "Original vector after move (should be empty or have unspecified state): ";
    for (int i : vec) std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
