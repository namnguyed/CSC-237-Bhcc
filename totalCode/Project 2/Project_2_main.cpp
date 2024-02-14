#include "InventoryItem.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
const int FIELD = 200;
const int MAX_ITEM = 100;
int SIZE_ITEM_ARRAY = 0;
void aOption(InventoryItem itemArr[]);
void hOption();
void iOption(ifstream& inFile, string arr[], InventoryItem itemArr[], int& size);
void pOption(InventoryItem itemArr[], int& size);
void nOption(InventoryItem itemArr[], int& size);
void oOption(ofstream& outFile, InventoryItem itemArr[], int& size);
void qOption();
void rOption(InventoryItem itemArr[]);
void split(string inputRecord, string delimiter, string fieldArray[]);
int main() {
    char command;
    ifstream inFile;
    ofstream outFile;
    int itemArrSize = 0;
    string array[FIELD];
    InventoryItem itemArr[MAX_ITEM];
    while (true) {
        cout << "\nCommand: ";
        cin >> command;
        cin.ignore();
        switch (command) {
        case 'a':    aOption(itemArr);    break;
        case 'h':   hOption();            break;
        case 'i':   iOption(inFile, array, itemArr, itemArrSize);   break;
        case 'p':   pOption(itemArr, itemArrSize);                  break;
        case 'n':   itemArrSize++;  nOption(itemArr, itemArrSize);  break;
        case 'o':   oOption(outFile, itemArr, itemArrSize);         break;
        case 'q':   qOption();            break;
        case 'r':   rOption(itemArr);    break;
        default:                        break;
        }
    }
    return 0;
}
// Add parts: DONE
void aOption(InventoryItem itemArr[]) {
    int itemNum, quantity;
    int newQuantity;
    cout << "\nChoose a Item Number: ";
    cin >> itemNum;
    cout << "How many parts to add? ";
    cin >> quantity;
    newQuantity = itemArr[itemNum].getUnits() + quantity;
    if (newQuantity > 30)
        cout << "Error: You cannot hold more than 30 parts.";
    else
        itemArr[itemNum].setUnits(newQuantity);
}
// print Help text: DONE
void hOption() {
    cout << "\nSupprted commands:"
        << "\n\t\t a \t\t Add parts."
        << "\n\t\t h \t\t print Help text."
        << "\n\t\t i \t\t Input inventory data from a file."
        << "\n\t\t p \t\t Print inventory list."
        << "\n\t\t n \t\t New inventory Item."
        << "\n\t\t o \t\t Output inventory data to a file."
        << "\n\t\t q \t\t quit (end the program)."
        << "\n\t\t r \t\t Remove parts.";
}
// Input inventory data from a file: DONE
void iOption(ifstream& inFile, string arr[], InventoryItem itemArr[], int& size) {
    string filename;
    string inputRecord;
    int record = 0;
    cout << "Enter name of input file: ";
    cin >> filename;
    inFile.open(filename);
    while (inFile.fail()) {
        cout << "Cannot open this file. Enter another file: ";
        cin >> filename;
        inFile.open(filename);
    }
    while (getline(inFile, inputRecord)) {
        split(inputRecord, "|", arr);
        string des = arr[1];
        double cost = stod(arr[2], NULL);
        int unit = stoi(arr[3], NULL);
        itemArr[size].setDescription(des);
        itemArr[size].setCost(cost);
        itemArr[size].setUnits(unit);
        size++;
        record++;
    }
    cout << record << " records loaded to array.";
    inFile.close();
}
// Print inventory list: DONE
void pOption(InventoryItem itemArr[], int& size) {
    cout << setw(5) << right << "\nItem Num" << left << setw(37) << "     Description"
        << setw(13) << right << "Cost" << setw(13) << "Quantity" << endl;
    cout << setw(5) << right << "________" << left << setw(37) << "     ___________"
        << setw(13) << right << "____" << setw(13) << "________" << endl;
    for (int i = 0; i < size; i++) {
        cout << setw(5) << right << i << "        "
            << left << setw(40) << itemArr[i].getDescription()
            << setw(5) << right << fixed << setprecision(2) << itemArr[i].getCost()
            << setw(13) << right << itemArr[i].getUnits() << endl;
    }
    cout << size << " records.";
}
// New inventory Item: DONE
void nOption(InventoryItem itemArr[], int& size) {
    string des;
    double cost;
    int unit;
    cout << "Enter description for new Item: ";
    getline(cin, des);
    itemArr[size - 1].setDescription(des);
    cout << "Enter unit cost for new Item: ";
    cin >> cost;
    itemArr[size - 1].setCost(cost);
    cout << "Enter initial quantity for the new Item: ";
    cin >> unit;
    if (unit < 0 || unit > 30)
        cout << "ERROR: initial quantity must be >= zero and <= 30.";
    else {
        itemArr[size - 1].setUnits(unit);
        cout << "Announcing a new inventory Item: " << des
            << "\nWe now have " << size << " different inventory Items in stock!";
    }
}
// Output inventory data to a file: DONE
void oOption(ofstream& outFile, InventoryItem itemArr[], int& size) {
    string filename;
    cout << "Enter name of output file: ";
    getline(cin >> ws, filename);
    outFile.open(filename);
    while (outFile.fail()) {
        cout << "Cannot open this file. Enter another file: ";
        cin >> filename;
        outFile.open(filename);
    }
    for (int i = 0; i < size; i++) {
        outFile << i
            << '|' << itemArr[i].getDescription()
            << '|' << itemArr[i].getCost()
            << '|' << itemArr[i].getUnits() << endl;
    }
    cout << size << " records written to file.";
    outFile.close();
}
// quit: DONE
void qOption() {
    exit(0);
}
// Remove parts: DONE
void rOption(InventoryItem itemArr[]) {
    int itemNum, quantity;
    int newQuantity;
    cout << "\nChoose a Item Number: ";
    cin >> itemNum;
    cout << "How many parts to remove? ";
    cin >> quantity;
    newQuantity = itemArr[itemNum].getUnits() - quantity;
    if (newQuantity < 0)
        cout << "Error: You are attemping to remove more parts than the Item currently holds.";
    else
        itemArr[itemNum].setUnits(newQuantity);
}
// Split lines into fields: DONE
void split(string inputRecord, string delimiter, string fieldArray[])
{
    int deliPos;            // Stores delimiter position
    int startFieldPos = 0;  // Stores the beginning of the current field
    int fieldCount = 0;     // Field-counter
    string fieldData;       // Stores Field-data
    bool endLine = false;   // Flag for the end of the current line
    // While it is NOT the end of the current line
    while (!endLine)
    {
        // Find the delimiter position in the current line
        deliPos = inputRecord.find(delimiter, startFieldPos);
        // If the delimiter is found
        if (deliPos >= 0)
        {
            fieldData = inputRecord.substr(startFieldPos, deliPos - startFieldPos);
            fieldCount++;
            startFieldPos = deliPos + 1;
        }
        // When reaching the end of line
        else
        {
            endLine = true;
            deliPos = inputRecord.length();
            if (deliPos > startFieldPos)
            {
                fieldData = inputRecord.substr(startFieldPos, deliPos - startFieldPos);
                fieldCount++;
            }
        }
        fieldArray[fieldCount - 1] = fieldData;
    }
}