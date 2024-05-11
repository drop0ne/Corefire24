#include "programExtensions.h"

#undef max() // This is a macro that prevents the max macro from being defined

// Init Global Object
MyConsoleAPI_extended fn;


// Constructor
MyConsoleAPI::MyConsoleAPI() {
    console_HWND = GetStdHandle(STD_OUTPUT_HANDLE);
    if (console_HWND == INVALID_HANDLE_VALUE) {
        throw std::runtime_error("Failed to get standard output handle");
    }
}

// Clear the console screen using Windows API for better performance and security
void MyConsoleAPI::clearScreen() {
    COORD topLeft = { 0, 0 };
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    if (!GetConsoleScreenBufferInfo(console_HWND, &screen)) {
        throw std::runtime_error("Failed to get console buffer info");
    }

    DWORD area = screen.dwSize.X * screen.dwSize.Y;
    if (!FillConsoleOutputCharacter(console_HWND, ' ', area, topLeft, &written) ||
        !FillConsoleOutputAttribute(console_HWND, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE, area, topLeft, &written)) {
        throw std::runtime_error("Failed to clear console screen");
    }

    SetConsoleCursorPosition(console_HWND, topLeft);
}

// Print to console using std::cout
void MyConsoleAPI::cout(const std::string& data) {
    std::cout << data;
}
void MyConsoleAPI::cout(const std::string& data, const int textColor) {
    set_text_color(textColor);
    std::cout << data;
}

// Set the console screen color (background and text) using a system call
void MyConsoleAPI::setScreenColor(int backgroundColor, int textColor) {
    if (!SetConsoleTextAttribute(console_HWND, backgroundColor | textColor)) {
        throw std::runtime_error("Failed to set screen color");
    }
}
/*
void MyConsoleAPI::setScreenColor(const char* data) {
    if (system(data) != 0) {
        throw std::runtime_error("Failed to set screen color");
    }
}
*/
// Set text color
void MyConsoleAPI::set_text_color(int data) {
    if (!SetConsoleTextAttribute(console_HWND, data)) {
        throw std::runtime_error("Failed to set text attributes");
    }
}

void MyConsoleAPI::clearInputStream() {
    std::cin.clear();
    if (std::cin.rdbuf()->in_avail() > 0) {
        // If there are characters in the input buffer, discard them up to the next newline
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void MyConsoleAPI::extractInputStream() {
    std::cout << "Contents of input stream: ";
    char c;
    while (std::cin.peek() != EOF) {
        std::cin.get(c);
        std::cout << c;
    }
}


#include "MyConsoleAPI_extended.h"

MyConsoleAPI_extended::MyConsoleAPI_extended() : MyConsoleAPI() {
    // Constructor
}

void MyConsoleAPI_extended::errorInvalidInput() {
    MyConsoleAPI_extended::cout("\nERROR: INVALID INPUT\n", red);
    MyConsoleAPI_extended::clearInputStream();
}

int MyConsoleAPI_extended::selectMenuOption() {
    int returnValue{ 0 };

    MyConsoleAPI_extended::cout("\nEnter Command: ", light_blue);
    if (std::cin >> returnValue) {
        return returnValue;
    }
    else {
        MyConsoleAPI_extended::clearInputStream();
        return 0;
    }
}


#include "Quize.h"

MyConsoleAPI fn; // Global Object of Inheritance Class

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
			else { throw std::invalid_argument("Invalid Characters after number\nTry Again: "); fn.clearInputStream(); }
			break;
		}
		catch (const std::invalid_argument& e)
		{
			std::cerr << "Invalid Data::Must Enter an integer\nTry Again: ", e;
			fn.clearInputStream();
		}
		catch (const std::out_of_range& e)
		{
			std::cerr << "Out of range\nTry Again: ", e;
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
	if (requestInput() == 3) { std::cout << "\nCorrect!\n" << std::endl; }
	else { std::cout << "\nIncorrect\n" << std::endl; }
}

void Quize::askSecondQuestion() {
	fn.cout("What's the biggest animal in the worl?\n1. Elephant\n2. Bue whale\n3.Great white shark\nchoose 1-3: ");
	if (requestInput() == 2) { std::cout << "\nCorrect!\n" << std::endl; }
	else { std::cout << "\nIncorrect\n" << std::endl; }
}

void Quize::askThirdQuestion() {
	fn.cout("How many elements are there in the periodic table?\n1. 118\n2. 115\n3. 120\nchoose 1-3: ");
	if (requestInput() == 1) { std::cout << "\nCorrect!\n" << std::endl; }
	else { std::cout << "\nIncorrect\n" << std::endl; }
}


// Constructor
NumberGenerator::NumberGenerator() : generator(rd()) {}

// Destructor
NumberGenerator::~NumberGenerator() {}

// Member function to return a random number within a range
int NumberGenerator::returnRandomNumber(int min, int max) {
	std::uniform_int_distribution<int> distribution(min, max);
	return distribution(generator);
}


#include "NumberGuessingGame.h"

NumberGuessingGame::NumberGuessingGame() : randomNumber(0), MAX_GUESSES(5), attempt(0), attemptCount(0) {
    rangeLimit.min = 0;
    rangeLimit.max = 20;
}

NumberGuessingGame::~NumberGuessingGame() {}

void NumberGuessingGame::run() {
    fn.clearScreen();
    fn.clearInputStream();
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
            fn.clearInputStream();
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

    MyConsoleAPI fn;

    fn.clearScreen();
    std::cout << "CannaCalculator\n\n"
        << "First, enter the percentage of THCa in your cannabis flower.\n"
        << "Then, enter the total number of grams of flower you will use to infuse oil or butter.\n\n";

    do {
        std::cout << "\nThe default loss is 20%\nWould you like enter a custom loss percentage? (y/n): ";
        if (std::cin >> inputChar && inputChar == 'y') {
            fn.clearInputStream();
            std::cout << "\nEnter a whole number 0 to 100 for your custom %: ";
            if (std::cin >> THC_loss) {
                THC_loss /= 100; // Convert to a percentage for calculation
                break;
            }
            else {
                fn.clearInputStream();
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
            fn.clearInputStream();
        }
    } while (true);

    do {
        std::cout << "Second: How many grams of flower will you be using?: ";
        if (std::cin >> gramsFlower) {
            break;
        }
        else {
            std::cout << "\nInvalid input";
            fn.clearInputStream();
        }
    } while (true);

    // Calculation logic
    mgTHC_Gross = (percent_THC * 10) * gramsFlower;
    mgTHC_Net = mgTHC_Gross * (1 - THC_loss);

    // Display results
    fn.clearScreen();
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