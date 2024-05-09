#include "MyFunctions.h"
#include "include.h"

void MyFunctions::errorInvalidInput() {
    cout("\nERROR: INVALID INPUT\n", red);
    clearInputStream();
}

void MyFunctions::updateMainProgramLoopCondition(bool data) {
    if (mainProgramLoopCondition == data) {
        this->mainProgramLoopCondition = data;
        return;
    }
}

int MyFunctions::selectMenuOption() {
    int returnValue{ 0 };

    cout("\nEnter Command: ", light_blue);
    if (std::cin >> returnValue) {
        return returnValue;
    }
    else {
        clearInputStream();
        return 0;
    }
}
