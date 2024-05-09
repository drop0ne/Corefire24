#pragma once
#include "include.h"

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