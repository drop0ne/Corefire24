#include"..\include.h"

class CannaCalculator {
private:

public:
    CannaCalculator() {};
    ~CannaCalculator() {};

    void run();
private:
    void programLoop();
};

void CannaCalculator::run() {
    programLoop();
};
    //  PRIVATE ///////////////////////////////////////////////////////////////////

void CannaCalculator::programLoop() {
    double inputValue{};
    std::string inputString{};
    double percentTHCloss = 20;
    double percentTHCflower{};
    double gramsFlower{};
    double mgTHC{};


    std::cout << "CannaCalculator\n\n";
    std::cout << "First, enter the percentage of THCa in your cannabis flower.\n"
        << "Then, enter the total number of grams of flower you will use to infuse oil or butter.\n\n";

    do // Handle THC % loss logic
    {
        cout << "Would you like me to account for loss of THC during the infusing process? (y/n): ";
        getline(cin, inputString);
        if (!inputString.empty()) {
            if (inputString.at(0) == 'y' | 'Y') {
                cout << "The default loss is 20%\nWould you like enter a custom loss % ?\nPrompt: ";
                if (cin >> inputString) {
                    if (inputString.at(0) == 'y' || 'Y') {
                        cout << "Enter a whole number 0 to 100 for your custom %\nPrompt: ";
                        if (cin >> percentTHCloss) {
                            break; // Set custom THC loss %
                        }
                    }
                    else {
                        break; // Use default value 20%
                    }

                }
            }
            else {
                percentTHCloss = 0;
                break; // Do not account for THC loss
            }
        }
    } while (true);

    do { // Handle THC in flower
        cout << "I need to know a couple more things!\n\nFirst: What is the listed THC% of your flower?\nPrompt: ";
        if (cin >> percentTHCflower) {
            break;  // Value is set
        }
        else {
            cout << "Invalid";
            continue; // Loop
        }
    } while (true);

    do { // Handle Grams of Flower
        cout << "\nNow I need to know how much flower you are using\nAt the prompts, enter the total wieght of flower is grams\nprompt: ";
        if (cin >> gramsFlower) {
            break; // Value is set
        }
        else {
            cout << "Invalid";
            continue;
        }
    } while (true);

   // Perform Calculations

    if (percentTHCloss > 0) {
        mgTHC = (percentTHCflower * 10) * percentTHCloss * gramsFlower;
    }
    else {
        mgTHC = (percentTHCflower * 10) * gramsFlower;
    }
    // OUTPUT RESULT
    std::cout << "\n" << percentTHCflower << "% THCa converts to "
        << static_cast<int>(mgTHC) << "mg THC per " << gramsFlower << "g of flower.\n\n";

    for (int i = 2; i <= 27; i += 2) {
        std::cout << static_cast<int>(mgTHC / i) << "mg per " << i << " servings\n";
    }
};