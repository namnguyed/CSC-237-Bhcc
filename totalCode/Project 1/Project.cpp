#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void packTextFile(const string& inputFileName, const string& outputFileName) {
    ifstream input(inputFileName);
    ofstream output(outputFileName);

    if (!input.is_open() || !output.is_open()) {
        cout << "Error opening files!" << endl;
        return;
    }

    string line;
    while (getline(input, line)) {
        cout << "Input text (length=" << line.length() << "): " << line << endl; 
        line += '\n'; // Append a new-line character

        // Pack four characters into an unsigned int
        unsigned int packed = 0;
        for (int i = 0; i < line.length(); i++) {
            packed |= (line[i] << (24 - (i % 4) * 8));
            if ((i + 1) % 4 == 0 || i == line.length() - 1) {
                output << hex << packed << endl; // Write the packed value in hexadecimal format
                packed = 0; // Reset the packed value
            }
        }
    }

    input.close();
    output.close();

    
}
void unpackText(const string& inputFile, const string& outputFile) {
    ifstream input(inputFile);
    ofstream output(outputFile);

    if (!input.is_open() || !output.is_open()) {
        cout << "Error opening files!" << endl;
        return;
    }

    unsigned int packed;
    while (input>> hex >> packed) {
        for (int i = 3; i >= 0; i--) {
            char c = (packed >> (i * 8)) & 0xFF;
            if (c != '\n') {
                output << c; // Write the character to the output file
            }
        }
    }

    input.close();
    output.close();

    
}


const int MAX_LINE_LENGTH = 80; // Maximum characters per line for display

void printHelp() {
    cout << "Supported commands:" << endl;
    cout << "p Pack a text document into unsigned integers." << endl;
    cout << "u Unpack unsigned integers to text." << endl;
    cout << "h Output 'help' text." << endl;
    cout << "q Exit the program." << endl;
    cout << "v Set or Clear verboseMode (debug aid)." << endl;
}

int main() {
    string command;

    while (true) {
        cout << "Enter command : ";
        cin >> command;

        if (command == "p") {
            string inputFile, outputFile;
            cout << "Enter the input filename: ";
            cin >> inputFile;
            cout << "Enter the output filename: ";
            cin >> outputFile;

            packTextFile(inputFile, outputFile);

            ifstream input(inputFile);
            string inputText;
            char ch;
            while (input.get(ch)) {
                inputText += ch;
            }
            input.close();

            
        }
        else if (command == "u") {
            string inputFile, outputFile;
            cout << "Enter the input filename: ";
            cin >> inputFile;
            cout << "Enter the output filename: ";
            cin >> outputFile;
            unpackText(inputFile, outputFile);
            // Implement the unpacking function here
        }
        else if (command == "h") {
            printHelp();
        }
        else if (command == "q") {
            char confirm;
            cout << "Are you sure that you want to exit the program? (y/n) ";
            cin >> confirm;
            if (confirm == 'y') {
                break;
            }
        }
        else {
            cout << "Invalid command! Enter 'h' for help." << endl;
        }
    }

    cout << "Exit the program." << endl;

    return 0;
}
