#pragma once
class MyFunctions : public Utility, public MyConsoleAPI
{
private:
	bool mainProgramLoopCondition{};
	//HANDLE console_HWND = MyConsoleAPI::console_HWND;

	enum colorINT
	{
		default_color = 7, black = 0, dark_green = 2, green = 2, bright_green = 10, blue = 1, bright_red = 12, red = 4, light_blue = 3, ice_blue = 9, teal_blue = 11,
		white = 7, bright_white = 15, gray = 8, purple = 5, yellow = 6, highlight_with_blue_blue = 19, highlight_with_blue_blue2 = 25, highlight_blue_white = 23, check = 27
	};
	/////////////////////////////////////////////////////
public:

	void errorInvalidInput();
	void updateMainProgramLoopCondition(bool data);
	int selectMenuOption();
};
