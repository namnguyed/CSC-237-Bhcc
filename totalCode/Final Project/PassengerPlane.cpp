#include "PassengerPlane.h"

// Mutators
void PassengerPlane::setMaxNumberOfPassengers(int passengers) {
    maxNumberOfPassengers = passengers;
}

// Accessors
int PassengerPlane::getMaxNumberOfPassengers() const {
    return maxNumberOfPassengers;
}

// Create and return a new PassengerPlane object
PassengerPlane* PassengerPlane::addNewPassengerPlane() {
    string manufacturer, model;
    int yearBuilt, flightHours, maxNumberOfPassengers;

    // Prompt the user for input
    cout << "Enter manufacturer: ";
    cin >> manufacturer;
    cout << "Enter model: ";
    cin >> model;
    cout << "Enter year built: ";
    cin >> yearBuilt;
    cout << "Enter flight hours: ";
    cin >> flightHours;
    cout << "Enter maximum number of passengers: ";
    cin >> maxNumberOfPassengers;

    // Create and return a new PassengerPlane object
    return new PassengerPlane(manufacturer, model, yearBuilt, flightHours, maxNumberOfPassengers);
}

// Return a description of the passenger plane
string PassengerPlane::getDescription() const {
    // Customize the output based on your requirements
    return Airplane::getDescription() +
        "\nMaximum Number of Passengers: " + to_string(maxNumberOfPassengers);
}
void PassengerPlane::fly(int hours) {

    Airplane::fly(hours);  // Call the base class implementation if needed
}