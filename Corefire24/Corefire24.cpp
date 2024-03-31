// Corefire24.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Class0ne.h"

int main()
{
    FN fn;
	fn.clearScreen();

 	do {
		std::cout << "CoreFireCode 2024 editioin" << std::endl;
		std::cout << "\n\nMain Menu\n";
		std::cout << "Option 1\nOption 2\nOption 3\n";

		fn.evaluateInput(fn.selectMenuOption());

		system("pause");
		fn.setMainLoopCondition(false);
	} while (fn.getMainLoopCondition());

	return 0;
}