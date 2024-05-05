#pragma once
class Quize
{
private:
	int guess{};

public:
	void run();

private:
	void gameLoop();
	void setupEnviorment();
	int requestInput();
	void question(int answer, int questionNumber);
	void askFirstQuestion();
	void askSecondQuestion();
	void askThirdQuestion();
};