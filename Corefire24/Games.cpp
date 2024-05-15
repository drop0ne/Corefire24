#include "Games.h"

Hangman::Hangman() : Alphabet({ "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T",
		"U", "V", "W", "X", "Y", "Z" }), guessedLetters(26, true), answer(26, false), guess(" ")
{
}

Hangman::~Hangman()
{
}