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

class COP3014
{
public:
    // Initialize values to Null
    COP3014( );
    
    // Set values when user inputs
    void setQuiz1(double);
    void setQuiz2(double);
    void setMidterm(double);
    void setFinalExam(double);
    void setZ_Num(double);
    
    // Gets values if user would like to
    double getQuiz1();
    double getQuiz2();
    double getMidterm();
    double getFinalExam();
    double getPercGrade();
    char getLetGrade();
    
    // Output all values
    void output(ostream& outs);
    
    
private:
    // functions not to be touched by user
    void setPercGrade();
    void setLetGrade();
    
    // Variable storage
    double quiz1;
    double quiz2;
    double midterm;
    double finalExam;
    double percGrade;
    char letGrade;
    int z_num;
    

    
};

int main() {
    cout << "Welcome to your grade calculator! Lets hope you'e doing well.";
    
    char replay = 'y';
    do{
        // Name variables for Student Profile
        COP3014 student1;
        double grade;
        
        // Set Quiz 1 grade
        cout << "\n\nEnter quiz 1 grade (1-10 points)\n>";
        cin >> grade;
        student1.setQuiz1(grade);
        
        // Set Quiz 2 grade
        cout << "Enter quiz 2 grade (1-10 points)\n>";
        cin >> grade;
        student1.setQuiz2(grade);
        
        // Set Midterm grade
        cout << "Enter Midterm grade (1-100 points)\n>";
        cin >> grade;
        student1.setMidterm(grade);

        // Set Final Exam grade
        cout << "Enter Final Exam grade (1-100 points)\n>";
        cin >> grade;
        student1.setFinalExam(grade);
        
        
        // Set Z-Number
        cout << "Enter Z-Number (Do not include Z)\n>";
        cin >> grade;
        student1.setZ_Num(grade);
        
        // Display data
        student1.output(cout);
        
        // Would user like to enter another student's grades?
        cout << "\n\nEnter 'Y' if you would like to calculate another student's grade\n>";
        cin >> replay;
    }while (replay == 'y' || replay == 'Y');
    
    return 0;
}

// Initialize values to null
COP3014::COP3014 () : quiz1(NULL), quiz2(NULL), midterm(NULL), finalExam(NULL), percGrade(NULL), letGrade(NULL), z_num(NULL)
{
    // Body intentionally empty
}

// Set Quiz 1 grade
void COP3014::setQuiz1(double grade)
{
    quiz1 = grade;
    if (quiz1 < 0 || quiz1 > 10)
    {
        cout << "Invalid code. Retry and only enter 1-10.";
        exit(1);
    }
}

// Set Quiz 2 grade
void COP3014::setQuiz2(double grade)
{
    quiz2 = grade;
    if (quiz2 < 0 || quiz2 > 10)
    {
        cout << "Invalid code. Retry and only enter 1-10.";
        exit(1);
    }

}

// Set Midterm grade
void COP3014::setMidterm(double grade)
{
    midterm = grade;
    if (midterm < 0 || midterm > 100)
    {
        cout << "Invalid code. Retry and only enter 1-100.";
        exit(1);
    }
}

// Set Final Exam grade
void COP3014::setFinalExam(double grade)
{
    finalExam = grade;
    if (finalExam < 0 || finalExam > 100)
    {
        cout << "Invalid code. Retry and only enter 1-100.";
        exit(1);
    }
    setPercGrade();
    setLetGrade();
}

// Set student's Z-Number
void COP3014::setZ_Num(double grade)
{
    z_num = grade;
}

// Calculate percent grade
void COP3014::setPercGrade()
{
    percGrade = (finalExam / 100 * 50 + midterm / 100 * 30 + (quiz1 + quiz2) / 20 * 20);
}

// Determine letter grade
void COP3014::setLetGrade()
{
    if (percGrade >= 90)
        letGrade = 'A';
    else if (percGrade >= 80)
        letGrade = 'B';
    else if (percGrade >= 70)
        letGrade = 'C';
    else if (percGrade >= 60)
        letGrade = 'D';
    else if (percGrade < 60)
        letGrade = 'F';
    else
    {
        cout << "Something's Wrong";
        exit (1);
    }
}

// Would return quiz 1
double COP3014::getQuiz1()
{
    return quiz1;
}

// Would return quiz 2
double COP3014::getQuiz2()
{
    return quiz2;
}

// Would return midterm
double COP3014::getMidterm()
{
    return midterm;
}

// Would return final exam
double COP3014::getFinalExam()
{
    return finalExam;
}

// Would return percent grade
double COP3014::getPercGrade()
{
    return percGrade;
}

// Would return letter grade
char COP3014::getLetGrade()
{
    return letGrade;
}

// Outputs all data stored in COP3014 student profile
void COP3014::output(ostream& outs)
{
    outs.setf(ios::fixed);
    outs.setf(ios::showpoint);
    outs.precision(2);
    cout << "First quiz value\n>" << quiz1 << " Points\nSecond quiz value\n>" << quiz2 << " Points\nMidterm exam value\n>" << midterm << " Points\nFinal exam value\n>" << finalExam << " Points\nWeighted grade value\n>" << percGrade << "%\nLetter grade value\n>" << letGrade << "\nZ-Number\n>Z-" << z_num;
}
