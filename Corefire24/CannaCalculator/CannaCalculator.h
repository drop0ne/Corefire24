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
    char inputChar{};
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
        if (cin >> inputChar) {
            if (inputChar == 'y') {
                cout << "\nThe default loss is 20%\nWould you like enter a custom loss percenage? (y/n): ";
                if (cin >> inputChar) {
                    if (inputChar == 'y') {
                        cout << "\nEnter a whole number 0 to 100 for your custom %: ";
                        if (cin >> percentTHCloss) {
                            break; // Set custom THC loss %
                        }
                    }
                    else {
                        break; // Use default loss %
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
        cout << "\n\nI need to know a couple more things!\n\First: What is the listed THC% of your flower?: ";
        if (cin >> percentTHCflower) {
            break;  // Value is set
        }
        else {
            cout << "\nInvalid";
            continue; // Loop
        }
    } while (true);

    do { // Handle Grams of Flower
        cout << "Secound: How many grams of flower will you be using?: ";
        if (cin >> gramsFlower) {
            break; // Value is set
        }
        else {
            cout << "\nInvalid";
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
    system("pause");
};