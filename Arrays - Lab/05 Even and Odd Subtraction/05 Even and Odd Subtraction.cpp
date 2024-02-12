// 05 Even and Odd Subtraction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
    int n;
    std::cin >> n;

    int* arr = new int[n];


    for (int i = 0; i < n; ++i)
    {
        int currentNumber;
        cin >> currentNumber;
        arr[i] = currentNumber;
    }

    int evenSum = 0, oddSum = 0;

    for (int i = 0; i < n; ++i)
    {
        evenSum += arr[i] * (1 - arr[i] % 2);
        oddSum += arr[i] * (arr[i] % 2);
    }

    cout << evenSum - oddSum << endl;
}

//Write a program that :
//•	Read an integer number(< 100), which represents size of the array, from the first line of the console
//    •	Read an array of integers(space - separated), from the second line of the console
    //•	Calculate the difference between the sum of the even and the sum of the odd numbers in an array
    //•	Print the difference