#include "Quize.h"
#include "include.h"


void Quize::run() {
	system("cls");
	gameLoop();
}

Quize::Quize() : iteration(0) {}
// Start Private Functions
void Quize::gameLoop() {
	setupEnviorment();
	do {
		this->iteration++;
		question(this->iteration);
	} while (this->iteration < 3);
	std::cout << "\nGAME OVER\n\n";
	system("pause");
}

void Quize::setupEnviorment() {
	clearInputStream();
	if (this->iteration != 0) { this->iteration = 0; }
}

int Quize::requestInput() {
	std::string guess{};
	int convertedGuess{};
	size_t pos{};
	do {
		std::getline(std::cin, guess);
		try
		{
			convertedGuess = std::stoi(guess, &pos);
			if (pos == guess.length()) {
				if (convertedGuess > 3) { std::cout << "Invalid Number::Out of Range\nTry Again: "; clearInputStream();continue; }
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
	switch (questionNumber)
	{
	case 1: askFirstQuestion(); break;
	case 2: askSecondQuestion(); break;
	case 3: askThirdQuestion(); break;
	}
}

void Quize::askFirstQuestion() {
	cout("What is the smallest county?\n1. USA\n2. India\n3.Vatican City\nchoose 1-3: ", default_color);
	if (requestInput() == 3) { std::cout << "\nCorrect!\n" << std::endl;}
	else { std::cout << "\nIncorrect\n" << std::endl;}
}

void Quize::askSecondQuestion() {
	std::cout << "What's the biggest animal in the worl?\n1. Elephant\n2. Bue whale\n3.Great white shark\nchoose 1-3: ";
	if (requestInput() == 2) { std::cout << "\nCorrect!\n" << std::endl;}
	else { std::cout << "\nIncorrect\n" << std::endl; }
}

void Quize::askThirdQuestion() {
	std::cout << "How many elements are there in the periodic table?\n1. 118\n2. 115\n3. 120\nchoose 1-3: ";
	if (requestInput() == 1) { std::cout << "\nCorrect!\n" << std::endl;}
	else { std::cout << "\nIncorrect\n" << std::endl; }
}
