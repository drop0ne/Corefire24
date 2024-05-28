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
    MyConsoleAPI::clearScreen();
	MyConsoleAPI::print("Hangman\n\n", Magenta);
    MyConsoleAPI::print("Guess a letter of the Alphabet");

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

    MyConsoleAPI::print("\nGAME OVER\n\n", Red);
    MyConsoleAPI::set_text_color(LightGray);
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
        MyConsoleAPI::set_text_color(Green);
        std::getline(std::cin, guess);
        try
        {
            convertedGuess = std::stoi(guess, &pos);
            if (pos == guess.length()) {
                if (convertedGuess > 3) { MyConsoleAPI::print("Invalid Number::Out of Range\nTry Again: ", Red); MyConsoleAPI::clearInputStream(); continue; }
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
    MyConsoleAPI::print("What is the smallest county?\n1. USA\n2. India\n3.Vatican City\nchoose 1-3: ", Cyan);
    if (requestInput() == 3) {
        MyConsoleAPI::setScreenColor("color 08"); // Gray on black
        MyConsoleAPI::print("\nCorrect!\n\n", Magenta);
    }
    else {
        MyConsoleAPI::setScreenColor("color 08"); // Gray on black
        MyConsoleAPI::print("\nIncorrect\n\n", Red);
    }
}

void Quiz::askSecondQuestion() {
    MyConsoleAPI::print("What's the biggest animal in the worl?\n1. Elephant\n2. Bue whale\n3.Great white shark\nchoose 1-3: ", Cyan);
    if (requestInput() == 2) {
        MyConsoleAPI::setScreenColor("color 08"); // Gray on black
        MyConsoleAPI::print("\nCorrect!\n\n", Magenta);
    }
    else {
        MyConsoleAPI::setScreenColor("color 08"); // Gray on black
        MyConsoleAPI::print("\nIncorrect\n\n", Red);
    }
}

void Quiz::askThirdQuestion() {
    MyConsoleAPI::print("How many elements are there in the periodic table?\n1. 118\n2. 115\n3. 120\nchoose 1-3: ", Cyan);
    if (requestInput() == 1) {
        MyConsoleAPI::setScreenColor("color 08"); // Gray on black
        MyConsoleAPI::print("\nCorrect!\n\n", Magenta);
    }
    else {
        MyConsoleAPI::setScreenColor("color 08"); // Gray on black
        MyConsoleAPI::print("\nIncorrect\n\n", Red);
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
int NumberGenerator::getRandomNumber(const int min, const int max) {
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

inline void NumberGuessingGame::gameLoop() {
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

inline void NumberGuessingGame::setGameState() {
    randomNumber = getRandomNumber(rangeLimit.min, rangeLimit.max);
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
CannaCalculator::CannaCalculator()
{

}

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

CalculatePowerLoss_Watts_x_Meters::CalculatePowerLoss_Watts_x_Meters() {}

CalculatePowerLoss_Watts_x_Meters::~CalculatePowerLoss_Watts_x_Meters() {}

void CalculatePowerLoss_Watts_x_Meters::run() {
    menu();
}

/* Start Private Methods */
long double CalculatePowerLoss_Watts_x_Meters::requestInput(std::string stringMessagePrompt, int promptColor,int inputColor) {
    long double input{};
    while (true) {
        print(stringMessagePrompt, promptColor);
        set_text_color(inputColor);
        std::cin >> input;
        if (std::cin.fail() || input <= 0) {
            print("Invalid input. Please enter a positive number for resistivity.\n", Red);
            clearInputStream();
        }
        else {
            break;
        }
    }
    return input;
}

auto CalculatePowerLoss_Watts_x_Meters::setProperties() -> BaseLongDoubles {
    BaseLongDoubles properties_m;
    clearScreen();
    print("Set Properties!\n\n", Green);
    // Resistivity input
    properties_m.resistivity_ohm = requestInput("Enter the resistivity of the wire in ohm: ",  /*Text Prompt Color*/ LightGray,  /*Input Number Color*/ LightBlue);
    // Current input
    properties_m.current_amps = requestInput("Enter the current in voltage: ", LightGray, LightBlue);
    // Length input
    properties_m.length_meters = requestInput("Enter the length of the wire in meters: ", LightGray, LightBlue);
    // Cross-sectional area input
    properties_m.crossSectionalArea_sqr_meter = requestInput("Enter the cross-sectional area of the wire in square meters: ", LightGray, LightBlue);
    clearInputStream();
    return properties_m;
}

void CalculatePowerLoss_Watts_x_Meters::performCalculation(BaseLongDoubles& baseNumbers) {
    ConvertionsLongDoubles convertions;
    // Calculations
    convertions.resistance = baseNumbers.resistivity_ohm * baseNumbers.length_meters / baseNumbers.crossSectionalArea_sqr_meter; // ohms
    convertions.powerLossTotal = std::powl(baseNumbers.current_amps, 2) * convertions.resistance; // watts
    convertions.powerLossPerMeter = convertions.powerLossTotal / baseNumbers.length_meters; // watts per meter

    // Conversion of Power Loss per meter to different units
    convertions.powerLossPerCentimeter = convertions.powerLossPerMeter / 100.0L; // watts per cm
    convertions.powerLossPerInch = convertions.powerLossPerMeter / 39.3701L; // watts per inch
    convertions.powerLossMilliwattsPerMeter = convertions.powerLossPerMeter * 1000.0L; // milliwatts per meter

    // Total Power Loss for Different Lengths of Wire
    long double lengths[] = { 500.0L, 1000.0L, 2000.0L }; // meters
    long double powerLossForLengths[3];
    for (int i = 0; i < 3; ++i) {
        powerLossForLengths[i] = std::powl(baseNumbers.current_amps, 2) * baseNumbers.resistivity_ohm * lengths[i] / baseNumbers.crossSectionalArea_sqr_meter; // watts
    }

    // Effect of Different Currents on Power Loss
    long double currents[] = { 5.0L, 10.0L, 20.0L }; // amperes
    long double powerLossForCurrents[3];
    for (int i = 0; i < 3; ++i) {
        powerLossForCurrents[i] = std::powl(currents[i], 2) * convertions.resistance; // watts
    }

    // Effect of Different Cross-sectional Areas on Power Loss
    long double crossSections[] = { 0.002L, 0.001L, 0.0005L }; // square meters
    long double powerLossForCrossSections[3];
    for (int i = 0; i < 3; ++i) {
        powerLossForCrossSections[i] = std::powl(baseNumbers.current_amps, 2) * baseNumbers.resistivity_ohm * baseNumbers.length_meters / crossSections[i]; // watts
    }

    // Effect of Different Resistivities on Power Loss
    long double resistivities[] = { 1.68e-8L, 2.82e-8L, 1.59e-8L }; // ohm meters for copper, aluminum, silver
    long double powerLossForResistivities[3];
    for (int i = 0; i < 3; ++i) {
        powerLossForResistivities[i] = std::powl(baseNumbers.current_amps, 2) * resistivities[i] * baseNumbers.length_meters / baseNumbers.crossSectionalArea_sqr_meter; // watts
    }






    printResults(convertions.powerLossTotal, baseNumbers);
    clearInputStream();
}

long double CalculatePowerLoss_Watts_x_Meters::calculatePowerLoss(BaseLongDoubles& baseNumbers) {
    // Calculate resistance
    long double resistance = baseNumbers.resistivity_ohm * baseNumbers.length_meters / baseNumbers.crossSectionalArea_sqr_meter;
    // Calculate power loss
    long double powerLoss = std::powl(baseNumbers.current_amps, 2) * resistance;
    return powerLoss;
}

void CalculatePowerLoss_Watts_x_Meters::printResults(const long double powerLoss, BaseLongDoubles& baseNumbers) {
    clearScreen();
    print("Calculate Power Loss in a copper wire as heat measured in Watts per Meter\n\n", Green);
    print("Resistivity            ", DarkGray); print(baseNumbers.resistivity_ohm, Brown); print(" * meters\n", Brown);
    print("Current                ", DarkGray); print(baseNumbers.current_amps, Brown); print("   voltage\n", LightBlue);
    print("Length                 ", DarkGray); print(baseNumbers.length_meters, Brown); print("   meters\n", LightBlue);
    print("Cross-sectional Area   ", DarkGray); print(baseNumbers.crossSectionalArea_sqr_meter, Brown); print("   square meters\n\n", LightBlue);
    print("Power Loss as heat: ", LightGray); print(powerLoss, LightBlue); print(" Watts\n\n", LightGray);
    system("pause");
}

inline void CalculatePowerLoss_Watts_x_Meters::information() {
    clearScreen();
	print("Information!\n\n", Green);
	print("This program calculates the power loss in watts per meter of a wire given the resistivity, current, length, and cross-sectional area.\n\n", LightBlue);
	print("The formula used is:\n", LightBlue);
	print("Power Loss = I^2 * R\n\n", Brown);
	print("Where:\n", LightBlue);
	print("I = Current in voltage\n", Brown);
	print("R = Resistance in ohms\n\n", Brown);
	print("The resistance is calculated using the formula:\n", LightBlue);
	print("R = resistivity * length / cross-sectional area\n\n", Brown);
	print("The resistivity of copper is 1.68e-8 ohm.\n\n", Brown);
    set_text_color(LightGray);	system("pause");
}

inline int CalculatePowerLoss_Watts_x_Meters::returnMenuOption() {
    std::string input{};
    int convertedInput{};
    int inputLenghtLimit{ 1 };

    do {
        print("Enter a number: ", LightGray);
        set_text_color(LightBlue);
        if (std::getline(std::cin, input)) {
            if (input.length() > inputLenghtLimit) {
                print("Invalid input. Please enter a number from 1 to 4.\n", LightGreen);
                clearInputStream();
                continue;
            }
            try
            {
                convertedInput = std::stoi(input);
                break;
            }
            catch (const std::invalid_argument& e)
            {
                std::cerr << "Invalid input. Please enter a number.\n";
                clearInputStream();
            }
            catch (const std::out_of_range& e) // need to build a logging system
            {
                std::cerr << "Out of range. Please enter a number.\n";
                clearInputStream();
            }
        }
        else {
            std::cerr << "Invalid input. Please enter a number.\n";
            clearInputStream();
        }
    } while (true);

    return convertedInput;
}


inline void CalculatePowerLoss_Watts_x_Meters::menu() {
    BaseLongDoubles properties_m;
    do
    {
        clearInputStream();
        clearScreen();
        print("Calculate Power Loss in a copper wire as heat measured in Watts per Meter\n\n", Green);
        print("1. ", LightBlue); print("Set Properties\n", LightGray);
        print("2. ", LightBlue); print("Calculate Power Loss\n", LightGray);
        print("3. ", LightBlue); print("Information\n", LightGray);
        print("4. ", LightBlue); print("Return to Main Menu\n\n", LightGray);

        switch (returnMenuOption())
        {
        case 1: properties_m = setProperties();
        case 2: performCalculation(properties_m); break;
        case 3: information(); break;
        case 4: clearInputStream(); return;
        default: print("Invalid input. Please enter a number from 1 to 4.\n", LightGreen); system("pause");
            break;
        }
    } while (true);
}
