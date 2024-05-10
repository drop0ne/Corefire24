#include "NumberGuessingGame.h"

NumberGuessingGame::NumberGuessingGame() : randomNumber(0), MAX_GUESSES(5), attempt(0), attemptCount(0) {
    rangeLimit.min = 0;
    rangeLimit.max = 20;
}

NumberGuessingGame::~NumberGuessingGame() {}

void NumberGuessingGame::run() {
    fn.clearScreen();
    fn.clearInputStream();
    setGameState();
    gameLoop();
}

void NumberGuessingGame::gameLoop() {
    do {
        attemptCount++;
        if (attemptCount >= MAX_GUESSES) {
            std::cout << "\nFAIL: You are out of guesses\n";
            std::cout << "The number was: " << randomNumber << "\n\n";
            system("pause");
            return;
        }

        std::cout << "\nGuess a number between " << rangeLimit.min << " and " << rangeLimit.max << "\n";
        std::cout << "Enter Guess: ";

        if (!(std::cin >> attempt)) {
            std::cout << "Invalid input. Please enter a valid number.\n";
            // Clear the input stream and reset error flags
            fn.clearInputStream();
            continue;
        }
        if (attempt < rangeLimit.min || attempt > rangeLimit.max) {
            std::cout << "Input out of range. Please enter a number between 0 and 100.\n";
            continue;
        }
        if (attempt == randomNumber) {
            // Winner winner chicken dinner
            std::cout << "Winner!\n";
            system("pause");
            return;
        }
        else {
            if (attempt < randomNumber) {
                std::cout << "Higher\n";
            }
            else {
                std::cout << "Lower\n";
            }
        }
    } while (true);
}

void NumberGuessingGame::setGameState() {
    randomNumber = returnRandomNumber(rangeLimit.min, rangeLimit.max);
    attemptCount = 0;
    attempt = 0;
}