#include "Quize.h"
#include "MyHeaders.h"

Inheritance fn; // Global Object of Inheritance Class

void Quize::run() { // Entry point *************
	gameLoop();
}

Quize::Quize() : iteration(0) {
} // Constructor

// Start Private Functions
void Quize::gameLoop() {
	setupEnviorment();
	do {
		iteration++;
		question(iteration);
	} while (iteration < 3);
	std::cout << "\nGAME OVER\n\n";
	system("pause"); // Last Instruction before returning to main menu
}

void Quize::setupEnviorment() {
	fn.clearScreen();
	fn.clearInputStream();
	if (iteration != 0) { iteration = 0; }
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
				if (convertedGuess > 3) { std::cout << "Invalid Number::Out of Range\nTry Again: "; fn.clearInputStream(); continue; }
				break;
			}
			else { throw std::invalid_argument("Invalid Characters after number\nTry Again: "); fn.clearInputStream();}
			break;
		}
		catch (const std::invalid_argument& e)
		{
			std::cerr << "Invalid Data::Must Enter an integer\nTry Again: ";
			fn.clearInputStream();
		}
		catch (const std::out_of_range& e)
		{
			std::cerr << "Out of range\nTry Again: ";
			fn.clearInputStream();
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
	fn.cout("What is the smallest county?\n1. USA\n2. India\n3.Vatican City\nchoose 1-3: ", default_color);
	if (requestInput() == 3) { std::cout << "\nCorrect!\n" << std::endl;}
	else { std::cout << "\nIncorrect\n" << std::endl;}
}

void Quize::askSecondQuestion() {
	fn.cout ("What's the biggest animal in the worl?\n1. Elephant\n2. Bue whale\n3.Great white shark\nchoose 1-3: ");
	if (requestInput() == 2) { std::cout << "\nCorrect!\n" << std::endl;}
	else { std::cout << "\nIncorrect\n" << std::endl; }
}

void Quize::askThirdQuestion() {
	fn.cout("How many elements are there in the periodic table?\n1. 118\n2. 115\n3. 120\nchoose 1-3: ");
	if (requestInput() == 1) { std::cout << "\nCorrect!\n" << std::endl;}
	else { std::cout << "\nIncorrect\n" << std::endl; }
}
