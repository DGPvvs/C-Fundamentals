// 02 Caesar Cipher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

int main()
{
    std::string text;
    std::getline(std::cin, text);

    std::string output = std::string();

    for (int i = 0; i < text.length(); i++)
    {
        output.append(1, text[i] + 3);
    }

    std::cout << output << std::endl;
}

//Write a program that :
//•	Read a text from the first line of the console
//•	Encrypt the text by shifting each character with three positions forward.
//Example :
//    o	A would be replaced by D
//    o	B would become E
//    o	P would become S
//    •	Print the encrypted text
