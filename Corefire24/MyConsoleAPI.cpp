#include "MyConsoleAPI.h"


//************************************************************************************************************************************************************/
// Constructor
/************************************************************************************************************************************************************/
MyConsoleAPI::MyConsoleAPI() : threadLimit(8) {
    console_HWND = GetStdHandle(STD_OUTPUT_HANDLE);
    if (console_HWND == INVALID_HANDLE_VALUE) {
        throw std::runtime_error("Failed to get standard output handle");
    }
    jthreadPool_concurrent.resize(threadLimit);
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

void MyConsoleAPI::launchThread(const std::function<void()>& func) {
    jthreadPool_concurrent.emplace_back(std::ref(func));
}

void MyConsoleAPI::createNewConsoleWindow() {
    if (AllocConsole()) {
        FILE* file;
        freopen_s(&file, "CONOUT$", "w", stdout);
        freopen_s(&file, "CONOUT$", "w", stderr);
        freopen_s(&file, "CONIN$", "r", stdin);
    }
    else {
        std::cerr << "Failed to create new console window." << std::endl;
    }
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
mainMenu_totalParameters(7), mainMenuParameterState({/*options(0)*/green, /*programID(1)*/purple, /*program(2)*/light_blue,
    /*exitID(3)*/red, /*exit(4)*/gray, /*objects(5)*/white, /*errorMessages(6)*/red })
{
    /* Initializing the main menu's theme state into a vector, set number_of_state_parameters equal to total number of default elements */
    mainMenu_defaultParameterState = mainMenuParameterState;
    FLAGS_theme_atomic.resize(threadLimit);
    FLAGS_theme_atomic.emplace_back(std::make_unique<std::atomic<bool>>(true)); // MainThread
    FLAGS_theme_atomic.emplace_back(std::make_unique<std::atomic<bool>>(true)); // ThemeThread
}
void MyConsoleAPI_extension::invalid_Input() {
    cout("\nERROR: INVALID INPUT\n", red);
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

    cout("CoreFireCode 2024 edition\n", green);
    cout("\n\nMain Menu\n\n", white);
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
        return;
    }

    for (size_t i = 0; i < mainMenuParameterState.size(); i++)
    {
        mainMenuParameterState[i] = returnRandomNumber(1, 15);
    }
}

/* enum eFLAG_ThemeID -- defaultTheme(0), RandomTheme(1), RainbowTheme(2) */

void MyConsoleAPI_extension::menuTheme_Rainbow() {
}

const std::vector<int>& MyConsoleAPI_extension::getMainMenuState() const {
    return mainMenuParameterState;
}

const std::vector<int>& MyConsoleAPI_extension::getMainMenuDefaultState() const {
	return mainMenu_defaultParameterState;
}

int MyConsoleAPI_extension::selectMenuOption() {
    int returnValue{ 0 };

    cout("\nEnter Command: ", default_color);
    if (std::cin >> returnValue) {
        return returnValue;
    }
    else {
        clearInputStream();
        return 0;
    }
}