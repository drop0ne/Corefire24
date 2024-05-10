#pragma once
#include "MyHeaders.h"


class MyConsoleAPI_extended : public MyConsoleAPI
{
private:
    //bool mainProgramLoopCondition{};

public:
    MyConsoleAPI_extended(); // Constructor

    void errorInvalidInput();
    int selectMenuOption();
};

/// ///////////////////////////////////////////////////////////////

// Path: Corefire24/MyFunctions.cpp