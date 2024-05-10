#include "MyFunctions.h"
#include "MyHeaders.h"

void MyFunctions::errorInvalidInput() {
    cout("\nERROR: INVALID INPUT\n", red);
    clearInputStream();
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
