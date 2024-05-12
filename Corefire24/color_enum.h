// Last update: 2024/05/09 by jake
enum dosINTcolors {
    default_color = 7, black = 0, dark_green = 2, green = 2, bright_green = 10, blue = 1,
    bright_red = 12, red = 4, light_blue = 3, ice_blue = 9, teal_blue = 11,
    white = 7, bright_white = 15, gray = 8, purple = 5, yellow = 6,
    highlight_with_blue_blue = 19, highlight_with_blue_blue2 = 25,
    highlight_blue_white = 23, check = 27
};

enum eFLAG_ThemeID {
	defaultTheme = 0, RandomTheme = 1, RainbowTheme = 2
};  

// Options(0), ProgramID(1), Program(2), ExitID(3), Exit(4), Objects(5), ErrorMessages(6)
enum eMainMenu_State_ID {
	Options = 0, ProgramID = 1, Program = 2, ExitID = 3, Exit = 4, Objects = 5, ErrorMessage = 6
};