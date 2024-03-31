#pragma once
#include "numberGame.h"

class NumberGuessingGame
{
public:
	NumberGuessingGame();
	virtual ~NumberGuessingGame();
	void runGame();


private:
	void mainEntryPoint();

};

NumberGuessingGame::NumberGuessingGame()
{
}

NumberGuessingGame::~NumberGuessingGame()
{
}


void NumberGuessingGame::runGame() {
	mainEntryPoint();
}


// PRIVATE ******
void NumberGuessingGame::mainEntryPoint() {
	system("cls");
	std::cout << "Number Guessing Game: reborn\n\n\n";



	return; // end of program!
}