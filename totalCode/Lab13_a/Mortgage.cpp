#include "Mortgage.h"
#include <iostream>
#include <cmath>

using namespace std;

// Set the loan amount
void Mortgage::setLoanAmount(double loanAmount)
{
    this->loanAmount = loanAmount;
}

// Set the annual interest rate
void Mortgage::setAnnualInterestRate(double annualInterestRate)
{
    this->annualInterestRate = annualInterestRate;
}

// Set the total years to repay the mortgage
void Mortgage::setTotalYearsToRepay(double totalYearsToRepay)
{
    this->totalYearsToRepay = totalYearsToRepay;
}

// Calculate and return the monthly mortgage payment
double Mortgage::monthlyPayment()
{
    double monthlyInterestRate = annualInterestRate / 12;
    int numberOfPayments = totalYearsToRepay * 12;
    double term = pow(1 + monthlyInterestRate, numberOfPayments);
    
    // The formula for calculating the monthly payment
    return loanAmount * monthlyInterestRate * term / (term - 1);
}

// Calculate and return the total amount to be paid back over the life of the mortgage
double Mortgage::totalPayBack()
{
    double monthlyPaymentAmount = monthlyPayment();
    int numberOfPayments = totalYearsToRepay * 12;
    
    // The total amount paid back is the monthly payment multiplied by the number of payments
    return monthlyPaymentAmount * numberOfPayments;
}
