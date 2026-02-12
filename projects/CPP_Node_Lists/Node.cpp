//
// Created by hayde on 4/26/2024.
//

#include "Node.h"

/*************************************************************
 * Description: The Node class constructor sets inputted values,
 *          defualt or given, to the variables data, nextPtr,
 *          and prevPtr.
 * Type: Constructor
 * Inputs: int mData, Node *mNextPtr, and Node *mPrevPtr
 * Outputs: N/A
 **************************************************************/
Node::Node(int mData, Node *mNextPtr, Node *mPrevPtr) {
    setData(mData);
    setNextPtr(mNextPtr);
    setPrevPtr(mPrevPtr);
}

int Node::getData() const {
    return data; // gets data variable
}
void Node::setData(int mData) {
    data = mData; // sets data variable
}

Node *Node::getNextPtr() const {
    return nextPtr; // gets nextPtr pointer
}
void Node::setNextPtr(Node *mNextPtr) {
    nextPtr = mNextPtr; // sets nextPtr pointer
}

Node *Node::getPrevPtr() const {
    return prevPtr; // gets prevPtr pointer
}
void Node::setPrevPtr(Node *mPrevPtr) {
    prevPtr = mPrevPtr; // sets prevPtr pointer
}

/*************************************************************
 * Description: The MyList print function prints out the node
 *          given.
 * Type: Function
 * Inputs: N/A
 * Outputs: N/A
 **************************************************************/
void Node::print(){
    cout << "Data in Node: " << getData() << endl; // print data in the node
}
