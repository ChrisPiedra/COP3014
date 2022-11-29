//
//  Assignment 06 Implementation File
//  rationals.cpp
//  COP3014
//  Created by: Christofer Piedra
//  11/29/22
//
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cctype>

#include "rationals.hpp"

using namespace std;

    // Function implementations
    namespace ChristoferRationals
{
    // + Overload
    rational_Num operator + (const rational_Num& numb1, const rational_Num& numb2)
    {
        return rational_Num ((numb1.num1 * numb2.num2 + numb2.num1 * numb1.num2), (numb1.num2 * numb2.num2));
    }
    
    // - (binary) Overload
    rational_Num operator - (const rational_Num& numb1, const rational_Num& numb2)
    {
        return rational_Num (((numb1.num1 * numb2.num2) - (numb2.num1 * numb1.num2)), (numb1.num2 * numb2.num2));
    }
    
    // - (unary) Overload
    rational_Num operator - (const rational_Num& numb1)
    {
        return rational_Num ((-numb1.num1), (numb1.num2));
    }
    
    // * Overload
    rational_Num operator * (const rational_Num& numb1, const rational_Num& numb2)
    {
        return rational_Num ((numb1.num1 * numb2.num1), (numb1.num2 * numb2.num2));
    }
    
    // / Overload
    rational_Num operator / (const rational_Num& numb1, const rational_Num& numb2)
    {
        return rational_Num ((numb1.num1 * numb2.num2), (numb2.num1 * numb1.num2));
    }
    
    // == Overload
    bool operator ==(const rational_Num& numb1, const rational_Num& numb2)
    {
        return (numb1.num1 == numb2.num1 && numb1.num2 == numb2.num2);
    }
    
    // < Overload
    bool operator < (const rational_Num& numb1, const rational_Num& numb2)
    {
        return (numb1.num1*numb2.num2 < numb2.num1 * numb1.num2);
    }
    
    // <= Overload
    bool operator <= (const rational_Num& numb1, const rational_Num& numb2)
    {
        return (numb1.num1*numb2.num2 <= numb2.num1 * numb1.num2);
    }
    
    // > Overload
    bool operator > (const rational_Num& numb1, const rational_Num& numb2)
    {
        return (numb1.num1*numb2.num2 > numb2.num1 * numb1.num2);
    }
    
    // >= Overload
    bool operator >= (const rational_Num& numb1, const rational_Num& numb2)
    {
        return (numb1.num1*numb2.num2 >= numb2.num1 * numb1.num2);
    }
    
    
    // rational_Num overload
    rational_Num::rational_Num(int numb1, int numb2)
    {
        num1 = numb1;
        num2 = numb2;
    }
    
    // rational_Num overload
    rational_Num::rational_Num(int numb1)
    {
        num1 = numb1;
        num2 = 1;
    }
    
    // rational_Num overload
    rational_Num::rational_Num( ) : num1(0), num2(1)
    {
        //Body intentionally blank.
    }
    
    // Get function #1
    double rational_Num::getNum1() const
    {
        return (num1);
    }
    
    // Get function #2
    double rational_Num::getNum2() const
    {
        return (num2);
    }
    
    
    // Takes rational_Num as an input
    istream& operator >>(istream& ins, rational_Num& numb1)
    {
        char c;
        ins >> numb1.num1;
        ins >> c;
        ins >> numb1.num2;
        
        // Exit if denominator = 0 or rational number isnt a fraction
        if (numb1.num2 == 0)
        {
            cout << "Cannot divide by 0\n\n";
            exit(1);
        }
        else if (c != '/')
        {
            cout << "Your input is invalid\n\n";
            exit (1);
        }
        
        // Bring negative to top if at bottom
        if (numb1.num2 < 0)
        {
            numb1.num1 = -numb1.num1;
            numb1.num2 = -numb1.num2;
        }
        
        return ins;
   
    }
    
    
    // Display rational_Num
    ostream& operator <<(ostream& outs, const rational_Num& numb1)
    {
        outs << numb1.num1;
        outs << '/';
        outs << numb1.num2;
        return outs;
    }
}

