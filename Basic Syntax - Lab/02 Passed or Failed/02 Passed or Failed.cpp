// 02 Passed or Failed.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    const string PASSED = "Passed!";
    const string FAILED = "Failed!";

    const double PASS_RANGE = 3.0;

    string input;
    getline(cin, input);

    string output = string();

    if (stod(input) >= 3.0)
    {
        output.append(PASSED);
    }
    else
    {
        output.append(FAILED);
    }

    cout << output << endl;
}

//Write a program that takes as an input a grade(floating - point number).
//Prints:
//•	"Passed!" if the grade is equal or more than 3.00
//•	"Failed!" if the grade is lower than 3.00
//Input
//The input comes as a single double number.
//Output
//The output is either "Passed!" if the grade is more than 2.99, otherwise, you should print "Failed!".