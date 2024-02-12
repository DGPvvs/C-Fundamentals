// 01 Reverse Strings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

int main()
{
    const std::string END = "end";

    std::string input;
    std::string output = std::string();

label: std::getline(std::cin, input);
    if (input != END)
    {
        std::string revers = std::string();

        for (int i = 0; i < input.length(); i++)
        {
            revers.append(1, input[input.length() - 1 - i]);
        }

        output.append(input).append(" = ").append(revers).append("\r\n");

        goto label;
    }

    std::cout << output;
}

//Write a program that :
//•	Read a series of words until you receive a word "end"
//•	Reverse each given word
//•	Prints each reversed word in the format :
//"{word} = {reversed word}"