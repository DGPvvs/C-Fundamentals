// 03 Replace Repeating Chars.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

int main()
{
    std::string text;
    std::getline(std::cin, text);

    std::string output = std::string();
    char ch = '\0';

    for (int i = 0; i < text.length(); i++)
    {
        char currentChar = text[i];
        if (ch != currentChar || i == 0)
        {
            ch = currentChar;
            output.append(1, ch);
        }
    }
    std::cout << output << std::endl;
}

//Write a program that :
//•	Reads a string from the console
//•	Replaces any sequence of the same letters with a single corresponding letter
//•	Print resulting string
