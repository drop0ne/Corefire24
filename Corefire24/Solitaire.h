#pragma once
#include "My Standard Includes.h"
#include "MyEnum.h"
#include "BaseClass.h"

class Solitaire : public cfc_core::CoreComponents, cfc_core::NumberGenerator {
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