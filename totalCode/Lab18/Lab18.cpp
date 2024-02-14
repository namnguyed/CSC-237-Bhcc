#include <iostream>
#include "IntList.h"
using namespace std;

//Function to display the commands
void printCommands() {
    cout << "Supported commands:" << endl;
    cout << "\t a: APPEND a value to the list." << endl;
    cout << "\t c: COUNT the nodes in the list (display LENGTH of the list)." << endl;
    cout << "\t d: DELETE a value from the list." << endl;
    cout << "\t i: INSERT a value into the list." << endl;
    cout << "\t m: display MAXIMUM (largest) value in the list." << endl;
    cout << "\t p: PRINT the list contents." << endl;
    cout << "\t h: print the help text." << endl;
    cout << "\t q: quit (end the program)." << endl;
    cout << "\t t: display TOTAL (sum) of all values in the list." << endl;
}

int main() {
    IntList list;
    char command;
    int value;

    //do-while loop to process interactive command-loop
    do {
        cout << "Command:  ";
        cin >> command;

        
        switch (command) {
        case 'a':
            cout << "Enter number to append to the list: ";
            cin >> value;
            list.appendNode(value);
            break;
        case 'c':
            cout << "Length of list = " << list.length() << " nodes" << endl;
            break;
        case 'd':
            cout << "Enter number to delete from the list: ";
            cin >> value;
            list.deleteNode(value);
            break;
        case 'i':
            cout << "Enter number to insert into the list: ";
            cin >> value;
            list.insertNode(value);
            break;
        case 'm':
            list.displayMaxValue();
            break;
        case 'p':
            list.print();
            break;
        case 'h':
            printCommands();
            break;
        case 't':
            cout << "Total of all list values =  " << list.total() << endl;
            break;
        case 'q':
            cout << "Exiting program with status = 0" << endl;
            return 0;
        default:
            cout << "Invalid command" << endl;
            break;
        }
        cout << endl;
    } while (command != 'q');
}