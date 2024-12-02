#pragma once
#include "My Standard Includes.h"
#include "MyEnum.h"
#include "MyConsoleAPI.h"

class Solitaire : public CFC_coreComponents, NumberGenerator {
private:
	std::vector<std::string> gameTitleVector;
	std::vector<int> storedRandomNumber;
	std::string gameTitleSourceString;

public:
	Solitaire();
	void run();

private:
	void startScreen();
	void gameLoop();
	void cardShufflingMachine();
	void printLOGO(const std::string& title);
};