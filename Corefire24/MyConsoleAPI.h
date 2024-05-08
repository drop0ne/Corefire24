#pragma once
class MyConsoleAPI
{
private:
	HANDLE console_HWND;
public:
	void clearScreen();
	void cout(std::string output);
	void setScreenColor(const char* cCode);
	void set_text_color(int color_choice);
	void receiveConsoleHWND(HANDLE data);
	void extractInputStream();
private:

protected:
};

