#ifndef BASECLASS_H
#define BASECLASS_H

#include "MyEnum.h"
#include "My Standard Includes.h"
#undef max

#ifndef NUMBER_GENERATOR_H
#define NUMBER_GENERATOR_H

class NumberGenerator {
private:
    std::random_device rd;
    std::mt19937_64 generator;
public:
    NumberGenerator();  // Constructor
    ~NumberGenerator(); // Destructor
    int getRandomNumber(const int min, const int max);
};
#endif // NUMBER_GENERATOR_H

#ifndef MY_CONSOLE_API_H
#define MY_CONSOLE_API_H
class CFC_coreComponents {
protected:
    HANDLE console_HWND;
    COORD topLeft;
public:
    CFC_coreComponents(); // Constructor
    virtual void clearScreen();
    virtual void print(const std::string& data);
    virtual void print(const std::string& data, const int set_text_color);
    virtual void print(const double& data, int numberColor);
    virtual void print(const std::string& string1, const double& data1, const std::string& string2, int& textColor, int& numberColor);
    virtual void print(const std::string& string1, const int& textColor1, const std::string& string2, const int& textColor2,
        const std::string& string3, const int& textColor3, const std::string& string4, const int& textColor4);
    virtual void setScreenColors(const char* screenTextColor);
    virtual void setMyTextColor(const int intConsolColorDOS);
    virtual void overrideConsoleColors(eConsoleTextColor foreground, eConsoleTextColor background);
    virtual void clearInputStream();
    virtual void extractInputStream();
    virtual void sleepTimer(int time);
private:
    bool check_IF_validCommand(const char* command);
};
#endif // MY_CONSOLE_API_H

#ifndef ESCKEYBUTTON_H
#define ESCKEYBUTTON_H
// ESCkeyButton definition using Windows API for key detection
class ESCkeyButton {
public:
    ESCkeyButton();
    ~ESCkeyButton();

    std::atomic<bool> exitRequested;
    std::jthread escThread;
    void isESCkeyPressed(std::stop_token stopToken);
};
#endif // !ESCKEYBUTTON_H

#ifndef MY_CONSOLE_API_EXTENDED
#define MY_CONSOLE_API_EXTENDED
class CoreFireCode_MainFunction : public CFC_coreComponents, public NumberGenerator, public ESCkeyButton {
private:
    int mainMenu_totalParameters;
    std::vector<int> mainMenuParameterCurentState;
    std::vector<int> mainMenu_defaultParameterState;
    std::vector<bool> FLAGS_theme;
public:
    CoreFireCode_MainFunction(); // Constructor
    void errorMessage();
    int mainMenuLogic();
    void setMainMenuState(const std::vector<int> newState);
    const std::vector<int>& getMainMenuState() const;
    const std::vector<int>& getMainMenuDefaultState() const;
    void generateMainMenu(const std::vector<int>& stateData);
    void setThemeFlag(const int themeFlag_ID);
    void callTheme_by_Flag_ID(const int& themeFlag_ID);
private:
    void menuTheme_Default();
    void menuTheme_Random();
    void menuTheme_betterRandom();
};
#endif // !MY_CONSOLE_API_EXTENDED
#endif // BASECLASS_H