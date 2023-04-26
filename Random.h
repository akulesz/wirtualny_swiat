#pragma once
#include <cstdlib>
#include <ctime>

class Random {
public:
    Random(int lower_bound, int upper_bound);
    int GetRandomNumber() const;
private:
    int lower_bound_;
    int upper_bound_;
};