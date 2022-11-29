//
//  christoferPiedra_Assignment02.cpp
//  COP 3014
//
//  Created by Christofer Piedra
//  Due: 9/20/22
//
// Functions: calcInterest, calcPayment, main
//
// Variables:
//      Inputs: loanAmount, intRate, termInMonths
//      Outputs: paymentTerm, monthlyPayment, princPerMonth, interestPerMonth, totalInterest, totalPaid, balanceDue
//

#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;


// Monthly Interest Rate
double calcInterest (double);

// Monthly Payment
double calcPayment (double, double, double);

// Monthly Interest Payment
double calcMonthInt (double, double);

// Monthly Principal Paid
double calcMonthPrinc (double, double);


int main() {
    //width of chart
    const int width = 20;
    char repeat = 'Y';
    
    do {
        
        //  Inputs For Program
        double loanAmount = 0, intRate = 0, termInMonths= 0;
        
        // Outputs for program
        double monthlyPayment = 0, princPerMonth = 0, termsLeft, interestPerMonth = 0, totalInterest = 0, totalPaid = 0, balanceDue = 0, interestMonthRate = 0;
        
        //  User inputs loan details
        cout << "\nHello, and welcome to Christofer's Loan Calculator!" << "\nPlease enter your total loan amount.\n>$";
        cin >> loanAmount;
        balanceDue = loanAmount;
        
        cout << "Now enter your interest rate in percent(%)\n>";
        cin >> intRate;
        intRate = intRate / 100;
        
        cout << "Now enter how many Monthly terms your loan has.\n>";
        cin >> termInMonths;
        termsLeft = termInMonths;
        
        // Calculate Monthly Interest Rate
        interestMonthRate = calcInterest (intRate);
        
        // Calculate Monthly Payment
        monthlyPayment = calcPayment(loanAmount, interestMonthRate, termInMonths);
        
        
        //  Setting Table Header
        cout.setf(ios::left);
        cout << setw(width) << "Terms Left" << setw(width) << "Monthly Payment" << setw(width) << "Int Paid Monthly" << setw(width) << "Princ Paid Monthly" << setw(width) << "Total Interest" << setw(width) << "Total Paid" << setw(width) << "Remaining Balance";
        
        // Output Data
        while (termsLeft > 1) {
            
            // Terms Left
            termsLeft--;
            
            // Monthly Payment
            
            // Monthly Interest
            interestPerMonth = calcMonthInt(intRate, balanceDue);
            
            // Monthly Principal
            princPerMonth = calcMonthPrinc (monthlyPayment, interestPerMonth);
            
            // Total Interest
            totalInterest += calcMonthInt(intRate, balanceDue);
            
            // Total Paid
            totalPaid += monthlyPayment;
            
            // Balance Due
            balanceDue -= princPerMonth;
            
            
            cout << "\n" << setw(width) << termsLeft << setw(width) << monthlyPayment << setw(width) << interestPerMonth << setw(width) << princPerMonth << setw(width) << totalInterest << setw(width) << totalPaid << setw(width) << balanceDue << "\n";
            
            
        }
        
        // Allow user to repeat Mortgage Calculations
        cout << "Would you like to repeat?\nY or N.\n";
        cin >> repeat;
    } while (repeat == 'Y' || repeat == 'y');
    
    return 0;
}

 double calcPayment (double amount, double rate, double totalTerms)
{
     // Calculates monthly payment in terms of $
     return (amount * (rate * pow ((1.0 + rate), totalTerms))) / (pow ((1.0 + rate), totalTerms) - 1.0);
 }

double calcInterest (double rate)
{
    // Calculates monthly interest payment in terms of %
    return rate/12;
}

double calcMonthInt (double rate, double balance)
{
    // Calculates monthly interest payment in terms of $
    return ((rate * balance) / 12);
}

double calcMonthPrinc (double payment, double interest)
{
    // Calculates monthly principal paid
    return (payment - interest);
}
