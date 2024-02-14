#ifndef INTLIST_H
#define INTLIST_H

//ListNode structure definition
struct ListNode {
    int value;
    struct ListNode* next;
};

//IntList class declaration
class IntList {
private:
    // List head pointer
    ListNode* head;
public:
    // Constructor
    IntList();
    // Destructor
    ~IntList();
    // Append a new node at the end of the list.
    void appendNode(int);
    // Insert a new node into the list, maintaining a sorted order.
    void insertNode(int);
    // remove a node from the list.
    void deleteNode(int);
    // output the contents of the list to the screen
    void print();
    // return the list length (number of nodes) to the caller.
    int length();
    // display the largest data value on the screen
    void displayMaxValue();
    // return the total (sum) of all list values to the caller.
    int total();
};

#endif  // INTLIST_H
