// 09 Magic Sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cmath>

int main()
{
    int n;
    std::cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    int magicSum;
    std::cin >> magicSum;

    std::string output = std::string();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == magicSum)
            {
                output.append(std::to_string(arr[i])).append(" ").append(std::to_string(arr[j])).append("\r\n");
            }
        }
    }

    std::cout << output;

    delete[] arr;

    return 0;
}

//Write a program that: 
//•	Read an integer number N (N < 100) from the first line of the console, which represents size of the array
//•	Read an integer array with the given size from the second line of the console
//•	Read an integer number from the third line of the console, which represents magic sum
//•	Print all unique pairs in an array of integers whose sum is equal to the given magic sum
//Note: Here's how to generate all pairs for the first two numbers of an array. Use the same logic for the whole array: