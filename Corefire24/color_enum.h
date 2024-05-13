/*
enum dosINTcolors {
    default_color = 7, black = 0, dark_green = 2, green = 2, bright_green = 10, blue = 1,
    bright_red = 12, red = 4, light_blue = 3, ice_blue = 9, teal_blue = 11,
    white = 7, bright_white = 15, gray = 8, purple = 5, yellow = 6,
    highlight_with_blue_blue = 19, highlight_with_blue_blue2 = 25,
    highlight_blue_white = 23, check = 27
};
*/

enum eText_Color {
	BLACK = 0,
	DARK_BLUE = 1,
	DARK_GREEN = 2,
	DARK_CYAN = 3,
	DARK_RED = 4,
	DARK_MAGENTA = 5,
	DARK_YELLOW = 6,
	LIGHT_GRAY = 7,
	DARK_GRAY = 8,
	BLUE = 9,
	GREEN = 10,
	CYAN = 11,
	RED = 12,
	MAGENTA = 13,
	YELLOW = 14,
	WHITE = 15
};

enum eFLAG_ThemeID {
	defaultTheme = 0, RandomTheme = 1, RainbowTheme = 2
};  

enum eMainMenu_State_ID {
	Options = 0, ProgramID = 1, Program = 2, ExitProgramID = 3, ExitProgram = 4, Symbols = 5, ErrorMessage = 6
};

enum eThread_ID {
	MainThread = 0, ThemeThread = 1
};