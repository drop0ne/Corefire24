#pragma once
#include "MyConsoleAPI.h"

#ifndef GAMES_H
#define GAMES_H


class Hangman : public MyConsoleAPI
{
public:
	Hangman();
	~Hangman();
	/* ******* */

	void run(); // Main entry point for the game

private:
	std::vector<std::string> alphabet;
	std::vector<bool> guessedLetters;
	std::vector<bool> answer;
	std::string guess;
	size_t iteration;

	/* *** Memory / Private Methods *** */

	void gameLoop();
	std::string get_userGuess();
	bool checkGuess(std::string guess);
	void drawScreen(bool state_DATA);



};

class Quiz : public MyConsoleAPI {
private:
    int iteration;

public:
    void run();
    Quiz();

private:
    void gameLoop();
    void setupEnviorment();
    int requestInput();
    void question(int questionNumber);
    void askFirstQuestion();
    void askSecondQuestion();
    void askThirdQuestion();

};

// ready for start screen with menu options
// options: set rng range; set number of guess; have default avalible - thats 3 options

class NumberGuessingGame : public NumberGenerator, public MyConsoleAPI {
private:
    struct NumberRangeLimit {
        int min;
        int max;
    };

    // Game state working memory
    int randomNumber;
    int MAX_GUESSES;
    int attempt;
    int attemptCount;
    NumberRangeLimit rangeLimit;

public:
    NumberGuessingGame();
    ~NumberGuessingGame();
    void run();

private:
    void gameLoop();
    void setGameState();
};


class CannaCalculator : public MyConsoleAPI {
public:
    CannaCalculator();
    ~CannaCalculator();

    void run();

private:
    void programLoop();
};

class CalculatePowerLoss_Watts_x_Meters : public MyConsoleAPI {
private:
   struct Properties_m {
        long double resistivity = 1.68e-8L; // resistivity of copper in ohms
        long double voltage = 10.0L; // current in volts
        long double length = 1000.0L; // length of the wire in meters
        long double crossSectionArea = 1e-3L; // cross-sectional area of the wire in square meters
    };

public:
    CalculatePowerLoss_Watts_x_Meters();
    ~CalculatePowerLoss_Watts_x_Meters();

    void run();
private:
    auto setProperties() -> Properties_m;
    long double requestInput(std::string stringMessagePrompt, int promptColor, int inputColor);
    void performCalculation(Properties_m& properties_m);
    long double calculatePowerLoss(Properties_m& properties_m);
    void printResults(const long double powerLoss, Properties_m& sourceData);
    inline void information();
    inline int returnMenuOption();
    inline void menu();
};

/***************/
/* END OF FILE */
/***************/
#endif // GAMES_H