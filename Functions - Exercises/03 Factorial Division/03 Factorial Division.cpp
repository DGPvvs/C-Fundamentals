// 03 Factorial Division.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>

std::string FormatDoubleNum(double, int);
double Factoriel(int);

int main()
{
    int num1, num2;
    std::cin >> num1 >> num2;


    std::cout << FormatDoubleNum((Factoriel(num1) / Factoriel(num2)), 2) << std::endl;
}

std::string FormatDoubleNum(double number, int precision)
{
    std::stringstream stream;

    stream.precision(precision);
    stream << std::fixed;

    stream << number;

    return stream.str();
}

double Factoriel(int n)
{
    if (n == 1)
    {
        return 1;
    }

    return n * Factoriel(n - 1);
}


//Write a program that :
//•	Read two integer numbers
//•	Calculate the factorial of each number
//•	Divide the factorial of the first number by the factorial of the second number
//•	Print the division, formatted to the second decimal point