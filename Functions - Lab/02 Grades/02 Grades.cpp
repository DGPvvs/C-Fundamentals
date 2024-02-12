// 02 Grades.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using std::cin;
using std::cout;
using std::string;
using std::endl;

string GradeString(double);

int main()
{
    double grade;
    cin >> grade;

    cout << GradeString(grade) << endl;
}

string GradeString(double grade)
{
    if (grade >= 2.00 && grade <= 2.99)
    {
        return "Fail";
    }
    else if (grade <= 3.49)
    {
        return "Poor";
    }
    else if (grade <= 4.49)
    {
        return "Good";
    }
    else if (grade <= 5.49)
    {
        return "Very good";
    }
    else if (grade <= 6.00)
    {
        return "Excellent";
    }
    else
    {
        return "";
    }
}

//Write a function that receives a grade between 2.00 and 6.00.
//Print the corresponding grade in words :
//•	2.00 – 2.99 – print "Fail"
//•	3.00 – 3.49 - print "Poor"
//•	3.50 – 4.49 - print "Good"
//•	4.50 – 5.49 - print "Very good"
//•	5.50 – 6.00 - print "Excellent"