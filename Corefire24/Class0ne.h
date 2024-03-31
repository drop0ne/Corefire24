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

		cout("\nEnter Command: ");
		if (std::cin >> returnValue) {
			return returnValue;
		}
		else {
			clearInputStream();
		}
	}
	void cout(std::string output) {
		std::cout << output;
	}

	void errorInvalidInput() {
		cout("\nERROR: INVALID SELECTION\n");
		clearInputStream();
	}

	void clearInputStream() {
		std::cin.clear();
		if (std::cin.rdbuf()->in_avail() > 0) {
			// If there are characters in the input buffer, discard them up to the next newline
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}

private:
	void updateMainProgramLoopCondition(bool data) {
		
		this->mainProgramLoopCondition = data;
		
		if (mainProgramLoopCondition == data) {
			return;
			}
		else {
			cout("Error: Failed to update manProgramLoopCondition bool private method\n");
			return;
		}
	}

	void extractInputStream() {
		std::cout << "Contents of input stream: ";
		char c;
		while (std::cin.peek() != EOF) {
			std::cin.get(c);
			std::cout << c;
		}
		std::cout << std::endl;
		return;
	}
};

FN::FN() :mainProgramLoopCondition(true)
{
}

FN::~FN()
{
}