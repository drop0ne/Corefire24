#pragma once
#include "include.h"



class programExtensions
{
};

#ifndef MY_CONSOLE_API_H
#define MY_CONSOLE_API_H

class MyConsoleAPI {
protected:
    HANDLE console_HWND; // Handle to the console window

public:
    MyConsoleAPI(); // Constructor
    virtual void clearScreen(); // Clear the console screen
    virtual void cout(const std::string& data); // Print text to the console
    virtual void cout(const std::string& data, const int set_text_color); // Print text to the console & set the text color
    virtual void setScreenColor(const int backgroundColor, const int textColor); // Set the full screen color
    virtual void set_text_color(const int data); // Set the text color in the console
    virtual void clearInputStream();
    virtual void extractInputStream();

};
#endif // MY_CONSOLE_API_H

class MyConsoleAPI_extended : public MyConsoleAPI
{
private:
    //bool mainProgramLoopCondition{};

public:
    MyConsoleAPI_extended(); // Constructor

    void errorInvalidInput();
    int selectMenuOption();
};


class Quize {
private:
    int iteration;

public:
    void run();
    Quize();

private:
    void gameLoop();
    void setupEnviorment();
    int requestInput();
    void question(int questionNumber);
    void askFirstQuestion();
    void askSecondQuestion();
    void askThirdQuestion();

};


#ifndef NUMBER_GENERATOR_H
#define NUMBER_GENERATOR_H

class NumberGenerator {
private:
    std::random_device rd;
    std::mt19937_64 generator;

public:
    NumberGenerator();  // Constructor
    ~NumberGenerator(); // Destructor

    int returnRandomNumber(int min, int max);
};

#endif // NUMBER_GENERATOR_H


// ready for start screen with menu options
// options: set rng range; set number of guess; have default avalible - thats 3 options

class NumberGuessingGame : public NumberGenerator, public MyConsoleAPI {
private:
    struct NumberRangeLimit {
        int min;
        int max;
    };

    // Game state working memory
    int randomNumber;
    int MAX_GUESSES;
    int attempt;
    int attemptCount;
    NumberRangeLimit rangeLimit;

public:
    NumberGuessingGame();
    ~NumberGuessingGame();
    void run();

private:
    void gameLoop();
    void setGameState();
};


class CannaCalculator : public MyConsoleAPI {
public:
    CannaCalculator();
    ~CannaCalculator();

    void run();

private:
    void programLoop();
};
