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
	system("pause");
}

void Solitaire::gameLoop() {

}

void Solitaire::cardShufflingMachine() {

}

void Solitaire::printLOGO(std::string string) {
	this->gameTitle.resize(string.size());

	for (size_t i = 0; i < string.size(); i++)
	{
		this->gameTitle.at(i) = string.at(i);

	}
	this->gameTitle.shrink_to_fit();

	int j = {0};
	for (auto i : this->logoSplashEffect) {
		setMyTextColor(this->logoSplashEffect.at(i));
		if (j <= this->gameTitle.size())
		{
			std::cout << this->gameTitle.at(j);
		}
		else
		{
			j = 0;
			clearScreen();
		}
	}
}