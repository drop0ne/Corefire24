#include "MyConsoleAPI.h"
#include "include.h"

inline void MyConsoleAPI::clearScreen() {system("cls");}

inline void MyConsoleAPI::cout(std::string data) {std::cout << data;}

inline void MyConsoleAPI::setScreenColor(const char* data) {system(data);}

inline void MyConsoleAPI::set_text_color(int data) {SetConsoleTextAttribute(this->console_HWND, data);}

inline void MyConsoleAPI::receiveConsoleHWND(HANDLE data) {this->console_HWND = data;}

inline void MyConsoleAPI::extractInputStream() {
	std::cout << "Contents of input stream: ";
	char c;
	while (std::cin.peek() != EOF) {
		std::cin.get(c);
		std::cout << c;
	}
	std::cout << std::endl;
	return;
}