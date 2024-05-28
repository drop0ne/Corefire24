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
        double resistivity = 1.68e-8; // resistivity of copper in ohm*meter
        double current = 25.0; // current in amperes
        double length = 10000.0; // length of the wire in meters
        double crossSectionArea = 1.0e-6; // cross-sectional area of the wire in square meters
    };

public:
    CalculatePowerLoss_Watts_x_Meters();
    ~CalculatePowerLoss_Watts_x_Meters();

    void run();
private:
    void programLoop();
    void menu();
    int returnMenuOption();
    void setProperties();
    void information();
    double calculatePowerLoss(double resistivity, double current, double length, double crossSectionArea);
    void printResults(const double powerLoss, Properties_m& sourceData);
};

/***************/
/* END OF FILE */
/***************/
#endif // GAMES_H