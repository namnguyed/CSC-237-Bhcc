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
    // Recursive function to print the contents of the list (forward direction)
    void printRecursive() const;
    // Recursive function to print the contents of the list backwards
    void printRecursiveBackward() const;
    // Recursive function to count the number of nodes in the list
    int countNodesRecursive() const;
    // Recursive function to calculate the sum of all values in the list
    int sumValuesRecursive() const;
    // Recursive function to find the largest value in the list
    int findLargestValueRecursive() const;
    ListNode* getHead() const;

private:
    // Recursive helper function for printing forward
    void printRecursiveHelper(ListNode*) const;
    // Recursive helper function for printing backward
    void printRecursiveBackwardHelper(ListNode*) const;
    // Recursive helper function for counting nodes
    int countNodesRecursiveHelper(ListNode*) const;
    // Recursive helper function for calculating the sum of values
    int sumValuesRecursiveHelper(ListNode*) const;
    // Recursive helper function for finding the largest value
    int findLargestValueRecursiveHelper(ListNode*) const;

};

#endif  // INTLIST_H
