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
    bool loop = true;
    

public:
    NumberGuessingGame();
	~NumberGuessingGame();
    void run(int newRandomNumber);
private:
    void gameLoop();
};

NumberGuessingGame::NumberGuessingGame()
{
}

NumberGuessingGame::~NumberGuessingGame()
{
}

void NumberGuessingGame::run(int newRandomNumber) {
    this->randomNumber = newRandomNumber;
    gameLoop();
}

void NumberGuessingGame::gameLoop() {
    do 
    {
        std::cout << "\nGuess a number between 0 and 100\n";
        std::cout << "Enter Guess: ";
        std::cin >> attempt;

        if (attemptCount > MAX_GUESSES) {
            // failed  out of guessess
            std::cout << "\nFAIL: You are out of guesses\n";
            loop = false;
            break;
        }
        else {
            if (attempt == randomNumber) {
                // winner winner chicken dinner
                std::cout << "Winner!\n";
                loop = false;
                system("pause");
                break;
            }

            if (attempt < randomNumber) {
                // print rng is higher
                std::cout << "Higher\n";
            }
            else {
                // print rng is lower
                std::cout << "Lower\n";
            }
        }
        attemptCount++;
    } while (loop);
}


