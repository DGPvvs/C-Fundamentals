// 01 Zig-Zag Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

void AddNumInArray(int arr[], int, int);

int main()
{
    int n;
    std::cin >> n;

    int* arr1 = new int[n];
    int* arr2 = new int[n];

    for (int i = 0; i < n; i++)
    {
        int n1, n2;
        std::cin >> n1 >> n2;

        if (i % 2 == 0)
        {
            AddNumInArray(arr1, n1, i);
            AddNumInArray(arr2, n2, i);
        }
        else
        {
            AddNumInArray(arr2, n1, i);
            AddNumInArray(arr1, n2, i);
        }
    }

    std::string output1 = std::string();
    std::string output2 = std::string();

    for (int i = 0; i < n; i++)
    {
        output1.append(std::to_string(arr1[i]))
               .append(" ");
        output2.append(std::to_string(arr2[i]))
               .append(" ");
    }

    std::cout << output1 << std::endl << output2 << std::endl;

    delete[] arr1;
    delete[] arr2;
}

void AddNumInArray(int arr[], int n, int idx)
{
    arr[idx] = n;
}

//Write a program that creates two arrays :
//•	Read an integer number N(N < 100) from the first line of the console, which represents size of the arrays
//    •	On the next N lines, read two integer numbers
//    •	Form two arrays as shown below
//    •	Print two arrays, each on the separate line
//    •	Elements in the arrays have to be printed, separated by single space

