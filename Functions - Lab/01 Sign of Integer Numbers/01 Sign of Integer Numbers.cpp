// 01 Sign of Integer Numbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::to_string;

string SingString(int);



int main()
{
    int num;
    cin >> num;

    cout << SingString(num) << endl;
}

string SingString(int n)
{
    string result = string()
        .append("The number ")
        .append(to_string(n))
        .append(" is ");

    if (n > 0)
    {
        result.append("positive.");
    }
    else if (n < 0)
    {
        result.append("negative.");
    }
    else
    {
        result.append("zero.");
    }

    return result;        
}

//Create a function that prints the sign of an integer number n.
//Print:
//•	"The number {number} is positive." – if the number < 0
//    •	"The number {number} is negative."– if the number > 0
//    •	"The number {number} is zero." – if the number == 0