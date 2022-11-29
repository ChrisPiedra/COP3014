//
//  ChristoferPiedra_Assignment03
//  COP 3014
//  Created by Christofer Piedra
//  11/28/2022
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

// \/\/\/\/\/\/\/\/\/\/ !!!!! CHANGE FILE LOCATION HERE!!!!! \/\/\/\/\/\/\\/\/\/
const string location = ("ChristoferPiedra_Rand.txt");

int main() {
    
    // Set input and output streams
    ifstream iStream;
    ofstream oStream;
  
    
    // Set Format (2 decimals)
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    
    // Variables Used
    int n = 0, i = 0, sum = 0, next = 0;
    double average = 0, stSum = 0, stDev = 0;

    
    
    // A. Generate Random Number 100-1000
    srand(time(0));
    n = ((rand() % 899) + 101);
    cout << "\nn is " << n << endl;
    
    
    
    // Opening File
    oStream.open(location);
    if (oStream.fail())
    {
        cout << "Output file opening 1 failed \n\n";
        exit(1);
    }
    
    // B Generate N Random Numbers that are ≤ 1000
    for (i = 0; i < n; i++)
    oStream << (rand() % 1000 + 1) << "\n";
    oStream.close();
    
    
    
    // Opening File
    iStream.open(location);
    if (iStream.fail())
    {
        cout << "Input file opening 1 failed \n\n";
        exit(1);
    }
    
    // C.  Calculate, Display, and Save average of all n values in the file
    while (iStream >> next)
        sum += next;
    iStream.close();
    average = sum / n;
    cout << "\n\nThe average of the " << n << " random numbers generated is\n>" << average << "\n\n";
    
    
    
    // Opening file
    iStream.open(location);
    if (iStream.fail())
    {
        cout << "Input file opening 2 failed \n\n";
        exit(1);
    }
    
    // D. Calculate, Display, and Save std dev of all values, save at the end of file
    while(iStream >> next)
        stSum += pow((next - average), 2);
    stDev = sqrt(stSum / n);
    cout << "\n\nThe Standard Deviation of the " << n << " random numbers generated is\n>" << stDev << "\n\n";
    iStream.close();
    
    // Opening file, saving stDev to input file
    oStream.open(location, ios::app);
    if (oStream.fail())
    {
        cout << "Output file opening 1 failed \n\n";
        exit(1);
    }
    oStream.setf(ios::fixed);
    oStream.setf(ios::showpoint);
    oStream.precision(2);
    oStream << "The average of the " << n << " numbers given is\n>" << average << "\nThe standard deviation is\n>" << stDev << "\n\n";
    oStream.close();
    
    return 0;
}
