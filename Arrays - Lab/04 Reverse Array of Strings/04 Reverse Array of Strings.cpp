// 04 Reverse Array of Strings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
    int n;
    std::cin >> n;

    string arr[100];

    for (int i = 0; i < n; ++i)
    {
        string currentNumber;
        cin >> currentNumber;
        arr[i] = currentNumber;
    }

    for (int i = 0; i < n / 2; i++)
    {
        string temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] <<  " ";
    }

    cout << endl;
}

//Write a program that :
//•	Read an integer number(< 100), which represents size of the array, from the first line of the console
//    •	Read an array of strings(space - separated), from the second line of the console
    //•	Reverse the given array
    //•	Print reversed array on a single line(space separated)