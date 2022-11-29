//
//  ChristoferPiedra_Assignment04.cpp
//  COP 3014
//  Created by Christofer Piedra
//  11/28/22
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

using namespace std;

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

int main()
{
    // Initialize variable
    rational_Num ratNum1, ratNum2;
    
    // Get values
    cout << "Enter a Rational Number\n>";
    cin >> ratNum1;
    cout << "Now enter another Rational Number\n>";
    cin >> ratNum2;
    
    // Display calculations then end program
    cout << "\nRational  Number 1 >" << ratNum1 << "\nRational Number 2 >" << ratNum2;
    
    cout << "\n\nRational  Number 1 + Rational  Number 2 = " << ratNum1 + ratNum2 << "\nRational  Number 1 - Rational  Number 2 = " << ratNum1 - ratNum2 << "\nNegative Rational Number 1 = " << - ratNum1 << "\nRational  Number 1 * Rational  Number 2 = " << ratNum1 * ratNum2 << "\nRational  Number 1 / Rational  Number 2 = " << ratNum1 / ratNum2 ;
    
    cout << "\n\nRational Number 1 > Rational Number 2?\n>" << (ratNum1 > ratNum2) << "\nRational Number 1 ≥ Rational Number 2?\n>" << (ratNum1 >= ratNum2) << "\nRational Number 1 < Rational Number 2?\n>" << (ratNum1 < ratNum2) << "\nRational Number 1 <= Rational Number 2?\n>" << (ratNum1 <= ratNum2) << "\nRational Number 1 = Rational Number 2?\n>" << (ratNum1 == ratNum2) << "\n";

    return 0;
}

// Function implementations

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
