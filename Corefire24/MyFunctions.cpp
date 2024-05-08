#include "MyFunctions.h"
#include "include.h"

void MyFunctions::errorInvalidInput() {
	std::cout << "\nERROR: INVALID INPUT\n";
	void clearInputStream();
}

	void MyFunctions::updateMainProgramLoopCondition(bool data) {
	this->mainProgramLoopCondition = data;
	if (mainProgramLoopCondition == data) {
		return;
	}
	else {
		std::cout << "Error: Failed to update manProgramLoopCondition bool private method\n";
		return;
	}
}

	int MyFunctions::selectMenuOption() {
		int returnValue{ 0 };
		void clearInputStream();

		std::cout << "\nEnter Command: ";
		set_text_color(light_blue);
		if (std::cin >> returnValue) {
			set_text_color(default_color);
			return returnValue;
		}
		else {
			clearInputStream();
			set_text_color(default_color);
			return 0;
		}
	}
