#pragma once
#include "MyConsoleAPI.h"

#ifndef GAMES_H
#define GAMES_H


class Hangman : public CFC_coreComponents
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

class Quiz : public CFC_coreComponents {
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

class NumberGuessingGame : public NumberGenerator, public CFC_coreComponents {
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


class CannaCalculator : public CFC_coreComponents {
private:
    enum MyEnum
    {
        flowerG = 0, THCp = 1, THCl = 2, grossMG = 3, netMG = 4 
    };

public:
     CannaCalculator();
    ~CannaCalculator();

    void run();

private:
    void entrypoint();
    char yesNOquestion(std::string promptMessage, int messageColor);
    double getDoubleFromUser(std::string promptMessage, int messageColor);
    const std::vector<double> mathProccessor(std::vector<double> userDATA);
    void printResults(std::vector<double> results);
    
};

class CalculatePowerLoss_Watts_x_Meters : public CFC_coreComponents {
private:
   struct Properties_m {
        long double resistivity = 1.68e-8L; // resistivity of copper in ohm*meter
        long double voltage = 10.0L; // current in amperes
        long double length = 1000.0L; // length of the wire in meters
        long double crossSectionArea = 1e-3L; // cross-sectional area of the wire in square meters
    };

public:
    CalculatePowerLoss_Watts_x_Meters();
    ~CalculatePowerLoss_Watts_x_Meters();

    void run();
private:
    auto setProperties() -> Properties_m;
    void performCalculation(Properties_m& properties_m);
    long double calculatePowerLoss(Properties_m& properties_m);
    void printResults(const long double powerLoss, Properties_m& sourceData);
    void information();
    int returnMenuOption();
    void menu();
};

/***************/
/* END OF FILE */
/***************/
#endif // GAMES_H