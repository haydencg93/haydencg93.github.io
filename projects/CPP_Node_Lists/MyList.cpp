//
// Created by hayde on 4/26/2024.
//

#include "MyList.h"

/*************************************************************
 * Description: The MyList class constructor sets currentPtr to nullptr.
 * Type: Constructor
 * Inputs: N/A
 * Outputs: N/A
 **************************************************************/
MyList::MyList(){
    cout << "In constructor." << endl; // print constructor message
    this->currentPtr = nullptr; // default value as nullptr for currentPtr
}

/*************************************************************
 * Description: The MyList printAscending function prints the list
 *          of nodes in ascending order or, if empty, prints that it
 *          is empy.
 * Type: Function
 * Inputs: N/A
 * Outputs: N/A
 **************************************************************/
void MyList::printAscending() {
    if (currentPtr == nullptr) { // if currentPtr is nullptr/list is empty...
        cout << "List is empty." << endl; // print that the list is empty
        return;
    }
    while (currentPtr->getPrevPtr() != nullptr) { // while prevPtr doesn't equal nullptr...
        currentPtr = currentPtr->getPrevPtr(); // move currentPtr to the left in the list until the beginning
    }
    while (currentPtr->getNextPtr() != nullptr) { // while nextPtr doesn't equal nullptr...
        cout << currentPtr->getData() << ", "; // print the data of currentPtr
        currentPtr = currentPtr->getNextPtr(); // move currentPtr to the right in the list until the end
    }
    cout << currentPtr->getData() << endl; // print out the last node in the list
}

/*************************************************************
 * Description: The MyList printDescending function prints the list
 *          of nodes in descending order or, if empty, prints that
 *          it is empy.
 * Type: Function
 * Inputs: N/A
 * Outputs: N/A
 **************************************************************/
void MyList::printDescending() {
    if (currentPtr == nullptr) { // if currentPtr is nullptr/list is empty...
        cout << "List is empty." << endl; // print that the list is empty
        return;
    }
    while (currentPtr->getNextPtr() != nullptr) { // while nextPtr doesn't equal nullptr...
        currentPtr = currentPtr->getNextPtr(); // move currentPtr to the right in the list until the end
    }
    while (currentPtr->getPrevPtr() != nullptr) {// while prevPtr doesn't equal nullptr...
        cout << currentPtr->getData() << ", "; // print the data of currentPtr
        currentPtr = currentPtr->getPrevPtr(); // move currentPtr to the left in the list until the beginning
    }
    cout << currentPtr->getData() << endl; // print out the last node in the list
}

/*************************************************************
 * Description: The MyList insert function inssrts a node in ascending
 *          order in the list.
 * Type: Function
 * Inputs: N/A
 * Outputs: N/A
 **************************************************************/
void MyList::insert(int value) {
    Node *newData = new Node(value); // newData node

    if (currentPtr == nullptr) { //  if currentPtr is nullptr...
        currentPtr = newData; // set currentPtr equal to newData node
        return;
    }
    while ((value < currentPtr->getData()) && (currentPtr->getPrevPtr() != nullptr)) {
        // while the new value is less than currentPtr and the prevPtr of currentPtr isn't nullptr...
        currentPtr = currentPtr->getPrevPtr(); // move currentPtr to the left in the list until the beginning
    }
    while ((value > currentPtr->getData()) && (currentPtr->getNextPtr() != nullptr)) {
        // while the new value is greater than currentPtr and the nextPtr of currentPtr isn't nullptr...
        currentPtr = currentPtr->getNextPtr(); // move currentPtr to the right in the list until the end
    }
    if (currentPtr->getData() > newData->getData()) { // if newData is less than the currentPtr...
        newData->setPrevPtr(currentPtr->getPrevPtr()); // set the newData's prevPtr to the currentPtr's prevPtr
        newData->setNextPtr(currentPtr); // set newData's nextPtr to currentPtr
        if (currentPtr->getPrevPtr() != nullptr){ // if the currentPtr is not nullptr...
            currentPtr->getPrevPtr()->setNextPtr(newData); // set the prevPtr's nextPtr of the currentPtr to the newData
        }
        currentPtr->setPrevPtr(newData); // set currentPtr's prevPtr to newData
        return;
    }
    if (currentPtr->getData() < newData->getData()) { // if newData is greater than the currentPtr...
        newData->setNextPtr(currentPtr->getNextPtr()); // set the newData's nextPtr to the currentPtr's nextPtr
        newData->setPrevPtr(currentPtr); // set newData's prevPtr to currentPtr
        if (currentPtr->getNextPtr() != nullptr) { // if the currentPtr is not nullptr...
            currentPtr->getNextPtr()->setPrevPtr(newData); // set the nextPtr's prevPtr of the currentPtr to the newData
        }
        currentPtr->setNextPtr(newData); // set currentPtr's prevPtr to newData
        return;
    }
}

/*************************************************************
 * Description: The MyList remove function removes the node given.
 * Type: Function
 * Inputs: N/A
 * Outputs: N/A
 **************************************************************/
void MyList::remove(int value) {
    if (currentPtr == nullptr){ // if currentPtr is nullptr...
        cout << "List is empty." << endl; // print that the list is empty
        return;
    }
    if (currentPtr->getPrevPtr() == nullptr && currentPtr->getNextPtr() == nullptr && currentPtr->getData() == value) {
        cout << "Deleting the only item in the list: " << currentPtr->getData() << endl;
        delete currentPtr;
        currentPtr = nullptr;
        return;
    }
    while ((value < currentPtr->getData()) && (currentPtr->getPrevPtr() != nullptr)) {
    // while the new value is less than currentPtr and the prevPtr of currentPtr isn't nullptr...
    currentPtr = currentPtr->getPrevPtr(); // move currentPtr to the left in the list until the beginning
    }
    while ((value > currentPtr->getData()) && (currentPtr->getNextPtr() != nullptr)) {
        // while the new value is greater than currentPtr and the NextPtr of currentPtr isn't nullptr...
        currentPtr = currentPtr->getNextPtr(); // move currentPtr to the right in the list until the end
    }
    if (currentPtr->getData() != value){ // if the currentPtr is not equal to the value...
        cout << value << " wasn't found in the list." << endl; // print that the value wasn't found in the list
        return;
    }
    if ((currentPtr->getPrevPtr() == nullptr) && (currentPtr->getData() == value)) {
        // if currentPtr's prevPtr is nullptr and currentPtr is equal to the value...
        cout << "deleting " << currentPtr->getData() << endl; // print deleting message
        Node *temp = currentPtr; // set temp node to currentPtr
        currentPtr = currentPtr->getNextPtr(); // move currentPtr to the right 1
        delete temp; // delete the temp node
        currentPtr->setPrevPtr(nullptr); // set the currentPtr's prevPtr to nullptr
        return;
    }
    if ((currentPtr->getNextPtr() == nullptr) && (currentPtr->getData() == value)) {
        // if currentPtr's nextPtr is nullptr and currentPtr is equal to the value...
        cout << "deleting " << currentPtr->getData() << endl; // print deleting message
        Node *temp = currentPtr; // set temp node to currentPtr
        currentPtr = currentPtr->getPrevPtr(); // move currentPtr to the left 1
        delete temp; // delete temp node
        currentPtr->setNextPtr(nullptr); // set currentPtr's nextPtr to nullptr
        return;
    }
    if (currentPtr->getData() == value) {
        // if currentPtr is equal to the value...
        cout << "deleting " << currentPtr->getData() << endl; // print deleting message
        Node *temp = currentPtr; // set temp node to currentPtr
        (currentPtr->getPrevPtr())->setNextPtr(currentPtr->getNextPtr());
        // set the prevPtr's nextPtr of currentPtr to currentPtr's nextPtr
        (currentPtr->getNextPtr())->setPrevPtr(currentPtr->getPrevPtr());
        // set nextPtr's prevPtr of currentPtr to currentPtr's prevPtr
        currentPtr = currentPtr->getNextPtr(); // move currentPtr to the right 1
        currentPtr->setPrevPtr(temp->getPrevPtr()); // set currentPtr's prevPtr to temp's prevPtr
        delete temp; // delete temp node
        return;
    }
}

/*************************************************************
 * Description: The MyList clear function clears the whole list
 *          by deleting each node in the list.
 * Type: Function
 * Inputs: N/A
 * Outputs: N/A
 **************************************************************/
void MyList::clear() {
    if (currentPtr == nullptr){ // if currentPtr is nullptr/list empty...
        cout << "List is already empty/cleared." << endl; // print already empty message
        return;
    }
    while (currentPtr->getPrevPtr() != nullptr) { // while currentPtr's prevPtr isn't nullptr
        currentPtr = currentPtr->getPrevPtr(); // move currentPtr to the left in the list until the beginning
    }
    cout << "clearing the list." << endl; // print clearing message
    while (currentPtr != nullptr) { // while the currentPtr isn't nullptr...
        cout << "deleting currentPtr: " << currentPtr->getData() << endl; // print deleting message
        Node *nextNode = currentPtr->getNextPtr(); // set nextNode node to currentPtr's nextPtr
        delete currentPtr; // delete currentPtr node
        currentPtr = nextNode; // set currentPtr to nextNode
    }
    currentPtr = nullptr; // set currentPtr to nullptr once done clearing list
}

/*************************************************************
 * Description: The MyList class destructor calls the clear
 *          function to remove each node.
 * Type: Destructor
 * Inputs: N/A
 * Outputs: N/A
 **************************************************************/
MyList::~MyList() {
    cout << "In destructor." << endl; // print destructor message
    MyList::clear(); // call clear function
}
