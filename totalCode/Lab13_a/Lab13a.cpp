#include <iostream>
#include <iomanip>
#include "Mortgage.cpp" 
using namespace std;

int main()
{
    char ch;
    do
    {
        float loan_amount, annual_rate;
        int years;
        cout << "Enter the loan amount : ";
        cin >> loan_amount;
        cout << "Enter the annual interest rate in decimal form (example .075) : ";
        cin >> annual_rate;
        cout << "Enter the length of the loan in years : ";
        cin >> years;

        Mortgage m; // Create an instance of the Mortgage class

        // Set the loan details using the setter methods
        m.setLoanAmount(loan_amount);
        m.setAnnualInterestRate(annual_rate);
        m.setTotalYearsToRepay(years);

        cout << fixed;
        // Display loan information
        cout << setw(2) << "\nLoan Amount: $" << loan_amount << endl;
        cout << setw(5) << "Annual Interest Rate: " << annual_rate << endl;
        cout << "Years to repay: " << years << endl;

        // Calculate and display the monthly payment and total payback using the Mortgage class methods
        cout << setw(2) << "Monthly Payment: $" << m.monthlyPayment() << endl;
        cout << setw(2) << "Total Pay Back: $" << m.totalPayBack() << endl;

        cout << "\nDo you wish to process another loan? ";
        cin >> ch;

    } while (ch == 'Y' || ch == 'y');

    return 0;
}
