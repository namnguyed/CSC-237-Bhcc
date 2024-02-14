#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class Employee
{
private:
    static int lastEmployeeNumberIssued;   // Sequential employee number
    int employeeNumber;                    // Employee number for current employee
    string employeeName;                       // Employee name
    string hireDate;                           // Hire date

public:

    // Constructors
    Employee();
    Employee(string aName, string aDate);

    // Mutators
    void setEmployeeName(string n);
    void setHireDate(string date);

    // Accessors
    string getEmployeeName() const;
    int getEmployeeNumber() const;
    string getHireDate() const;
    static int getLastEmployeeNumberIssued();
    bool isValidDate(string);
};

class InvalidHireDate :public exception {
public:
    virtual const char* what()const throw() {
        return "";
    }
}; 
#endif