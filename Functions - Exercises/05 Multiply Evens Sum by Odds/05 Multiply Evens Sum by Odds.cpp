// 05 Multiply Evens Sum by Odds.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>

int main()
{
    int num;
    std::cin >> num;

    int evenSum = 0, oddSum = 0;

    num = std::abs(num);
    while (num > 0)
    {
        int n = num % 10;
        num /= 10;

        evenSum += n * (1 - (n % 2));
        oddSum += n * (n % 2);
    }

    std::cout << evenSum * oddSum << std::endl;
}

//Write a program that :
//•	Read an integer number
//•	Multiply the sum of all its even digits by the sum of all its odd digits
//•	Print the result of the multiplication
