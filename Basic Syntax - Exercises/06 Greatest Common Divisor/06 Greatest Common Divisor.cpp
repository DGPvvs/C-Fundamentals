// 06 Greatest Common Divisor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int GreatestCommonDivisor(int, int);

int main()
{
    int num1, num2;
    cin >> num1 >> num2;

    if (num2 > num1)
    {
        num1 += num2;
        num2 = num1 - num2;
        num1 -= num2;
    }


    cout << GreatestCommonDivisor(num1, num2) << endl;
}

int GreatestCommonDivisor(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return GreatestCommonDivisor(b, a % b);
}

//Write a program that calculates the greatest common divisor(GCD) of given two numbers
//•	Read two integer numbers on a single line from the console, separated by a single space
//•	Find their GCD(Greatest Common Divisor)
//•	Print their GCD(Greatest Common Divisor)
//Hint: you can use the Euclidean algorithm.
