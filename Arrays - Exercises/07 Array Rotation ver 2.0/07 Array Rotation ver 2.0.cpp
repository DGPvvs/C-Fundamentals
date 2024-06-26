// 07 Array Rotation ver 2.0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void ArrayRottate(int arr[], int, int);

int main() {
    int arrLength;
    cin >> arrLength;

    int* arr = new int[arrLength];

    for (int i = 0; i < arrLength; ++i)
    {
        cin >> arr[i];
    }

    int step = 0;
    cin >> step;

    step = step % arrLength;

    if (step < 0)
    {
        step += arrLength;
    }

    if (step != 0)
    {
        ArrayRottate(arr, step, arrLength);
    }

    for (int i = 0; i < arrLength; ++i)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    delete[] arr;

    return 0;
}

void ArrayRottate(int arr[], int step, int arrLength)
{
    int start = 0;
    int next = step;

    while (start != next)
    {
        int swap = arr[start];
        arr[start++] = arr[next];
        arr[next++] = swap;

        if (next == arrLength)
        {
            next = step;
        }
        else if (start == step)
        {
            step = next;
        }
    }
}
//Write a program that:
//�	Read an integer number N (N < 100) from the first line of the console, which represents size of the array
//�	Read an integer array with the given size from the second line of the console
//�	Read an integer number from the third line of the console, which represents count rotations you have to perform
//�	One rotation is when the first element goes at the end (first element becomes last element)
//�	Print the resulting array elements, separated by single space