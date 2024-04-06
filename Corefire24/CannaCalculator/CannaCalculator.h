#include"..\include.h"

class CannaCalculator {
private:
    double percentage_THCa{ 0 };
    double grams_flower{ 0 };
    double mg_THC{ 0 };
    double customLoss{ 0 };
    bool enableLoss = false;
    char response{ };

public:
    CannaCalculator() {};
    ~CannaCalculator() {};

    void run();

};

CannaCalculator::CannaCalculator() {};
CannaCalculator::~CannaCalculator() {};



    double getDoubleInput(const std::string& prompt, double minValue, double maxValue) {
        double value{ 0 };
        while (true) {

            std::cout << prompt;
            try {



                if (std::cin.fail()) {
                    throw std::runtime_error("Invalid input. Please enter a numeric value.");
                }



                if (value >= minValue && value <= maxValue) {
                    return value;
                }
            }
            catch (const std::exception& e) {
                std::cout << e.what() << "\n";
            }
        }
    }

    std::string_view getStringInput(const std::string& prompt) {
        std::string_view response;

        while (true) {
            std::cout << prompt;

            std::string tempResponse;
            std::cin >> tempResponse;

            response = tempResponse;

            if (response == "y" || response == "Y" || response == "n" || response == "N") {
                return response;
            }
            else {
                std::cout << "Invalid input. Please enter 'y' or 'n'.\n";
            }
        }
    }

    void check_cin_failSate() {
        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a numeric value.\n";
        }
    }

    void CannaCalculator::run() {
        while (true) {
            std::cout << "CannaCalculator\n\n";
            std::cout << "First, enter the percentage of THCa in your cannabis flower.\n"
                << "Then, enter the total number of grams of flower you will use to infuse oil or butter.\n\n";


            // START User Input
            while (true) {
                std::cout << "Would you like me to account for loss of THC during the infusing process? (y/n): ";

                if (std::cin >> response) {
                    if (response == 'y' || response == 'Y') {
                        enableLoss = true;
                        std::cout << "\nThe default loss is 20% THC\n";

                        std::cout << "Would you like to use a custom percentage? (y/n): ";
                        std::cin >> response;
                        if (response == 'y' || response == 'Y') {
                            customLoss = 0;

                            while (true) {
                                std::cout << "Enter Custom Loss as a decimal number. For example, 0.8 is 20%: ";
                                try {
                                    if (std::cin >> customLoss) {
                                        if (customLoss >= 0 && customLoss <= 1) {
                                            break;
                                        }
                                        else {
                                            throw std::out_of_range("Invalid input. Please enter a decimal number between 0 and 1.");
                                        }
                                    }
                                    else {
                                        throw std::runtime_error("Invalid input. Please enter a numeric value.");
                                    }
                                }
                                catch (const std::exception& e) {
                                    std::cout << e.what() << "\n";
                                }
                            }
                        }
                        break;
                    }
                    else if (response == 'n' || response == 'N') {
                        break;
                    }
                    else {
                        std::cout << "Invalid input. Please enter 'y' or 'n'.\n";
                    }
                }
                else {
                    std::cout << "Invalid input. Please enter 'y' or 'n'.\n";
                }
            }

            while (true) {
                std::cout << "\nWhat percentage of THCa is the cannabis flower you are using? ";
                try {
                    double tempPercentage;
                    if (std::cin >> tempPercentage) {
                        if (tempPercentage >= 0 && tempPercentage <= 100) {
                            percentage_THCa = tempPercentage;
                            break;
                        }
                        else {
                            throw std::out_of_range("Invalid input. Please enter a percentage between 0 and 100.");
                        }
                    }
                    else {
                        throw std::runtime_error("Invalid input. Please enter a numeric value.");
                    }
                }
                catch (const std::exception& e) {
                    std::cout << e.what() << "\n";
                }
            }

            while (true) {
                std::cout << "How many grams of flower are you using? ";
                try {
                    double tempGrams;
                    if (std::cin >> tempGrams) {
                        if (tempGrams > 0) {
                            grams_flower = tempGrams;
                            break;
                        }
                        else {
                            throw std::out_of_range("Invalid input. Please enter a positive value.");
                        }
                    }
                    else {
                        throw std::runtime_error("Invalid input. Please enter a numeric value.");
                    }
                }
                catch (const std::exception& e) {
                    std::cout << e.what() << "\n";
                }
            }
            // END User Input
            // 
            // Perform calculations
            double percentLoss = 0.8;

            if (customLoss > 0) {
                percentLoss = customLoss;
            }

            if (enableLoss) {
                mg_THC = (percentage_THCa * 10) * percentLoss * grams_flower;
            }
            else {
                mg_THC = (percentage_THCa * 10) * grams_flower;
            }
            // END Calculations
            //
            // OUTPUT RESULT
            std::cout << "\n" << percentage_THCa << "% THCa converts to "
                << static_cast<int>(mg_THC) << "mg THC per " << grams_flower << "g of flower.\n\n";

            for (int i = 2; i <= 27; i += 2) {
                std::cout << static_cast<int>(mg_THC / i) << "mg per " << i << " servings\n";
            }

            std::cout << "\n\n";
            // 
            // END OF PROGRAM LOGIC
            //
            while (true) {
                std::cout << "Do you want to reset or exit the program? (reset/exit): ";
                std::string response;
                std::cin >> response;

                if (response == "reset") {
                    percentage_THCa = 0;
                    grams_flower = 0;
                    mg_THC = 0;
                    customLoss = 0;
                    break;
                }
                else if (response == "exit") {
                    return ;
                }
                else {
                    std::cout << "Invalid input. Please enter 'reset' or 'exit'.\n";
                }
            }
        }

        return ;
    }