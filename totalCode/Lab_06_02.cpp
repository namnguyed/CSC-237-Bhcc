#include <iostream>
#include <iomanip>
#include <bitset>
#include <string>

using namespace std;

void printBinary(unsigned int value)
{
    cout << "Binary: ";
    for (int i = 31; i >= 0; --i) {
        cout << ((value >> i) & 1);
        if (i % 4 == 0) {
            cout << '_';
        }
    }
    cout << endl;
}

void set_uIntData(unsigned int& param)
{
    unsigned int userInput;

    cout << "Original data value (hex) = " << hex << param << endl;

    cout << "Enter argument for new data value (hex): ";

    unsigned int tempUserInput;
    if (!(cin >> hex >> tempUserInput)) {
        cout << "Invalid input. Please enter a valid hexadecimal value." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    param = tempUserInput;

    cout << "Modified data value (hex) = " << hex << param << endl;
    cout << "Decimal: " << dec << param << " Octal: " << oct << param << " Hex: " << hex << param << " ";
    printBinary(param);
}

void bitwise_LeftShift(unsigned int& param)
{
    int shiftAmount;
    cout << "Enter decimal argument for Bitwise-LeftShift: ";
    cin >> shiftAmount;
    param <<= shiftAmount;

    cout << "Modified data value (hex) = " << hex << param << endl;
    cout << "Decimal: " << dec << param << " Octal: " << oct << param << " Hex: " << hex << param << " ";
    printBinary(param);
}

void invert(unsigned int& param)
{
    param = ~param;

    cout << "Original data value (hex) = " << hex << param << endl;
    cout << "Modified data value (hex) = " << hex << param << endl;
    cout << "Decimal: " << dec << param << " Octal: " << oct << param << " Hex: " << hex << param << " ";
    printBinary(param);
}

void bitwise_OR(unsigned int& param)
{
    unsigned int userInput;
    cout << "Original data value (hex) = " << hex << param << endl;
    cout << "Enter hex argument for Bitwise-OR: ";
    cin >> hex >> userInput;
    cin.ignore(10, '\n');
    param |= userInput;

    cout << "Modified data value (hex) = " << hex << param << endl;
    cout << "Decimal: " << dec << param << " Octal: " << oct << param << " Hex: " << hex << param << " ";
    printBinary(param);
}

void bitwise_XOR(unsigned int& param)
{
    unsigned int operand;
    cout << "Enter hex argument for Bitwise-XOR: ";
    cin >> hex >> operand;
    cin.ignore(10, '\n');
    param ^= operand;

    cout << "Modified data value (hex) = " << hex << param << endl;
    cout << "Decimal: " << dec << param << " Octal: " << oct << param << " Hex: " << hex << param << " ";
    printBinary(param);
}

void bitwise_RightShift(unsigned int& param)
{
    int shiftAmount;
    cout << "Enter decimal argument for Bitwise-RightShift: ";
    cin >> shiftAmount;
    param >>= shiftAmount;

    cout << "Modified data value (hex) = " << hex << param << endl;
    cout << "Decimal: " << dec << param << " Octal: " << oct << param << " Hex: " << hex << param << " ";
    printBinary(param);
}

void clearHexDigit(unsigned int& param)
{
    unsigned int digitNumber;
    cout << "Enter the digit number (0-7): ";
    cin >> digitNumber;

    if (digitNumber >= 0 && digitNumber <= 7) {
        unsigned int mask = ~(0xF << (digitNumber * 4));
        param &= mask;

        cout << "Modified data value (hex) = " << hex << param << endl;
        cout << "Decimal: " << dec << param << " Octal: " << oct << param << " Hex: " << hex << param << " ";
        printBinary(param);
    }
    else {
        cout << "Invalid digit number. Using 0 by default." << endl;
    }
}

void defineNewValueForHexDigit(unsigned int& param)
{
    unsigned int digitNumber;
    cout << "Enter the digit number (0-7): ";
    cin >> digitNumber;

    if (digitNumber >= 0 && digitNumber <= 7) {
        unsigned int newValue;
        cout << "Enter the new hex value: ";
        cin >> hex >> newValue;

        unsigned int mask = ~(0xF << (digitNumber * 4));
        param &= mask;
        param |= (newValue << (digitNumber * 4));

        cout << "Modified data value (hex) = " << hex << param << endl;
        cout << "Decimal: " << dec << param << " Octal: " << oct << param << " Hex: " << hex << param << " ";
        printBinary(param);
    }
    else {
        cout << "Invalid digit number. Using 0 by default." << endl;
    }
}

void displayHelpText()
{
    cout << "Supported commands:" << endl;
    cout << " s SET data value (hex)." << endl;
    cout << " l bitwise LEFT SHIFT." << endl;
    cout << " n Negate (invert) all bits." << endl;
    cout << " o bitwise OR." << endl;
    cout << " x bitwise XOR." << endl;
    cout << " r bitwise RIGHT SHIFT." << endl;
    cout << " c Clear specific Hex digit." << endl;
    cout << " d Define new contents for specific Hex digit." << endl;
    cout << " h Enter single-letter command (or 'h' for help)" << endl;
    cout << " q quit (end the program)." << endl;
}

int main()
{
    unsigned int uIntData = 5;
    bool keepRunning = true;

    while (keepRunning) {
        string command;
        cout << "Enter single-letter command (or 'h' for help): ";
        cin >> command;

        if (command == "s") {
            set_uIntData(uIntData);
        }
        else if (command == "l") {
            bitwise_LeftShift(uIntData);
        }
        else if (command == "n") {
            invert(uIntData);
        }
        else if (command == "o") {
            bitwise_OR(uIntData);
        }
        else if (command == "x") {
            bitwise_XOR(uIntData);
        }
        else if (command == "r") {
            bitwise_RightShift(uIntData);
        }
        else if (command == "c") {
            clearHexDigit(uIntData);
        }
        else if (command == "d") {
            defineNewValueForHexDigit(uIntData);
        }
        else if (command == "h") {
            displayHelpText();
        }
        else if (command == "q") {
            char response;
            cout << "Are you sure that you want to exit the program? (y/n): ";
            cin >> response;
            if (response == 'y' || response == 'Y') {
                keepRunning = false;
                cout << "Exit the program." << endl;
            }
        }
        else {
            cout << "Invalid command. Type 'h' for help." << endl;
        }
    }

    return 0;
}
