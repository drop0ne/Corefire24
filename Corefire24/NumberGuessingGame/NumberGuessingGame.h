#pragma once
#include <iostream>

class NumberGuessingGame {
private:
    // Game state working memory
    int randomNumber{ 0 };
    const int MAX_GUESSES = 5; // Set the guess limit
    int attempt{ 0 }; // Number guessed
    int attemptCount{ 0 }; // Number of guesses

public:
    NumberGuessingGame();
    ~NumberGuessingGame();
    void run(int rng);

private:
    void gameLoop();
    void clearMemory();
};

NumberGuessingGame::NumberGuessingGame() {}

NumberGuessingGame::~NumberGuessingGame() {}

void NumberGuessingGame::run(int rng) {
    this->randomNumber = rng;
    gameLoop();
}

void NumberGuessingGame::gameLoop() {
    do {
        this->attemptCount++;

        if (this->attemptCount >= this->MAX_GUESSES) {
            std::cout << "\nFAIL: You are out of guesses\n";
            system("pause");
            return;
        }

        std::cout << "\nGuess a number between 0 and 100\n";
        std::cout << "Enter Guess: ";

        // Error handling for invalid input
        if (!(std::cin >> this->attempt)) {
            std::cout << "Invalid input. Please enter a valid number.\n";

            // Clear the input stream and reset error flags
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue; // Skip the rest of the loop and prompt for input again
        }
        if (this->attempt < 0 || this->attempt > 100) {
            std::cout << "Input out of range. Please enter a number between 0 and 100.\n";
            continue; // Skip the rest of the loop and prompt for input again
        }
        else {
            if (this->attempt == this->randomNumber) {
                // Winner winner chicken dinner
                std::cout << "Winner!\n";
                system("pause"); // Consider using platform-independent methods for pausing
                return; // Exit the function since the correct number has been guessed
            }
            else {
                if (this->attempt < this->randomNumber) {
                    // Print that the random number is higher
                    std::cout << "Higher\n";
                }
                else {
                    // Print that the random number is lower
                    std::cout << "Lower\n";
                }
            }
        }
    } while (true); // Removed the unnecessary loop variable

    clearMemory();
}

void NumberGuessingGame::clearMemory() {
    this->randomNumber = 0;
    this->attemptCount = 0;
    this->attempt = 0;
}
