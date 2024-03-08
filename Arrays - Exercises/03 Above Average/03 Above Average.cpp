// 03 Above Average.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

int main()
{
	int arrLength;
	std::cin >> arrLength;

	int* arr = new int[arrLength];

	int sum = 0;

	for (int i = 0; i < arrLength; i++)
	{
		int num;
		std::cin >> num;

		arr[i] = num;
		sum += num;
	}

	int average = sum / arrLength;

	std::string output = std::string();

	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] >= average)
		{
			output.append(std::to_string(arr[i])).append(" ");
		}
	}

    std::cout << output << std::endl;

	delete[] arr;
}

//Write a program that :
//•	Read an integer number N(N < 100) from the first line of the console, which represents size of the array
//    •	Read an integer array with the given size from the second line of the console
//    •	Find all numbers which are larger than or equal to the mathematical average of the numbers in the array
//    •	The numbers should be printed on a single line, separating the output number by spaces.
//    Note : The output numbers should be in the same order as they were in the input.