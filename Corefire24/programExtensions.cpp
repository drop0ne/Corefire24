#include "programExtensions.h"


// Init Global Object
static MyConsoleAPI_extension fn;

// Constructor
MyConsoleAPI::MyConsoleAPI() : threadLimit(8) {
    console_HWND = GetStdHandle(STD_OUTPUT_HANDLE);
    if (console_HWND == INVALID_HANDLE_VALUE) {
        throw std::runtime_error("Failed to get standard output handle");
    }
    threadID_vector.resize(threadLimit);/* plus one to account for the main thread plus the reservasion */
    threadID_vector[MainThread] = std::this_thread::get_id();/* Set The ID for the calling thread of exacution -- should be the main thread */
    thread_vector.resize(threadLimit);
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

void MyConsoleAPI::cout(const std::string& string1, const int& textColor1, const std::string& string2, const int& textColor2,
    const std::string& string3, const int& textColor3, const std::string& string4, const int& textColor4) {
    /* Custom cout for -- void generateMainMenu(const std::vector<int>& stateData); */
    set_text_color(textColor1);
    std::cout << string1;
    set_text_color(textColor2);
    std::cout << string2;
    set_text_color(textColor3);
    std::cout << string3;
    set_text_color(textColor4);
    std::cout << string4;
}


/*
// Set the console screen color (background and text) using a system call
void setScreenColor(int backgroundColor, int textColor) {
    // Validate input ranges (assumed range for demonstration)
    if (backgroundColor < 0 || backgroundColor > 255 || textColor < 0 || textColor > 255) {
        throw std::invalid_argument("Color values out of range");
    }
    HANDLE console_HWND = GetStdHandle(STD_OUTPUT_HANDLE);
    if (console_HWND == INVALID_HANDLE_VALUE) {
        throw std::runtime_error("Failed to get standard output handle");
    }

    // Attempt to set the console text attribute
    BOOL result = SetConsoleTextAttribute(console_HWND, backgroundColor | textColor);
    if (!result) {
        throw std::runtime_error("Failed to set screen color");
    }
}
*/


void MyConsoleAPI::setScreenColor(const char* data) {
    try {
        // Validate the input before executing
        if (!isValidCommand(data)) {
            throw std::invalid_argument("Invalid command for screen color.");
        }
        // Execute the system command
        int result = system(data);
        if (result != 0) { // Check system() return value
            throw std::runtime_error("Failed to execute system command.");
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

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
void MyConsoleAPI::passFunction_toThread_new(void (function)()) {
    thread_vector.push_back(std::thread(function));
    //  todo: save thread ID to threadID_vector
}

// END Public Functions // Start Private Functions

bool MyConsoleAPI::isValidCommand(const char* command) {
    // List of allowed commands for setting screen colors, now including gray
    const std::vector<std::string> allowedCommands = {
        "color 0A", // Light green on black
        "color 0B", // Light aqua on black
        "color 0C", // Light red on black
        "color 0D", // Light purple on black
        "color 0E", // Light yellow on black
        "color 0F", // Bright white on black
        "color 08"  // Gray on black
    };

    // Check if the command is in the list of allowed commands
    for (const auto& cmd : allowedCommands) {
        if (cmd == command) {
            return true;
        }
    }
    return false;
}



//********************************************************************************************************************************************  < MyConsoleAPI_extended >   05/12/24

/*************************************************************/
/*                   < MyConsoleAPI_extended >               */
/*                         ****$****                         */
/*                      < Constructor >                      */
/*                     < Main Menu API >                     */
/*************************************************************/

MyConsoleAPI_extension::MyConsoleAPI_extension() : FLAGS_theme({/*them_default(0)*/true, /*themeRandom(1)*/false, /*themeRainbow(2)*/false }),
mainMenu_totalParameters(7), mainMenuParameterState({/*options(0)*/GREEN, /*programID(1)*/DARK_MAGENTA, /*program(2)*/CYAN,
    /*exitID(3)*/DARK_RED, /*exit(4)*/LIGHT_GRAY, /*objects(5)*/WHITE, /*errorMessages(6)*/RED })
{
    /* Initializing the main menu's theme state into a vector, set number_of_state_parameters equal to total number of default elements */
    mainMenu_defaultParameterState = mainMenuParameterState;
    FLAGS_theme_atomic.resize(threadLimit);
    FLAGS_theme_atomic.emplace_back(std::make_unique<std::atomic<bool>>(true)); // MainThread
    FLAGS_theme_atomic.emplace_back(std::make_unique<std::atomic<bool>>(true)); // ThemeThread
}
void MyConsoleAPI_extension::invalid_Input() {
    cout("\nERROR: INVALID INPUT\n", RED);
    clearInputStream();
}

void MyConsoleAPI_extension::setMainMenuState(const std::vector<int> newState) {
    cout("Setting new state\n");
    for (size_t i = 0; i < mainMenuParameterState.size(); i++)
    {
        mainMenuParameterState[i] = newState[i];
    }
    system("pause");
}

void MyConsoleAPI_extension::generateMainMenu(const std::vector<int>& stateData) {
    /* StateDate.at( recieves and int ) to identify group to apply color state change to */
    /* Using enum eMainMenu_State_ID Options(0), ProgramID1), Program(2), ExitProgramID(3), ExitProgram(4), Symbols(5), ErrorMessage(6) */

    /* cout has three overloads as of 2024/05/12 */
    /* cout(string, int, string, int, string, int, string, int) */
    /* cout(string, int, string, int) */
    /* cout(string, int) */

    cout("CoreFireCode 2024 edition\n", GREEN);
    cout("\n\nMain Menu\n\n", WHITE);
    cout("Option", stateData.at(Options), " 1 ", stateData.at(ProgramID), "-", stateData.at(Symbols), " Number Gussing Game\n", stateData.at(Program));
    cout("Option", stateData.at(Options), " 2 ", stateData.at(ProgramID), "-", stateData.at(Symbols), " CannabisCalculator\n",  stateData.at(Program));
    cout("Option", stateData.at(Options), " 3 ", stateData.at(ProgramID), "-", stateData.at(Symbols), " Quiz\n",                stateData.at(Program));
    cout("Option", stateData.at(Options), " 4 ", stateData.at(ProgramID), "-", stateData.at(Symbols), " Random Menu Theme\n",   stateData.at(Program));
    cout("Option", stateData.at(Options), " 5 ", stateData.at(ProgramID), "-", stateData.at(Symbols), " Default Menu Theme\n",  stateData.at(Program));
    cout("Option", stateData.at(Options), " 9 ", stateData.at(ExitProgramID), "-", stateData.at(Symbols), " Exit\n",        stateData.at(ExitProgram));
}

void MyConsoleAPI_extension::setThemeFlag(const int themeFlag_ID) {
    try
    {
        if (!FLAGS_theme.empty())
        {
            for (size_t i = 0; i < FLAGS_theme.size(); i++)
            {
                try
                {
                    if (FLAGS_theme.at(themeFlag_ID))
                    {
                        FLAGS_theme.at(themeFlag_ID) = true; // Set the callers ID theme to true
                    }
                    else
                    {
                        FLAGS_theme.at(i) = false; // Set all other themes to false
                    }
                }
                catch (const std::exception&)
                {

                }
            }//end of for loop

        }
        else
        {

        }
    }
    catch (const std::exception&)
    {

    }

}

void MyConsoleAPI_extension::callTheme_by_Flag_ID(const int& themeFlag_ID) {
    switch (themeFlag_ID)
    {
    case 0:  setThemeFlag(defaultTheme); menuTheme_Default(); break;
    case 1:  setThemeFlag(RandomTheme);  menuTheme_Random(); break;
    case 2:  setThemeFlag(RainbowTheme); menuTheme_Rainbow(); break;
    default: setThemeFlag(defaultTheme); menuTheme_Default(); break;
	}
}

/*************************************************************/
/*      END OF PUBLIC METHODS FOR MyConsolAPI_Enstension     */
/*                         ****$****                         */
/*     START OF PRIVATE METHODS FOR MyConsoleAPI_Exstension  */
/*************************************************************/

void MyConsoleAPI_extension::menuTheme_Default() {
    setThemeFlag(defaultTheme);

    for (size_t i = 0; i < mainMenuParameterState.size(); i++)
    {
        mainMenuParameterState[i] = mainMenu_defaultParameterState[i];
    }
}

void MyConsoleAPI_extension::menuTheme_Random() {
    /*menuTheme_Random FLAGs_theme(1) set this theme to true and all others to false*/

    if (FLAGS_theme.at(RainbowTheme)) {
        do
        {
            for (size_t i = 0; i < mainMenuParameterState.size(); i++)
            {
                mainMenuParameterState[i] = returnRandomNumber(1, 15);
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        } while (FLAGS_theme_atomic[ThemeThread]->load());

        thread_vector.at(ThemeThread).join();
        return;
    }

    for (size_t i = 0; i < mainMenuParameterState.size(); i++)
    {
        mainMenuParameterState[i] = returnRandomNumber(1, 15);
    }
}

/* enum eFLAG_ThemeID -- defaultTheme(0), RandomTheme(1), RainbowTheme(2) */

void MyConsoleAPI_extension::menuTheme_Rainbow() {
    setThemeFlag(RainbowTheme);
    thread_vector.at(ThemeThread) = std::thread(&MyConsoleAPI_extension::menuTheme_Random, this);
    thread_vector.at(ThemeThread).detach();
}

const std::vector<int>& MyConsoleAPI_extension::getMainMenuState() const {
    return mainMenuParameterState;
}

const std::vector<int>& MyConsoleAPI_extension::getMainMenuDefaultState() const {
	return mainMenu_defaultParameterState;
}

int MyConsoleAPI_extension::selectMenuOption() {
    int returnValue{ 0 };

    cout("\nEnter Command: ", WHITE);
    set_text_color(DARK_CYAN);
    if (std::cin >> returnValue) {
        return returnValue;
    }
    else {
        fn.clearInputStream();
        return 0;
    }
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

	fn.cout("\nGAME OVER\n\n", RED);
    fn.set_text_color(WHITE);
	system("pause"); // Last Instruction before returning to main menu
}

void Quiz::setupEnviorment() {
	fn.clearScreen();
	fn.clearInputStream();
	if (iteration != 0) { iteration = 0; }
}

int Quiz::requestInput() {
	std::string guess{};
	int convertedGuess{};
	size_t pos{};
	do {
        fn.set_text_color(GREEN);
		std::getline(std::cin, guess);
		try
		{
			convertedGuess = std::stoi(guess, &pos);
			if (pos == guess.length()) {
				if (convertedGuess > 3) { fn.cout("Invalid Number::Out of Range\nTry Again: ", RED); fn.clearInputStream(); continue; }
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

inline void Quiz::question(int questionNumber) {
	switch (questionNumber)
	{
	case 1: askFirstQuestion(); break;
	case 2: askSecondQuestion(); break;
	case 3: askThirdQuestion(); break;
	}
}

void Quiz::askFirstQuestion() {
	fn.cout("What is the smallest county?\n1. USA\n2. India\n3.Vatican City\nchoose 1-3: ", BLUE);
    if (requestInput() == 3) {
        fn.setScreenColor("color 08"); // Gray on black
        fn.cout("\nCorrect!\n\n", DARK_MAGENTA);
    } 
    else {
        fn.setScreenColor("color 08"); // Gray on black
        fn.cout("\nIncorrect\n\n", RED);
    }
}

void Quiz::askSecondQuestion() {
	fn.cout("What's the biggest animal in the worl?\n1. Elephant\n2. Bue whale\n3.Great white shark\nchoose 1-3: ", BLUE);
	if (requestInput() == 2) {
        fn.setScreenColor("color 08"); // Gray on black
        fn.cout("\nCorrect!\n\n", DARK_MAGENTA);
    }
    else {
        fn.setScreenColor("color 08"); // Gray on black
        fn.cout("\nIncorrect\n\n", RED);
    }
}

void Quiz::askThirdQuestion() {
	fn.cout("How many elements are there in the periodic table?\n1. 118\n2. 115\n3. 120\nchoose 1-3: ", BLUE);
    if (requestInput() == 1) {
        fn.setScreenColor("color 08"); // Gray on black
        fn.cout("\nCorrect!\n\n", DARK_MAGENTA);
    }
    else {
        fn.setScreenColor("color 08"); // Gray on black
        fn.cout("\nIncorrect\n\n", RED);
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
int const NumberGenerator::returnRandomNumber(const int min, const int max) {
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
