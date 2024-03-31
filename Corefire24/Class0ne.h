#pragma once
#include <iostream>

class FN
{
private:
	bool mainProgramLoopCondition{};

public:
	FN();
	~FN();

	void setMainLoopCondition(bool newCondition) {
		updateMainProgramLoopCondition(newCondition);
		return;
	}
	bool getMainLoopCondition() {
		return mainProgramLoopCondition;
	}
	void clearScreen() {
		system("cls");
	}
	int selectMenuOption() {
		int returnValue{ 0 };

		std::cout << "Enter Command: ";
		if (std::cin >> returnValue) {
			return returnValue;
		}
		else {
			std::cout << "Invalid Input: Must enter a whole number!" << std::endl;
		}

	}
	void cout(std::string output) {
		std::cout << output;
	}

private:
	void updateMainProgramLoopCondition(bool data) {
		
		this->mainProgramLoopCondition = data;
		
		if (mainProgramLoopCondition == data) {
			return;
			}
		else {
			std::cout << "Error: Failed to update manProgramLoopCondition bool private method" << std::endl;
			return;
		}
	}

};

FN::FN() :mainProgramLoopCondition(true)
{
}

FN::~FN()
{
}