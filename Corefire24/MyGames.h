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
    void askFirstQuestion(); //todo: consolidate askQuestion to a single generic function; Load questions from a file; then optomize the code
    void askSecondQuestion();
    void askThirdQuestion();

};

class NumberGuessingGame : public NumberGenerator, public MyConsoleAPI { //todo: Create a Start Screen with options to set the range of the random number, and the number of guesses
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
    inline void gameLoop();
    inline void setGameState();
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
   struct BaseLongDoubles {
       long double resistivity_ohm = 1.68e-8L;
       long double current_amps = 10.0L;
       long double length_meters = 1000.0L;
       long double crossSectionalArea_sqr_meter = 1e-3L;
    };
   struct ConvertionsLongDoubles {
       long double resistance{};
       long double powerLossTotal{};
       long double powerLossPerMeter{};
       long double powerLossPerCentimeter{};
       long double powerLossPerInch{};
       long double powerLossMilliwattsPerMeter{};
   };

public:
    CalculatePowerLoss_Watts_x_Meters();
    ~CalculatePowerLoss_Watts_x_Meters();

    void run();
private:
    long double requestInput(std::string stringMessagePrompt, int promptColor, int inputColor);
    auto setProperties() -> BaseLongDoubles;
    void performCalculation(BaseLongDoubles& baseNumber);
    long double calculatePowerLoss(BaseLongDoubles& baseNumbers);
    void printResults(const BaseLongDoubles& baseNumbers, const ConvertionsLongDoubles& convertions);
    inline void information();
    inline int returnMenuOption();
    inline void menu();
};

/***************/
/* END OF FILE */
/***************/
#endif // GAMES_H