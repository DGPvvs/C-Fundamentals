// 09 Greater of Two Values.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

int main()
{
    const std::string INT = "int", CHAR = "char", STRING = "string";
    auto Bigger = [](auto a, auto b) {return a >= b ? a : b;};

    std::string dataType;

    std::getline(std::cin, dataType);

    if (dataType == INT)
    {
        int int1;
        int int2;
        std::cin >> int1 >> int2;

        std::cout << Bigger(int1, int2) << std::endl;
    }
    else if (dataType == CHAR)
    {
        char ch1, ch2;
        std::cin >> ch1 >> ch2;
        std::cout << Bigger(ch1, ch2) << std::endl;
    }
    else if (dataType == STRING)
    {
        std::string s1, s2;
        std::getline(std::cin, s1);
        std::getline(std::cin, s1);
        std::cout << Bigger(s1, s2) << std::endl;
    }
}

//Write a program that :
//•	Reads a type(string) and two values of this type from the console
//•	Entered type can be one of the following values : "int", "char" or "string"
//•	Create functions which can compare int, char or string
//•	Return the biggest of the two values