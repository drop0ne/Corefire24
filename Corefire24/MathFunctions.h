#ifndef MATHFUNCTIONS_H
#define MATHFUNCTIONS_H

#include <string>
#include <map>

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
class MathProofs {
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
