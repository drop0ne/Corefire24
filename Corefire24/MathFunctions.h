#pragma once
#include "My Standard Includes.h"
#include "MyConsoleAPI.h"

#ifndef MATHFUNCTIONS_H
#define MATHFUNCTIONS_H


// Class for basic arithmetic and algebraic operations
class MathematicalComputationalLogic {
public:
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);
    double power(double base, double exponent);
    double squareRoot(double a);
    double logarithm(double a);
    double sine(double angle);
    double cosine(double angle);
    double tangent(double angle);
    double arcsine(double value);
    double arccosine(double value);
    double arctangent(double value);
};

// Class for displaying mathematical proofs
class MathProofs : public MyConsoleAPI{
public:
    MathProofs();  // Constructor declaration
    void showProofs();

private:
    struct Proof {
        std::string name;
        std::string details;
    };
    std::map<int, Proof> proofs;
    void printProof(int choice);
};

#endif // MATHFUNCTIONS_H

#ifndef ARITHMETICPROCESSOR_H
#define ARITHMETICPROCESSOR_H

class ArithmeticProcessor : public MyConsoleAPI{
public:
    // Constructor that takes an instance of MathematicalComputationalLogic
    ArithmeticProcessor(MathematicalComputationalLogic& mcl);

    // Method to perform arithmetic operations
    void performArithmetic();

private:
    // Member variable to hold reference to MathematicalComputationalLogic
    MathematicalComputationalLogic& mcl_;

    // Helper method to get input from the user
    double getInput(const std::string& prompt);

    // Helper method to print the result of an operation
    void printResult(const std::string& operation, double result);

    // Method to display the menu and get the user's choice
    int getChoice();

    // Method to map user choice to functions and perform the operation
    void executeOperation(int choice, double a);
};

#endif // ARITHMETICPROCESSOR_H
