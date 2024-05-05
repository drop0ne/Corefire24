#pragma once
class Quize
{
private:
	int guess{0};
	int iteration{0};

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
};