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
		std::cin >> returnValue;

		return returnValue;
	}
	void evaluateInput(int choice) {
		if (choice != 0) {
			switch (choice)
			{
			case 1: std::cout << "option 1"; break;
			default:
				break;
			}

		}
		else {
			std::cout << "Invalid Choice" << std::endl;
		}
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