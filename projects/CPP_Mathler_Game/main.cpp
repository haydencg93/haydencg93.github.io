/************************************************************************************************
 * Programmer: Hayden Gamble
 * Date: 02/16/2024
 * Project Name: hw3
 * Description of Program: This C++ program is a program that accomplishes the same goal as the
 *      famous Mathler game.
 ************************************************************************************************/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Mathler.h" // includes the code inside Mathler.h

/*************************************************************
 * Description: The main() function tests the isValidEquation(),
 *      evaluateEquation(), constructor, setter, getter, secretEquation(),
 *      and printEquation() methods in Mathler.cpp/.h files.
 * Type: Main Method
 * Inputs: N/A
 * Outputs: The tests for each method mentioned above being tested.
 **************************************************************/
int main() {
    srand(time(nullptr)); // seed random number generator

    /* Milestone 1: */
    cout << "MILESTONE 1:\n" << endl;

    /* testing Constructor: */
    cout << "testing Constructor: " << endl;
    Mathler mathler0("02+22");
    if (mathler0.getSecretEquation() == "02+22") {
        cout << "test passed. constructor test value: " << mathler0.getSecretEquation() << endl;
    } else {
        cout << "test failed. equation should be 02+22 and not " << mathler0.getSecretEquation() << endl;
    }

    /* Testing printEquation() */
    cout << "\n" << "Testing print():" << endl;
    Mathler printTest("24+02");
    if (printTest.getSecretEquation() == "24+02") {
        cout << "test passed. printTest value: " << printTest.getSecretEquation() << endl;
    } else {
        cout << "test failed. equation should be 24+02 and not " << printTest.getSecretEquation() << endl;
    }


    /* testing evaluateEquation and isValidEquation at once: */
    Mathler mathler1("12+24");
    cout << "\n" << "testing evaluateEquation and isValidEquation at once: " << endl;
    if (evaluateEquation(mathler1.getSecretEquation()) == 36){
        cout << "Test passed: 12+24 = " << evaluateEquation(mathler1.getSecretEquation()) << endl;
    } else {
        cout << "Test failed: 12+24 != " << evaluateEquation(mathler1.getSecretEquation()) << endl;
    }
    Mathler mathler2("100-4");
    if (evaluateEquation(mathler2.getSecretEquation()) == 96){
        cout << "Test passed: 100-4 = " << evaluateEquation(mathler2.getSecretEquation()) << endl;
    } else {
        cout << "Test failed: 100-4 != " << evaluateEquation(mathler2.getSecretEquation()) << endl;
    }
    Mathler mathler3("4*100");
    if (evaluateEquation(mathler3.getSecretEquation()) == 400){
        cout << "Test passed: 4*100 = " << evaluateEquation(mathler3.getSecretEquation()) << endl;
    } else {
        cout << "Test failed: 4*100 != " << evaluateEquation(mathler3.getSecretEquation()) << endl;
    }
    if (isValidEquation(mathler3.getSecretEquation())){
        cout << "Test passed: 4*100 was correctly not flagged as an invalid equation." << endl;
    } else {
        cout << "Test failed: 4*100 should not be flagged as an invalid equation." << endl;
    }
    Mathler mathler4("1+24");
    if (evaluateEquation(mathler4.getSecretEquation()) == INT_MIN){
        cout << "Test passed: 1+24 was correctly flagged as an invalid equation." << endl;
    } else {
        cout << "Test failed: 1+24 should be flagged as an invalid equation." << endl;
    }
    Mathler mathler5("12+4");
    if (evaluateEquation(mathler5.getSecretEquation()) == INT_MIN){
        cout << "Test passed: 12+4 was correctly flagged as an invalid equation." << endl;
    } else {
        cout << "Test failed: 12+4 should be flagged as an invalid equation." << endl;
    }
    Mathler mathler6("1+4");
    if (evaluateEquation(mathler6.getSecretEquation()) == INT_MIN){
        cout << "Test passed: 1+4 was correctly flagged as an invalid equation." << endl;
    } else {
        cout << "Test failed: 1+4 should be flagged as an invalid equation." << endl;
    }
    Mathler mathler7("+8564");
    if (evaluateEquation(mathler7.getSecretEquation()) == INT_MIN){
        cout << "Test passed: +8564 was correctly flagged as an invalid equation." << endl;
    } else {
        cout << "Test failed: +8564 should be flagged as an invalid equation." << endl;
    }
    Mathler mathler8("6585+");
    if (evaluateEquation(mathler8.getSecretEquation()) == INT_MIN){
        cout << "Test passed: 6585+ was correctly flagged as an invalid equation." << endl;
    } else {
        cout << "Test failed: 6585+ should be flagged as an invalid equation." << endl;
    }
    Mathler mathler9("24-90");
    if (mathler9.getSecretEquation() == "24-90"){
        cout << "Test passed: 24-90 was correctly set as the secret equation: " << mathler9.getSecretEquation() << endl;
    } else {
        cout << "Test failed: 24-90 was not set as the secret equation: " << mathler9.getSecretEquation() << endl;
    }

    /* Milestone 2: */
    cout << "\n\nMILESTONE 2:\n" << endl;

    /* testing generateRandomEquation(): */
    cout << "testing generateRandomEquation(): " << endl;
    Mathler testGenerate;
    for(int i = 0; i < 5; i++) {
        testGenerate.generateRandomEquation();
        string equation = testGenerate.getSecretEquation();
        cout << "test " << (i+1) << ": " << equation << endl;
    }

    /* Milestone 3: */
    cout << "\n\nMILESTONE 3:\n" << endl;

    /* testing makeGuess() & printFeedback(): */
    cout << "testing makeGuess() & printFeedback(): " << endl;
    Mathler mathler10("11+11");
    mathler10.setSecretEquation("13+15");
    cout << "Setting secret equation to 13+15. The secret equation is " << mathler10.getSecretEquation() << ".\n" << endl;
    mathler10.makeGuess("10+18");
    mathler10.makeGuess("30-02");
    mathler10.makeGuess("20+08");
    mathler10.makeGuess("50-22");
    mathler10.makeGuess("10-18");
    mathler10.makeGuess("30+02");
    mathler10.makeGuess("99-71");
    mathler10.makeGuess("29-01");
    mathler10.makeGuess("13+15");
    mathler10.printFeedback();

    /* Milestone 4: */
    cout << "\n\nMILESTONE 4:\n" << endl;

    /* starting the actual Mathler game: */
    Mathler mathlerGame;
    cout << "Guess the easy Mathler in 6 tries.\n" << endl;
    cout << "Each guess must be a valid 5-character equation that evaluates to the same value as the secret equation." << endl;
    cout << "Hit the enter button to submit.\n" << endl;
    mathlerGame.generateRandomEquation(); // gets the random secret equation
//    mathlerGame.setSecretEquation("03+02"); // uncomment for testing an easy equation of "03+02"
    string secEquation = mathlerGame.getSecretEquation();
    cout << "Randomly set secret equation: " << secEquation << "\n" << endl;
    cout << "Guess an equation that evaluates to " << evaluateEquation(secEquation) << ".\n" << endl;
    string userInput; // create variable for grabbing user's guess
    bool gameOver = false;
    while ((mathlerGame.getGuessNum() < MAX_GUESS_NUM) && (!gameOver)){ // while the amount of guesses is 6 or less...
        mathlerGame.printFeedback(); // prints the amount of guesses the user has done so far
        cout << "You're on guess #" << (mathlerGame.getGuessNum() + 1) << "." << endl;
        cout << "Enter Guess: " << endl;
        cin >> userInput; // grabs user's input
        mathlerGame.makeGuess(userInput); // evaluates if the guess is valid and will print out if user lost/won
        // mathlerGame.getGuessNum(); // grabs the amount of guesses the user has done so far
        if (userInput == mathlerGame.getSecretEquation()) { // if the user's guess is the same as the randomly generated secret equation...
            gameOver = true;
        } else if (mathlerGame.getGuessNum() == 6) {
            cout << "You lost! You're out of guesses. The secret equation was '" << mathlerGame.getSecretEquation() << "'." << endl;
        }
    }
}
