#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct MovieData {
    string title;
    string director;
    int yearReleased;
    double runningTime;
};

void displayMovie(MovieData* moviePtr) {
    cout << "Title      : " << moviePtr->title << endl;
    cout << "Director   : " << moviePtr->director << endl;
    cout << "Released   : " << moviePtr->yearReleased << endl;
    cout << "Running Time : " << moviePtr->runningTime << " minutes" << endl;
}

void populateMovieDataArray(MovieData* arrayPtr, int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        cout << "Enter Title " << i << ": ";
        cin.ignore();
        getline(cin, arrayPtr[i].title);
        cout << "Enter Director " << i << ": ";
        getline(cin, arrayPtr[i].director);
        cout << "Enter Year Released " << i << ": ";
        cin >> arrayPtr[i].yearReleased;
        cout << "Enter running time (minutes) " << i << ": ";
        cin >> arrayPtr[i].runningTime;
    }
}

void displayMovieDataArray(MovieData* arrayPtr, int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        cout << "Movie " << i << ":" << endl;
        displayMovie(&arrayPtr[i]);
        cout << std::endl;
    }
}

int findLongestMovie(MovieData* arrayPtr, int arraySize) {
    int longestMovieIndex = 0;
    double longestRunningTime = arrayPtr[0].runningTime;
    for (int i = 1; i < arraySize; i++) {
        if (arrayPtr[i].runningTime > longestRunningTime) {
            longestRunningTime = arrayPtr[i].runningTime;
            longestMovieIndex = i;
        }
    }
    return longestMovieIndex;
}

int main() {
    int arraySize;
    cout << "Enter desired array size: ";
    cin >> arraySize;

    // Allocate memory for the array of MovieData structs
    MovieData* movieArray = new MovieData[arraySize];

    // Print the address of movieArray in the desired format
    cout << "arrayPtr = " << "0000" << hex << setw(16) << setfill('0') << reinterpret_cast<uintptr_t>(movieArray) << endl;

    // Call the populateMovieDataArray function
    populateMovieDataArray(movieArray, arraySize);

    // Call the displayMovieDataArray function
    displayMovieDataArray(movieArray, arraySize);

    // Call the findLongestMovie to obtain the index of the longest movie
    int longestMovieIndex = findLongestMovie(movieArray, arraySize);

    // Call displayMovie using the index of the longest movie
    cout << "Longest Movie in list:" << endl;
    displayMovie(&movieArray[longestMovieIndex]);

    cout << "\nLongest Movie is: " << movieArray[longestMovieIndex].runningTime << " minutes long\n";

    delete[] movieArray;
    cout << "\nDELETING array at movieArray = " << movieArray << endl;

    return 0;
}
