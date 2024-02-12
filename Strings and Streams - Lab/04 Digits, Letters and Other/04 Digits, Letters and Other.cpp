// 04 Digits, Letters and Other.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    const std::string NEW_LINE = "\r\n";

    std::string input;
    std::cin >> input;

    std::string digits = std::string();
    std::string letters = std::string();
    std::string otherCharacters = std::string();

    for (int i = 0; i < input.length(); i++)
    {
        char ch = input[i];

        bool isDigit = ch >= '0' && ch <= '9';
        bool isLetter = (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
        bool isAny = ch >= 32 && ch <= 126;

        if (isDigit)
        {
            digits.append(1, ch);
        }
        else if (isLetter)
        {
            letters.append(1, ch);
        }
        else if (isAny)
        {
            otherCharacters.append(1, ch);
        }
    }

    digits.append(NEW_LINE)
          .append(letters)
          .append(NEW_LINE)
          .append(otherCharacters)
          .append(NEW_LINE);

    std::cout << digits;
}

//Write a program that :
//•	Read a string from the first line of the console
//•	Prints :
//o	On the first line : all the digits
//o	On the second line : all the letters
//o	On the third line : all the other characters
//Note : There will always be at least one digit, one letter and another character.