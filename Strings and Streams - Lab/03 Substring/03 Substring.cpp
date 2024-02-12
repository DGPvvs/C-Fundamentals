// 03 Substring.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    std::string first, second;
    std::cin >> first;
    std::cin >> second;

    bool isLoopExit = false;

    while (!isLoopExit)
    {
        int index = second.find(first);

        if (index > -1)
        {
            second.erase(index, first.length());
        }
        else
        {
            isLoopExit = true;
        }

    }


    std::cout << second <<std::endl;
}

//Write a program that :
//•	Read a string(first) from the first line of the console
//•	Read another string(second) from the second line of the console
//•	Remove all of the occurrences of the first string in the second string until there is no match
//•	Print the remaining string