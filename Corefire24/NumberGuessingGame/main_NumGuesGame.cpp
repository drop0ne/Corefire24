/*
Written by: Jacob D. Dougherty
aka: drop0ne
Started Project: Tuseday December 13th 2022
*/



// TODO: remove RNG code from MyCustomCode class and consolidate it with the Random number generator class 
// Also: Ajust load/spash screen.  Print loading... then print ganerating number with some kind of visual updating action, must not scroll screen.




#include <iostream>
#include <string>
#include <thread>
#include <random>
#include <Windows.h>
#include <chrono>

using namespace std::chrono_literals;

// Main class for the random number generator thread
class RandomNumberGeneratorThread {
private:
    // The minimum and maximum values for the random number range
    int rng_minimum;
    int rng_maximum;
    // The current random number
    int current_random_number;

public:
    // Flag to stop the thread
    std::atomic<bool> stop_thread;
    // Constructor for the random number generator thread
    RandomNumberGeneratorThread(int min, int max) : stop_thread(false), rng_minimum(min), rng_maximum(max), current_random_number(0) {}
    // Function for generating random numbers on a separate thread
    void GenerateRandomNumbers() {
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
    int getRNG() {
        return current_random_number;
    }
};


void splash_Screen(int rng, HANDLE color);
bool playGuessingGame(int rng, int MIN_rng, int MAX_rng, int MAX_G, HANDLE hwnd_color);

//MAIN - MAIN - MAIN - MAIN - MAIN - MAIN - MAIN - MAIN - MAIN - MAIN - MAIN - MAIN - MAIN - MAIN - MAIN
int main() {
    std::cout << "LOADING...\n";
    // Constants
    const int rng_minimum = 0;// The new minimum value for the random number range
    const int rng_maximum = 100;// The new maximum value for the random number range
    const int MAX_GUESSES = 10;// Set the guess limit
    const int NumerRoll = 35;

    // Get the handle to the console output
    HANDLE console_HWND = GetStdHandle(STD_OUTPUT_HANDLE);

    // Create the random number generator thread and start it
    auto random_number_generator = RandomNumberGeneratorThread(rng_minimum, rng_maximum);
    std::thread random_number_generator_thread(&RandomNumberGeneratorThread::GenerateRandomNumbers, &random_number_generator);
    std::this_thread::sleep_for(250ms);//Required!  This allows for the RNG thread time to spool up

    // Create the MyCustomCode object
    MyCustomCode cc{ random_number_generator.getRNG(), console_HWND };


    auto si = MyCustomCode(random_number_generator.getRNG(), console_HWND);
    si.print("Picking a Number\n");
    si.set_text_color(green);

    for (size_t i = 0; i < NumerRoll; i++) {
        std::this_thread::sleep_for(30ms);//RNG engine is set to 10ms //This ratio gives a random number for all calls.  At least the calls that are locked in and set in local memory. 
        if ((i + 1) < NumerRoll) {
            si.reset_RNG(random_number_generator.getRNG());
            si.print("Generating Number Roll\n");
        }
        else {
            si.reset_RNG(random_number_generator.getRNG());
            si.setScreenColor("color 8");
            si.set_text_color(highlight_blue_white);
            si.print("Random Number is Generated!");
            std::this_thread::sleep_for(750ms);//Slow code exicucoin down so user can see this print out to the screen.
            si.clearScreen("color 7");
        }
    }
    // Splash screen
    splash_Screen(si.local_RNG(), console_HWND);

    // Play guessing games until the player chooses to exit
    while (true) {
        // Play a game of guessing the secret number
        {
            bool player_won = playGuessingGame(si.local_RNG(), rng_minimum, rng_maximum, MAX_GUESSES, console_HWND);

            if (player_won) {
                si.print("\nYou win!");
            }
            else {
                si.print("\nThe Number was: ", si.local_RNG());
            }

            // Ask the player if they want to continue playing
            si.set_text_color(yellow);
            si.print("\n\nWould you like to play again? (y/n) :: ");
            si.set_text_color(ice_blue);
            std::string response;
            std::cin >> response;
            if (response == "n") {
                break;
            }
        }
        si.reset_RNG(random_number_generator.getRNG());
    }
    // Stop the random number generator thread and wait for it to finish
    random_number_generator.stop_thread = true;
    random_number_generator_thread.join();

    return 0;
}

// Function for playing a game of guessing the secret number
// Returns true if the player won the game, or false if they lost
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

void splash_Screen(int rng, HANDLE color) {
    auto si = MyCustomCode(rng, color);
    si.clearScreen();
    si.set_text_color(highlight_with_blue_blue2);
    si.print("Number Guessing Game Super\n\n\n");
    si.set_text_color(ice_blue);
    si.print("I have used multiple programming languages, including MS qBASIC, C, C++, C#, and Python, to create different versions of number guessing game variants. I used my C code version as a starting point and used the OpenAI ChatGPT to translate it into other languages. In addition to relying on AI, I have also manually edited the code and made my own contributions. The use of AI has been helpful but has limitations, so I have needed to do manual work to improve the code. The project has been complex and time-consuming, but AI has made the coding process more efficient. The code base has grown beyond what ChatGPT can handle and is now fully human-written.\n\n");
    si.systemCommand("pause");//probably a security valnerabillity - passing text literals to the system cmd api
    return;
}