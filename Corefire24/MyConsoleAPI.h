#pragma once
#include "MyHeaders.h"

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