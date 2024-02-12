// 06 Sum of Odd Numbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
	const int START = 1;
	const int INCREASER = 2;

	string input;
	getline(cin, input);

	int n = stoi(input);

	int i = 1;
	int sum = 0;

	label: if (n > 0)
	{
		cout << i << endl;

		sum += i;
		i += INCREASER;
		n--;
		goto label;
	}

	string output = string("Sum: ").append(to_string(sum));

	cout << output << endl;
}

//Write a program that prints the next n odd numbers(starting from 1) and on the last row prints the sum of them.
//Input
//On the first line, you will receive a number – n.This number shows how many odd numbers you should print.
//Output
//Print the next n odd numbers, starting from 1, separated by new lines.On the last line, print the sum of these numbers.
//Constraints
//•	n will be in the interval[1…100]