#include "Employee.h"
#include"ProductionWorker.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    bool quit = false;
    char command;
    string name, date;
    int shift, numEmployees = 0;
    double rate;
    ProductionWorker newEmployees[100];
    while (!quit)
    {
        cout << "Enter command (or 'h' for help): ";
        cin >> command;
        cin.ignore(80, '\n');
        switch (command)
        {
        case 'c': {
            ProductionWorker* p = ProductionWorker::createNewProductionWorker();
            newEmployees[numEmployees] = *p;
            numEmployees++;
            break;
        }
        case 'h': {
            cout << "Supported commands: " << endl;
            cout << "\tc create a new ProductionWorker object." << endl;
            cout << "\th print help text." << endl;
            cout << "\tp print ProductionWorker information." << endl;
            cout << "\tq quit(end the program)." << endl;
            break;
        }
        case 'p': {
            for (int index = 0; index < numEmployees; index++) {
                newEmployees[index].printWorkerData();
            }
            break;
        }
        case 'q': {
            quit = true;
            break;
        }
        default: {
            cout << "Invalid input." << endl;
            break;
        }
        }
        cout << endl;
    }
    return 0;
}
