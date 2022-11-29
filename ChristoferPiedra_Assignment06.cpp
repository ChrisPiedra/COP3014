//
//  Assignment 06 Driver File
//  ChristoferPiedra_Assignment06.hpp
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
#include <iomanip>
#include <cctype>
#include "rationals.hpp"

using namespace std;
using namespace ChristoferRationals;

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
   cout << "\nRational  Number 1\n>" << ratNum1 << "\nRational Number 2\n>" << ratNum2;
   
   cout << "\n\nRational  Number 1 + Rational  Number 2\n>" << ratNum1 + ratNum2 << "\nRational  Number 1 - Rational  Number 2\n>" << ratNum1 - ratNum2 << "\nNegative Rational Number 1\n>" << - ratNum1 << "\nRational  Number 1 * Rational  Number 2\n>" << ratNum1 * ratNum2 << "\nRational  Number 1 / Rational  Number 2\n>" << ratNum1 / ratNum2 ;
   
   cout << "\n\nRational Number 1 > Rational Number 2?\n>" << (ratNum1 > ratNum2) << "\nRational Number 1 ≥ Rational Number 2?\n>" << (ratNum1 >= ratNum2) << "\nRational Number 1 < Rational Number 2?\n>" << (ratNum1 < ratNum2) << "\nRational Number 1 <= Rational Number 2?\n>" << (ratNum1 <= ratNum2) << "\nRational Number 1 = Rational Number 2?\n>" << (ratNum1 == ratNum2) << "\n";

   return 0;
}
