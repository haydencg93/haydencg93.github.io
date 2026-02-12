//
// Created by hcgamble on 4/3/2024.
//

#include "Audiobook.h" // includes the code inside Audiobook.h

/*************************************************************
 * Description: The Audiobook class constructor initializes the 
 *      narrator and duration variables and sets the default values
 *      for them. It also initializes the title, author, and year 
 *      variables in the Item class.
 * Type: Constructor
 * Inputs: Variables narrator and duration
 * Outputs: N/A
 **************************************************************/
Audiobook::Audiobook(const string &title, const string &author,
                     int year, const string &narrator, int duration):Item(title, 
                      author, year), narrator(narrator), duration(duration) {
    Audiobook::setDuration(duration); // sets the duration variable to the inputted duration variable
    Audiobook::setNarrator(narrator); // calls the setNarrator method
}

/*************************************************************
 * Description: The getNarrator method returns the narrator variable.
 * Type: Getter
 * Inputs: N/A
 * Outputs: Private narrator Variable
 **************************************************************/
const string &Audiobook::getNarrator() const {
    return narrator;
}

/*************************************************************
 * Description: The setNarrator method sets the narrator variable 
 *            to correct value.
 * Type: Setter
 * Inputs: Inputted narrator variable
 * Outputs: N/A
 **************************************************************/
void Audiobook::setNarrator(const string &narrator) {
    Audiobook::narrator = narrator;
}

/*************************************************************
 * Description: The getdDuration method returns the duration variable.
 * Type: Getter
 * Inputs: N/A
 * Outputs: Private duration Variable
 **************************************************************/
int Audiobook::getDuration() const {
    return duration;
}

/*************************************************************
 * Description: The setDuration method sets the duration variable 
 *            to correct value.
 * Type: Setter
 * Inputs: Inputted duration variable
 * Outputs: N/A
 **************************************************************/
void Audiobook::setDuration(int duration) {
    Audiobook::duration = duration;
}

/*************************************************************
 * Description: The print method prints the output for the program.
 * Type: print Method
 * Inputs: N/A
 * Outputs: private narrator and duration variables along with 
 *      the output of the Item class print method
 **************************************************************/
void Audiobook::print(){
    cout << "Type: Audiobook" << endl;
    Item::print();
    cout << "Narrator: " << getNarrator() << endl;
    cout << "Duration: " << getDuration() << endl;
}