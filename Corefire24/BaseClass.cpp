#include "BaseClass.h"

//************************************************************************************************************************************************************/
// MyConsoleAPI Class
// Constructor
/*************************************************************************************************************************************************************/
CFC_coreComponents::CFC_coreComponents() : console_HWND(), topLeft({ 0, 0 }) {
	console_HWND = GetStdHandle(STD_OUTPUT_HANDLE);
	if (console_HWND == INVALID_HANDLE_VALUE) {
		throw std::runtime_error("Failed to get standard output handle");
	}
}

// Clear the console screen using Windows API for better performance and security
void CFC_coreComponents::clearScreen() {
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

void CFC_coreComponents::print(const std::string& data) {
	std::cout << data;
	// Base
}
void CFC_coreComponents::print(const std::string& data, const int textColor) {
	setMyTextColor(textColor);
	std::cout << data;
	// Set text color and print data
}

void CFC_coreComponents::print(const double& data, int numberColor) {
	setMyTextColor(numberColor);
	std::cout << data;
}

void CFC_coreComponents::print(const std::string& string1, const double& data1, const std::string& string2, int& textColor, int& numberColor) {
	setMyTextColor(textColor);
	std::cout << string1;
	setMyTextColor(numberColor);
	std::cout << data1;
	setMyTextColor(textColor);
	std::cout << string2;
	// Used by CalculatePowerLoss_Watts_x_Meters
}


void CFC_coreComponents::print(const std::string& string1, const int& textColor1, const std::string& string2, const int& textColor2,
	const std::string& string3, const int& textColor3, const std::string& string4, const int& textColor4) {
	setMyTextColor(textColor1);
	std::cout << string1;
	setMyTextColor(textColor2);
	std::cout << string2;
	setMyTextColor(textColor3);
	std::cout << string3;
	setMyTextColor(textColor4);
	std::cout << string4;
	// Used to generate Main Menu
}

void CFC_coreComponents::setScreenColors(const char* data) {
	try {
		// Validate the input before executing
		if (!check_IF_validCommand(data)) {
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

void CFC_coreComponents::setMyTextColor(int data) {
	if (!SetConsoleTextAttribute(console_HWND, data)) {
		throw std::runtime_error("Failed to set text attributes");
	}
}

void CFC_coreComponents::overrideConsoleColors(eConsoleTextColor foreground, eConsoleTextColor background) {
	WORD color = (static_cast<WORD>(background) << 4) | static_cast<WORD>(foreground);
	if (!SetConsoleTextAttribute(console_HWND, color)) {
		throw std::runtime_error("Failed to set text attributes");
	}
}

void CFC_coreComponents::clearInputStream() {
	std::cin.clear();
	if (std::cin.rdbuf()->in_avail() > 0) {
		// If there are characters in the input buffer, discard them up to the next newline
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

void CFC_coreComponents::extractInputStream() {
	std::cout << "Contents of input stream: ";
	char c;
	while (std::cin.peek() != EOF) {
		std::cin.get(c);
		std::cout << c;
	}
}

void CFC_coreComponents::sleepTimer(int time) { std::this_thread::sleep_for(std::chrono::milliseconds(time)); }

// ********** Start Private Functions **********

bool CFC_coreComponents::check_IF_validCommand(const char* command) {
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

ToolSet_MainMenu::ToolSet_MainMenu() : FLAGS_theme({/*them_default(0)*/true, /*themeRandom(1)*/false, /*themeRainbow(2)*/false }),
mainMenu_totalParameters(8), mainMenuParameterCurentState({/*options(0)*/Green, /*programID(1)*/Magenta, /*program(2)*/Cyan,
	/*exitID(3)*/Red, /*exit(4)*/Gray, /*objects(5)*/DefaultWhite, /*errorMessages(6)*/Green, /*WAIT(7)*/LightBlue })
{
	/* Initializing the main menu's theme state into a vector, set number_of_state_parameters equal to total number of default elements */
	mainMenu_defaultParameterState = mainMenuParameterCurentState;
}
/*************************************************************/
/*      END OF CONSTRUCTOR FOR MyConsolAPI_Enstension        */
/*                         ****$****                         */
/*************************************************************/


void ToolSet_MainMenu::errorMessage() {
	clearInputStream();
	print("\nERROR: INVALID INPUT\n", getMainMenuState().at(/*enum eMainMenu_State_ID*/ErrorMessage));
}

void ToolSet_MainMenu::setMainMenuState(const std::vector<int> newState) {
	print("Setting new state\n");
	for (size_t i = 0; i < mainMenuParameterCurentState.size(); i++)
	{
		mainMenuParameterCurentState[i] = newState[i];
	}
	system("pause");
}

void ToolSet_MainMenu::generateMainMenu(const std::vector<int>& stateData) {
	/* StateDate.at( recieves and int ) to identify group to apply color state change to */
	/* Using enum eMainMenu_State_ID Options(0), ProgramID1), Program(2), ExitProgramID(3), ExitProgram(4), Symbols(5), ErrorMessage(6) */

	/* cout has three overloads as of 2024/05/12 */
	/* cout(string, int, string, int, string, int, string, int) */
	/* cout(string, int, string, int) */
	/* cout(string, int) */

	print("CoreFireCode 2024 edition\n", Green);
	print("\n\nMain Menu\n\n", DefaultWhite);
	print("Option", stateData.at(Option), " 1 ", stateData.at(ProgramID), "-", stateData.at(Symbols), " CannabisCalculator\n", stateData.at(Program));
	print("Option", stateData.at(Option), " 2 ", stateData.at(ProgramID), "-", stateData.at(Symbols), " Calculation of Power Loss\n", stateData.at(Program));
	print("Option", stateData.at(Option), " 3 ", stateData.at(ProgramID), "-", stateData.at(Symbols), " Number Gussing Game\n", stateData.at(Program));
	print("Option", stateData.at(Option), " 4 ", stateData.at(ProgramID), "-", stateData.at(Symbols), " Quiz\n", stateData.at(Program));
	print("Option", stateData.at(Option), " 5 ", stateData.at(ProgramID), "-", stateData.at(Symbols), " Hangman\n", stateData.at(Program));
	print("Option", stateData.at(Option), " 6 ", stateData.at(ProgramID), "-", stateData.at(Symbols), " Default Menu Theme\n", stateData.at(Program));
	print("Option", stateData.at(Option), " 7 ", stateData.at(ProgramID), "-", stateData.at(Symbols), " Random Menu Theme\n", stateData.at(Program));
	print("Option", stateData.at(Option), " 8 ", stateData.at(ProgramID), "-", stateData.at(Symbols), " Rainbow Effect\n", stateData.at(Program));
	print("Option", stateData.at(Option), " 10 ", stateData.at(ProgramID), "-", stateData.at(Symbols), " Solitaire\n", stateData.at(Program));
	print("Option", stateData.at(Option), " 9 ", stateData.at(ExitProgramID), "-", stateData.at(Symbols), " Exit\n", stateData.at(ExitProgram));
}

void ToolSet_MainMenu::setThemeFlag(const int themeFlag_ID) {
	if (!FLAGS_theme.empty())
	{
		for (size_t i = 0; i < FLAGS_theme.size(); i++)
		{
			if (FLAGS_theme.at(themeFlag_ID))
			{
				FLAGS_theme.at(themeFlag_ID) = true; // Set the callers ID theme to true
			}
			else
			{
				FLAGS_theme.at(i) = false; // Set all other themes to false
			}
		}//end of for loop
	}
	else
	{
		std::abort();
	}

}

void ToolSet_MainMenu::callTheme_by_Flag_ID(const int& themeFlag_ID) {
	switch (themeFlag_ID)
	{
	case 0:  setThemeFlag(defaultTheme); menuTheme_Default(); break;
	case 1:  setThemeFlag(RandomTheme);  menuTheme_Random(); break;
	case 2:  setThemeFlag(RainbowTheme); menuTheme_betterRandom(); break;
	default: setThemeFlag(defaultTheme); menuTheme_Default(); break;
	}
}

/*************************************************************/
/*      END OF PUBLIC METHODS FOR ToolSet_MainMenu           */
/*                         ****$****                         */
/*     START OF PRIVATE METHODS FOR ToolSet_MainMenu         */
/*************************************************************/

void ToolSet_MainMenu::menuTheme_Default() {
	setThemeFlag(defaultTheme);

	for (size_t i = 0; i < mainMenuParameterCurentState.size(); i++)
	{
		mainMenuParameterCurentState[i] = mainMenu_defaultParameterState[i];
	}
}

void ToolSet_MainMenu::menuTheme_Random() {
	/*menuTheme_Random FLAGs_theme(1) set this theme to true and all others to false*/

	for (size_t i = 0; i < mainMenuParameterCurentState.size(); i++)
	{
		mainMenuParameterCurentState[i] = getRandomNumber(1, 15);
	}
}

/* enum eFLAG_ThemeID -- defaultTheme(0), RandomTheme(1), RainbowTheme(2) */

void ToolSet_MainMenu::menuTheme_betterRandom() {
	using namespace std::chrono_literals;

	for (size_t i = 0; i < 60; i++)
	{
		for (size_t j = 0; j < mainMenuParameterCurentState.size(); j++)
		{
			mainMenuParameterCurentState[j] = getRandomNumber(1, 15);
		}
		clearScreen();
		generateMainMenu(mainMenuParameterCurentState);
		print("\nWAIT!", WAIT_);
		std::this_thread::sleep_for(0.025s);
	}
}

const std::vector<int>& ToolSet_MainMenu::getMainMenuState() const {
	return mainMenuParameterCurentState;
}

const std::vector<int>& ToolSet_MainMenu::getMainMenuDefaultState() const {
	return mainMenu_defaultParameterState;
}

int ToolSet_MainMenu::mainMenuLogic() {
	int returnValue{ 0 };

	do {
		clearScreen(); generateMainMenu(mainMenuParameterCurentState); print("\nSelect option: ", LightGreen); setMyTextColor(DefaultWhite);
		
		std::cin >> returnValue;
		if (std::cin.fail())
		{
			errorMessage();
			system("pause");
			continue;
		}
		else
		{
			return returnValue;
		}
	} while (true);
}

ESCkeyButton::ESCkeyButton() : exitRequested({ false })
{
}

ESCkeyButton::~ESCkeyButton()
{
}

void ESCkeyButton::ESCkeyExit_Jthread_start() {
	escThread = std::jthread(&ESCkeyButton::isESCkeyPressed, this);
}

void ESCkeyButton::isESCkeyPressed(std::stop_token stopToken) {
	while (!stopToken.stop_requested() && !exitRequested.load()) {
		if (_kbhit()) {
			int ch = _getch();
			if (ch == 27) { // ESC key
				exitRequested.store(true);
				break;
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
}
