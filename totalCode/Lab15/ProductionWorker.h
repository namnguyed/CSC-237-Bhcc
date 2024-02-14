// Specification file for the ProductionWorker Class
#ifndef PRODUCTION_WORKER_H
#define PRODUCTION_WORKER_H
#include <iostream>
#include <iomanip>
#include <string>
#include "Employee.h"

using namespace std;

class ProductionWorker : public Employee
{
private:
	int shift;		// The worker's shift
	double payRate;	// The worker's hourly pay rate

public:
	// Default constructor
	ProductionWorker() : Employee() {
		shift = 0; payRate = 0.0;
	}


	// Constructor
	ProductionWorker(string aName, string aDate, int aShift, double aPayRate)
		: Employee(aName, aDate) {
		shift = aShift; payRate = aPayRate;
	}


	// Mutators
	void setShift(int s);
	void setPayRate(double r);
	static ProductionWorker* createNewProductionWorker();

	// Accessors
	int getShiftNumber() const;
	string getShiftName() const;
	double getPayRate() const;
	void printWorkerData() const;
	void displayInfo(ProductionWorker e);

};


#endif