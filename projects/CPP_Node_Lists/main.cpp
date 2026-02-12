/************************************************************************************************
 * Programmer: Hayden Gamble
 * Date: 05/03/2024
 * Project Name: hw8
 * Description of Program: This C++ program is a program that creates, manuevers, manipulates, and
 *              adds to doubly-linked lists.
 ************************************************************************************************/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Necessary Header Files */
#include <iostream>
#include "Node.h"
#include "MyList.h"

using namespace std;

int main() {
    cout << "testing Node class: " << endl;
    Node dat0;
    dat0.print(); // Expected output: 0
    cout << "Expected output: 0." << endl;
    Node dat1(1);
    dat1.print(); // Expected output: 1
    cout << "Expected output: 1." << endl;
    Node dat2(5);
    dat2.print(); // Expected output: 5
    cout << "Expected output: 5." << endl;
    cout << "___________________________________________________________\n" << endl;

    cout << "testing insert(): " << endl;
    MyList list1;
    list1.insert(5);
    cout << "list currently: ";
    list1.printAscending();
    list1.insert(10);
    cout << "list currently: ";
    list1.printAscending();
    list1.insert(3);
    cout << "list currently: ";
    list1.printAscending();
    list1.insert(8);
    cout << "list currently: ";
    list1.printAscending(); // Expected output: 3, 5, 8, 10
    cout << endl;
    cout << "Expected output: 3, 5, 8, 10." << endl;
    cout << "___________________________________________________________\n" << endl;

    cout << "testing remove(): " << endl;
    MyList list2;
    cout << "inserting 5. list currently: ";
    list2.insert(5);
    list2.printAscending();
    cout << "inserting 10. list currently: ";
    list2.insert(10);
    list2.printAscending();
    cout << "inserting 3. list currently: ";
    list2.insert(3);
    list2.printAscending();
    cout << "inserting 8. list currently: ";
    list2.insert(8);
    list2.printAscending();
    cout << "removing 10. list currently: ";
    list2.remove(10);
    list2.printAscending();
    cout << "removing 3. list currently: ";
    list2.remove(5);
    list2.printAscending();
    cout << "removing 38. list currently: ";
    list2.remove(38);
    list2.printAscending();
    list2.remove(3);
    cout << "removing 3. list currently: ";
    list2.printAscending();
    list2.remove(8);
    cout << "removing 8. list currently: ";
    list2.printAscending(); // Expected output: List is empty.
    cout << endl;
    cout << "Expected output: List is empty." << endl;
    cout << "___________________________________________________________\n" << endl;

    cout << "testing printAscending(): " << endl;
    MyList list3;
    cout << "inserting 5. list currently: ";
    list3.insert(5);
    list3.printAscending();
    cout << "inserting 10. list currently: ";
    list3.insert(10);
    list3.printAscending();
    cout << "inserting 3. list currently: ";
    list3.insert(3);
    list3.printAscending();
    cout << "inserting 8. list currently: ";
    list3.insert(8);
    list3.printAscending(); // Expected output: 3, 5, 8, 10
    cout << endl;
    cout << "Expected output: 3, 5, 8, 10" << endl;
    cout << "___________________________________________________________\n" << endl;

    cout << "testing printDescending(): " << endl;
    MyList list4;
    cout << "inserting 5. list currently: ";
    list4.insert(5);
    list4.printDescending();
    cout << "inserting 10. list currently: ";
    list4.insert(10);
    list4.printDescending();
    cout << "inserting 3. list currently: ";
    list4.insert(3);
    list4.printDescending();
    cout << "inserting 11. list currently: ";
    list4.insert(11);
    list4.printDescending();
    cout << "inserting 8. list currently: ";
    list4.insert(8);
    list4.printDescending(); // Expected output: 10, 8, 5, 3
    cout << endl;
    cout << "Expected output: 10, 8, 5, 3" << endl;
    cout << "___________________________________________________________\n" << endl;

    cout << "testing clear(): " << endl;
    MyList list5;
    cout << "inserting 5. list currently: ";
    list5.insert(5);
    list5.printAscending();
    cout << "inserting 10. list currently: ";
    list5.insert(10);
    list5.printAscending();
    cout << "inserting 3. list currently: ";
    list5.insert(3);
    list5.printAscending();
    cout << "inserting 8. list currently: ";
    list5.insert(8);
    list5.printAscending();
    list5.clear();
    cout << endl;
    cout << "___________________________________________________________\n" << endl;
    cout << "running destructor: " << endl;
}
