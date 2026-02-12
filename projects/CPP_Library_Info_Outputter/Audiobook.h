//
// Created by hcgamble on 4/3/2024.
//

#ifndef HW6_AUDIOBOOK_H
#define HW6_AUDIOBOOK_H

#include "Item.h" // includes the code inside Item.h

class Audiobook : public Item { // Audiobook class with inheritance from Item
public: // public access
    Audiobook(const string &title=" ", const string &author=" ",
              int year=0000, const string &narrator=" ", int duration=0); // Audiobook constructor

    const string &getNarrator() const; // narrator getter

    void setNarrator(const string &narrator); // narrator setter

    int getDuration() const; // duration getter

    void setDuration(int duration); // duration setter

    void print(); // print method

private: // private access
    string narrator; // narrator variable
    int duration; // duration variable
};


#endif //HW6_AUDIOBOOK_H