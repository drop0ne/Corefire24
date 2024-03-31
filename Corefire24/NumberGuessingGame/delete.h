#pragma once
class NumberGuessingGame
{
public:
	NumberGuessingGame();
	~NumberGuessingGame();

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


}