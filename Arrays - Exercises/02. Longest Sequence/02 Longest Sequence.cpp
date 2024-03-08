// 02 Longest Sequence.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

int main()
{
	int arrLength;
	std::cin >> arrLength;

	int* arr = new int[arrLength];

	for (int i = 0; i < arrLength; i++)
	{
		int num;
		std::cin >> num;

		arr[i] = num;
	}

	int counter = 0;
	int currentCounter = 1;
	int index = 0;
	int currentIndex = 0;
	int num = arr[0];

	for (int i = 1; i < arrLength; i++)
	{
		if (arr[i] == num)
		{
			currentCounter++;
		}
		else if (currentCounter >= counter)
		{
			index = currentIndex;
			counter = currentCounter;
			currentCounter = 1;
			num = arr[i];
			currentIndex = i;
		}
		else
		{
			currentCounter = 1;
			num = arr[i];
			currentIndex = i;
		}
	}

	if (currentCounter >= counter)
	{
		index = currentIndex;
		counter = currentCounter;
	}

	std::string output = std::string();

	for (int i = index; i <= index + counter - 1; i++)
	{
		output.append(std::to_string(arr[i])).append(" ");
	}

	std::cout << output << std::endl;

	delete[] arr;
}



//Write a program that :
//•	Read an integer number N(N < 100) from the first line of the console, which represents size of the array
//    •	Read an integer array with the given size from the second line of the console
//    •	Finds the longest sequence of equal elements in the given integer array
//    •	Prints that sequence on the console(integer numbers are separated by single space on a single line)
//    Note : If there is more than one such sequence, print the last one.