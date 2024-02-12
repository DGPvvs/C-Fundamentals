// 05 Min and Max.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <string>
#include <climits>
#include <vector>
#include <cmath>

using std::cin;
using std::min;
using std::max;

int main()
{
    int n;
    cin >> n;

    bool isNotFirst = false;

    int minNum, maxNum, currentNum;

    for (int i = 0; i < n; i++)
    {
        cin >> currentNum;

        if (isNotFirst)
        {
            minNum = min(minNum, currentNum);
            maxNum = max(maxNum, currentNum);
        }
        else
        {
            minNum = maxNum = currentNum;
            isNotFirst = !isNotFirst;
        }
    }

    std::cout << minNum << " " << maxNum << std::endl;
}

//Write a program that :
//•	Reads an integer number N
//•	Then reads a line of N integers
//•	 Print the minimumand maximum of those integers, separated by single space