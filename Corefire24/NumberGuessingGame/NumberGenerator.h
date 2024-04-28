#include "..\include.h"

class NumberGenerator {
private:
    std::random_device rd;
    std::mt19937_64 generator;

public:
    NumberGenerator();
    ~NumberGenerator();

    int returnRandomNumber(int min, int max);
};

NumberGenerator::NumberGenerator() : generator(rd()) {}

NumberGenerator::~NumberGenerator() {}

int NumberGenerator::returnRandomNumber(int min, int max) {
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}