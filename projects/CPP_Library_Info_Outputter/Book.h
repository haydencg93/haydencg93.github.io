//
// Created by hcgamble on 4/3/2024.
//

#ifndef HW6_BOOK_H
#define HW6_BOOK_H

#include "Item.h" // includes the code inside Item.h

class Book : public Item { // Book class with inheritance from Item
public: // public access
    Book(const string &title=" ", const string &author=" ",
         int year=0000, const string &genre=" ", int pages=0); // Book constructor

    const string &getGenre() const; // genre getter

    void setGenre(const string &genre); // genre setter

    int getPages() const; // pages getter

    void setPages(int pages); // pages setter

    void print(); // print method

private:
    string genre; // genre variable
    int pages; // pages variable
};


#endif //HW6_BOOK_H