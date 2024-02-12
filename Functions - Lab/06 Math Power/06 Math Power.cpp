// 06 Math Power.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    auto MathPow = [](int a, int b) {
        int result = 1;
        for (int i = 0; i < b; i++)
        {
            result *= a;
        }

        return result;
    };

    int a, b;

    std::cin >> a >> b;

    std::cout << MathPow(a, b) << std::endl;
}

// Create a function that calculates and returns the value of a number raised to a given power.