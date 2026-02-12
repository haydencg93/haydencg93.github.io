//
// Created by hayde on 4/26/2024.
//
#ifndef HW8_NODE_H
#define HW8_NODE_H

/* Necessary Header Files */
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std; // using std namespace

class Node{
public: // public member variables
    Node(int mData = 0, Node *mNextPtr = nullptr, Node *mPrevPtr = nullptr);

    int getData() const;
    void setData(int mData);

    Node *getNextPtr() const;
    void setNextPtr(Node *mNextPtr);

    Node *getPrevPtr() const;
    void setPrevPtr(Node *mPrevPtr);

    void print();

private: // private member variables
    int data; // int data of node
    Node *nextPtr; // pointer to the next node
    Node *prevPtr; // pointer to the previous node
};

#endif //HW8_NODE_H
