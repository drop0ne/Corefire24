#include "Quize.h"
#include "include.h"
void Quize::run() {
	system("cls");
	gameLoop();
}
void Quize::gameLoop() {
	setupEnviorment();
	do {
		this->iteration++;
		question(this->iteration);
	} while (this->iteration < 3);
	cout << "\nGAME OVER\n\n";
	system("pause");
}
void Quize::setupEnviorment() {
	clearInputStream();
	if (this->iteration != 0) { this->iteration = 0; }
}
int Quize::requestInput() {
	string guess{};
	int convertedGuess{};
	size_t pos{};
	do {
		getline(cin, guess);
		try
		{
			convertedGuess = std::stoi(guess, &pos);
			if (pos == guess.length()) {
				if (convertedGuess > 3) { cout << "Invalid Number::Out of Range\nTry Again: "; clearInputStream();continue; }
				break;
			}
			else { throw std::invalid_argument("Invalid Characters after number\nTry Again: "); clearInputStream();}
			break;
		}
		catch (const std::invalid_argument& e)
		{
			std::cerr << "Invalid Data::Must Enter an integer\nTry Again: ";
			clearInputStream();
		}
		catch (const std::out_of_range& e)
		{
			std::cerr << "Out of range\nTry Again: ";
			clearInputStream();
		}
	} while (true);
	return convertedGuess;
}
inline void Quize::question(int questionNumber) {
	this->flag = true;
	do {
	switch (questionNumber)
	{
	case 1: askFirstQuestion(); break;
	case 2: askSecondQuestion(); break;
	case 3: askThirdQuestion(); break;
	}
	} while (this->flag);
}
void Quize::askFirstQuestion() {
	cout << "What is the smallest county?\n1. USA\n2. India\n3.Vatican City\nchoose 1-3: ";
	if (requestInput() == 3) { cout << "\nCorrect!\n" << endl;}
	else {cout << "\nIncorrect\n" << endl;}
	this->flag = false;
}
void Quize::askSecondQuestion() {
	cout << "What's the biggest animal in the worl?\n1. Elephant\n2. Bue whale\n3.Great white shark\nchoose 1-3: ";
	if (requestInput() == 2) { cout << "\nCorrect!\n" << endl;}
	else { cout << "\nIncorrect\n" << endl; }
	this->flag = false;
}
void Quize::askThirdQuestion() {
	cout << "How many elements are there in the periodic table?\n1. 118\n2. 115\n3.120\nchoose 1-3: ";
	if (requestInput() == 1) { cout << "\nCorrect!\n" << endl;}
	else { cout << "\nIncorrect\n" << endl; }
	this->flag = false;
}
inline void Quize::clearInputStream() {
	std::cin.clear();
	if (std::cin.rdbuf()->in_avail() > 0) {
		// If there are characters in the input buffer, discard them up to the next newline
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}