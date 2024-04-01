#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <random>
#include <Windows.h>
#include <chrono>
using namespace std::chrono_literals;
#define interface_type_data HANDLE color
#define interface_data color

enum color_name_to_cCode
{
    default_color = 7, black = 0, dark_green = 2, green = 2, bright_green = 10, blue = 1, bright_red = 12, red = 4, light_blue = 3, ice_blue = 9, teal_blue = 11, white = 7, bright_white = 15, gray = 8, purple = 5, yellow = 6, highlight_with_blue_blue = 19, highlight_with_blue_blue2 = 25, highlight_blue_white = 23, check = 27
};

//**************************** \\\\//// ****************************\\

class NumberGenerator {
private:
    // The minimum and maximum values for the random number range
    int rng_minimum{0};
    int rng_maximum{0};
    // The current random number
    int current_random_number{0};

public:
	NumberGenerator(int min, int max);
	~NumberGenerator();
    std::atomic<bool> stop_thread;

    void GenerateRandomNumbers();
    int getRNG();
    void splash_Screen(int rng, HANDLE color);
    bool playGuessingGame(int rng, int MIN_rng, int MAX_rng, int MAX_G, HANDLE hwnd_color);


private:

};

NumberGenerator::NumberGenerator(int min, int max) :stop_thread(false), rng_minimum(min), rng_maximum(max), current_random_number(0) {
}

NumberGenerator::~NumberGenerator()
{
}

void NumberGenerator::GenerateRandomNumbers() {
    // Use the Mersenne Twister engine to generate random numbers
    std::mt19937 generator;
    // Create a uniform distribution
    std::uniform_int_distribution<int> distribution(rng_minimum, rng_maximum);

    // Generate random numbers until the thread is stopped
    while (!stop_thread) {
        // Generate a new random number between 0 and 11
        current_random_number = distribution(generator);
        std::this_thread::sleep_for(std::chrono::milliseconds(10ms));
    }
}
// Returns the current saved random number
int NumberGenerator::getRNG() {
    return current_random_number;
}



//********************************* STOP ******************************************************












//***************************************STOP******************************************************





bool playGuessingGame(int rng, int MIN_rng, int MAX_rng, int MAX_guesses, HANDLE hwnd_color)
{
    // Initialize the number of guesses and the maximum number of guesses allowed
    auto si = MyCustomCode(rng, hwnd_color);
    si.setScreenColor("color 8");//color 8 is cCode for gray //Set all on screen char color to gray
    si.set_text_color(white);
    int number_of_guesses{ 0 };
    //int MAX_GUESSES = MAX_G, min_RNG = MIN_rng, max_RNG = MAX_rng;
    bool player_won = false;

    // START GAME LOOP ~ ####
    while (true) {
        // Ask the player to make a guess
        si.print("\nGuess a number between ", MIN_rng, MAX_rng);
        int guess{};
        si.set_text_color(ice_blue);
        std::cin >> guess;

        // Print the number of guesses remaining
        si.set_text_color(purple);
        std::cout << "You have " << ((MAX_guesses - number_of_guesses) - 1) << " guesses left.\n";
        si.set_text_color(white);

        // Check if the player's guess is correct
        if (guess == rng) {
            player_won = true;
            break;
        }
        //Escape code to end game
        if (guess == -1) {
            break;
        }
        if (guess < rng) {
            si.set_text_color(blue);
            si.print("The Securet Number is higher!\n");
            si.set_text_color(default_color);
        }
        else {
            si.set_text_color(blue);
            si.print("The Securet Number is lower!\n");
            si.set_text_color(default_color);
        }
        // If the player ran out of guesses, stop the game
        if (++number_of_guesses == MAX_guesses) {
            break;
        }
    }
    return player_won;
}
