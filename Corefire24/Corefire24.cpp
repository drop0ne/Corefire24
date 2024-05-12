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
		fn.cout("CoreFireCode 2024 edition\n", dark_green);
		fn.cout("\n\nMain Menu\n\n", bright_white);
		fn.cout("Option ", green); fn.cout("1 ", purple); fn.cout("- Number Gussing Game\n", default_color);
		fn.cout("Option ", green); fn.cout("2 ", purple); fn.cout("- CannabisCalculator\n", default_color);
		fn.cout("Option ", green); fn.cout("3 ", purple); fn.cout("- Quiz\n", default_color);
		fn.cout("Option ", green); fn.cout("9", red); fn.cout(" - ", default_color); fn.cout("Exit\n", red);

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
