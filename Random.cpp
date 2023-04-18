#include "Random.h"
#include <cstdlib>
#include <ctime>

Random::Random(int lower_bound, int upper_bound) : lower_bound_(lower_bound), upper_bound_(upper_bound) {
    std::srand(std::time(nullptr)); // seed the random number generator with the current time
}

int Random::GetRandomNumber() const {
    return std::rand() % (upper_bound_ - lower_bound_ + 1) + lower_bound_;
}
