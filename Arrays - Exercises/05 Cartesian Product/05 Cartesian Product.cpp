// 05 Cartesian Product.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <string>

int main()
{
    int n;
    std::cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++)
    {        
        std::cin >> arr[i];
    }

    int cartesianSize = n * n;

    int* cartesianArr = new int[cartesianSize];
    int idx = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cartesianArr[idx++] = arr[i] * arr[j];
        }
    }

    std::string output = std::string();

    for (int i = 0; i < cartesianSize; i++)
    {
        output.append(std::to_string(cartesianArr[i])).append(" ");
    }

    std::cout << output << std::endl;

    delete[] cartesianArr;
    delete[] arr;

    return 0;
}

//Write a program that:
//•	Read an integer number N (N < 100) from the first line of the console, which represents size of the array
//•	Read an integer array with the given size from the second line of the console 
//•	Find and print the product of each of its elements with all elements
//Example: 
//For the array {1, 7, 3} the result would be: {1*1, 1*7, 1*3, 7*1, 7*7, 7*3, 3*1, 3*7, 3*3},
//which gives us the array    {1, 7, 3, 7, 49, 21, 3, 21, 9}, so for the input 1 7 3, the program should print 1 7 3 7 49 21 3 21 9.
