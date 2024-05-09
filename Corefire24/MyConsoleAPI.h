#pragma once
class MyConsoleAPI
{
private:
	HANDLE console_HWND;

public:
	void clearScreen();
	void cout(std::string data);
	void setScreenColor(const char* color_choice);
	virtual void set_text_color(int color_choice);
	virtual void receiveConsoleHWND(HANDLE data);
private:

protected:
};

