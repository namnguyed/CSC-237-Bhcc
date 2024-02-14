#include <iostream>
#include <fstream>
using namespace std;

const int ARRAY_SIZE = 100;

// Function to find the lowest number in the array
int getLowest(int numbers[], int size) {
    int lowest = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] < lowest) {
            lowest = numbers[i];
        }
    }
    return lowest;
}

// Function to find the highest number in the array
int getHighest(int numbers[], int size) {
    int highest = numbers[0];
    for (int i = 0; i < size; i++) {
        if (numbers[i] > highest) {
            highest = numbers[i];
        }
    }
    return highest;
}

// Function to calculate the sum of the numbers in the array
int getSum(int numbers[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }
    return sum;
}

// Function to calculate the average of the numbers in the array
double getAverage(int numbers[], int size) {
    int sum = getSum(numbers, size);
    return static_cast<double>(sum) / size;
}

int main() {
    int numbers[ARRAY_SIZE];

    // Prompt the user for the input file name
    string fileName;
    cout << "Enter the input file name: ";
    cin >> fileName;

    // Open the file for input
    ifstream inputFile(fileName);

    // Check if the file is open
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open the file." << endl;
        return 0;
    }

    // Read the contents of the file into the array
    int count = 0;
    while (count < ARRAY_SIZE && inputFile >> numbers[count]) {
        count++;
    }

    inputFile.close();

    // Call functions and display results
    int lowest = getLowest(numbers, count);
    int highest = getHighest(numbers, count);
    int sum = getSum(numbers, count);
    double average = getAverage(numbers, count);

    // Display results
    cout << count << " numbers read from input file"<< endl;
    cout << "Lowest Number: " << lowest << endl;
    cout << "Highest Number: " << highest << endl;
    cout << "Sum of Numbers: " << sum << endl;
    cout << "Average of Numbers: " << average << endl;

    return 0;
}