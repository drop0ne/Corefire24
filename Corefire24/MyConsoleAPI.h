#pragma once

class MyConsoleAPI {
private:
    HANDLE console_HWND; // Handle to the console window

public:
    MyConsoleAPI(); // Constructor
    virtual void clearScreen() const; // Clear the console screen
    virtual void cout(const std::string& data) const; // Print text to the console
    virtual void cout(const std::string& data,const int set_text_color) const; // Print text to the console & set the text color
    virtual void setScreenColor(const int backgroundColor,const int textColor) const; // Set the full screen color
    virtual void set_text_color(const int data) const; // Set the text color in the console
};