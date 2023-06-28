//
//  main.cpp
//  Project Two
//
//  Created by ritu mathews on 6/4/23.
//

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class InvestmentCalculator {
private:
    double initialInvestmentAmount;
    double monthlyDeposit;
    double annualInterest;
    int numberOfYears;

public:
    InvestmentCalculator() {
         initialInvestmentAmount = 0.0;
         monthlyDeposit = 0.0;
         annualInterest = 0.0;
         numberOfYears = 0;
     }

    void setInitialInvestmentAmount(double amount) {
        this->initialInvestmentAmount = amount;
    }

    void setMonthlyDeposit(double deposit) {
        this->monthlyDeposit = deposit;
    }

    void setAnnualInterest(double interest) {
        this->annualInterest = interest;
    }

    void setNumberOfYears(int years) {
        this->numberOfYears = years;
    }

    double getInitialInvestmentAmount() const {
        return initialInvestmentAmount;
    }

    double getMonthlyDeposit() const {
        return monthlyDeposit;
    }

    double getAnnualInterest() const {
        return annualInterest;
    }

    int getNumberOfYears() const {
        return numberOfYears;
    }

    void displayInvestmentDetails() const {
        cout << "**********************************" << endl;
        cout << "********* Data Input *************" << endl;
        cout << "Initial Investment Amount: $" << fixed << setprecision(2) << initialInvestmentAmount << endl;
        cout << "Monthly Deposit: $" << fixed << setprecision(2) << monthlyDeposit << endl;
        cout << "Annual Interest Rate: " << fixed << setprecision(2) << annualInterest << "%" << endl;
        cout << "Number of Years: " << numberOfYears << endl;
        cout << endl;
    }

    void generateYearEndReport() const {
        double openingAmount = initialInvestmentAmount;
        double closingBalance = initialInvestmentAmount;

        cout << "Year|  Opening-Amount|\tInterest|\tClosing Balance" << endl;
        cout << "**************************************************" << endl;

        for (int year = 1; year <= numberOfYears; year++) {
            double interest = openingAmount * (annualInterest / 100.0);
            closingBalance += interest;

            cout << setw(4) << year << "|\t" << fixed << setprecision(2) << setw(4) << "$" << openingAmount << "\t\t" << fixed << setprecision(2) << setw(4) << "$"
                 << interest << "\t\t" << fixed << setprecision(2) << setw(4) << "$" << closingBalance << endl;

            openingAmount = closingBalance;
        }
        
        cout << endl;
    }

    void generateYearEndReportWithMonthlyDeposits() const {
        double openingAmount = initialInvestmentAmount;
        double closingBalance = initialInvestmentAmount;
        double totalInterest = 0.0;

        cout << "Year|  Opening-Amount|\tInterest|\tClosing Balance" << endl;
        cout << "**************************************************" << endl;

        for (int year = 1; year <= numberOfYears; year++) {
            double yearTotalInterest = 0.0;

            for (int month = 1; month <= 12; month++) {
                // Calculate monthly interest
                double interestAmount = (closingBalance + monthlyDeposit) * (annualInterest / 100.0) / 12.0;
                yearTotalInterest += interestAmount;

                // Calculate month-end total
                closingBalance += monthlyDeposit + interestAmount;
            }

            // Print the yearly report
            cout << setw(4) << year << "|\t" << fixed << setprecision(2) << setw(4) << "$" << openingAmount << "\t" << fixed << setprecision(2) << setw(4) << "$"
                 << yearTotalInterest << "\t" << fixed << setprecision(2) << setw(4) << "$" << closingBalance << endl;

            openingAmount = closingBalance;
            totalInterest += yearTotalInterest;
        }
        
        cout << endl;
    }

};

int main() {
    double initialInvestmentAmount;
    double monthlyDeposit;
    double annualInterest;
    int numberOfYears;

    cout << "Enter Initial Investment Amount: $";
    cin >> initialInvestmentAmount;

    cout << "Enter Monthly Deposit: $";
    cin >> monthlyDeposit;

    cout << "Enter Annual Interest Rate: ";
    cin >> annualInterest;

    cout << "Enter Number of Years: ";
    cin >> numberOfYears;

    InvestmentCalculator calculator;
    calculator.setInitialInvestmentAmount(initialInvestmentAmount);
    calculator.setMonthlyDeposit(monthlyDeposit);
    calculator.setAnnualInterest(annualInterest);
    calculator.setNumberOfYears(numberOfYears);

    cout << endl;
    calculator.displayInvestmentDetails();

    cout << "Press any key to continue...";
    cin.ignore();
    cin.get();

    cout << endl;
    cout << "Year-End Report (Without Monthly Deposits):" << endl;
    calculator.generateYearEndReport();

    cout << "Year-End Report (With $" << monthlyDeposit << " Monthly Deposits):" << endl;
    calculator.generateYearEndReportWithMonthlyDeposits();

    return 0;
}
