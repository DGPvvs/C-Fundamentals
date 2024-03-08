// 08 Top Integers.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

    std::string output = std::string();

    for (int i = 0; i < n; i++)
    {
        bool isBig = true;

        for (int j = i + 1; j < n && isBig; j++)
        {
            isBig = arr[i] > arr[j];
        }

        if (isBig)
        {
            output.append(std::to_string(arr[i])).append(" ");
        }
    }

    std::cout << output << std::endl;

    delete[] arr;

    return 0;
}

//Write a program that:
//•	Read an integer number N (N < 100) from the first line of the console, which represents size of the array
//•	Read an integer array with the given size from the second line of the console
//•	Find all the top integers in an array
//•	Top integer is an integer that is bigger than all the elements to its right
//•	Print all top integers, separated by single space


