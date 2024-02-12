// 02 Print Numbers in Reverse Order.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main() {
    int n;
    std::cin >> n;

    int arr[100];

    int currentNumber;

    for (int i = 0; i < n; ++i)
    {
        cin >> currentNumber;
        arr[i] = currentNumber;
    }

    for (int i = 0; i < n; ++i)
    {
        cout << arr[n - 1 - i] << " ";
    }

    cout << endl;

    return 0;
}

//Write a program that :
//•	Read integer number N from the first line of the console(N < 100)
//    •	Read N integer numbers from the next N lines of the console
//    •	Print entered numbers in reverse order