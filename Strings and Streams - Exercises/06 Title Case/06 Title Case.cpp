// 06 Title Case.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <string>

int main()
{
    std::string text;
    std::getline(std::cin, text);

    char previousChar = text[0];
    text[0] = toupper(text[0]);

    for (int i = 1; i < text.length(); i++)
    {
        previousChar = text[i - 1];

        if (!((previousChar >= 'a' && previousChar <= 'z') || (previousChar >= 'A' && previousChar <= 'Z')))
        {
            if (text[i] >= 'a' && text[i] <= 'z')
            {
                text[i] -= ' ';
            }
        }
    }

    std::cout << text << std::endl;
}

//Write a program that :
//•	Reads a text from the first line of the console
//•	Changes each word in a text to start with a capital letter
//•	Print the resulting string
//Note : The first letter of a word is an English alphabetical symbol preceded by a non - alphabetical symbol.So in "we will--rock you", "we", "will", "rock" and "you" are all considered words which need to be capitalized.