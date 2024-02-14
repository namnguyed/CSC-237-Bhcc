#include "IntList.h"
#include <iostream>
#include <iomanip>
using namespace std;

//Constructor
IntList::IntList() {
    head = nullptr;
}

//Destructor
IntList::~IntList() {
    ListNode* temp = head;
    //Delete the entire list
    while (head != nullptr) {
        head = head->next;
        delete temp;
        temp = head;
    }
}


//Append a new node at the end of the list.
void IntList::appendNode(int value) {
    ListNode* newNode = new ListNode;
    newNode->value = value;
    newNode->next = nullptr;
    //check if list is empty
    if (head == nullptr) {
        head = newNode;
    }
    else {
        //traverse the list to get the last node
        ListNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

//Insert a new node into the list, maintaining a sorted order.
void IntList::insertNode(int value) {
    ListNode* newNode = new ListNode;
    newNode->value = value;
    newNode->next = nullptr;
    //check if list is empty or value less than header's value
    if (head == nullptr || value < head->value) {
        newNode->next = head;
        head = newNode;
    }
    else {
        ListNode* current = head;
        //traverse the list
        while (current->next != nullptr && current->next->value < value) {
            current = current->next;
        }
        //insert the newNode
        newNode->next = current->next;
        current->next = newNode;
    }
}

//remove a node from the list.
void IntList::deleteNode(int value) {
    //check if list is empty
    if (head == nullptr) {
        return;
    }
    //check if value equals to header's value
    if (head->value == value) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    ListNode* current = head;
    //traverse the list
    while (current->next != nullptr && current->next->value != value) {
        current = current->next;
    }

    if (current->next != nullptr) {
        ListNode* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
    else {
        cout << "Data value " << value << " not found." << endl;
    }
}

//output the contents of the list to the screen
void IntList::print() {
    unsigned address = (unsigned)head;
    unsigned addressNext;
    cout << "head=" << uppercase << hex << setfill('0') << setw(8) << address << endl;
    ListNode* current = head;
    //traverse the list to print
    while (current != nullptr) {
        address = (unsigned)current;
        addressNext = (unsigned)current->next;
        cout << setw(8) << address << ":  value= " << dec << setfill(' ')
            << setw(5) << right << current->value << " next= 00000"
            << setfill('0') << setw(8) << addressNext << endl;
        current = current->next;
    }
}

//return the list length (number of nodes) to the caller.
int IntList::length() {
    int count = 0;
    ListNode* current = head;
    //traverse the list to count the list length
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

//display the largest data value on the screen
void IntList::displayMaxValue() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    int maxVal = head->value;
    ListNode* current = head->next;
    //traverse the list to get maximum value
    while (current != nullptr) {
        if (current->value > maxVal) {
            maxVal = current->value;
        }
        current = current->next;
    }
    cout << "Maximum value in list = " << maxVal << endl;
}

//return the total (sum) of all list values to the caller.
int IntList::total() {
    int sum = 0;
    ListNode* current = head;
    //traverse the list to compute sum
    while (current != nullptr) {
        sum += current->value;
        current = current->next;
    }
    return sum;
}