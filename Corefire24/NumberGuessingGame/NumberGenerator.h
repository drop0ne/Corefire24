#pragma once

#include <iostream>
#include <random>

class NumberGenerator {
private:
    std::random_device rd;
    std::mt19937 generator;
    std::uniform_int_distribution<int> distribution;

public:
    NumberGenerator();
    ~NumberGenerator();

    int getNewRandomNumber();
};

NumberGenerator::NumberGenerator() : generator(rd()), distribution(0, 100) {}

NumberGenerator::~NumberGenerator() {}

int NumberGenerator::getNewRandomNumber() {
    return distribution(generator);
}
