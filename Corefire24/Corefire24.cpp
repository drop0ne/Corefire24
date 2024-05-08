// Corefire24.cpp : This file contains the 'main' function. Program execution begins and ends there.
/////////////////////////////////////////////////////
#include "include.h"
#include "Class0ne.h"
#include "NumberGuessingGame/NumberGenerator.h"
#include "NumberGuessingGame/NumberGuessingGame.h"
#include "CannaCalculator/CannaCalculator.h"
#include "Quize.h"

enum colorINT
{
	default_color = 7, black = 0, dark_green = 2, green = 2, bright_green = 10, blue = 1, bright_red = 12, red = 4, light_blue = 3, ice_blue = 9, teal_blue = 11, white = 7, bright_white = 15, gray = 8, purple = 5, yellow = 6
};

int main()
{
    FN fn;
	fn.receiveConsoleHWND(GetStdHandle(STD_OUTPUT_HANDLE));
	// Number Guessing Game START
	NumberGenerator RNG;
	NumberGuessingGame numberGuessingGame;
	// END ****************
	// More programs
	CannaCalculator cannaCalcultor;
	Quize quize;

 	do {
		fn.clearScreen();
		fn.set_text_color(green);
		fn.cout("CoreFireCode 2024 edition\n");
		fn.set_text_color(default_color);
		fn.cout("\n\nMain Menu\n");
		fn.cout("Option 1 - Number Gussing Game\nOption 2 - CannabisCalculator\nOption 3 - Quize\nOption 9 to Exit\n");

		switch (fn.selectMenuOption())
		{
		case 1: numberGuessingGame.run(RNG.returnRandomNumber(numberGuessingGame.rngRangeLimt().min, numberGuessingGame.rngRangeLimt().max)); break;
		case 2: cannaCalcultor.run(); break;
		case 3: quize.run(); break;
		case 9: return 0;
		default: fn.errorInvalidInput(); system("pause"); break;
		}

	} while (true);
	return -1;
}