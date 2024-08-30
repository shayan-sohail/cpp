#include <iostream>
#include <random>

/*
Random Engines: Generate sequences of random numbers based on algorithms (e.g., std::default_random_engine, std::mt19937).
Distributions: Define how random numbers are distributed (e.g., std::uniform_int_distribution, std::normal_distribution).
Seed: Initializes random engines to produce different sequences or repeatable sequences of random numbers.
*/

// https://godbolt.org/z/q6bof6nGn

int main() {
    // Create a random engine and seed it with a random value
    std::random_device rd; // Random seed
    std::mt19937 gen(rd()); // Standard Mersenne Twister engine

    // Uniform integer distribution in the range [1, 6]
    std::uniform_int_distribution<> distrib(1, 6);

    // Generate and print random numbers
    for (int i = 0; i < 10; ++i) {
        std::cout << distrib(gen) << " ";
    }
    std::cout << std::endl;

    // Uniform real distribution in the range [0.0, 1.0]
    std::uniform_real_distribution<> distrib_real(0.0, 1.0);

    // Generate and print random floating-point numbers
    for (int i = 0; i < 10; ++i) {
        std::cout << distrib_real(gen) << " ";
    }
    std::cout << std::endl;

    // Normal distribution with mean 0 and standard deviation 1
    std::normal_distribution<> distrib_normal(0, 1);

    // Generate and print random numbers with normal distribution
    for (int i = 0; i < 10; ++i) {
        std::cout << distrib_normal(gen) << " ";
    }
    std::cout << std::endl;

    return 0;
}
