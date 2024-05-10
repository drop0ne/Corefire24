#include "MyFunctions.h"
#include "MyHeaders.h"

MyFunctions::MyFunctions() : Utility(), MyConsoleAPI() {
    // Constructor
}

void MyFunctions::errorInvalidInput() {
    MyConsoleAPI::cout("\nERROR: INVALID INPUT\n", red);
    Utility::clearInputStream();
}

int MyFunctions::selectMenuOption() {
    int returnValue{ 0 };

    MyConsoleAPI::cout("\nEnter Command: ", light_blue);
    if (std::cin >> returnValue) {
        return returnValue;
    }
    else {
        Utility::clearInputStream();
        return 0;
    }
}

// Path: Corefire24/MyHeaders.h