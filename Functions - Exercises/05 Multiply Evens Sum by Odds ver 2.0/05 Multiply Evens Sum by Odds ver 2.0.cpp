// 05 Multiply Evens Sum by Odds ver 2.0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>

using namespace std;

enum ActionFlag
{
    NONE = 0b00000000,
    ODD =  0b00000001,
    EVEN = 0b00000010,

    ALL_ACTIONS = ODD | EVEN // 0b00000011
};

int sumDigits(int, ActionFlag);

int main()
{
    int number;
    cin >> number;

    int evenSum = sumDigits(number, EVEN);
    int oddSum = sumDigits(number, ODD);

    int result = evenSum * oddSum;
    cout << result << endl;

    int sum = sumDigits(number, ALL_ACTIONS);

    cout << "The sum of the digits of the " << number << " is: " << sum << endl;
}

int sumDigits(int number, ActionFlag action)
{
    int result = 0;

    if (action == NONE)
    {
        return result;
    }

    while (number != 0)
    {
        int digit = number % 10;

        bool remainderIsZero = digit % 2 == 0;

        if ((action & EVEN) == EVEN && remainderIsZero)
        {
            result += digit;
        }

        if ((action & ODD) == ODD && !remainderIsZero)
        {
            result += digit;
        }

        number /= 10;
    }

    return result;
}