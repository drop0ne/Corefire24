// Corefire24.cpp : This file contains the 'main' function. Program execution begins and ends there.
/////////////////////////////////////////////////////
#include "include.h"


int main()
{
	MyConsoleAPI_extended fn;

	// Number Guessing Game START
	NumberGenerator RNG;
	NumberGuessingGame numberGuessingGame;
	// END ****************
	// More programs
	CannaCalculator cannaCalcultor;
	Quize quize;

 	do {
		fn.clearScreen();
		fn.cout("CoreFireCode 2024 edition\n", green);
		fn.cout("\n\nMain Menu\n", default_color);
		fn.cout("Option 1 - Number Gussing Game\nOption 2 - CannabisCalculator\nOption 3 - Quize\nOption 9 to Exit\n");

		switch (fn.selectMenuOption())
		{
		case 1: numberGuessingGame.run(); break;
		case 2: cannaCalcultor.run(); break;
		case 3: quize.run(); break;
		case 9: return 0;
		default: fn.cout("Invalid :: Try Again", red); system("pause"); break;
		}

	} while (true);
	return -1;
}
