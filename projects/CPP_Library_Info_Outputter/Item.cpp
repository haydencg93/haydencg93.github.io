//
// Created by hcgamble on 4/1/2024.
//

#include "Item.h" // includes the code inside Item.h

/*************************************************************
 * Description: The Item class constructor initializes the title, 
 *      author, and year variables and sets the default values for 
 *      them.
 * Type: Constructor
 * Inputs: Variables title, author, and year
 * Outputs: N/A
 **************************************************************/
Item::Item(const string &title, const string &author, int year) : title(title), author(author), year(year) {
    Item::setTitle(title);
    Item::setAuthor(author);
    Item::setYear(year);
  // cout << "~ Inside Item Constructor" << endl;
}

/*************************************************************
 * Description: The getTitle method returns the title variable.
 * Type: Getter
 * Inputs: N/A
 * Outputs: Private title Variable
 **************************************************************/
const string &Item::getTitle() const {
    return title;
}

/*************************************************************
 * Description: The setTitle method sets the title variable to
 *            correct value.
 * Type: Setter
 * Inputs: Inputted title variable
 * Outputs: N/A
 **************************************************************/
void Item::setTitle(const string &title) {
    Item::title = title;
}

/*************************************************************
 * Description: The getAuthor method returns the author variable.
 * Type: Getter
 * Inputs: N/A
 * Outputs: Private author Variable
 **************************************************************/
const string &Item::getAuthor() const {
    return author;
}

/*************************************************************
 * Description: The setAuthor method sets the author variable to
 *            correct value.
 * Type: Setter
 * Inputs: Inputted author variable
 * Outputs: N/A
 **************************************************************/
void Item::setAuthor(const string &author) {
    Item::author = author;
}

/*************************************************************
 * Description: The getUear method returns the year variable.
 * Type: Getter
 * Inputs: N/A
 * Outputs: Private year Variable
 **************************************************************/
int Item::getYear() const {
    return year;
}

/*************************************************************
 * Description: The setYear method sets the year variable to
 *            correct value.
 * Type: Setter
 * Inputs: Inputted year variable
 * Outputs: N/A
 **************************************************************/
void Item::setYear(int year) {
    Item::year = year;
}

/*************************************************************
 * Description: The print method prints the output for the program.
 * Type: print Method
 * Inputs: N/A
 * Outputs: private title, author, and year variables
 **************************************************************/
void Item::print() {
    cout << "Title: " << getTitle() << endl;
    cout << "Author: " << getAuthor() << endl;
    cout << "Year: " << getYear() << endl;
}