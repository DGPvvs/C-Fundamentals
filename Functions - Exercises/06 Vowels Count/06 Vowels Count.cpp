// 06 Vowels Count.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

int GetVowels(std::string);

int main()
{
    std::string input;
    std::getline(std::cin, input);

    std::cout << GetVowels(input) << std::endl;
}

int GetVowels(std::string text)
{
    std::string vowels = std::string("aeiouAEIOU");

    int count = 0;

    for (int i = 0; i < text.length(); i++)
    {
        int index = vowels.find(text[i]);

        if (index > -1)
        {
            count++;
        }
    }

    return count;
}

//Write a program that :
//•	Read a text(string) from the console
//•	Create a function that receives a text
//•	Find the count of the vowels contained in the text
//•	Print the count of the vowels in the text
