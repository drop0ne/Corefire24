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
		fn.clearScreen();
		fn.cout("CoreFireCode 2024 edition\n", bright_green);
		fn.cout("\n\nMain Menu\n", bright_white);
		fn.cout("Option ", green); fn.cout("1 - Number Gussing Game\n", default_color);
		fn.cout("Option ", green); fn.cout("2 - CannabisCalculator\n", default_color);
		fn.cout("Option ", green); fn.cout("3 - Quiz\n", default_color);
		fn.cout("Option ", green); fn.cout("9 - Exit\n", default_color);

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
