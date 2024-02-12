// 03 Sum Even Numbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main() {
    int n;
    std::cin >> n;

    int arr[100];


    for (int i = 0; i < n; ++i)
    {
        int currentNumber;    
        cin >> currentNumber;        
        arr[i] = currentNumber;
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i] * (1 - arr[i] % 2);
    }

    cout << sum << endl;

    return 0;
}

//Write a program that :
//•	Read an integer number(< 100), which represents size of the array, from the first line of the console
//    •	Read an array of integer numbers from the second line of the console
//    •	Sum only the even numbers from the given array
//    •	Print calculated sum
