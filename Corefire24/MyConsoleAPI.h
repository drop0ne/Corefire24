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

    int returnRandomNumber(const int min,const int max);
};

#endif // NUMBER_GENERATOR_H

#ifndef PROGRAM_EXTENSIONS
#define PROGRAM_EXTENSIONS

#include <string>

class programExtensions {
public:
    static void setConsoleTitle(const std::string& title);
    static void setConsoleSize(int width, int height);
    static void setConsoleFont(int width, int height, const std::string& fontName);
    static void setConsoleIcon(int iconID);
    static void setConsoleIcon(const std::string& iconPath);

    struct IconSettings {
        std::string path;
        int id = -1;
    };
    static void setConsoleIcon(const IconSettings& settings);
};
#endif // PROGRAM_EXTENSIONS

//////////////////////////////////////////

#ifndef MY_CONSOLE_API_H
#define MY_CONSOLE_API_H

class MyConsoleAPI {
private:
protected:
    HANDLE console_HWND; // Handle to the console window
    int threadLimit;
    std::vector<std::thread::id> threadID_vector;
    std::vector<std::thread> thread_vector;
public:

    // Methods
    MyConsoleAPI(); // Constructor
    virtual void clearScreen(); // Clear the console screen
    virtual void cout(const std::string& data); // Print text to the console
    virtual void cout(const std::string& data, const int set_text_color); // Print text to the console & set the text color
    virtual void cout(const std::string& string1, const int& textColor1, const std::string& string2, const int& textColor2,
        const std::string& string3, const int& textColor3, const std::string& string4, const int& textColor4);

    //virtual void setScreenColor(const int backgroundColor, const int textColor); // Set the full screen color
    virtual void setScreenColor(const char* screenTextColor); // Set the full screen color)
    virtual void set_text_color(const int data); // Set the text color in the console
    virtual void clearInputStream();
    virtual void extractInputStream();
    virtual void passFunction_toThread_new/*copy a Function to new thread*/(void (function)());
private:
    bool isValidCommand(const char* command);
};
#endif // MY_CONSOLE_API_H

//////////////////////////////////////////

#ifndef MY_CONSOLE_API_EXTENDED
#define MY_CONSOLE_API_EXTENDED


class MyConsoleAPI_extension : public MyConsoleAPI, public NumberGenerator {
private:
    int mainMenu_totalParameters;
    std::vector<int> mainMenuParameterState;
    std::vector<int> mainMenu_defaultParameterState;
    std::vector<bool> FLAGS_theme;
    std::vector<std::unique_ptr<std::atomic<bool>>> FLAGS_theme_atomic;
        
public:
    // Structs
    // Methods
    MyConsoleAPI_extension(); // Constructor

    void invalid_Input();
    int selectMenuOption();
    void setMainMenuState(const std::vector<int> newState);
    const std::vector<int>& getMainMenuState() const;
    const std::vector<int>& getMainMenuDefaultState() const;
    void generateMainMenu(const std::vector<int>& stateData);
    void setThemeFlag(const int themeFlag_ID);
    void callTheme_by_Flag_ID(const int& themeFlag_ID);
    
private:
    void menuTheme_Default(); // ID (0)
    void menuTheme_Random(); // ID (1)
    void menuTheme_Rainbow(); // ID (2)
    

    /*
    
        void checkFlag(size_t index) {
        if (index < flags.size() && flags[index]->load()) {  // Correctly accessing atomic bool
            // Handle the flag being true
        }
    }

    void setFlag(size_t index, bool value) {
        if (index < flags.size()) {
            flags[index]->store(value);  // Correctly setting atomic bool
        }
    }

    */
};
#endif // !MY_CONSOLE_API_EXTENDED