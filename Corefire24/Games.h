#pragma once
#include "include.h"

#ifndef GAMES
#define GAMES


class Hangman : public MyConsoleAPI
{
public:
	Hangman();
	~Hangman();
	/* ******* */

	void run(); // Main entry point for the game

private:
	std::vector<std::string> alphabet;
	std::vector<bool> guessedLetters;
	std::vector<bool> answer;
	std::string guess;

	/* *** Memory / Private Methods *** */

	void gameLoop();
	std::string userGuess();
	bool checkGuess(std::string guess);
	void update_draw(bool state_DATA);



};

#endif // GAMES