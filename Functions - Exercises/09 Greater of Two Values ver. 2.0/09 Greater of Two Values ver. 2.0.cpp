// 09 Greater of Two Values ver. 2.0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

template <typename T>
T Bigger(const T*, const T*);

int main()
{
    const std::string INT = "int", CHAR = "char", STRING = "string";

    std::string dataType;
    std::getline(std::cin, dataType);

    std::string s1, s2;
    std::getline(std::cin, s1);
    std::getline(std::cin, s2);

    if (dataType == INT)
    {
        int a = stoi(s1);
        int b = stoi(s2);
        std::cout << Bigger<int>(&a, &b) << std::endl;
    }
    else if (dataType == CHAR)
    {
        char a = s1[0];
        char b = s2[0];
        std::cout << Bigger<char>(&a, &b) << std::endl;
    }
    else if (dataType == STRING)
    {
        std::cout << Bigger<std::string>(&s1, &s2) << std::endl;
    }
}

template <typename T>
T Bigger(const T* a, const T* b)
{
    return *a >= *b ? *a : *b;
}

//Write a program that :
//•	Reads a type(string) and two values of this type from the console
//•	Entered type can be one of the following values : "int", "char" or "string"
//•	Create functions which can compare int, char or string
//•	Return the biggest of the two values