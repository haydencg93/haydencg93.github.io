//
// Created by hcgamble on 4/3/2024.
//

#include "Book.h" // includes the code inside Book.h

/*************************************************************
 * Description: The Book class constructor initializes the genre 
 *      and pages variables and sets the default values for them.
 *      It also initializes the title, author, and year variables
 *      in the Item class.
 * Type: Constructor
 * Inputs: Variables genre and pages
 * Outputs: N/A
 **************************************************************/
Book::Book(const string &title, const string &author,
           int year, const string &genre, int pages) : Item(title, 
            author, year), genre(genre), pages(pages) {
    Book::setGenre(genre); // sets the genre variable
    Book::setPages(pages); // sets the pages variable
}

/*************************************************************
 * Description: The getGenre method returns the genre variable.
 * Type: Getter
 * Inputs: N/A
 * Outputs: Private genre Variable
 **************************************************************/
const string &Book::getGenre() const {
    return genre;
}

/*************************************************************
 * Description: The setGenre method sets the genre variable to
 *            correct value.
 * Type: Setter
 * Inputs: Inputted genre variable
 * Outputs: N/A
 **************************************************************/
void Book::setGenre(const string &genre) {
    Book::genre = genre;
}

/*************************************************************
 * Description: The getPages method returns the pages variable.
 * Type: Getter
 * Inputs: N/A
 * Outputs: Private pages Variable
 **************************************************************/
int Book::getPages() const {
    return pages;
}

/*************************************************************
 * Description: The setPages method sets the pages variable to
 *            correct value.
 * Type: Setter
 * Inputs: Inputted pages variable
 * Outputs: N/A
 **************************************************************/
void Book::setPages(int pages) {
    Book::pages = pages;
}

/*************************************************************
 * Description: The print method prints the output for the program.
 * Type: print Method
 * Inputs: N/A
 * Outputs: private genre and pages variables along with the output
 *      of the Item class print method
 **************************************************************/
void Book::print(){
    cout << "Type: Book" << endl;
    Item::print();
    cout << "Genre: " << getGenre() << endl;
    cout << "Pages: " << getPages() << endl;
}