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