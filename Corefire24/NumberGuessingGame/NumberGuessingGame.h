#pragma once
#include <iostream>
#include "NumberGenerator.h"

class NumberGuessingGame {
private:
    //int rng_minimum{ 0 };// The new minimum value for the random number range
    //int rng_maximum{ 0 };// The new maximum value for the random number range
    int randomNumber {0};
    const int MAX_GUESSES{ 10 };// Set the guess limit
    int attempt{ 0 };
    int attemptCount{ 1 };
    bool winner = false;
    

public:
    NumberGuessingGame(int rng);
	~NumberGuessingGame();
    void run();
private:
    void gameLoop();
};

NumberGuessingGame::NumberGuessingGame(int rng) : randomNumber(rng)
{
}

NumberGuessingGame::~NumberGuessingGame()
{
}

void NumberGuessingGame::run() {
    gameLoop();
}

void NumberGuessingGame::gameLoop() {
    do 
    {
        std::cout << "\nGuess a number between 0 and 100\n";
        if (attemptCount > MAX_GUESSES) {
            // failed  out of guessess
            std::cout << "\nFAIL: You are out of guesses\n";
            break;
        }
        else {
            if (attempt == randomNumber) {
                // winner winner chicken dinner
                break;
            }

            if (attempt < randomNumber) {
                // print rng is higher
            }
            else {
                // print rng is lower
            }
        }
        attemptCount++;
    } while (true);
}


