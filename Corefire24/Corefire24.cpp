// Corefire24.cpp : This file contains the 'main' function. Program execution begins and ends there.
/////////////////////////////////////////////////////
#include "include.h"


int main()
{
	static MyConsoleAPI_extension fn;
	NumberGuessingGame numberGuessingGame;
	CannaCalculator cannaCalcultor;
	Quiz quiz;

 	do {
		fn.clearScreen();
		fn.generateMainMenu(fn.getMainMenuState());

		switch (fn.selectMenuOption())
		{
		case 1: numberGuessingGame.run(); break;
		case 2: cannaCalcultor.run(); break;
		case 3: quiz.run(); break;
		case 4: fn.callTheme_by_Flag_ID(/*enum eFLAG_ThemeID*/RandomTheme); break;
		case 5: fn.callTheme_by_Flag_ID(/*enum eFLAG_ThemeID*/defaultTheme); break;
		case 6: fn.callTheme_by_Flag_ID(/*enum eFLAG_ThemeID*/RainbowTheme); break;
		case 9: return 0;/*EXIT PROGRAM WITHOUT ERROR*/
		default: fn.cout("Invalid :: Try Again", fn.getMainMenuState().at(/*enum eMainMenu_State_ID*/ErrorMessage)); system("pause"); break;
		}

	} while (true);
	return -1;
}