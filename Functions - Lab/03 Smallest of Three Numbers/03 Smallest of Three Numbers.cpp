// 03 Smallest of Three Numbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	auto Smallest = [](int a, int b) -> int {
		if (a < b)
		{
			return a;
		}

		return b;
	};

	int arr[3];

	for (int i = 0; i < 3; i++)
	{
		cin >> arr[i];
	}

	cout << Smallest(arr[0], Smallest(arr[1], arr[2])) << endl;
}

// Write a function to print the smallest of three integer numbers. Use an appropriate name for the function.