// Corefire24.cpp : This file contains the 'main' function. Program execution begins and ends there.
/////////////////////////////////////////////////////
#include "MyConsoleAPI.h"
#include "MyGames.h"

void games(int option);

int main()
{
	static MyConsoleAPI_extension fn;
	CannaCalculator cannaCalcultor;
	CalculatePowerLoss_Watts_x_Meters powerLossCalculator;

 	do {
		switch (fn.mainMenuLogic())
		{
		case 1: games(numberGame); break;
		case 2: cannaCalcultor.run(); break;
		case 3: games(quiz); break;
		case 4: fn.callTheme_by_Flag_ID(/*enum eFLAG_ThemeID*/RandomTheme); break;
		case 5: fn.callTheme_by_Flag_ID(/*enum eFLAG_ThemeID*/defaultTheme); break;
		case 6: fn.callTheme_by_Flag_ID(/*enum eFLAG_ThemeID*/RainbowTheme); break;
		case 7: powerLossCalculator.run(); break;
		case 9: return 0;/*EXIT PROGRAM WITHOUT ERROR*/
		default: fn.print("\nCommand must be intager from 1 - 6\n", fn.getMainMenuState().at(/*enum eMainMenu_State_ID*/ErrorMessage)); system("pause"); break;
		}

	} while (true);
	return -1;
}

void games(int option) {
	Quiz quiz;
	NumberGuessingGame ngg;

	switch (option)
	{
	case 1: quiz.run(); break;
	case 2: ngg.run(); break;
	default:
		break;
	}
}
