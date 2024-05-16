#include "MyGames.h"

Hangman::Hangman() : alphabet({ "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T",
		"U", "V", "W", "X", "Y", "Z" }), guessedLetters(std::size(alphabet), false), answer(std::size(answer), false), guess(" "), iteration(0)
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
	if (this->iteration != 0) { this->iteration = 0; }
	do
	{
		this->iteration++;
		drawScreen(checkGuess(get_userGuess()));
	} while (true);
}
/* *** ** * ** *** */
std::string Hangman::get_userGuess() {
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

void Hangman::drawScreen(bool state_DATA) {

}

// QUIZ GAME  ////////////////////////////////////////////////////////
void Quiz::run() {
    gameLoop();
}

Quiz::Quiz() : iteration(0) {
} // Constructor

// Start Private Functions
void Quiz::gameLoop() {
    setupEnviorment();
    do {
        iteration++;
        question(iteration);
    } while (iteration < 3);

    MyConsoleAPI::cout("\nGAME OVER\n\n", red);
    MyConsoleAPI::set_text_color(default_color);
    system("pause"); // Last Instruction before returning to main menu
}

void Quiz::setupEnviorment() {
    MyConsoleAPI::clearScreen();
    MyConsoleAPI::clearInputStream();
    if (iteration != 0) { iteration = 0; }
}

int Quiz::requestInput() {
    std::string guess{};
    int convertedGuess{};
    size_t pos{};
    do {
        MyConsoleAPI::set_text_color(green);
        std::getline(std::cin, guess);
        try
        {
            convertedGuess = std::stoi(guess, &pos);
            if (pos == guess.length()) {
                if (convertedGuess > 3) { MyConsoleAPI::cout("Invalid Number::Out of Range\nTry Again: ", red); MyConsoleAPI::clearInputStream(); continue; }
                break;
            }
            else { throw std::invalid_argument("Invalid Characters after number\nTry Again: "); MyConsoleAPI::clearInputStream(); }
            break;
        }
        catch (const std::invalid_argument& e)
        {
            std::cerr << "Invalid Data::Must Enter an integer\nTry Again: ", e;
            MyConsoleAPI::clearInputStream();
        }
        catch (const std::out_of_range& e)
        {
            std::cerr << "Out of range\nTry Again: ", e;
            MyConsoleAPI::clearInputStream();
        }
    } while (true);
    return convertedGuess;
}

inline void Quiz::question(int questionNumber) {
    switch (questionNumber)
    {
    case 1: askFirstQuestion(); break;
    case 2: askSecondQuestion(); break;
    case 3: askThirdQuestion(); break;
    }
}

void Quiz::askFirstQuestion() {
    MyConsoleAPI::cout("What is the smallest county?\n1. USA\n2. India\n3.Vatican City\nchoose 1-3: ", ice_blue);
    if (requestInput() == 3) {
        MyConsoleAPI::setScreenColor("color 08"); // Gray on black
        MyConsoleAPI::cout("\nCorrect!\n\n", purple);
    }
    else {
        MyConsoleAPI::setScreenColor("color 08"); // Gray on black
        MyConsoleAPI::cout("\nIncorrect\n\n", red);
    }
}

void Quiz::askSecondQuestion() {
    MyConsoleAPI::cout("What's the biggest animal in the worl?\n1. Elephant\n2. Bue whale\n3.Great white shark\nchoose 1-3: ", ice_blue);
    if (requestInput() == 2) {
        MyConsoleAPI::setScreenColor("color 08"); // Gray on black
        MyConsoleAPI::cout("\nCorrect!\n\n", purple);
    }
    else {
        MyConsoleAPI::setScreenColor("color 08"); // Gray on black
        MyConsoleAPI::cout("\nIncorrect\n\n", red);
    }
}

void Quiz::askThirdQuestion() {
    MyConsoleAPI::cout("How many elements are there in the periodic table?\n1. 118\n2. 115\n3. 120\nchoose 1-3: ", ice_blue);
    if (requestInput() == 1) {
        MyConsoleAPI::setScreenColor("color 08"); // Gray on black
        MyConsoleAPI::cout("\nCorrect!\n\n", purple);
    }
    else {
        MyConsoleAPI::setScreenColor("color 08"); // Gray on black
        MyConsoleAPI::cout("\nIncorrect\n\n", red);
    }
}

// END QUIZ GAME  ////////////////////////////////////////////////////////


// Number Guessing Game  ////////////////////////////////////////////////////////   
//  
// Constructor
NumberGenerator::NumberGenerator() : generator(rd()) {}

// Destructor
NumberGenerator::~NumberGenerator() {}

// Member function to return a random number within a range
int NumberGenerator::returnRandomNumber(const int min, const int max) {
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}

// End Number Generator
//
// Start Number Guessing Game  //////////////////////////////////////////////////////
//
NumberGuessingGame::NumberGuessingGame() : randomNumber(0), MAX_GUESSES(5), attempt(0), attemptCount(0) {
    rangeLimit.min = 0;
    rangeLimit.max = 20;
}

NumberGuessingGame::~NumberGuessingGame() {}

void NumberGuessingGame::run() {
    MyConsoleAPI::clearScreen();
    MyConsoleAPI::clearInputStream();
    setGameState();
    gameLoop();
}

void NumberGuessingGame::gameLoop() {
    do {
        attemptCount++;
        if (attemptCount >= MAX_GUESSES) {
            std::cout << "\nFAIL: You are out of guesses\n";
            std::cout << "The number was: " << randomNumber << "\n\n";
            system("pause");
            return;
        }

        std::cout << "\nGuess a number between " << rangeLimit.min << " and " << rangeLimit.max << "\n";
        std::cout << "Enter Guess: ";

        if (!(std::cin >> attempt)) {
            std::cout << "Invalid input. Please enter a valid number.\n";
            // Clear the input stream and reset error flags
            MyConsoleAPI::clearInputStream();
            continue;
        }
        if (attempt < rangeLimit.min || attempt > rangeLimit.max) {
            std::cout << "Input out of range. Please enter a number between 0 and 100.\n";
            continue;
        }
        if (attempt == randomNumber) {
            // Winner winner chicken dinner
            std::cout << "Winner!\n";
            system("pause");
            return;
        }
        else {
            if (attempt < randomNumber) {
                std::cout << "Higher\n";
            }
            else {
                std::cout << "Lower\n";
            }
        }
    } while (true);
}

void NumberGuessingGame::setGameState() {
    randomNumber = returnRandomNumber(rangeLimit.min, rangeLimit.max);
    attemptCount = 0;
    attempt = 0;
}
//
// End Number Guessing Game  ////////////////////////////////////////////////////////
//
// Start CannaCalculator  ////////////////////////////////////////////////////////
//
//
// Constructor
CannaCalculator::CannaCalculator() {}

// Destructor
CannaCalculator::~CannaCalculator() {}

// Public member function to start the program loop
void CannaCalculator::run() {
    programLoop();
}

// Private member function to handle the core program logic
void CannaCalculator::programLoop() {
    char inputChar{};
    double percent_THC{};
    double THC_loss{};
    double gramsFlower{};
    double mgTHC_Gross{};
    double mgTHC_Net{};

    MyConsoleAPI::clearScreen();
    std::cout << "CannaCalculator\n\n"
        << "First, enter the percentage of THCa in your cannabis flower.\n"
        << "Then, enter the total number of grams of flower you will use to infuse oil or butter.\n\n";

    do {
        std::cout << "\nThe default loss is 20%\nWould you like enter a custom loss percentage? (y/n): ";
        if (std::cin >> inputChar && inputChar == 'y') {
            MyConsoleAPI::clearInputStream();
            std::cout << "\nEnter a whole number 0 to 100 for your custom %: ";
            if (std::cin >> THC_loss) {
                THC_loss /= 100; // Convert to a percentage for calculation
                break;
            }
            else {
                MyConsoleAPI::clearInputStream();
                continue;
            }
        }
        else {
            THC_loss = 0.20; // Default loss percentage
            break;
        }
    } while (true);

    do {
        std::cout << "\nFirst: What is the listed THC% of your flower?: ";
        if (std::cin >> percent_THC) {
            break;
        }
        else {
            std::cout << "\nInvalid input" << std::endl;
            MyConsoleAPI::clearInputStream();
        }
    } while (true);

    do {
        std::cout << "Second: How many grams of flower will you be using?: ";
        if (std::cin >> gramsFlower) {
            break;
        }
        else {
            std::cout << "\nInvalid input";
            MyConsoleAPI::clearInputStream();
        }
    } while (true);

    // Calculation logic
    mgTHC_Gross = (percent_THC * 10) * gramsFlower;
    mgTHC_Net = mgTHC_Gross * (1 - THC_loss);

    // Display results
    MyConsoleAPI::clearScreen();
    std::cout << "\n" << percent_THC << "% THCa converts to "
        << static_cast<int>(mgTHC_Gross) << "mg THC per " << static_cast<int>(gramsFlower) << "g of flower before decarboxylation.\n"
        << "and " << static_cast<float>(mgTHC_Net) << "mg THC after decarboxylation\n\n";

    std::cout << "Gross THC\n";
    for (int i = 2; i <= 13; i += 2) {
        std::cout << static_cast<int>(mgTHC_Gross) / i << "mg per " << i << " servings\n";
    }

    std::cout << "NET THC\n";
    for (int i = 2; i <= 13; i += 2) {
        std::cout << static_cast<int>(mgTHC_Net) / i << "mg per " << i << " servings\n";
    }

    std::cout << std::endl;
    system("pause");
}
