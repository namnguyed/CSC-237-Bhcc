#include <iostream>
#include <iomanip>
#include "Mortgage_1.h"

using namespace std;

int main() {
    char ch;
    do {
        float loan_amount, annual_rate;
        int years;
        string outputFileName;

        cout << "Enter the loan amount: ";
        cin >> loan_amount;
        cout << "Enter the annual interest rate in decimal form (example 0.075): ";
        cin >> annual_rate;
        cout << "Enter the length of the loan in years: ";
        cin >> years;
        cout << "Enter a name for the output file: ";
        cin >> outputFileName;

        Mortgage m;
        m.setLoanAmount(loan_amount);
        m.setAnnualInterestRate(annual_rate);
        m.setTotalYearsToRepay(years);

        cout << fixed;
        cout << setprecision(2) << "\nLoan Amount: $" << loan_amount << endl;
        cout << setprecision(5) << "Annual Interest Rate: " << annual_rate << endl;
        cout << "Years to repay: " << years << endl;
        cout << setprecision(2) << "Monthly Payment: $" << m.monthlyPayment() << endl;
        cout << setprecision(2) << "Total Pay Back: $" << m.totalPayBack() << endl;

        m.outputPaymentSchedule(outputFileName);

        cout << "\nDo you wish to process another loan? ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');

    return 0;
}
