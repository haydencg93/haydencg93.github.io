//
// Created by hayde on 4/26/2024.
//

#ifndef HW8_MYLIST_H
#define HW8_MYLIST_H

/* Necessary Header Files */
#include "Node.h"

class MyList{
public: // public member attributes
    MyList();

    void printAscending();

    void printDescending();

    void insert(int value);

    void remove(int value);

    void clear();

    virtual ~MyList();

private: // private member attributes
    Node *currentPtr; // pointer to current node
};

#endif //HW8_MYLIST_H
