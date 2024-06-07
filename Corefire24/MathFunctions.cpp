﻿#include "MathFunctions.h"
#include <cmath>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <stdexcept>

// MathematicalComputationalLogic Implementation

double MathematicalComputationalLogic::add(double a, double b) {
    return a + b;
}

double MathematicalComputationalLogic::subtract(double a, double b) {
    return a - b;
}

double MathematicalComputationalLogic::multiply(double a, double b) {
    return a * b;
}

double MathematicalComputationalLogic::divide(double a, double b) {
    if (b == 0) {
        throw std::runtime_error("Division by zero error");
    }
    return a / b;
}

double MathematicalComputationalLogic::power(double base, double exponent) {
    return std::pow(base, exponent);
}

double MathematicalComputationalLogic::squareRoot(double a) {
    if (a < 0) {
        throw std::runtime_error("Square root of negative number error");
    }
    return std::sqrt(a);
}

double MathematicalComputationalLogic::logarithm(double a) {
    if (a <= 0) {
        throw std::runtime_error("Logarithm of non-positive number error");
    }
    return std::log(a);
}

double MathematicalComputationalLogic::sine(double angle) {
    return std::sin(angle);
}

double MathematicalComputationalLogic::cosine(double angle) {
    return std::cos(angle);
}

double MathematicalComputationalLogic::tangent(double angle) {
    return std::tan(angle);
}

double MathematicalComputationalLogic::arcsine(double value) {
    if (value < -1 || value > 1) {
        throw std::runtime_error("Arcsine domain error");
    }
    return std::asin(value);
}

double MathematicalComputationalLogic::arccosine(double value) {
    if (value < -1 || value > 1) {
        throw std::runtime_error("Arccosine domain error");
    }
    return std::acos(value);
}

double MathematicalComputationalLogic::arctangent(double value) {
    return std::atan(value);
}

// MathProofs Implementation

MathProofs::MathProofs() {
    // Initialize the map with proofs
    proofs = {
        {1, {"Pythagorean Theorem", "In a right triangle, the square of the hypotenuse is equal to the sum of the squares of the other two sides.\n\nProof: c² = a² + b²."}},
        {2, {"Fundamental Theorem of Calculus", "Connects differentiation and integration, showing that they are essentially inverse processes.\n\nProof: If F is an antiderivative of f, then F(b) - F(a) = ∫[a, b] f(x) dx."}},
        {3, {"Euler's Formula", "Establishes the deep relationship between trigonometric functions and the exponential function.\n\nProof: e^(ix) = cos(x) + i sin(x)."}},
        {4, {"Quadratic Formula", "Provides the solutions to a quadratic equation.\n\nProof: The solutions to ax² + bx + c = 0 are given by x = (-b ± sqrt(b² - 4ac)) / (2a)."}}
    };
}

void MathProofs::showProofs() {
    std::cout << "Select a math proof to display:\n";
    for (const auto& [key, proof] : proofs) {
        std::cout << key << ". " << proof.name << "\n";
    }
    std::cout << "Enter the number of your choice: ";
    int choice;
    std::cin >> choice;
    printProof(choice);
}

void MathProofs::printProof(int choice) {
    if (proofs.find(choice) != proofs.end()) {
        std::cout << "Selected Proof: " << proofs[choice].name << "\n";
        std::cout << proofs[choice].details << "\n";
    }
    else {
        std::cout << "Invalid choice. Please try again.\n";
    }
}

// Implementation of the performArithmetic function
void performArithmetic(MathematicalComputationalLogic& mcl) {
    double a, b;
    int choice;

    // Function to get a single input
    auto getInput = [](const std::string& prompt) -> double {
        double value;
        std::cout << prompt;
        std::cin >> value;
        return value;
        };

    // Function to print the result of an operation
    auto printResult = [](const std::string& operation, double result) {
        std::cout << operation << ": " << result << std::endl;
        };

    // Get the first number
    a = getInput("Enter first number: ");

    // Map user choices to functions
    std::unordered_map<int, std::function<double()>> operations = {
        {1, [&]() { b = getInput("Enter second number: "); return mcl.add(a, b); }},
        {2, [&]() { b = getInput("Enter second number: "); return mcl.subtract(a, b); }},
        {3, [&]() { b = getInput("Enter second number: "); return mcl.multiply(a, b); }},
        {4, [&]() { b = getInput("Enter second number: "); return mcl.divide(a, b); }},
        {5, [&]() { b = getInput("Enter exponent: "); return mcl.power(a, b); }},
        {6, [&]() { return mcl.squareRoot(a); }},
        {7, [&]() { return mcl.logarithm(a); }},
        {8, [&]() { return mcl.sine(a); }},
        {9, [&]() { return mcl.cosine(a); }},
        {10, [&]() { return mcl.tangent(a); }},
        {11, [&]() { return mcl.arcsine(a); }},
        {12, [&]() { return mcl.arccosine(a); }},
        {13, [&]() { return mcl.arctangent(a); }}
    };

    // Display the menu
    std::cout << "Choose an operation:\n";
    std::cout << "1. Add\n";
    std::cout << "2. Subtract\n";
    std::cout << "3. Multiply\n";
    std::cout << "4. Divide\n";
    std::cout << "5. Power\n";
    std::cout << "6. Square Root (first number)\n";
    std::cout << "7. Logarithm (first number)\n";
    std::cout << "8. Sine (first number)\n";
    std::cout << "9. Cosine (first number)\n";
    std::cout << "10. Tangent (first number)\n";
    std::cout << "11. Arcsine (first number)\n";
    std::cout << "12. Arccosine (first number)\n";
    std::cout << "13. Arctangent (first number)\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    // Perform the selected operation
    try {
        if (operations.find(choice) != operations.end()) {
            double result = operations[choice]();
            printResult("Result", result);
        }
        else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
