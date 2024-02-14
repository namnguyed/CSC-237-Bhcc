// ProductionWorker.cpp
// Implementation file for the ProductionWorker class

#include "ProductionWorker.h"
#include <string>
using namespace std;


// Default constructor
ProductionWorker::ProductionWorker() : Employee() {
    shift = 0;
    payRate = 0.0;
}

// Constructor
ProductionWorker::ProductionWorker(string aName, string aDate, int aShift, double aPayRate) : Employee(aName, aDate) {
    shift = aShift;
    payRate = aPayRate;
}
// Mutators
void ProductionWorker::setShift(int s)
{
    shift = s;
}

void ProductionWorker::setPayRate(double r)
{
    payRate = r;
}

// Accessors
int ProductionWorker::getShiftNumber() const
{
    return shift;
}
string ProductionWorker::getShiftName() const
{
    if (shift == 1) {
        return "day shift";
    }
    else if (shift == 2) {
        return "night shift";
    }
    else {
        return "unknown shift";
    }
}

double ProductionWorker::getPayRate() const
{
    return payRate;
}
// create new ProductionWorker
ProductionWorker* ProductionWorker::createNewProductionWorker() {
    string name, hireDate;
    int shift;
    double payRate;
    cout << "Enter name of new employee: ";
    getline(cin, name);
    cout << "Enter hire date of new employee: ";
    getline(cin, hireDate);
    cout << "Enter shift for new employee (1 = day, 2 = night): ";
    cin >> shift;
    cout << "Enter hourly pay rate for new employee: ";
    cin >> payRate;
    // dynamically create new ProductionWorker and return it
    ProductionWorker* pw = new ProductionWorker(name, hireDate, shift, payRate);
    return pw;
}
void ProductionWorker::printWorkerData() const
{
    cout << "Name:" << Employee::getEmployeeName() << endl;
    cout << "Number: " << Employee::getEmployeeNumber() << endl;
    cout << "Hire Date: " << Employee::getHireDate() << endl;
    cout << "Shift: " << this->getShiftName() << endl;
    cout << "Pay Rate: " << this->getPayRate() << endl;
}

void ProductionWorker::displayInfo(ProductionWorker e)
{
    e.printWorkerData();
}