// 08 Strong Number.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    auto Factoriel = [](int n) -> int
    {
        int result = 1;

        for (int i = 1; i <= n; i++)
        {
            result *= i;
        }
        
        return result;
    };

    int num;
    std::cin >> num;

    int n = num, magicSum = 0;


    while (n > 0)
    {
        int digit = n % 10;
        magicSum += Factoriel(digit);
        n /= 10;
    }

    std::string output = num == magicSum ? "yes" : "no";

    std::cout << output << std::endl;
}

//Write a program that :
//•	Reads an integer number N
//•	Check whether a given number is strong
//o	Number is strong if the sum of the Factorial of each digit is equal to the number.
//For example : 145 is a strong number, because 1!+ 4!+ 5!= 145
//•	Print "yes" if the number is strong
//•	Print "no" if the number is NOT strong