#ifndef MORTGAGE_H
#define MORTGAGE_H

class Mortgage {
private:
    double loanAmount;
    double annualInterestRate;
    double totalYearsToRepay;

public:
    void setLoanAmount(double loanAmount);
    void setAnnualInterestRate(double annualInterestRate);
    void setTotalYearsToRepay(double totalYearsToRepay);
    double monthlyPayment();
    double totalPayBack();
    void outputPaymentSchedule(const std::string& outputFileName);
};

#endif
