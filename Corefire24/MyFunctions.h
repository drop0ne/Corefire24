#pragma once

class MyFunctions : public Utility, public MyConsoleAPI
{
private:
    //bool mainProgramLoopCondition{};

public:
    MyFunctions(); // Constructor

    void errorInvalidInput();
    int selectMenuOption();
};

/// ///////////////////////////////////////////////////////////////

class Inheritance : public Utility, public MyConsoleAPI
{
public:
	Inheritance(); // Constructor
	~Inheritance();

    

private:

};

Inheritance::Inheritance()
{
}

Inheritance::~Inheritance()
{
}

// Path: Corefire24/MyFunctions.cpp