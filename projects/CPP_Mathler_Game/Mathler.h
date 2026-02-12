//
// Created by hayde on 2/13/2024.
//

/************************************************************************************************
 * Programmer: Hayden Gamble
 * Date: 02/16/2024
 * Project Name: hw3
 * Description of Program: This C++ program is a program that accomplishes the same goal as the
 *      famous Mathler game.
 ************************************************************************************************/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef HW3_MATHLER_H
#define HW3_MATHLER_H

// necessary header files
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <limits.h>
#include <time.h>

using namespace std;
const int MAX_GUESS_NUM = 6; // maximum number of guesses

/*************************************************************
 * Description: The Mathler class includes the isValidEquation(),
 *      evaluateEquation(), getter, setter, and printEquation()
 *      methods and the constructor for the class.
 * Type: Class
 * Inputs: N/A
 * Outputs: N/A
 **************************************************************/
class Mathler {
public:
    /* Prototypes for the methods in the Mathler class */
    Mathler(string equation = "01+02");
    string getSecretEquation();
    void setSecretEquation(string secretEquation);
    int getGuessNum();
    void printEquation();
    void generateRandomEquation();
    bool makeGuess(string equationGuess);
    void printFeedback();
private:
    /* Private variables for the Mathler class */
    string secretEquation; // the secret equation
    int guessNum = 0;  // number of guesses
    vector<string> guess;  // vector of previous guesses
};
bool isValidEquation(const string & testEquation);
int evaluateEquation(const string & equation);

#endif //HW3_MATHLER_H
