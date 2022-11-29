//
//  Assignment 06 Header File
//  rationals.hpp
//  COP3014
//  Created by: Christofer Piedra
//  11/29/22
//

#ifndef RATIONALS_H
#define RATIONALS_H

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cctype>
using namespace std;

namespace ChristoferRationals
{

class rational_Num
{
public:
    
    // Overloading operators to do computations for me
    friend rational_Num operator + (const rational_Num&, const rational_Num&);
    friend rational_Num operator - (const rational_Num&, const rational_Num&);
    friend rational_Num operator - (const rational_Num&);
    friend rational_Num operator *(const rational_Num&, const rational_Num&);
    friend rational_Num operator /(const rational_Num&, const rational_Num&);
    friend bool operator == (const rational_Num&, const rational_Num&);
    friend bool operator < (const rational_Num&, const rational_Num&);
    friend bool operator <= (const rational_Num&, const rational_Num&);
    friend bool operator > (const rational_Num&, const rational_Num&);
    friend bool operator >= (const rational_Num&, const rational_Num&);
    
    
    // Takes rational number as an input
    friend istream& operator >> (istream&, rational_Num&);
    // Display Rational Number
    friend ostream& operator << (ostream&, const rational_Num&);
    
    // Takes different types of input
    rational_Num (int, int);
    rational_Num (int);
    rational_Num ( );
    
    // Gets numbers
    double getNum1 ( ) const;
    double getNum2 ( ) const;
    
private:
    // Saves the 2 parts of the rational number
    int num1;
    int num2;
    
};

}

#endif // RATIONALS_H
