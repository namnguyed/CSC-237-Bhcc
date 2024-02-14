#include <iostream>
#include <vector>
#include "Airplane.h"
#include "CargoPlane.h"
#include "PassengerPlane.h"

using namespace std;

// Function prototypes
void addNewAirplane(vector<Airplane*>& fleet);
void flyAirplane(const vector<Airplane*>& fleet);
void printHelpText();
void printFleetInformation(const vector<Airplane*>& fleet);
void removeAirplane(vector<Airplane*>& fleet);

int main() {
    vector<Airplane*> fleet;

    char command;
    do {
        cout << "Enter command (or 'h' for help): ";
        cin >> command;

        switch (command) {
        case 'a':
            addNewAirplane(fleet);
            break;
        case 'f':
            flyAirplane(fleet);
            break;
        case 'h':
            printHelpText();
            break;
        case 'p':
            printFleetInformation(fleet);
            break;
        case 'r':
            removeAirplane(fleet);
            break;
        case 'q':
            cout << "Are you sure that you want to exit the program?\n";
            break;
        default:
            cout << "Invalid command. Type 'h' for help.\n";
        }
    } while (command != 'q');

    // Clean up allocated memory
    for (auto& airplane : fleet) {
        delete airplane;
    }

    return 0;
}

// Implement the functions for each command

// Function to add a new airplane to the fleet
void addNewAirplane(vector<Airplane*>& fleet) {
    char type;
    cout << "Enter type of airplane (c = cargo, p = passenger): ";
    cin >> type;

    string manufacturer, model;
    int yearBuilt, flightHours;

    cout << "Enter name of manufacturer: ";
    cin >> manufacturer;

    cout << "Enter model: ";
    cin >> model;

    cout << "Enter year built: ";
    cin >> yearBuilt;

    cout << "Enter flight hours: ";
    cin >> flightHours;

    Airplane* newAirplane = nullptr;

    // Create a new CargoPlane or PassengerPlane based on user input
    if (type == 'c') {
        int maxCargoWeight;
        cout << "Enter maximum cargo weight: ";
        cin >> maxCargoWeight;
        newAirplane = new CargoPlane(manufacturer, model, yearBuilt, flightHours, maxCargoWeight);
    }
    else if (type == 'p') {
        int maxPassengers;
        cout << "Enter maximum number of passengers: ";
        cin >> maxPassengers;
        newAirplane = new PassengerPlane(manufacturer, model, yearBuilt, flightHours, maxPassengers);
    }
    else {
        cout << "Invalid airplane type.\n";
        return;
    }

    // Add the new airplane to the fleet
    fleet.push_back(newAirplane);

    cout << "New airplane information:";
    cout << newAirplane->getDescription() << endl;

    cout << "addNewAirplane: Size of fleet = " << fleet.size() << endl;
}

// Function to simulate flying an airplane in the fleet
void flyAirplane(const vector<Airplane*>& fleet) {
    int airplaneID, flightHours;
    cout << "Which airplane do you want to fly? ";
    cin >> airplaneID;
    cout << "Length of flight (hours)? ";
    cin >> flightHours;

    // Find the specified airplane in the fleet and simulate flying it
    for (auto& airplane : fleet) {
        if (airplane->getAirplane_ID() == airplaneID) {
            airplane->fly(flightHours);

            cout << "Choosing airplane:" << airplane->getDescription() << '\n';
            cout << "Flight complete:" << airplane->getDescription() << '\n';
            return;
        }
    }

    cout << "Airplane " << airplaneID << " not found.\n";
}

// Function to print the available commands
void printHelpText() {
    cout << "Supported commands:\n"
        << " a Add a new airplane to the fleet.\n"
        << " f Fly a plane in the fleet.\n"
        << " h Print help text.\n"
        << " p Print current fleet information.\n"
        << " q Quit (end the program).\n"
        << " r Remove airplane from the fleet.\n";
}

// Function to print information about the current fleet
void printFleetInformation(const vector<Airplane*>& fleet) {
    cout << "Current fleet contains " << fleet.size() << " airplane(s):\n";
    for (const auto& airplane : fleet) {
        cout << airplane->getDescription() << '\n';
    }
}

// Function to remove an airplane from the fleet
void removeAirplane(vector<Airplane*>& fleet) {
    int airplaneID;
    cout << "Which airplane do you want to remove? ";
    cin >> airplaneID;

    // Find the specified airplane in the fleet
    auto it = find_if(fleet.begin(), fleet.end(),
        [airplaneID](const Airplane* airplane) {
            return airplane->getAirplane_ID() == airplaneID;
        });

    // If the airplane is found, remove it from the fleet
    if (it != fleet.end()) {
        string removedDetails = (*it)->getDescription(); // Store details before deletion

        cout << "Choosing airplane: " << removedDetails << endl;

        delete* it;
        fleet.erase(it);

        cout << "Removal complete: Airplane [ID#: " << removedDetails << " ] has been removed.\n";
    }
    else {
        cout << "Airplane " << airplaneID << " not found.\n";
    }
}
