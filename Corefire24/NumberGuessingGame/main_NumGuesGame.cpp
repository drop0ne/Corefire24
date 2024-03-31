#include "numberGame.h"
#include "../Class0ne.h"
void run_NumberGuessingGame();

void run_NumberGuessingGame() {
    // Constants
    const int rng_minimum{ 0 };// The new minimum value for the random number range
    const int rng_maximum{ 100 };// The new maximum value for the random number range
    const int MAX_GUESSES{ 10 };// Set the guess limit
    int guessCount{ 0 };

    // Get the handle to the console output
    HANDLE console_HWND = GetStdHandle(STD_OUTPUT_HANDLE);

    // Create the random number generator thread and start it
    auto numberGenerator = NumberGenerator(rng_minimum, rng_maximum);
    std::thread numberGeneratorThread(&NumberGenerator::GenerateRandomNumbers, &numberGenerator);
    std::this_thread::sleep_for(250ms);//Required!  This allows for the RNG thread time to spool up



    return;  // end of game // return to main //
}