// Corefire24.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Class0ne.h"
#include "NumberGuessingGame/NumberGuessingGame.h"

class Loader
{
public:
	Loader();
	~Loader();
	auto loadGame() {
		auto game = new Game;
		return game;
	}

private:

};

Loader::Loader()
{
}

Loader::~Loader()
{
}


int main()
{
    HANDLE console_HWND = GetStdHandle(STD_OUTPUT_HANDLE);
    FN fn;
	Loader ld;

 	do {
		fn.clearScreen();
		fn.cout("CoreFireCode 2024 editioin\n");
		fn.cout("\n\nMain Menu\n");
		fn.cout("Option 1 - Number Gussing Game\nOption 2\nOption 3\nOption 9 to Exit\n");

		switch (fn.selectMenuOption())
		{
		case 1: auto game = ld.loadGame(); game->run(); delete game; break; // Need ***  Class::method || void create() { auto game = new Game; }
		case 2: fn.cout("Option 2 was slected\n"); break;
		case 3: fn.cout("Option 3 was slected\n"); break;
		case 9: fn.setMainLoopCondition(false); break;
		default: fn.errorInvalidInput(); system("pause"); break;
		}

	} while (fn.getMainLoopCondition());

	return 0;
}