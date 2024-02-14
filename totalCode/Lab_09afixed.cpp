#include <iostream>
#include <iomanip>
using namespace std;

// Function to populate an integer array with user input
void populateIntegerArray(int* arrayPtr, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        cout << "Enter an integer value for element " << i << ": ";
        cin >> *(arrayPtr + i);
    }
}

// Function to display the elements of an integer array, including address, decimal, and hexadecimal values
void displayIntegerArray(int* arrayPtr, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%x: arrayPtr[%d] = ", arrayPtr + i, i); // Display address in hexadecimal
        printf("%10d", *(arrayPtr + i)); // Display value in decimal
        printf(" (Hex %08X)\n", *(arrayPtr + i)); // Display value in hexadecimal
    }
}
/*void displayIntegerArray(int* arrayPtr, int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        cout << hex << arrayPtr + i << ": arrayPtr[" << i << "] = ";
        cout << dec << setw(10) << setfill(' ') << *(arrayPtr + i);
        cout << " (Hex " << hex << setw(8) << setfill('0') << *(arrayPtr + i) << ")" << endl;
    }
}
*/

// Function to find the maximum integer in an array
int findMaximumInteger(int* arrayPtr, int arraySize)
{
    int max = *arrayPtr; // Initialize max with the first element
    for (int i = 0; i < arraySize; i++)
    {
        if (*(arrayPtr + i) > max)
        {
            max = *(arrayPtr + i); // Update max if a larger value is found
        }
    }
    return max;
}

int main()
{
    int arraySize;
    cout << "Enter desired array size: ";
    cin >> arraySize;

    int* arrayPtr = new int[arraySize]; // Dynamic memory allocation

    cout << "arrayPtr = " << arrayPtr << endl;

    populateIntegerArray(arrayPtr, arraySize);
    displayIntegerArray(arrayPtr, arraySize);

    cout << "Maximum integer in array is: "
        << findMaximumInteger(arrayPtr, arraySize) << endl;

    cout << "DELETING array at arrayPtr = " << arrayPtr << endl;
    delete[] arrayPtr; // Deallocate the dynamically allocated memory

    return 0;
}
