#include "Solitaire.h"

Solitaire::Solitaire() : logoSplashEffect(42), gameTitle(14), gameTitleSourceString("Solitaire 2002")
{
	for (auto i : logoSplashEffect) {
		logoSplashEffect.at(i) = getRandomNumber(1, 15);
	}
}

void Solitaire::run() {
	startScreen();
}

// PRIVATE METHODS **********
//
void Solitaire::startScreen() {
	clearScreen();
	print(gameTitleSourceString, Red);
	printLOGO(gameTitleSourceString);
}

void Solitaire::gameLoop() {

}

void Solitaire::cardShufflingMachine() {

}

void Solitaire::printLOGO(std::string string) {
	gameTitle.resize(string.size());
	for (auto i : string)
	{
		gameTitle.at(i) = string.at(i);
	}
	gameTitle.shrink_to_fit();
	
	int j = {0};
	for (auto i : logoSplashEffect) {
		setMyTextColor(logoSplashEffect.at(i));
		if (j <= gameTitle.size())
		{
			std::cout << gameTitle.at(j);
		}
		else
		{
			j = 0;
			clearScreen();
		}
	}
}