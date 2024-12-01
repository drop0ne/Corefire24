// Corefire24.cpp : This file contains the 'main' function. Program execution begins and ends there.
/////////////////////////////////////////////////////
#include "MyConsoleAPI.h"
#include "MyGames.h"

void games(int option);
void apps(int option);

int main()
{
	static ToolSet_MainMenu fn;

 	do {
		switch (fn.mainMenuLogic())
		{
		case 1: games(numberGame); break;
		case 2: apps(CannaCalc); break;
		case 3: games(quiz); break;
		case 4: fn.callTheme_by_Flag_ID(/*enum eFLAG_ThemeID*/RandomTheme); break;
		case 5: fn.callTheme_by_Flag_ID(/*enum eFLAG_ThemeID*/defaultTheme); break;
		case 6: fn.callTheme_by_Flag_ID(/*enum eFLAG_ThemeID*/RainbowTheme); break;
		case 7: apps(PowerLossCalc); break;
		case 8: apps(hangman); break;
		case 9: return 0;/*EXIT PROGRAM WITHOUT ERROR*/
		default: fn.print("\nCommand must be intager from 1 - 6\n", fn.getMainMenuState().at(/*enum eMainMenu_State_ID*/ErrorMessage)); system("pause"); break;
		}

	} while (true);
	return -1;
}

void games(int option) {
	Quiz quiz;
	NumberGuessingGame ngg;
	Hangman hangman;

	switch (option)
	{
	case 1: quiz.run(); break;
	case 2: ngg.run(); break;
	default:
		break;
	}
}

void apps(int option) {
	CannaCalculator CannaCalc;
	CalculatePowerLoss_Watts_x_Meters powerLossCalc;

	switch (option)
	{
	case 1: CannaCalc.run(); break;
	case 2: powerLossCalc.run(); break;
	case 3: //hangman.run(); break;
	default:
		break;
	}
}
