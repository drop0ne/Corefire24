#include  "MyEnum.h"
#include "My Standard Includes.h"
#undef max

// This is a macro that prevents the max macro from being defined


#ifndef NUMBER_GENERATOR_H
#define NUMBER_GENERATOR_H

class NumberGenerator {
private:
    std::random_device rd;
    std::mt19937_64 generator;

public:
    NumberGenerator();  // Constructor
    ~NumberGenerator(); // Destructor

    int getRandomNumber(const int min,const int max);
};

#endif // NUMBER_GENERATOR_H

//////////////////////////////////////////

#ifndef MY_CONSOLE_API_H
#define MY_CONSOLE_API_H

class MyConsoleAPI {
private:
protected:
    HANDLE console_HWND; // Handle to the console window
    int threadLimit;
    std::vector<std::jthread> jthreadPool_concurrent;
    mutable std::mutex mutex_;
public:
    MyConsoleAPI(); // Constructor
    virtual void clearScreen(); 
    virtual void print(const std::string& data);
    virtual void print(const std::string& data, const int set_text_color);
    virtual void print(const double& data, int numberColor);
    virtual void print(const std::string& string1, const double& data1, const std::string& string2, int& textColor, int& numberColor);
    virtual void print(const std::string& string1, const int& textColor1, const std::string& string2, const int& textColor2,
        const std::string& string3, const int& textColor3, const std::string& string4, const int& textColor4);

    virtual void setScreenColor(const char* screenTextColor);
    virtual void set_text_color(const int data);
    virtual void setConsoleColor_FGtext_BG(ConsoleColor foreground, ConsoleColor background); // Needs testing the verify funcionality
    virtual void clearInputStream();
    virtual void extractInputStream();
    virtual void createNewConsoleWindow(); // not working

private:
    bool isValidCommand(const char* command);
};
#endif // MY_CONSOLE_API_H

//////////////////////////////////////////
//////////////////////////////////////////
#ifndef MY_CONSOLE_API_EXTENDED
#define MY_CONSOLE_API_EXTENDED

class ToolSet_MainMenu : public MyConsoleAPI, public NumberGenerator {
private:
    int mainMenu_totalParameters;
    std::vector<int> mainMenuParameterState;
    std::vector<int> mainMenu_defaultParameterState;
    std::vector<bool> FLAGS_theme;
       
public:
    ToolSet_MainMenu(); // Constructor

    void errorMessage();
    int mainMenuLogic();
    void setMainMenuState(const std::vector<int> newState);
    const std::vector<int>& getMainMenuState() const;
    const std::vector<int>& getMainMenuDefaultState() const;
    void generateMainMenu(const std::vector<int>& stateData);
    void setThemeFlag(const int themeFlag_ID);
    void callTheme_by_Flag_ID(const int& themeFlag_ID);
    
private:
    void menuTheme_Default();      // ID (0)
    void menuTheme_Random();       // ID (1)
    void menuTheme_betterRandom(); // ID (2)
    };
#endif // !MY_CONSOLE_API_EXTENDED