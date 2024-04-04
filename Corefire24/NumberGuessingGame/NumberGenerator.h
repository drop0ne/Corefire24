#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <random>
#include <Windows.h>
#include <chrono>
using namespace std::chrono_literals;

class NumberGenerator {
private:
    // The minimum and maximum values for the random number range
    int rng_minimum{0};
    int rng_maximum{0};

public:
	NumberGenerator(int min, int max);
	~NumberGenerator();

    int getNewRandomNumber();

private:
    int numberGenerator();
};

NumberGenerator::NumberGenerator(int min, int max) : rng_minimum(min), rng_maximum(max) {
}

NumberGenerator::~NumberGenerator()
{
}

int NumberGenerator::getNewRandomNumber() {
    return numberGenerator();
}

int NumberGenerator::numberGenerator() {
    int newNumber{ 0 };
    std::mt19937 generator;
    std::uniform_int_distribution<int> distribution(rng_minimum, rng_maximum);
    newNumber = distribution(generator);
    return newNumber;
}
