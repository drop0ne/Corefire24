// Corefire24.cpp : This file contains the 'main' function. Program execution begins and ends there.
/////////////////////////////////////////////////////
#include "BaseClass.h"
#include "MyGames.h"
#include "Solitaire.h"
#include "Hangman.h"

int main() {
	/* Main Menu & Program Start*/
	cfc_core::Startscreen function;

	

	while (!function.exitRequested.load()) {
		switch (function.mainMenuLogic())
		{
		case 1: {
			auto CannaCalc_OBJ = std::make_unique<CannaCalculator>();
			CannaCalc_OBJ->run();
			break;
		}
		case 2: {
			auto calculatePowerLoss_OBJ = std::make_unique<CalculatePowerLoss_Watts_x_Meters>();
			calculatePowerLoss_OBJ->run();
			break;
		}
		case 3: {
			auto numberGuessingGame_OBJ = std::make_unique<NumberGuessingGame>();
			numberGuessingGame_OBJ->run();
			break;
		}
		case 4: {
			auto quize_OBJ = std::make_unique<Quiz>();
			quize_OBJ->run();
			break;
		}
		case 5: {
			auto hangman_OBJ = std::make_unique<Hangman>();
			hangman_OBJ->run();
			break;
		}
		case 6: function.callTheme_by_Flag_ID(/*enum eFLAG_ThemeID*/defaultTheme); break;
		case 7: function.callTheme_by_Flag_ID(/*enum eFLAG_ThemeID*/RandomTheme); break;
		case 8: function.callTheme_by_Flag_ID(/*enum eFLAG_ThemeID*/RainbowTheme); break;
		case 9: {
			auto solitaire_OBJ = std::make_unique<Solitaire>();
			solitaire_OBJ->run();
			break;
		}
		default: function.print("\nCommand must be intager from 1 - 9\n", function.getMainMenuState().at(/*enum eMainMenu_State_ID*/ErrorMessage)); function.pause(); break;
		}
	}
	return 0;
}