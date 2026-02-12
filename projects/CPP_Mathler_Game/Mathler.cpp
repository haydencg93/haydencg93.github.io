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

#include "Mathler.h" // includes the code inside Mathler.h

/*  use for loop that is shown in public\lec05Vectors */
/*************************************************************
 * Description: The Mathler class constructor initializes the equation
 *      variable and sets the default value to the equation "01+02".
 * Type: Constructor
 * Inputs: Variable equation
 * Outputs: N/A
 **************************************************************/
Mathler::Mathler(string equation) {
    Mathler::setSecretEquation(equation); // calls the setSecretEquation method
}

/*************************************************************
 * Description: The isValidEquation() method checks to see if the
 *      equation inputted is a valid equation. A valid equation
 *      meets all of the following requirements: only contains the
 *      characters 0-9, +, -, or *; only contains one math operation;
 *      does not have a math operation in the first or last character;
 *      and has exactly five characters.
 * Type: Method
 * Inputs: Variable testEquation
 * Outputs: Boolean true or false
 **************************************************************/
bool isValidEquation(const string & testEquation){
    int opCount = 0; // creates the variable for the count of the operators present in the equation
    if (testEquation.length() == 5) {
        // checks if the length of the equation is 5
        for (int i=0; i < 5; i++) {
            // loops through the string to test each index of the equation
            if ((testEquation[i] == '+' || testEquation[i] == '-' || testEquation[i] == '*') || (testEquation[i] >= '0' && testEquation[i] <= '9')){
                // checks to ensure there are only numbers in the equation that are <10 in each index
                if ((testEquation[i] == '+') || (testEquation[i] == '-') || (testEquation[i] == '*')){
                    opCount++; // adds to the operator count
                    if (i == 0 || i == 4){
                        // finds if the index is the first or last and has the value of an operator
//                        cout << "Failed because of operator being in the first/last char." << endl;
                        return false;  // returns false because of operator being in the first/last char
                    }
                }
                // tests for an operator
                if (opCount > 1) { // if there is more than one operator
                    return false; // returns false because there is more than one operator
                    cout << "Failed because there is more than one operator. opCount: " << opCount << endl;
                }
            } else {
                return false; // returns false because equation isn't valid
                cout << "The equation is not a valid one." << endl;
            }
        }
        return true;
    } else {
        return false; // returns false because the length of the equation was not 5
    }
}

/*************************************************************
 * Description: The getSecretEquation() method grabs the
 *      secretEquation variable from private and returns it.
 * Type: Getter Method
 * Inputs: Private variable secretEquation
 * Outputs: The secretEquation variable
 **************************************************************/
string Mathler::getSecretEquation() {
    return secretEquation; // returns the secretEquation variable
}

/*************************************************************
 * Description: The setSecretEquation() method assigns the
 *      secretEquation variable to the inputted equation if
 *      it is a valid equation. If it is not a valid equation,
 *      then the secretEquation will be set equal to "01+02".
 * Type: Setter Method
 * Inputs: Variable settingSecretEquation and the boolean output from the
 *      isValidEquation() method.
 * Outputs: N/A
 **************************************************************/
void Mathler::setSecretEquation(string settingSecretEquation) {
    if (isValidEquation(settingSecretEquation) == true) { // checks to see if it's a valid equation
        secretEquation = settingSecretEquation; // assigns secretEquation to settingSecretEquation
    } else {
        secretEquation = INT_MIN; // if not valid, sets secretEquation to the default INT_MIN
    }
}

/*************************************************************
 * Description: The printEquation() method will print the valid
 *      secretEquation variable.
 * Type: Printing Method
 * Inputs: N/A
 * Outputs: Variable secretEquation
 **************************************************************/
void Mathler::printEquation() {
    cout << secretEquation << endl;
}

/*************************************************************
 * Description: The getGuessNum() method will return the guessNum
 *      variable.
 * Type: Getter Method
 * Inputs: N/A
 * Outputs: Variable guessNum
 **************************************************************/
int Mathler::getGuessNum() {
    return guessNum;
}

/*************************************************************
 * Description: The makeGuess() method will check if an inputted
 *      equation from the user is a valid equation and check if 
 *      it's equal to the secretEquation or not.
 * Type: Method
 * Inputs: a string variable equationGuess
 * Outputs: A boolean true or false, true for if the equation is
 *      equal to the secretEquation and false if it's not equal.
 **************************************************************/
bool Mathler::makeGuess(string equationGuess){
    if (guessNum < (MAX_GUESS_NUM)) { // if number of guesses are less than the max number of guesses allowed...
          if (isValidEquation(equationGuess) == true) { // if the guess equation is a valid equation...
              if (equationGuess == secretEquation) { // if equationGuess is equal to secretEquation...
                  guess.push_back(equationGuess); // adds guess equation to the guess vector
                  guessNum++; // adds a number to guessNum to represent how many guesses the user is at/has made
                  if (getGuessNum() == 1){
                      cout << "Congratulations! You guessed the secret equation in " << (getGuessNum()) << " guess." << endl;
                  } else {
                      cout << "Congratulations! You guessed the secret equation in " << (getGuessNum()) << " guesses." << endl;
                  }
                  return true;
              } else if (evaluateEquation(equationGuess) == evaluateEquation(secretEquation)) { // otherwise if the answer of equationGuess is equal to the answer of secretEquation...
                  guess.push_back(equationGuess); // adds guess equation to the guess vector
                  guessNum++; // adds a number to guessNum to represent how many guesses the user is at/has made
                  return false; // returns false because the guess is not equal to the secretEquation but the answer is equal to the answer of secretEquation
              } else {
                  return false; // returns false because the guess is not equal to the secretEquation nor the answer of secretEquation
              }
          } else {
              return false; // returns false because the guess is not a valid equation
          }
    } else {
        cout << "You lost! You're out of guesses. The secret equation was '" << secretEquation << "'." << endl;
        return false; // returns false because the guess is not valid due to too many guesses
    }
}

/*************************************************************
 * Description: The printFeedback() method will print the guess
 *      vector to display the guesses and guess numbers correlating
 *      with the guesses.
 * Type: Printing Method
 * Inputs: N/A
 * Outputs: Prints the guess vector to display the guesses and 
 *      guess numbers.
 **************************************************************/
void Mathler::printFeedback() {
    for (int i = 0; i < guessNum; i++) { // loops through the guess vector
        cout << i + 1 << ": " << guess[i] << endl; // displays the guess numbers with correlating guesses
    }
}

/*************************************************************
 * Description: The generateRandomEquation() method generates a
 *      random valid equation for the secret equation.
 * Type: Method
 * Inputs: N/A
 * Outputs: Variable secretEquation
 **************************************************************/
void Mathler::generateRandomEquation() {
    int num1 = rand() % 10; // generate a random number between 1 and 10
    int num2 = rand() % 10; // generate a random number between 1 and 10
    int num3 = rand() % 10; // generate a random number between 1 and 10
    int num4 = rand() % 10; // generate a random number between 1 and 10
    int num5 = rand() % 10; // generate a random number between 1 and 10
    int opPos = rand() % 3 + 1;
    int operation = rand() % 3; // generate a random number between 0 and 2
    string aSecretEquation;


    stringstream ss;
    ss << num1;
    string strNum1 = ss.str();
    ss.str("");
    ss.clear();
    ss << num2;
    string strNum2 = ss.str();
    ss.str("");
    ss.clear();
    ss << num3;
    string strNum3 = ss.str();
    ss.str("");
    ss.clear();
    ss << num4;
    string strNum4 = ss.str();
    ss.str("");
    ss.clear();
    ss << num5;
    string strNum5 = ss.str();

    if (operation == 0) {
        // addition = 0
        // sets aSecretEquation to a randomized 5 number digit
        aSecretEquation = strNum1 + strNum2 + strNum3 + strNum4 + strNum5;
        aSecretEquation[opPos] = '+'; // changes the opPos index of aSecretEquation to the operator
    } else if (operation == 1) {
        // subtraction = 1
        aSecretEquation = strNum1 + strNum2 + strNum3 + strNum4 + strNum5;
        aSecretEquation[opPos] = '-';
    } else if (operation == 2) {
        // multiplication = 2
        aSecretEquation = strNum1 + strNum2 + strNum3 + strNum4 + strNum5;
        aSecretEquation[opPos] = '*';
    } else {
        cout << "Invalid number for finding secret equation. The number was: " << operation << endl;
    }
    secretEquation = aSecretEquation; // sets secretEquation to the value of aSecretEquation
}

/*************************************************************
 * Description: The evaluateEquation() method takes a given valid
 *      equation and evaluates it and returns the answer to the
 *      given valid equation.
 * Type: Method
 * Inputs: Variable equation and the boolean output from the
 *      isValidEquation() method.
 * Outputs: The answer to the either integar addition, subtraction,
 *      or multiplication OR INT_MIN if it is an invalid equation.
 **************************************************************/
int evaluateEquation(const string & equation){
    if (isValidEquation(equation) == true){ // checks if the equation is valid
        int answer;
        // string buffer = "12+35";
        stringstream ss(equation);
        int num1, num2;
        char theOperator;
        ss >> num1 >> theOperator >> num2;

        if (theOperator == '+') { // checks if the equation's operator indicates addition
            answer = num1 + num2; // sets answer to the sum of the equation
//            cout << "The answer to add. is: " << answer << endl;
        } else if (theOperator == '-') { // checks if the equation's operator indicates subtraction
            answer = num1 - num2; // sets answer to the difference of the equation
//            cout << "The answer to sub. is: " << answer << endl;
        } else if (theOperator == '*') { // checks if the equation's operator indicates multiplication
            answer = num1 * num2; // sets answer to the product of the equation
//            cout << "The answer to mult. is: " << answer << endl;
        }
        return answer;
        cout << "The final answer is: " << answer << endl; // return the final answer
    } else {
        return INT_MIN; // returns INT_MIN if not valid equation
    }
}
