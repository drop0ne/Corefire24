// Corefire24.cpp : This file contains the 'main' function. Program execution begins and ends there.
/////////////////////////////////////////////////////
#include "BaseClass.h"
#include "MyGames.h"
#include "Solitaire.h"
#include "Hangman.h"

void games(const int &option);
void apps(const int &option);

int main()
{
	ToolSet_MainMenu cf;

	do {
		switch (cf.mainMenuLogic())
		{
		case 1: apps(CannaCalc); break;
		case 2: apps(PowerLossCalc); break;
		case 3: games(numberGame); break;
		case 4: games(quiz); break;
		case 5: games(hangman); break;
		case 6: cf.callTheme_by_Flag_ID(/*enum eFLAG_ThemeID*/defaultTheme); break;
		case 7: cf.callTheme_by_Flag_ID(/*enum eFLAG_ThemeID*/RandomTheme); break;
		case 8: cf.callTheme_by_Flag_ID(/*enum eFLAG_ThemeID*/RainbowTheme); break;
		case 10: games(solitaire); break;
		case 9: return 0;/*EXIT PROGRAM WITHOUT ERROR*/
		default: cf.print("\nCommand must be intager from 1 - 6\n", cf.getMainMenuState().at(/*enum eMainMenu_State_ID*/ErrorMessage)); system("pause"); break;
		}
	} while (true);
}

void games(const int &option) {

	switch (option)
	{
	case 0: {
		auto quize_OBJ = std::make_unique<Quiz>();
		quize_OBJ->run();
		break; 
	}
	case 1: {
		auto numberGuessingGame_OBJ = std::make_unique<NumberGuessingGame>();
		numberGuessingGame_OBJ->run();
		break;
	}
	case 2: {
		auto hangman_OBJ = std::make_unique<Hangman>();
		hangman_OBJ->run();
		break;
	}
	case 3: {
		auto solitaire_OBJ = std::make_unique<Solitaire>();
		solitaire_OBJ->run();
		break;
	}
	default: {
		break;
	}
	}
}

void apps(const int &option) {

	switch (option)
	{
	case 0: {
		auto CannaCalc_OBJ = std::make_unique<CannaCalculator>();
		CannaCalc_OBJ->run();
		break;
	}
	case 1: {
		auto calculatePowerLoss_OBJ = std::make_unique<CalculatePowerLoss_Watts_x_Meters>();
		calculatePowerLoss_OBJ->run();
		break;
	}
	case 2: {
		break;
	}
	default: {
		break;
	}
	}
}