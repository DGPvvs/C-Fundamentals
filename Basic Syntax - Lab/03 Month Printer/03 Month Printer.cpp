// 03 Month Printer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;
    getline(cin, input);

    int inputNum = stoi(input) - 1;

    string output = string();

    string mounth[] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December",
        "Error!"
    };

    switch (inputNum)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
        output = mounth[inputNum];
        break;
    default:
        output = mounth[12];
        break;
    }

    cout << output << endl;
}

//Write a program that takes an integer from the consoleand prints the corresponding month.
//If the number is more than 12 or less than 1 print "Error!".
//Input
//You will receive a single integer on a single line.
//Output
//If the number is within the boundaries, print the corresponding month, otherwise, print "Error!".