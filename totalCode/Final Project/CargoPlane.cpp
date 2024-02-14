#include "CargoPlane.h"

// Mutators
void CargoPlane::setMaxCargoWeight(int s) {
    maxCargoWeight = s;
}

// Accessors
int CargoPlane::getMaxCargoWeight() const {
    return maxCargoWeight;
}

// Create and return a new CargoPlane object
CargoPlane* CargoPlane::addNewCargoPlane() {
    string manufacturer, model;
    int yearBuilt, flightHours, maxCargoWeight;

    // Prompt the user for input
    cout << "Enter manufacturer: ";
    cin >> manufacturer;
    cout << "Enter model: ";
    cin >> model;
    cout << "Enter year built: ";
    cin >> yearBuilt;
    cout << "Enter flight hours: ";
    cin >> flightHours;
    cout << "Enter maximum cargo weight: ";
    cin >> maxCargoWeight;

    // Create and return a new CargoPlane object
    return new CargoPlane(manufacturer, model, yearBuilt, flightHours, maxCargoWeight);
}

// Return a description of the cargo plane
string CargoPlane::getDescription() const {
    // Customize the output based on your requirements
    return Airplane::getDescription() +
        "\nMaximum Cargo Weight: " + to_string(maxCargoWeight);
}
void CargoPlane::fly(int hours) {

    Airplane::fly(hours);  // Call the base class implementation if needed
}