// 05 Divisible by 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
    const int RANGE = 100;
    const int DIVIDER = 3;

    int i = 3;

label: if (i <= RANGE)
    {
        cout << i << endl;
        i += DIVIDER;
        goto label;
    }
}

//Write a program that prints all the numbers(on separate line) from 1 to 100, which are divisible by 3. You have to use a single for loop.The program should not receive input.