#include "numberGame.h"
void run_NumberGuessingGame();
//
// *******//////start of program \\\\\\*******
//
void run_NumberGuessingGame() {
    const int rng_minimum{ 0 };// The new minimum value for the random number range
    const int rng_maximum{ 100 };// The new maximum value for the random number range
    const int MAX_GUESSES{ 10 };// Set the guess limit
    int attempt{ 0 };
    int attemptCount{ 0 };
    bool winner = false;

    // Get the handle to the console output
    HANDLE console_HWND = GetStdHandle(STD_OUTPUT_HANDLE);

    auto numberGenerator = NumberGenerator(rng_minimum, rng_maximum);
    int randomNumber = numberGenerator.getRNG();

    // ******* ////// Game Loop \\\\\\ *******

    while (winner) {
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
        if (guess < randomNumber) {
            std::cout << "No! My number is bigger!\n";
        }
        else {
            std::cout << "No.  My number is smaller\n";
        }
        // If the player ran out of guesses, stop the game
        if (attempt >= MAX_GUESSES) {
            break;
        }
    }
    return;
}// end of game // return to main //