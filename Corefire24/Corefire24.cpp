// Corefire24.cpp : This file contains the 'main' function. Program execution begins and ends there.
/////////////////////////////////////////////////////
#include "include.h"


int main()
{
	MyConsoleAPI_extended fn;
	NumberGuessingGame numberGuessingGame;
	CannaCalculator cannaCalcultor;
	Quize quize;

 	do {
		fn.generateMainMenu(fn.getMainMenuState());

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
