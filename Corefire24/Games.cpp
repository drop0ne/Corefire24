#include "Games.h"

Hangman::Hangman() : alphabet({ "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T",
		"U", "V", "W", "X", "Y", "Z" }), guessedLetters(std::size(alphabet), false), answer(std::size(answer), false), guess(" ")
{
}

Hangman::~Hangman() {
	this->alphabet.clear();
	this->guessedLetters.clear();
	this->answer.clear();
	this->guess.clear();
	
}

void Hangman::run() {
	gameLoop();
}

void Hangman::gameLoop() {
	// LOOP
}
/* *** ** * ** *** */
std::string Hangman::userGuess() {
	do
	{
		MyConsoleAPI::clearInputStream();
		try
		{
			std::getline(std::cin, guess);
			return guess;
		}
		catch (const std::exception&)
		{
			std::cout << "Invalid input. Please try again." << std::endl;
			continue;
		}
	} while (true);

	return guess;
}

bool Hangman::checkGuess(std::string guess) {
	for (size_t i = 0; i < std::size(alphabet);)
	{
		if (guess == alphabet.at(i)) {
			guessedLetters[i] = true;
			if (guessedLetters [i] == answer[i]) {
				return true;
			}
			else {
				return false;
			}						
		}
	}
	return false;
}

void update_draw(bool state_DATA) {

}