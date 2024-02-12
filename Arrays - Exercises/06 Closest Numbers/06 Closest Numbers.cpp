// 06 Closest Numbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
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

    int closestValue = abs(arr[0] - arr[1]);

    if (n == 1)
    {
        closestValue = 0;
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            closestValue = std::min(closestValue, abs(arr[i] - arr[j]));
        }
    }

    std::cout << closestValue << std::endl;

    delete arr;

    return 0;
}

//Write a program that:
//•	Read an integer number N (N < 100) from the first line of the console, which represents size of the array
//•	Read an integer array with the given size from the second line of the console
//•	Finds the two closest (by value) integer numbers in the array
//•	Prints the absolute difference between them