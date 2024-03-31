#pragma once
#include <iostream>

class FN
{
private:
	bool mainProgramLoopCondition{};
//////
public:
	FN();
	~FN();

	void setMainLoopCondition(bool newCondition);
	bool getMainLoopCondition();
	void clearScreen();
	int selectMenuOption();
	void cout(std::string output);
	void errorInvalidInput();
	void clearInputStream();
////// 
private:
	void updateMainProgramLoopCondition(bool data);
	void extractInputStream();
};
/////////////////////////////////////////////////////

// PUBLIC METHODS ******
FN::FN() :mainProgramLoopCondition(true)
{
}
FN::~FN()
{
}

void FN::setMainLoopCondition(bool newCondition) {
	updateMainProgramLoopCondition(newCondition);
	return;
}

bool FN::getMainLoopCondition() {
	return mainProgramLoopCondition;
}
void FN::clearScreen() {
	system("cls");
}
int FN::selectMenuOption() {
	int returnValue{ 0 };

	cout("\nEnter Command: ");
	if (std::cin >> returnValue) {
		return returnValue;
	}
	else {
		clearInputStream();
	}
}


void FN::cout(std::string output) {
	std::cout << output;
}


void FN::errorInvalidInput() {
	cout("\nERROR: INVALID SELECTION\n");
	clearInputStream();
}


void FN::clearInputStream() {
	std::cin.clear();
	if (std::cin.rdbuf()->in_avail() > 0) {
		// If there are characters in the input buffer, discard them up to the next newline
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

// PRIVATE METHODS  ******

void FN::updateMainProgramLoopCondition(bool data) {

	this->mainProgramLoopCondition = data;

	if (mainProgramLoopCondition == data) {
		return;
	}
	else {
		cout("Error: Failed to update manProgramLoopCondition bool private method\n");
		return;
	}
}

void FN::extractInputStream() {  //Unused code
	std::cout << "Contents of input stream: ";
	char c;
	while (std::cin.peek() != EOF) {
		std::cin.get(c);
		std::cout << c;
	}
	std::cout << std::endl;
	return;
}