// 05 Mathematical Expression ver 2.0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    const std::string CORRECT = "correct";
    const std::string INCORRECT = "incorrect";
    const char OPEN_BRACKET = '(';
    const char CLOSET_BRACKET = ')';

    std::string expresion;
    std::cin >> expresion;

    int bracketsCount = 0;

    bool isCorrect = true;
    for (int i = 0; isCorrect && i < expresion.length(); i++)
    {
        if (expresion[i] == CLOSET_BRACKET)
        {
            if (bracketsCount == 0)
            {
                isCorrect = false;
            }
            else
            {
                bracketsCount--;
            }
        }
        else if (expresion[i] == OPEN_BRACKET)
        {
            bracketsCount++;
        }
    }

    if (isCorrect && bracketsCount != 0)
    {
        isCorrect = false;
    }

    if (isCorrect)
    {
        std::cout << CORRECT << std::endl;
    }
    else
    {
        std::cout << INCORRECT << std::endl;
    }
}

//Write a program that :
//•	Reads a line from the console containing a mathematical expression
//•	Check whether the brackets in the expression() are placed correctly
//•	Print "correct", if the brackets are placed correctly
//•	Print "incorrect", if the brackets are placed incorrectly
//Note : Assume everything else is correct, you don't need to check for correct signs, correct variables / numbers.