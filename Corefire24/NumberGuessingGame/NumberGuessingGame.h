#pragma once
#include <iostream>
#include "NumberGenerator.h"

class NumberGuessingGame {
private:
    int randomNumber {0};
    const int MAX_GUESSES{ 5 };// Set the guess limit
    int attempt{ 0 };// number guessed
    int attemptCount{ 0 };//number of guessess
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
    // private method here to reset memory
}

void NumberGuessingGame::gameLoop() {
    do 
    {
        ++attemptCount;
        std::cout << "\nGuess a number between 0 and 100\n";
        std::cout << "Enter Guess: ";
        std::cin >> attempt;

        if (attemptCount = MAX_GUESSES) {
            // failed  out of guessess
            std::cout << "\nFAIL: You are out of guesses\n";
            loop = false;
            system("pause");
        }
        else {
            if (attempt == randomNumber) {
                // winner winner chicken dinner
                std::cout << "Winner!\n";
                loop = false;
                system("pause");
            }
            else {
                if (attempt < randomNumber) {
                    // print rng is higher
                    std::cout << "Higher\n";
                }
                else {
                    // print rng is lower
                    std::cout << "Lower\n";
                }
            }
        }
    } while (loop);
    // RESET MEMORY **************************
}