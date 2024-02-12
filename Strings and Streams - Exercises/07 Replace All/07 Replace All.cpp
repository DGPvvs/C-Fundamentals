// 07 Replace All.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

int main()
{
    std::string text, findString, replaceString;
    std::getline(std::cin, text);
    std::getline(std::cin, findString);
    std::getline(std::cin, replaceString);

    int idx = text.find(findString);

    while (idx > -1)
    {
        text.replace(idx, findString.length(), replaceString);
        idx = text.find(findString);
    }

    std::cout << text << std::endl;
}

//Write a program that:
//•	Read a text from the first line of the console 
//•	Read a "find" string from the second line of the console
//•	Read a "replace" string from the third line of the console
//•	Any part of the text which matches the "find" string should be replaced with the "replace" string
//•	Print the resulting text on the console