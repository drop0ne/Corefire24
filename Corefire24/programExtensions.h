#pragma once
#include "include.h"


#ifndef PROGRAM_EXTENSIONS
#define PROGRAM_EXTENSIONS

#include <string>

class programExtensions {
 /*
public:
    static void setConsoleTitle(const std::string& title);
    static void setConsoleSize(int width, int height);
    static void setConsoleFont(int width, int height, const std::string& fontName);

    // Simplified setConsoleIcon with basic use cases
    static void setConsoleIcon(int iconID);
    static void setConsoleIcon(const std::string& iconPath);

    // Example of a more flexible function using a settings structure
    struct IconSettings {
        std::string path;
        int id = -1; // Default ID
        // Add more properties as needed
    };
    static void setConsoleIcon(const IconSettings& settings);
 */
};

#endif // PROGRAM_EXTENSIONS

//////////////////////////////////////////

#ifndef MY_CONSOLE_API_H
#define MY_CONSOLE_API_H

class MyConsoleAPI {
protected:
    HANDLE console_HWND; // Handle to the console window

public:

    // Methods
    MyConsoleAPI(); // Constructor
    virtual void clearScreen(); // Clear the console screen
    virtual void cout(const std::string& data); // Print text to the console
    virtual void cout(const std::string& data, const int set_text_color); // Print text to the console & set the text color
    //virtual void setScreenColor(const int backgroundColor, const int textColor); // Set the full screen color
    virtual void setScreenColor(const char* screenTextColor); // Set the full screen color)
    virtual void set_text_color(const int data); // Set the text color in the console
    virtual void clearInputStream();
    virtual void extractInputStream();
private:
    bool isValidCommand(const char* command);
};
#endif // MY_CONSOLE_API_H

//////////////////////////////////////////

#ifndef MY_CONSOLE_API_EXTENDED
#define MY_CONSOLE_API_EXTENDED


class MyConsoleAPI_extended : public MyConsoleAPI {
private:
    int number_of_state_parameters;
    std::vector<int> mainMenuState;
        
public:
    // Structs
    // Methods
    MyConsoleAPI_extended(); // Constructor

    void errorInvalidInput();
    int selectMenuOption();
    void setMainMenuState(const std::vector<int>& parameters);
    const std::vector<int>& getMainMenuState() const;
    void generateMainMenu(const std::vector<int>& stateData);
    
};
#endif // !MY_CONSOLE_API_EXTENDED

//////////////////////////////////////////

#ifndef Quiz_H
#define Quiz_H

class Quiz {
private:
    int iteration;

public:
    void run();
    Quiz();

private:
    void gameLoop();
    void setupEnviorment();
    int requestInput();
    void question(int questionNumber);
    void askFirstQuestion();
    void askSecondQuestion();
    void askThirdQuestion();

};
#endif // Quiz_H

//////////////////////////////////////////

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

//////////////////////////////////////////

#ifndef NUMBER_GUESSING_GAME_H
#define NUMBER_GUESSING_GAME_H
// ready for start screen with menu options
// options: set rng range; set number of guess; have default avalible - thats 3 options

class NumberGuessingGame : public NumberGenerator {
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


class CannaCalculator {
public:
    CannaCalculator();
    ~CannaCalculator();

    void run();

private:
    void programLoop();
};
#endif // NUMBER_GUESSING_GAME_H
