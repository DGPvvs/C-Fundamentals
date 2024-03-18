// 08 Top Integers ver 2.0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <limits.h>

enum Flags
{
    ZERO  = 0b0000000000000000000000000000000000000000000000000000000000000000,
    ONE   = 0b0000000000000000000000000000000000000000000000000000000000000001,
    HIGHT = 0b1000000000000000000000000000000000000000000000000000000000000000
};

void carryLeft(unsigned long long int*, unsigned long long int*, Flags);
bool carryRight(unsigned long long int*, unsigned long long int*);

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

    unsigned long long int flagsH = 0, flagsL = 0;

    int runningMax = INT_MIN;

    for (int i = n - 1; i >= 0; i--)
    {
        carryLeft(&flagsH, &flagsL, arr[i] > runningMax ? ONE : ZERO);

        if (arr[i] > runningMax)
        {
            runningMax = arr[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (carryRight(&flagsH, &flagsL))
        {
            output.append(std::to_string(arr[i])).append(" ");
        }
    }

    std::cout << output << std::endl;

    delete[] arr;

    return 0;
}

void carryLeft(unsigned long long int* flagsH, unsigned long long int* flagsL, Flags flag)
{    
    *flagsH <<= 1; //*flagsH = (*flagsH << 1);

    if ((*flagsL & HIGHT) != ZERO)
    {
        *flagsH |= ONE;
    }

    *flagsL = (*flagsL << 1) | flag;
}

bool carryRight(unsigned long long int* flagsH, unsigned long long int* flagsL)
{
    bool result = true;

    if ((*flagsL & ONE) == ZERO)
    {
        result = false;
    }

    *flagsL = (*flagsL >> 1);
    
    if ((*flagsH & ONE) == ONE)
    {
        *flagsL |= HIGHT; // *flagsL = *flagsL | HIGHT;
    }

    *flagsH >>= 1; // *flagsH = *flagsH >> 1; 

    return result;
}

//Write a program that:
//•	Read an integer number N (N < 100) from the first line of the console, which represents size of the array
//•	Read an integer array with the given size from the second line of the console
//•	Find all the top integers in an array
//•	Top integer is an integer that is bigger than all the elements to its right
//•	Print all top integers, separated by single space


