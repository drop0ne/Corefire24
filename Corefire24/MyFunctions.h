#pragma once

class MyFunctions : public Utility, public MyConsoleAPI {
private:
    bool mainProgramLoopCondition{};

public:
    void errorInvalidInput();
    int selectMenuOption();
};
