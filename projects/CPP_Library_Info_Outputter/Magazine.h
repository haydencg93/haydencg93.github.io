//
// Created by hcgamble on 4/3/2024.
//

#ifndef HW6_MAGAZINE_H
#define HW6_MAGAZINE_H

#include "Item.h" // includes the code inside Item.h

class Magazine { // Magazine class
public: // public access
    Magazine(char *name=nullptr, int issueNumber=0); // Magazine constructor
    Magazine(const Magazine &object); // Magazine copy constructor

    Magazine &operator=(const Magazine &objToCopy); // Magazine assignment operator

    ~Magazine(); // Magazine destructor

    char *getName() const; // name getter

    void setName(char *name); // name setter

    int getIssueNumber() const; // issueNumber getter

    void setIssueNumber(int issueNumber); // issueNumber setter

    void print(); // print method

private: // private access
    char *name;
    int issueNumber;
};

#endif //HW6_MAGAZINE_H