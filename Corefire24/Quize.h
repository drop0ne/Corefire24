#pragma once
class Quize
{
private:
	int iteration{0};
	bool flag{};

public:
	void run();

private:
	void gameLoop();
	void setupEnviorment();
	int requestInput();
	void question(int questionNumber);
	void askFirstQuestion();
	void askSecondQuestion();
	void askThirdQuestion();
	void clearInputStream();
};