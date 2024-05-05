#include"..\include.h"

class CannaCalculator {
private:

public:
    CannaCalculator() {};
    ~CannaCalculator() {};

    void run();
private:
    void programLoop();
    void clearInputStream();
};

void CannaCalculator::run() {
    system("cls");
    programLoop();
};
    //  PRIVATE ///////////////////////////////////////////////////////////////////

void CannaCalculator::programLoop() {
    char inputChar{};
    double percent_THC{};
    double THC_loss{};
    double gramsFlower{};
    double mgTHC_Gross{};
    double mgTHC_Net{};

    std::cout << "CannaCalculator\n\n";
    std::cout << "First, enter the percentage of THCa in your cannabis flower.\n"
        << "Then, enter the total number of grams of flower you will use to infuse oil or butter.\n\n";

    do // Handle THC % loss logic
    {
        cout << "\nThe default loss is 20%\nWould you like enter a custom loss percenage? (y/n): ";
        if (cin >> inputChar) {
            if (inputChar == 'y') {
                clearInputStream();
                cout << "\nEnter a whole number 0 to 100 for your custom %: ";
                if (cin >> THC_loss) {
                    THC_loss /= 100;
                    break; // Set custom THC loss %
                }
                else {
                    clearInputStream();
                    continue;
                }
            }
            else {
                THC_loss = 0.20;
                break; // Use default loss %
            }
        }
        else {
            clearInputStream();
            continue;
        }
    } while (true);
    
    clearInputStream();
    
    do { // Handle THC in flower
        cout << "\n\n";
        cout << "I need to know a couple more things!\nFirst: What is the listed THC% of your flower?: ";
        if (cin >> percent_THC) {
            //percent_THC /= 100; //convert to decimal
            break;  // Value is set
        }
        else {
            cout << "\nInvalid" << endl;
            clearInputStream();
            continue; // Loop
        }
    } while (true);
    
    clearInputStream();
   
    do { // Handle Grams of Flower
        cout << "Secound: How many grams of flower will you be using?: ";
        if (cin >> gramsFlower) {
            break; // Value is set
        }
        else {
            cout << "\nInvalid";
            clearInputStream();
            continue;
        }
    } while (true);
    
    clearInputStream();

   // Perform Calculations
     
    mgTHC_Gross = (percent_THC * 10) * gramsFlower;
    mgTHC_Net = mgTHC_Gross * (1 - THC_loss);
   

    // OUTPUT RESULT
    system("cls");
    std::cout << "\n" << percent_THC << "% THCa converts to "
        << static_cast<int>(mgTHC_Gross) << "mg THC per " << static_cast<int>(gramsFlower) << "g of flower Before decarboxylation.\nand " << static_cast<int>(mgTHC_Net) << "mg THC after decarboxylation\n\n";
    cout << "\nGross THC\n";
    for (int i = 2; i <= 13; i += 2) {
        std::cout << static_cast<int>(mgTHC_Gross) / i << "mg per " << i << " servings\n";
    }
    cout << "\nNET THC\n";
    for (int i = 2; i <= 13; i += 2) {
        std::cout << static_cast<int>(mgTHC_Net) / i << "mg per " << i << " servings\n";
    }

    cout << endl;
    system("pause");
};

inline void CannaCalculator::clearInputStream() {
    std::cin.clear();
    if (std::cin.rdbuf()->in_avail() > 0) {
        // If there are characters in the input buffer, discard them up to the next newline
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
};