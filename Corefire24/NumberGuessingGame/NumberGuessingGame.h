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
    int attemptCount{ 0 };
    bool winner = false;
    

public:
    NumberGuessingGame(int rng);
	~NumberGuessingGame();
    void run();
private:
    void initializeRNG();
    void gameLoop();
};

NumberGuessingGame::NumberGuessingGame(int rng) : randomNumber(rng)
{
}

NumberGuessingGame::~NumberGuessingGame()
{
}

void NumberGuessingGame::run() {
    initializeRNG();
    gameLoop();
}

void NumberGuessingGame::initializeRNG() {
    //auto numberGenerator = NumberGenerator(rng_minimum, rng_maximum);
    //this->randomNumber = numberGenerator.getRNG();
}

void NumberGuessingGame::gameLoop() {
    do {
        std::cout << "\nGuess a number between 0 and 100";
        if (std::cin >> attempt) {
            ++attemptCount;
        }

        std::cout << "You have " << (MAX_GUESSES - attemptCount) << " attempts remaining.\n";

        if (attempt == randomNumber) {
            winner = true;
            break;
        }
        //Escape code to end game
        if (attempt < 0) {
            break;
        }
        if (attempt < randomNumber) {
            std::cout << "No! My number is bigger!\n";
        }
        else {
            std::cout << "No.  My number is smaller\n";
        }
        // If the player ran out of guesses, stop the game
        if (attempt >= MAX_GUESSES) {
            break;
        }
    } while (!winner);
}


