#include "Base.hpp"
#include <random>

Base* Base::generate(void) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(1, 3);
    int randomValue = distribution(gen);

    if (randomValue == 1)
        //generate A
    else if (randomValue == 2)
        // generate B
    else
        //generate C
}