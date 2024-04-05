#pragma once
#include <iostream>
#include "NumberGenerator.h"

class NumberGuessingGame {
private:
    // Game state working memory
    int randomNumber {0};
    const int MAX_GUESSES = 5;// Set the guess limit
    int attempt{0};// number guessed
    int attemptCount{0};//number of guessess
    bool loop = true;

public:
    NumberGuessingGame();
	~NumberGuessingGame();
    void run(int newRandomNumber);
private:
    void gameLoop();
    void clearMemory();
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
        this->attemptCount++;
        std::cout << "\nGuess a number between 0 and 100\n";
        std::cout << "Enter Guess: ";
        std::cin >> this->attempt;

        if (this->attemptCount >= this->MAX_GUESSES) {
            // failed  out of guessess
            std::cout << "\nFAIL: You are out of guesses\n";
            this->loop = false;
            system("pause");
        }
        else {
            if (this->attempt == this->randomNumber) {
                // winner winner chicken dinner
                std::cout << "Winner!\n";
                this->loop = false;
                system("pause");
            }
            else {
                if (this->attempt < this->randomNumber) {
                    // print rng is higher
                    std::cout << "Higher\n";
                }
                else {
                    // print rng is lower
                    std::cout << "Lower\n";
                }
            }
        }
    } while (this->loop);
    clearMemory();
}

inline void NumberGuessingGame::clearMemory() {
    this->randomNumber = 0;
    this->attemptCount = 0;
    this->attempt = 0;
}

