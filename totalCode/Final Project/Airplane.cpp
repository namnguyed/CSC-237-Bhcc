#include "Airplane.h"
#include <iostream>
#include <sstream>

// Initialize the static member variable
int Airplane::last_airplane_ID_issued = 0;

// Constructors
Airplane::Airplane() {
    airplane_ID = ++last_airplane_ID_issued;
    manufacturer = "";
    model = "";
    yearBuilt = 0;
    flightHours = 0;
}

Airplane::Airplane(string manufacturer, string model, int year, int hours) {
    airplane_ID = ++last_airplane_ID_issued;
    this->manufacturer = manufacturer;
    this->model = model;
    yearBuilt = year;
    flightHours = hours;
}

// Mutators
void Airplane::setManufacturer(string company) {
    manufacturer = company;
}

void Airplane::setModel(string name) {
    model = name;
}

void Airplane::setYearBuilt(int year) {
    yearBuilt = year;
}

void Airplane::setFlightHours(int hours) {
    flightHours = hours;
}

// Accessors
string Airplane::getManufacturer() const {
    return manufacturer;
}

string Airplane::getModel() const {
    return model;
}

int Airplane::getAirplane_ID() const {
    return airplane_ID;
}

int Airplane::getYearBuilt() const {
    return yearBuilt;
}

int Airplane::getFlightHours() const {
    return flightHours;
}

int Airplane::get_last_airplane_ID_issued() {
    return last_airplane_ID_issued;
}

// Return a description of the airplane
std::string Airplane::getDescription() const {
    // Create a string with detailed information about the airplane
    // Customize this based on the actual data members in your class

    // Using stringstream to build a formatted string
    std::stringstream ss;
    ss << "ID#: " << airplane_ID << ", "
        << "manufacturer: " << manufacturer << ", "
        << "model: " << model << ", "
        << "year: " << yearBuilt << ", "
        << "hours: " << flightHours;
    return ss.str();
}

// Simulate flying the airplane for a given number of hours
void Airplane::fly(int hours) {
    // Implement the general behavior for flying an airplane
    // Update total flight hours

    // Increment the flight hours by the specified amount
    flightHours += hours;

    // Print a message indicating the airplane has flown for a certain duration
    std::cout << "The airplane with ID " << airplane_ID << " has flown for " << hours << " hours.\n";
    std::cout << "Total flight hours is now: " << flightHours << " hours.\n";
}
