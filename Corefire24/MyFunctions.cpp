#include "MyFunctions.h"
#include "include.h" // Ensure this include is necessary and correct

void MyFunctions::errorInvalidInput() {
    std::cout << "\nERROR: INVALID INPUT\n";
    clearInputStream(); // Assuming this function is defined elsewhere
}

void MyFunctions::updateMainProgramLoopCondition(bool data) {
    if (mainProgramLoopCondition == data) {
        this->mainProgramLoopCondition = data;
        return;
    }
}

int MyFunctions::selectMenuOption() {
    int returnValue{ 0 };

    std::cout << "\nEnter Command: ";
    set_text_color(light_blue);
    if (std::cin >> returnValue) {
        set_text_color(default_color);
        return returnValue;
    }
    else {
        clearInputStream(); // Call function without void
        set_text_color(default_color);
        std::cin.clear(); // Clears error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the input
        return 0;
    }
}
