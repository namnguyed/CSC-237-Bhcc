#include "Employee.h"
#include <string>
#include<ctype.h>
using namespace std;

int Employee::lastEmployeeNumberIssued = 0;   // Sequential employee number

// Default constructor
Employee::Employee()
{
    lastEmployeeNumberIssued++;
    employeeNumber = lastEmployeeNumberIssued;
    employeeName = "";
    hireDate = "";
}


// Constructor
Employee::Employee(string aName, string aDate)
{
    if (!isValidDate(aDate)) {
        throw InvalidHireDate();
    }
    lastEmployeeNumberIssued++;
    employeeNumber = lastEmployeeNumberIssued;
    employeeName = aName;
    hireDate = aDate;
}



// Mutators
void Employee::setEmployeeName(string n)
{
    employeeName = n;
}


void Employee::setHireDate(string date)
{
    if (!isValidDate(date)) {
        throw InvalidHireDate();
    }
    hireDate = date;
}

// Accessors
string Employee::getEmployeeName() const
{
    return employeeName;
}

int Employee::getEmployeeNumber() const
{
    return employeeNumber;
}

string Employee::getHireDate() const
{

    return hireDate;
}

int Employee::getLastEmployeeNumberIssued()
{
    return lastEmployeeNumberIssued;
}

bool Employee::isValidDate(string date) {
    if (date.length() == 10) {
        if (date[2] == '/' && date[5] == '/') {
            for (int i = 0; i < date.length(); i++) {   //this one keep missing the element[0] and throw and exception even the right format.
                if (i != 2 && i != 5) {
                    if (!isdigit(date[i])) {
                        return false;
                    }
                }
            }
            return true;
        }
    }
    return false;
}