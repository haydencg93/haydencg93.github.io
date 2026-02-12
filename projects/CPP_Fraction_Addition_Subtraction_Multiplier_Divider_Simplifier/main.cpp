/************************************************************************************************
 * Programmer: Hayden Gamble
 * Date: 02/09/2024
 * Project Name: hw2
 * Description of Program: This C++ program takes fractions and calculates/finds the decimal version
 *           of the fraction, the sum, difference, product, and quotient two fractions, and can
 *           simplify a fraction to it's simplest form.
 ************************************************************************************************/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Header Files */
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

/*************************************************************
 * Description: The constructor
 * Type: Class
 * Inputs:
 * Outputs:
 **************************************************************/
class Fraction{
public:
    /*************************************************************
    * Description: The Fraction constructor initializes numer
    *           and denom as public variables.
    * Type: Constructor
    * Inputs: Variables numer and denom.
    * Outputs: N/A
    **************************************************************/
    Fraction(int numer = 0, int denom = 1){
        // Calling out the setFraction() method using the variable inputs.
        // If no input is given, the numerator will be 0 and the denominator will be 1.
        setFraction(numer, denom);
    }
    /*************************************************************
    * Description: The setFraction() method uses the variable numer
    *           and denom to set the numerator and denominator
    *           variables to the correct numbers that were inputted
    *           according to basic mathematical fraction regulations.
    * Type: Method
    * Inputs: Variables names numer and denom.
    * Outputs: Print statements showing what stage each one is in
    *           and assigns the private varibles numerator and
    *           denominator to the correct value based on the
    *           numer and denom variables.
    **************************************************************/
    void setFraction(int numer, int denom) {
        if (denom > 0){
            // If the denominator is greater than zero...
            denominator = denom;
            numerator = numer;
            // Assigns correct values in for the main numerator and denominator variables
            cout << "testing if above 0 in denominator. numerator: " << numerator << endl;
            cout << "testing if above 0 in denominator. denominator: " << denominator << endl;
        } else if (denom < 0){
            // If the denominator is negative...
            denominator = abs(denom);
            numerator = numer * (-1);
            // Changes the sign of the numerator and takes the absolute value of the denominator
            cout << "testing negative in denominator. numerator: " << numerator << endl;
            cout << "testing negative in denominator. denominator: " << denominator << endl;
        } else {
            // If the denominator is zero...
            denominator = 1;
            numerator = numer;
            // Assign the denominator to 1 and the numerator to the correct numerator
            cout << "making 1 the denominator. numerator: " << numerator << endl;
            cout << "making 1 the denominator. denominator: " << denominator << endl;
        }
    }
    int getNumerator() const {
        return numerator;
        // Returns the final numerator.
        cout << "getNumerator finished:" << numerator << endl;
    }
    int getDenominator () const {
        return denominator;
        // Returns the final denominator.
        cout << "getDenominator finished:" << denominator << endl;
    }
    /*************************************************************
    * Description: The toFloat() method returns the decimal value
    *           of the fraction that has been determined above.
    * Type: Method
    * Inputs: The private numerator and denominator variables.
    * Outputs: A decimal value of the fraction in form of a float.
    **************************************************************/
    float toFloat() {
        // Returns the decimal value of the fraction that has been determined.
        return ((static_cast<float>(numerator)) / (denominator));
        cout << "toFloat method finished. decimal of fraction: " << ((static_cast<float>(numerator)) / (static_cast<float>(denominator))) << endl;
    }
    /*************************************************************
    * Description: The print() method prints the fraction in the
    *           form of "(n_1)/(n_2).
    * Type: Method
    * Inputs: The private numerator and denominator variables.
    * Outputs: The fraction in the form of "(n_1)/(n_2).
    **************************************************************/
    void print() const {
        // Prints out the final fraction in fraction form.
        cout << numerator << "/" << denominator << endl;
    }
    /*************************************************************
    * Description: The add() method adds two fractions together.
    * Type: Method
    * Inputs: The private numerator and denominator variables and
    *           a new variable for the second fraction given.
    * Outputs: The new numerator and denominator of the sum of the
    *           two fractions.
    * Thought Process:
    * (n_1/d_1) + (n_2/d_2) = (n_1*d_2 + n_2*d_1)/(d_1*d_2)
     **************************************************************/
    void add(const Fraction& frac2) {
        // Calculates the sum of two fractions.
        numerator = ((numerator * frac2.getDenominator()) + (frac2.getNumerator() * denominator));
        denominator = (denominator * frac2.getDenominator());
    }
    /*************************************************************
    * Description: The subtract() method subtracts two fractions
    *           together.
    * Type: Method
    * Inputs: The private numerator and denominator variables and
    *           a new variable for the second fraction given.
    * Outputs: The new numerator and denominator of the difference
    *            of the two fractions.
    * Thought Process:
    * (n_1/d_1) - (n_2/d_2) = (n_1*d_2 - n_2*d_1)/(d_1*d_2)
    **************************************************************/
    void subtract(const Fraction& frac2) {
        // Calculates the difference of two fractions.
        numerator = ((numerator * frac2.getDenominator()) - (frac2.getNumerator() * denominator));
        denominator = (denominator * frac2.getDenominator());
    }
    /*************************************************************
    * Description: The multiply() method multiplies two fractions
    *           together.
    * Type: Method
    * Inputs: The private numerator and denominator variables and
    *           a new variable for the second fraction given.
    * Outputs: The new numerator and denominator of the product of
    *            the two fractions.
    **************************************************************/
    void multiply(const Fraction& frac2){
        // Calculates the product of two fractions.
        numerator = (numerator * frac2.getNumerator());
        denominator = (denominator * frac2.getDenominator());
    }
    /*************************************************************
    * Description: The divide() method divides two fractions
    *           together.
    * Type: Method
    * Inputs: The private numerator and denominator variables and
    *           a new variable for the second fraction given.
    * Outputs: The new numerator and denominator of the quotient
    *            of the two fractions.
    **************************************************************/
    void divide(const Fraction& frac2){
        // Calculates the quotient of two fractions.
        numerator = (numerator * frac2.getDenominator());
        denominator = (denominator * frac2.getNumerator());
    }
    /*************************************************************
    * Description: The simplify() method simplifies the fraction.
    * Type: Method
    * Inputs: The private numerator and denominator variables.
    * Outputs: The new numerator and denominator of the simplified
    *            fraction.
    **************************************************************/
    void simplify() {
        // Simplifies the fraction given.
        int gcdOfFrac = __gcd(numerator, denominator);
        numerator = (numerator / gcdOfFrac);
        denominator = (denominator / gcdOfFrac);
    }

private:
    int numerator;
    int denominator;
};

/*************************************************************
 * Description: The main() method is where the inputs for the
 *          fractions go. Also, it holds the test cases for the
 *          methods in the class.
 * Type: Main Method
 * Inputs: N/A
 * Outputs: The test cases for everything inside the class and
 *          and the answers for each method necessary in the
 *          Fraction class.
 **************************************************************/
int main() {
    /* Testing toFloat() */
    cout << "\n" << "Testing toFLoat():" << endl;
    cout << " Test #1:" << endl;
    Fraction float1;
    if (abs(float1.toFloat() - 0.0/1.0) < 0.0001) {
        cout << "Test passed: fraction evaluated to the correct answer: " << float1.toFloat() << endl;
    } else {
        cout << "Test failed: fraction evaluated to " << float1.toFloat() << ". The correct answer is " << 0.0/1.0 << endl;
    }
    cout << " Test #2:" << endl;
    Fraction float2(2);
    if (abs(float2.toFloat() - 2.0/1.0) < 0.0001) {
        cout << "Test passed: fraction evaluated to the correct answer: " << float2.toFloat() << endl;
    } else {
        cout << "Test failed: fraction evaluated to " << float2.toFloat() << ". The correct answer is " << 2.0/1.0 << endl;
    }
    cout << " Test #3:" << endl;
    Fraction float3(2, 3);
    if (abs(float3.toFloat() - 2.0/3.0) < 0.0001) {
        cout << "Test passed: fraction evaluated to the correct answer: " << float3.toFloat() << endl;
    } else {
        cout << "Test failed: fraction evaluated to " << float3.toFloat() << ". The correct answer is " << 2.0/3.0 << endl;
    }

    /* Testing print() */
    cout << "\n" << "Testing print():" << endl;
    Fraction printTest(3, 4);
    printTest.print();

    /* Addition Tests */
    cout << "\n" << "Addition Tests: " << endl;
    cout << " Test #1: " << endl;
    Fraction add1;
    Fraction add2(3, 2);
    add2.add(add1);
    if (add2.getNumerator() == 3 && add2.getDenominator() == 2) {
        cout << "Test passed: 0/1 + 3/2 = 3/2." << endl;
    } else {
        cout << "Test failed: 0/1 - 3/2 = 3/2 and not " << add2.getNumerator() << "/" << add2.getDenominator() << "." << endl;
    }
    cout << " Test #2: " << endl;
    Fraction add3(2);
    Fraction add4(1, 5);
    add4.add(add3);
    if (add4.getNumerator() == 11 && add4.getDenominator() == 5) {
        cout << "Test passed: 1/5 + 2/1 = 11/5." << endl;
    } else {
        cout << "Test failed: 1/5 - 2/1 = 11/5 and not " << add4.getNumerator() << "/" << add4.getDenominator() << "." << endl;
    }
    cout << " Test #3: " << endl;
    Fraction add5(2, 3);
    Fraction add6(1, 2);
    add6.add(add5);
    if (add6.getNumerator() == 7 && add6.getDenominator() == 6) {
        cout << "Test passed: 1/2 + 2/3 = 7/6." << endl;
    } else {
        cout << "Test failed: 1/2 - 2/3 = 7/6 and not " << add6.getNumerator() << "/" << add6.getDenominator() << "." << endl;
    }

    /* Subtraction Tests */
    cout << "\n" << "Subtraction Tests: " << endl;
    cout << " Test #1: " << endl;
    Fraction sub1;
    Fraction sub2(9, 5);
    sub2.subtract(sub1);
    if (sub2.getNumerator() == -1 && sub2.getDenominator() == 6) {
        cout << "Test passed: 9/5 - 0/1 = 9/5." << endl;
    } else {
        cout << "Test failed: 9/5 - 0/1 = 9/5 and not " << sub2.getNumerator() << "/" << sub2.getDenominator() << "." << endl;
    }
    cout << " Test #2: " << endl;
    Fraction sub3(10, 9);
    Fraction sub4(3);
    sub4.subtract(sub3);
    if (sub4.getNumerator() == 17 && sub4.getDenominator() == 9) {
        cout << "Test passed: 3/1 - 10/9 = 17/9." << endl;
    } else {
        cout << "Test failed: 3/1 - 10/9 = 17/9 and not " << sub4.getNumerator() << "/" << sub4.getDenominator() << "." << endl;
    }
    cout << " Test #3: " << endl;
    Fraction sub5(2, 3);
    Fraction sub6(1, 2);
    sub6.subtract(sub5);
    if (sub6.getNumerator() == -1 && sub6.getDenominator() == 6) {
        cout << "Test passed: 1/2 - 2/3 = -1/6." << endl;
    } else {
        cout << "Test failed: 1/2 - 2/3 = -1/6 and not " << sub6.getNumerator() << "/" << sub6.getDenominator() << "." << endl;
    }

/* Multiplication Tests */
    cout << "\n" << "Multiplication Tests: " << endl;
    cout << " Test #1: " << endl;
    Fraction multiply1;
    Fraction multiply2(3, 2);
    multiply2.multiply(multiply1);
    if (multiply2.getNumerator() == 0 && multiply2.getDenominator() == 2) {
        cout << "Test passed: 0/1 * 3/2 = 0/2." << endl;
    } else {
        cout << "Test failed: 0/1 * 3/2 = 0/2 and not " << multiply2.getNumerator() << "/" << multiply2.getDenominator() << "." << endl;
    }
    cout << " Test #2: " << endl;
    Fraction multiply3(2);
    Fraction multiply4(1, 5);
    multiply4.multiply(multiply3);
    if (multiply4.getNumerator() == 2 && multiply4.getDenominator() == 5) {
        cout << "Test passed: 1/5 * 2/1 = 2/5." << endl;
    } else {
        cout << "Test failed: 1/5 * 2/1 = 2/5 and not " << multiply4.getNumerator() << "/" << multiply4.getDenominator() << "." << endl;
    }
    cout << " Test #3: " << endl;
    Fraction multiply5(2, 3);
    Fraction multiply6(1, 2);
    multiply6.multiply(multiply5);
    if (multiply6.getNumerator() == 2 && multiply6.getDenominator() == 6) {
        cout << "Test passed: 1/2 * 2/3 = 2/6." << endl;
    } else {
        cout << "Test failed: 1/2 * 2/3 = 2/6 and not " << multiply6.getNumerator() << "/" << multiply6.getDenominator() << "." << endl;
    }

/* Division Tests */
    cout << "\n" << "Division Tests: " << endl;
    cout << " Test #1: " << endl;
    Fraction divide1;
    Fraction divide2(3, 2);
    divide1.divide(divide2);
    if (divide1.getNumerator() == 0 && divide1.getDenominator() == 3) {
        cout << "Test passed: 0/1 / 3/2 = 0/3." << endl;
    } else {
        cout << "Test failed: 0/1 / 3/2 = 0/3 and not " << divide1.getNumerator() << "/" << divide1.getDenominator() << "." << endl;
    }
    cout << " Test #2: " << endl;
    Fraction divide3(2);
    Fraction divide4(1, 5);
    divide4.divide(divide3);
    if (divide4.getNumerator() == 1 && divide4.getDenominator() == 10) {
        cout << "Test passed: 1/5 / 2/1 = 1/10." << endl;
    } else {
        cout << "Test failed: 1/5 / 2/1 = 1/10 and not " << divide4.getNumerator() << "/" << divide4.getDenominator() << "." << endl;
    }
    cout << " Test #3: " << endl;
    Fraction divide5(2, 3);
    Fraction divide6(1, 2);
    divide6.divide(divide5);
    if (divide6.getNumerator() == 3 && divide6.getDenominator() == 4) {
        cout << "Test passed: 1/2 / 2/3 = 3/4." << endl;
    } else {
        cout << "Test failed: 1/2 / 2/3 = 3/4 and not " << divide6.getNumerator() << "/" << divide6.getDenominator() << "." << endl;
    }

    /* testing simplification: */
    cout << "\n" << "Simplification Tests: " << endl;
    cout << " Test #1: " << endl;
    Fraction simplify1;
    simplify1.simplify();
    if (simplify1.getNumerator() == 0 && simplify1.getDenominator() == 1) {
        cout << "Test passed: 0/1 simplified to 0/1." << endl;
    } else {
        cout << "Test failed: 8/2 simplified to " << simplify1.getNumerator() << "/" << simplify1.getDenominator() << " and not 0/1." << endl;
    }
    cout << " Test #2: " << endl;
    Fraction simplify2(100);
    simplify2.simplify();
    if (simplify2.getNumerator() == 100 && simplify2.getDenominator() == 1) {
        cout << "Test passed: 100/1 simplified to 100/1." << endl;
    } else {
        cout << "Test failed: 100/2 simplified to " << simplify2.getNumerator() << "/" << simplify2.getDenominator() << " and not 100/1." << endl;
    }
    cout << " Test #3: " << endl;
    Fraction simplify3(50, 15);
    simplify3.simplify();
    if (simplify3.getNumerator() == 10 && simplify3.getDenominator() == 3) {
        cout << "Test passed: 50/15 simplified to 10/3." << endl;
    } else {
        cout << "Test failed: 50/15 simplified to " << simplify3.getNumerator() << "/" << simplify3.getDenominator() << " and not 10/3." << endl;
    }
    // Returns 0 to end the running of the file.
    return 0;
}
