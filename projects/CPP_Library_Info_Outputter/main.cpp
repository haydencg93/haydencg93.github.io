/************************************************************************************************
 * Programmer: Hayden Gamble
 * Date: 04/05/2024
 * Project Name: hw6
 * Description of Program: This C++ program is a program that outputs the name, author, and year for a 
 *                   book and audiobook. It will also output the genre and pages for a book,
 *                   the narrator and duration for an audiobook. On top of that, it'll also output the name
 *                   and issue number for a magazine.
 ************************************************************************************************/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Necessary Header Files*/
#include <iostream>
#include "Item.h"
#include "Book.h"
#include "Audiobook.h"
#include "Magazine.h"

/*************************************************************
 * Description: The main() function tests the Item, Book, Audiobook, and Magazine
 *             classes. It also tests specific things inside each one like the 
 *             print() functions, the constructors, and assignment copy operators.
 * Type: Main Method
 * Inputs: N/A
 * Outputs: The tests for each class mentioned above being tested.
 **************************************************************/
int main() {
  /* Item Testing */
    cout << "\nItem Testing: " << endl;
  // item1
    cout << "\nTesting parameterized constructor for item1. Expected output: IT, Stephen King, 1986." << endl;
    Item item1("IT", "Stephen King", 1986);
    cout << "Actual Output: " << endl;
    item1.print();
  // item2
    cout << "\nTesting parameterized constructor for item2. Expected output: ' ', ' ', 0." << endl;
    Item item2("");
    cout << "Actual Output: " << endl;
    item2.print();
  // item 3
    cout << "\nTesting parameterized constructor for item3. Expected output: Dance on My Grave, ' ', 0." << endl;
    Item item3("Dance on My Grave");
    cout << "Actual Output: " << endl;
    item3.print();

    cout << "___________________________________________________" << endl;

  /* Book Testing */
    cout << "\nBook Testing: " << endl;
    // book1
    cout << "\nTesting parameterized constructor for book1. Expected output: The Great Gatsby, F. Scott Fitzgerald, 1925, Fiction, 180." << endl;
    Book book1("The Great Gatsby", "F. Scott Fitzgerald", 1925, "Fiction", 180);
    cout << "Actual Output: " << endl;
    book1.print();
  // book2
    cout << "\nTesting parameterized constructor for book2. Expected output: Heartstopper #5: A Graphic Novel, Alice Oseman, 2023, Comics, 336" << endl;
    Book book2("Heartstopper #5: A Graphic Novel", "Alice Oseman", 2023, "Comics", 336);
    cout << "Actual Output: " << endl;
    book2.print();
  // book3
    cout << "\nTesting parameterized constructor for book3. Expected output: ' ', ' ', 0, ' ', 0" << endl;
    Book book3("");
    cout << "Actual Output: " << endl;
    book3.print();
  // book4
    cout << "\nTesting parameterized constructor for book4. Expected output: 1984, George Orwell, 1949, Fiction, 0" << endl;
    Book book4("1984", "", 1949, "Fiction");
    cout << "Actual Output: " << endl;
    book4.print();

    cout << "___________________________________________________" << endl;

  /* Audiobook Testing */
    cout << "\nAudiobook Testing: " << endl;
  // ab1
    cout << "\nTesting parameterized constructor for ab1. Expected output: Pride and Prejudice, Jane Austen, 1813, Emma Thompson, 360." << endl;
    Audiobook ab1("Pride and Prejudice", "Jane Austen", 1813, "Emma Thompson", 360);
    cout << "Actual Output: " << endl;
    ab1.print();
  // ab2
    cout << "\nTesting parameterized constructor for ab2. Expected output: Harry Potter and the Goblet of Fire, J.K. Rowling, 2000, Jim Dale, 21." << endl;
    Audiobook ab2("Harry Potter and the Goblet of Fire", "J.K. Rowling", 2000, "Jim Dale", 21);
    cout << "Actual Output: " << endl;
    ab2.print();
  // ab3
    cout << "\nTesting parameterized constructor for ab3. Expected output: ' ', ' ', 0, ' ', 0" << endl;
    Audiobook ab3("");
    cout << "Actual Output: " << endl;
    ab3.print();
  // ab4
    cout << "\nTesting parameterized constructor for ab4. Expected output: Wonder, R.J. Palacio, 1987, Dariana Alvarez, 0" << endl;
    Audiobook ab4("Wonder", "", 1987, "Dariana Alvarez");
    cout << "Actual Output: " << endl;
    ab4.print();

    cout << "___________________________________________________" << endl;

  /* Magazine Testing */
    cout << "\nMagazine Testing: " << endl;
  // mag1
    cout << "\nTesting copy assignment operator for mag1. Expected output: IEEE Spectrum, 42." << endl;
    char mag1Test[] = "IEEE Spectrum";
    Magazine mag1(mag1Test, 42);
    cout << "Actual Output: " << endl;
    mag1.print();
  // mag2
    cout << "\nTesting copy assignment operator for mag2. Expected output: NY Times, 42." << endl;
    char mag2Test[] = "NY Times";
    Magazine mag2(mag2Test, 42);
    cout << "Actual Output: " << endl;
    mag2.print();
  // mag3
    cout << "\nTesting copy assignment operator for mag3. Expected output: ' ', 0" << endl;
    char mag3Test[] = "";
    Magazine mag3(mag3Test);
    cout << "Actual Output: " << endl;
    mag3.print();
  // mag4
    cout << "\nTesting copy assignment operator for mag4. Expected output: Vogue, 0" << endl;
    char mag4Test[] = "Vogue";
    Magazine mag4(mag4Test);
    cout << "Actual Output: " << endl;
    mag4.print();

  /* Constructor, Copy Constructor, and Assignment Copy Operator Testing */
    cout << "\n----------\nTesting Constructor, Copy Constructor, and Assignment Copy Operator: " << endl;
  // constructor
    cout << "\nTesting Constructor:" << endl;
    char mag5Test[] = "Vogue";
    Magazine mag5(mag5Test, 24);
    mag5.print();
  // copy constructor
    cout << "\nTesting Copy Constructor:" << endl;
    Magazine mag6(mag5);
    mag6.print();
  // assignment copy operator
    cout << "\nTesting Assignment Copy Operator:" << endl;
    Magazine mag7 = mag5;
    mag7.print();
  // testing to ensure that the assignment copy operator works properly
    char mag5Test2[] = "test";
    mag5.setName(mag5Test2);
  // testing new names
    cout << "\n----------\nNew Names Testing: \n\nmag5: " << endl;
  // mag5
    mag5.print();
  // mag7
    cout << "\nmag7: " << endl;
    mag7.print();

  /* Destructor Testing */
    cout << "___________________________________________________" << endl;
    cout << "\nTesting Destructor: " << endl;
}
