// Corefire24.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Class0ne.h"

void option1();

int main()
{
    FN fn;
	fn.clearScreen();

 	do {
		std::cout << "CoreFireCode 2024 editioin" << std::endl;
		std::cout << "\n\nMain Menu\n";
		std::cout << "Option 1\nOption 2\nOption 3\nOption 9 to Exit\n";

		switch (fn.selectMenuOption())
		{
		case 1: option1(); break;
		case 2: std::cout << "Option 2 was slected\n"; break;
		case 3: std::cout << "Option 3 was slected\n"; break;
		case 9: fn.setMainLoopCondition(false); break;
		default:
			break;
		}

		system("pause");
	} while (fn.getMainLoopCondition());

	return 0;
}

void option1() {
	FN fn;
	fn.clearScreen();
	std::cout << "Option 1\n";
	return;
}