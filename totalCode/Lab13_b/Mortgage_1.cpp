#include "Mortgage_1.h"
#include <fstream>

void Mortgage::outputPaymentSchedule(const std::string& outputFileName) {
    std::ofstream outputFile(outputFileName);

    if (!outputFile.is_open()) {
        std::cerr << "Error opening output file." << std::endl;
        return;
    }

    double monthlyInterestRate = annualInterestRate / 12;
    int numberOfPayments = totalYearsToRepay * 12;
    double term = pow(1 + monthlyInterestRate, numberOfPayments);
    double monthlyPaymentAmount = loanAmount * monthlyInterestRate * term / (term - 1);

    outputFile << "Payment Schedule" << std::endl;
    outputFile << "Pmt# | Payment Amount | Interest | Contrib to Principle | Remaining Balance" << std::endl;

    double remainingBalance = loanAmount;
    for (int month = 1; month <= numberOfPayments; month++) {
        double interestPayment = remainingBalance * monthlyInterestRate;
        double principalPayment = monthlyPaymentAmount - interestPayment;
        remainingBalance -= principalPayment;

        outputFile << month << " | " << monthlyPaymentAmount << " | " << interestPayment
            << " | " << principalPayment << " | " << remainingBalance << std::endl;
    }

    outputFile.close();
}
