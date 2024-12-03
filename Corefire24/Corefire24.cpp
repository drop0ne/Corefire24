// Corefire24.cpp : This file contains the 'main' function. Program execution begins and ends there.
/////////////////////////////////////////////////////
#include "MyConsoleAPI.h"
#include "MyGames.h"
#include "Solitaire.h"

void games(int option);
void apps(int option);

int main()
{
	static ToolSet_MainMenu cf;

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

void games(int option) {
	auto quizGame = new Quiz;
	auto numberGame = new NumberGuessingGame;
	auto solitaireGame = new Solitaire;
	//auto hangmanGame = new Hangman;

	switch (option)
	{
	case 0: quizGame->run(); break;
	case 1: numberGame->run(); break;
	case 2: /*hangman.run();*/break;
	case 3: solitaireGame->run(); break;
	default: break;
	}
	delete quizGame;
	delete numberGame;
	delete solitaireGame;
	//delete hangmanGame;
}

void apps(int option) {
	auto CannabisAPP = new CannaCalculator;
	auto PowerLossAPP = new CalculatePowerLoss_Watts_x_Meters;

	switch (option)
	{
	case 0: CannabisAPP->run(); break;
	case 1: PowerLossAPP->run(); break;
	case 2: break;
	default:
		break;
	}
	delete CannabisAPP;
	delete PowerLossAPP;
	//delete hangmanGame;
	//delete solitaireGame;
}