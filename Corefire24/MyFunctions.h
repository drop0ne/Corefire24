class MyFunctions : public Utility, public MyConsoleAPI {
private:
    bool mainProgramLoopCondition{};

public:
    void errorInvalidInput();
    void updateMainProgramLoopCondition(bool data);
    int selectMenuOption();
};
