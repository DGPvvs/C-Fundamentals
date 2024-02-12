// 02 Product Sign.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

string Sing(double);

int main()
{
	double num1, num2, num3;
	cin >> num1 >> num2 >> num3;

	cout << Sing(num1 * num2 * num3);
}

string Sing(double num)
{
	if (num >= 0)
	{
		return "+";
	}

	return "-";
}

//Write a program that shows the sign(+or -) of the product of three real numbers without calculating it.
//•	Read 3 real numbers from the console(on a single line, separated by spaces)
//•	Print the sign of their product(if the product is 0, print '+')