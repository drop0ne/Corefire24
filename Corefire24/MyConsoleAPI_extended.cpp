#include "MyConsoleAPI_extended.h"

MyConsoleAPI_extended::MyConsoleAPI_extended() : MyConsoleAPI() {
    // Constructor
}

void MyConsoleAPI_extended::errorInvalidInput() {
    MyConsoleAPI_extended::cout("\nERROR: INVALID INPUT\n", red);
    MyConsoleAPI_extended::clearInputStream();
}

int MyConsoleAPI_extended::selectMenuOption() {
    int returnValue{ 0 };

    MyConsoleAPI_extended::cout("\nEnter Command: ", light_blue);
    if (std::cin >> returnValue) {
        return returnValue;
    }
    else {
        MyConsoleAPI_extended::clearInputStream();
        return 0;
    }
}
