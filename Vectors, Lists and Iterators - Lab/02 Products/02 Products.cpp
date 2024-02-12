// 02 Products.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <string>

int main()
{
    std::string text;
    std::getline(std::cin, text);

    int n = stoi(text);

    std::list<std::string> result = std::list<std::string>();

    for (int i = 0; i < n; i++)
    {

        std::getline(std::cin, text);

        result.push_back(text);
    }

    result.sort([](std::string& a, std::string& b) {return a < b;});

    std::string output = std::string();

    int i = 1;
    for (std::list<std::string>::iterator it = result.begin(); it != result.end(); it++)
    {
        output.append(std::to_string(i).append(".").append(*it)).append("\r\n");
        i++;
    }

    std::cout << output << std::endl;
}

//Write a program that:
//•	Read an integer number N (count of the products) from the first line of the console
//•	Read N lines of products (string)
//•	Print a numbered list of all the products ordered by name