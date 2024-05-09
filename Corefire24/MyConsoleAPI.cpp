#include "MyConsoleAPI.h"
#include "include.h"

// Constructor
MyConsoleAPI::MyConsoleAPI() {
    this->console_HWND = GetStdHandle(STD_OUTPUT_HANDLE);
    if (this->console_HWND == INVALID_HANDLE_VALUE) {
        throw std::runtime_error("Failed to get standard output handle");
    }
}

// Clear the console screen using Windows API for better performance and security
void MyConsoleAPI::clearScreen() {
    COORD topLeft = { 0, 0 };
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    if (!GetConsoleScreenBufferInfo(this->console_HWND, &screen)) {
        throw std::runtime_error("Failed to get console buffer info");
    }

    if (!FillConsoleOutputCharacter(
        this->console_HWND, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written)) {
        throw std::runtime_error("Failed to fill console output");
    }

    if (!FillConsoleOutputAttribute(
        this->console_HWND, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written)) {
        throw std::runtime_error("Failed to fill console output attributes");
    }

    // Move the cursor to the top left of the console
    SetConsoleCursorPosition(this->console_HWND, topLeft);
}

// Print to console using std::cout
void MyConsoleAPI::cout(const std::string& data) {
    std::cout << data;
}
void MyConsoleAPI::cout(const std::string& data, int set_Tx_color) {
    set_text_color(set_Tx_color);
    std::cout << data;
}

// Set the console screen color (background and text) using a system call
void MyConsoleAPI::setScreenColor(const char* data) {
    if (system(data) != 0) {
        throw std::runtime_error("Failed to set screen color");
    }
}

// Set text color
void MyConsoleAPI::set_text_color(int data) {
    if (!SetConsoleTextAttribute(this->console_HWND, data)) {
        throw std::runtime_error("Failed to set text attributes");
    }
}
