// 04 Most Frequent Number.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <string>

int main()
{
    int n;
    std::cin >> n;

    unsigned char* counts = new unsigned char[10];

    for (int i = 0; i < 10; i++)
    {
        counts[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int num;
        std::cin >> num;
        counts[num]++;
    }

    unsigned char maxCount = 0;

    for (int i = 0; i < 10; i++)
    {
        maxCount = std::max(maxCount, counts[i]);
    }

    std::string output = std::string();

    for (int i = 0; i < 10; i++)
    {
        if (counts[i] == maxCount)
        {
            output.append(std::to_string(i)).append(" ");
        }
    }

    std::cout << output << std::endl;

    delete[] counts;

    return 0;
}

//Write a program that:
//•	Read an integer number N (N < 100) from the first line of the console, which represents size of the array
//•	Read an integer array with the given size from the second line of the console 
//•	Integer numbers in the array will be in the range [0, 9]
//•	Find the most frequent number in the given integer array
//•	Print the most frequent number
//Note: In case of multiple numbers with the same maximal frequent, print all of them, ordered from smallest to largest, separated by space.