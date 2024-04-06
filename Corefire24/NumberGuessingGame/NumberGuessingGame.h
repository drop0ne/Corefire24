#include "..\include.h"

// ready for start screen with menu options
// options: set rng range; set number of guess; have default avalible - thats 3 options

class NumberGuessingGame {
private:
    struct NumberRangeLimit {
        int min;
        int max;
    };

    // Game state working memory
    int randomNumber;
    int MAX_GUESSES;
    int attempt;
    int attemptCount;
    NumberRangeLimit rangeLimit;

public:
    NumberGuessingGame();
    ~NumberGuessingGame();
    void run(int rng);
    auto rngRangeLimt();

private:
    void gameLoop();
    void clearMemory();
};

NumberGuessingGame::NumberGuessingGame() : randomNumber(0), MAX_GUESSES(5), attempt(0), attemptCount(0) {
    this->rangeLimit.min = 0;
    this->rangeLimit.max = 20;
}

NumberGuessingGame::~NumberGuessingGame() {}

void NumberGuessingGame::run(int rng) {
    this->randomNumber = rng;
    gameLoop();
    clearMemory();
}

inline auto NumberGuessingGame::rngRangeLimt() {
    return rangeLimit;
}

void NumberGuessingGame::gameLoop() {
    do {
        this->attemptCount++;
        if (this->attemptCount >= this->MAX_GUESSES) {
            std::cout << "\nFAIL: You are out of guesses\n";
            std::cout << "The number was: " << randomNumber << "\n\n";
            system("pause");
            return;
        }

        std::cout << "\nGuess a number between " << this->rangeLimit.min << " and "<< this->rangeLimit.max <<"\n";
        std::cout << "Enter Guess: ";

        if (!(std::cin >> this->attempt)) {
            std::cout << "Invalid input. Please enter a valid number.\n";

            // Clear the input stream and reset error flags
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if (this->attempt < this->rangeLimit.min || this->attempt > this->rangeLimit.max) {
            std::cout << "Input out of range. Please enter a number between 0 and 100.\n";
            continue;
        }
        if (this->attempt == this->randomNumber) {
            // Winner winner chicken dinner
            std::cout << "Winner!\n";
            system("pause");
            return;
        } else {
                if (this->attempt < this->randomNumber) {
                    std::cout << "Higher\n";
                }
                else {
                    std::cout << "Lower\n";
                }
        }
    } while (true);
}

void NumberGuessingGame::clearMemory() {
    this->randomNumber = 0;
    this->attemptCount = 0;
    this->attempt = 0;
}