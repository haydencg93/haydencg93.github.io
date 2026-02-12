//
// Created by hcgamble on 4/3/2024.
//

#include "Magazine.h" // includes the code inside Magazine.h

/*************************************************************
 * Description: The Magazine class constructor initializes the 
 *      name and issueNumber variables and sets the default values
 *      for them.
 * Type: Constructor
 * Inputs: Variables narrator and duration
 * Outputs: N/A
 **************************************************************/
Magazine::Magazine(char *name, int issueNumber) {
    Magazine::setName(name); // calls the setName method
    Magazine::setIssueNumber(issueNumber); // calls the setIssueNumber method
}

/*************************************************************
 * Description: The Magazine class copy constructor initializes  
 *      the name and issueNumber variables and sets the default 
 *      values for them.
 * Type: Copy Constructor
 * Inputs: Object
 * Outputs: N/A
 **************************************************************/
Magazine::Magazine(const Magazine &obj){
    Magazine::setName(obj.getName()); // calls the setName method
    Magazine::setIssueNumber(obj.getIssueNumber()); // calls the setIssueNumber method
}

/*************************************************************
 * Description: The Magazine assignment copy operator makes a 
 *            copy of the object inputted in into it.
 * Type: Assignment Copy Operator
 * Inputs: objToCopy
 * Outputs: returns "this"
 **************************************************************/
Magazine &Magazine::operator=(const Magazine &objToCopy){
    if (this != &objToCopy){ // if the object is being copied...
      delete []name; // deletes the name variable
      Magazine::setName(objToCopy.getName()); // calls the setName method
      Magazine::setIssueNumber(objToCopy.getIssueNumber()); // calls the setIssueNumber method
    }
  return *this; // returns "this"
}

/*************************************************************
 * Description: The Magazine class destructor deletes the memory
 *      allocated to the name variable.
 * Type: Destructor
 * Inputs: Variables narrator and duration
 * Outputs: N/A
 **************************************************************/
Magazine::~Magazine() {
  if (name != nullptr){ // if the name variable is not null...
    cout << "Destructor has been called on ''" << name << "'." << endl; // prints the destructor message
    delete []name; // deletes the name variable
    name = nullptr; // sets the name variable to null
  }
}

/*************************************************************
 * Description: The getName method returns the name variable.
 * Type: Getter
 * Inputs: N/A
 * Outputs: Private name Variable
 **************************************************************/
char *Magazine::getName() const {
    return name;
}

/*************************************************************
 * Description: The setName method sets the name char array 
 *            to correct values.
 * Type: Setter
 * Inputs: Inputted name variable
 * Outputs: N/A
 **************************************************************/
void Magazine::setName(char *name) {
  int counter = 0; // initializes the counter variable
  while(name[counter] != '\0') { // while the name variable is not null...
    counter ++; // increments the counter variable by 1
  }
  this->name = new char[counter+1]; // creates a new char array
  for (int i = 0; i < counter; i++){ // for the length of the name variable...
    this->name[i] = name[i]; // sets the name variable to the name variable
  }
  this->name[counter] = '\0'; // sets the name variable to null
}

/*************************************************************
 * Description: The getIssueNumber method returns the issueNumber
 *            variable.
 * Type: Getter
 * Inputs: N/A
 * Outputs: Private issueNumber Variable
 **************************************************************/
int Magazine::getIssueNumber() const {
    return issueNumber;
}

/*************************************************************
 * Description: The setIssueNumber method sets the issueNumber  
 *            variable to correct value.
 * Type: Setter
 * Inputs: Inputted issueNumber variable
 * Outputs: N/A
 **************************************************************/
void Magazine::setIssueNumber(int issueNumber) {
    Magazine::issueNumber = issueNumber;
}

/*************************************************************
 * Description: The print method prints the output for the program.
 * Type: print Method
 * Inputs: N/A
 * Outputs: private name and issueNumber variables
 **************************************************************/
void Magazine::print(){
    cout << "Type: Magazine" << endl;
    int counter = 0; // initializes the counter variable
    cout << "Name: ";
    while(name[counter] != '\0') { // while the name variable is not null...
      cout << name[counter]; // prints the name variable
      counter ++; // increments the counter variable by 1
    }
    cout << "\nIssue Number: " << getIssueNumber() << endl;
}
