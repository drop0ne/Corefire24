#pragma once
#ifndef MYCONSOLEAPI_H
#define MYCONSOLEAPI_H
#define NOMAXMIN // This is a macro that prevents the min and max macros from being defined

#include <iostream>
#include <stdexcept>
#include <windows.h> // Ensure this is included in your project for console functions

class MyConsoleAPI {
private:
    HANDLE console_HWND; // Handle to the console window

public:
    MyConsoleAPI(); // Constructor
    void clearScreen(); // Clear the console screen
    void cout(const std::string& data); // Print text to the console
    void cout(const std::string& data, int set_tx_color); // Print text to the console
    void setScreenColor(const char* data); // Set the full screen color
    void set_text_color(int data); // Set the text color in the console
};

#endif // MYCONSOLEAPI_H
