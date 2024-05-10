#pragma once

class Quize : public Utility, public MyConsoleAPI {
private:
	int iteration;

public:
	void run();
	Quize();

private:
	void gameLoop();
	void setupEnviorment();
	int requestInput();
	void question(int questionNumber);
	void askFirstQuestion();
	void askSecondQuestion();
	void askThirdQuestion();
};