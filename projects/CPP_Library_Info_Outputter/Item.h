//
// Created by hcgamble on 4/1/2024.
//

/* Necessary Header Files */
#ifndef HW6_ITEM_H
#define HW6_ITEM_H
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std; // using std namespace

/*************************************************************
 * Description: The Mathler class includes the getters, setters, 
 *      and print methods and the constructor for the Item class.
 * Type: Class
 * Inputs: N/A
 * Outputs: N/A
 **************************************************************/
class Item {
public: // public access
    Item(const string &title=" ", const string &author=" ", int year=0000); // constructor

    const string &getTitle() const; // title getter

    void setTitle(const string &title); // title setter

    const string &getAuthor() const; // author getter

    void setAuthor(const string &author); // author setter

    int getYear() const; // year getter

    void setYear(int year); // year setter

    void print(); // print method

private: // private access
    string title; // title variable
    string author; // author variable
    int year; // year variable
};


#endif //HW6_ITEM_H