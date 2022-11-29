//
//  Assignment 1
//  Create a coin dispenser machine
//  ChristoferPiedra_Assignment1
//  09/08/2022.
//

#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <stdio.h>

using namespace std;

const int quarter = 25;
const int dime = 10;
const int nickel = 5;

// OPTION 'A' OR 'a'
void cash_to_coins ()
{

    // Prompting user to enter cash value
    double total = 0;
    cout << "\nInput your total cash value including coins, then press the \"Return\" key\n> $";
    cin >> total;
    cout << "\nYou entered $" << total << "\n";
        
    // Initialize coin counts
    int quarter_count = 0, dime_count = 0, nickel_count = 0, cents = total * 100;

    // Separate the number of cents into coint
    if ( cents / quarter >= 1)
    {
        quarter_count = cents / quarter;
        cents -= ( quarter_count * quarter );
    }

    if (cents / dime >= 1)
    {
        dime_count = cents / dime;
        cents -= ( dime_count * dime );
    }
        
    if (cents / nickel >= 1)
    {
        nickel_count = cents / nickel;
        cents -= ( nickel_count * nickel );
    }

    cout << "\nThere are " << quarter_count << " quarters\n" << "There are " << dime_count << " dimes\n" << "There are " << nickel_count << " nickels\n" << "There are " << cents << " pennys\n\n";
        
}

//Option 'B' or 'b'
void coins_to_cash ()
{
    
    // Prompting user to enter how many of each coin denomination they have, will return total cash value
    int quarter_count = 0, dime_count = 0, nickel_count = 0, penny_count = 0;
    
    cout << "\nEnter how many quarters you have\n>";
    cin >> quarter_count;
    
    cout << "Enter how many dimes you have\n>";
    cin >> dime_count;
    
    cout << "Enter how many nickels you have\n>";
    cin >> nickel_count;
    
    cout << "Enter how many pennies you have\n>";
    cin >> penny_count;
    
    cout << "You entered " << quarter_count << " quarter(s), " << dime_count << " dime(s), " << nickel_count << " nickel(s), and " << penny_count << " penny(ies)\n\n";
    
    quarter_count *= quarter;
    dime_count *= dime;
    nickel_count *= nickel;
    
    double total = ((double)quarter_count + dime_count + nickel_count + penny_count)/100;
    
    
    cout << "The total cash value of your coins is $" << total << "!\n";
}

int main()
{
    // Setting decimal places for a dollar value
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    //program will loop until continue = N || continue = n
    char play_again = 'Y';
    do
    {
        
    //Asking the user if they want to convert cash to coins or coins to cash
    char choice = 'Z';
    cout << "\nPress \"A\" to convert cash to coins\nPress \"B\" to convert coins to cash\nPress \"N\" to leave\n>";
    cin >> choice;
    
    // Picking which statement will run
    switch (choice)
    {

        case 'A':
        {
            cash_to_coins ();
            break;
        }
            
        case 'a':
        {
            cash_to_coins();
            break;
        }
            
        case 'B':
        {
            coins_to_cash();
            break;
        }
            
        case 'b':
        {
            coins_to_cash();
            break;
        }

        default:
        {
            cout << "Invalid entry.";
            break;
        }
            
    }
        cout << "Would you like to play again?\nPress \"N\" to exit, if not, enter any other character.\n>";
        cin >> play_again;
        
    } while(play_again != 'n' && play_again != 'N');
    
    return 0;
}
