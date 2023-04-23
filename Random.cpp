#include "Random.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Random::Random(int lower_bound, int upper_bound) : lower_bound_(lower_bound), upper_bound_(upper_bound) {
}

int Random::GetRandomNumber() const {
    return std::rand() % (upper_bound_ - lower_bound_ + 1) + lower_bound_;
}
