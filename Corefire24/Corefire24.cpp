// Corefire24.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Class0ne.h"
#include "NumberGuessingGame/numberGame.h"

void run_NumberGuessingGame();

int main()
{
    FN fn;

 	do {
		fn.clearScreen();
		fn.cout("CoreFireCode 2024 editioin\n");
		fn.cout("\n\nMain Menu\n");
		fn.cout("Option 1 - Number Gussing Game\nOption 2\nOption 3\nOption 9 to Exit\n");

		switch (fn.selectMenuOption())
		{
		case 1: run_NumberGuessingGame(); break;
		case 2: fn.cout("Option 2 was slected\n"); break;
		case 3: fn.cout("Option 3 was slected\n"); break;
		case 9: fn.setMainLoopCondition(false); break;
		default: fn.errorInvalidInput(); system("pause"); break;
		}

	} while (fn.getMainLoopCondition());

	return 0;
}

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