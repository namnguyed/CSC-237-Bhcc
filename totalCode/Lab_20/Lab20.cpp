#include <iostream>
#include "IntList.h"
using namespace std;

// Function to display the commands
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
    cout << "\t r: RECURSIVELY PRINT the list contents (forward)." << endl;
    cout << "\t b: RECURSIVELY PRINT the list contents BACKWARDS." << endl;
    cout << "\t n: RECURSIVELY COUNT the number of nodes in the list." << endl;
    cout << "\t s: RECURSIVELY CALCULATE the SUM of all values in the list." << endl;
    cout << "\t l: RECURSIVELY CALCULATE the LARGEST value in the list." << endl;
}

int main() {
    IntList list;
    char command;
    int value;

    // do-while loop to process the interactive command-loop
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
            cout << "\nNumber of nodes in list, head=" << list.getHead() << ", count=" << list.length() << endl;
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
            cout << "head=00000" << list.getHead() << endl;
            list.print();
            break;
        case 'h':
            printCommands();
            break;
        case 't':
            cout << "Total of all value fields in list, head=00000" << list.getHead()
                << ", total=" << list.total() << endl;
            break;
        case 'r':
            cout << "Recursive print of list, head=00000" << list.getHead() << endl;
            list.printRecursive();
            break;
        case 'b':
            cout << "BACKWARDS recursive print of list, head=00000" << list.getHead()<< endl;
            list.printRecursiveBackward();
            break;
        case 'n':
            cout << "Recursively counting the number of nodes in the list: " << list.countNodesRecursive() << endl;
            break;
        case 's':
            cout << "Recursively calculating the sum of all values in the list: " << list.sumValuesRecursive() << endl;
            break;
        case 'l':
            cout << "Recursively calculating the largest value in the list: " << list.findLargestValueRecursive() << endl;
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
