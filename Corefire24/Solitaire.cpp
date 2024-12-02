#include "Solitaire.h"

Solitaire::Solitaire() : storedRandomNumber(42), gameTitleVector(), gameTitleSourceString("Solitaire 2002")
{
	for (auto i : storedRandomNumber) {
		storedRandomNumber.at(i) = getRandomNumber(1, 15);
	}
}

void Solitaire::run() {
	startScreen();
}

// PRIVATE METHODS **********
//
void Solitaire::startScreen() {
	clearScreen();
	print(gameTitleSourceString, Red);
	printLOGO(gameTitleSourceString);
	system("pause");
}

void Solitaire::gameLoop() {

}

void Solitaire::cardShufflingMachine() {

}

void Solitaire::printLOGO(const std::string& title) {
    // Resize the gameTitleVector and populate with characters from title
    this->gameTitleVector.resize(title.size());
    
    for (size_t i = 0; i < title.size(); i++) {
        gameTitleVector.at(i) = std::string(1, title.at(i));
    }

    // Initialize cursor position variables
    int j = 0;
    int cursorPOS = 0;

    // Loop through storedRandomNumber to display characters
    for (auto l : this->storedRandomNumber) {
        // Set text color using the random value
        setMyTextColor(this->storedRandomNumber.at(l));

        // Display characters from gameTitleVector
        if (j < gameTitleVector.size()) {
            // Set cursor position
            COORD coord = { static_cast<SHORT>(cursorPOS), 0 };
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cursorPOS++;

            // Print the character
            std::cout << gameTitleVector[j];
            j++;
            sleepTimer(0250); // 1000:1 Millisecounds

            // Reset loop variables when reaching the end of the title
            if (j >= gameTitleVector.size()) {
                j = 0;
                cursorPOS = 0;
            }
        }
    }
}