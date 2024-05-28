#pragma once

enum ConsoleColor {
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGray = 7,
    DarkGray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    Yellow = 14,
    White = 15,
};

enum eFLAG_ThemeID {
	defaultTheme = 0, RandomTheme = 1, RainbowTheme = 2, betterRandomTheme = 3
};  

enum eMainMenu_State_ID {
	Options = 0, ProgramID = 1, Program = 2, ExitProgramID = 3, ExitProgram = 4, Symbols = 5, ErrorMessage = 6, WAIT_ = 7
};

enum eThread_ID {
	MainThread = 0, ThemeThread = 1
};

enum eNotation {
    eLengths = 0, ePowerLossForLengths = 1, eCurrents = 2, ePowerlossForCurrents = 3, eCrossSections = 4, ePowerLossForCrossSections = 5, eResistances = 6, ePowerLossForResistances = 7
};