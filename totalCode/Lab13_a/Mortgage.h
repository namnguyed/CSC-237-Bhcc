class Mortgage
{
private:
	double loanAmount, annualInterestRate;
	int totalYearsToRepay;

public:
	void setLoanAmount(double);
	void setAnnualInterestRate(double);
	void setTotalYearsToRepay(double);
	double monthlyPayment();
	double totalPayBack();
};