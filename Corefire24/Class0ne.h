#include "include.h"

class FN
{
private:
	bool mainProgramLoopCondition{};
	HANDLE console_HWND{};
	enum colorINT
	{
		default_color = 7, black = 0, dark_green = 2, green = 2, bright_green = 10, blue = 1, bright_red = 12, red = 4, light_blue = 3, ice_blue = 9, teal_blue = 11, white = 7, bright_white = 15, gray = 8, purple = 5, yellow = 6, highlight_with_blue_blue = 19, highlight_with_blue_blue2 = 25, highlight_blue_white = 23, check = 27
	};
	/////////////////////////////////////////////////////
public:
	FN();
	~FN();

	void clearScreen();
	int selectMenuOption();
	void cout(std::string output);
	void errorInvalidInput();
	void clearInputStream();
	void setScreenColor(const char* cCode);
	void set_text_color(int color_choice);
	void receiveConsoleHWND(HANDLE data);
///////////////////////////////////////////////////// 
private:
	void updateMainProgramLoopCondition(bool data);
	//void extractInputStream();
};
/////////////////////////////////////////////////////

// PUBLIC METHODS /////////////////////////////////////////////////////
FN::FN() :mainProgramLoopCondition(true)
{
}
FN::~FN()
{
}
inline void FN::clearScreen() {
	system("cls");
}
int FN::selectMenuOption() {
	int returnValue{ 0 };
	clearInputStream();

	cout("\nEnter Command: ");
	set_text_color(light_blue);
	if (std::cin >> returnValue) {
		set_text_color(default_color);
		return returnValue;
	}
	else {
		clearInputStream();
		set_text_color(default_color);
		return 0;
	}
}
inline void FN::cout(std::string output) {
	std::cout << output;
}
inline void FN::errorInvalidInput() {
	cout("\nERROR: INVALID INPUT\n");
	clearInputStream();
}
inline void FN::clearInputStream() {
	std::cin.clear();
	if (std::cin.rdbuf()->in_avail() > 0) {
		// If there are characters in the input buffer, discard them up to the next newline
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}
void FN::setScreenColor(const char* cCode) {
	system(cCode);
	return;
}
void FN::set_text_color(int colorDATA) {
	SetConsoleTextAttribute(this->console_HWND, colorDATA);
	return;
}
void FN::receiveConsoleHWND(HANDLE data) {
	this->console_HWND = data;
}

// PRIVATE METHODS  /////////////////////////////////////////////////////

inline void FN::updateMainProgramLoopCondition(bool data) {

	this->mainProgramLoopCondition = data;

	if (mainProgramLoopCondition == data) {
		return;
	}
	else {
		cout("Error: Failed to update manProgramLoopCondition bool private method\n");
		return;
	}
}
/*
inline void FN::extractInputStream() {  //Unused code
	std::cout << "Contents of input stream: ";
	char c;
	while (std::cin.peek() != EOF) {
		std::cin.get(c);
		std::cout << c;
	}
	std::cout << std::endl;
	return;
}
*/