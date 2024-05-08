#include "MyConsoleAPI.h"
#include "include.h"

MyConsoleAPI::MyConsoleAPI() : console_HWND(NULL)
{
}

inline void MyConsoleAPI::clearScreen() {system("cls");}

inline void MyConsoleAPI::cout(std::string data) {std::cout << data;}

void MyConsoleAPI::setScreenColor(const char* data) {system(data);}

void MyConsoleAPI::set_text_color(int data) {SetConsoleTextAttribute(this->console_HWND, data);}

void MyConsoleAPI::receiveConsoleHWND(HANDLE data) {this->console_HWND = data;}