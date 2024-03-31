// Corefire24.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Class0ne.h"

void option1();

int main()
{
    FN fn;

 	do {
		fn.clearScreen();
		fn.cout("CoreFireCode 2024 editioin\n");
		fn.cout("\n\nMain Menu\n");
		fn.cout("Option 1 - Number Gussing Game\nOption 2\nOption 3\nOption 9 to Exit\n");

		switch (fn.selectMenuOption())
		{
		case 1: option1(); break;
		case 2: fn.cout("Option 2 was slected\n"); break;
		case 3: fn.cout("Option 3 was slected\n"); break;
		case 9: fn.setMainLoopCondition(false); break;
		default: fn.errorInvalidInput(); system("pause"); break;
		}

	} while (fn.getMainLoopCondition());

	return 0;
}

void option1() {
	
	return;
}