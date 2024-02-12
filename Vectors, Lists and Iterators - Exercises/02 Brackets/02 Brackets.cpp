// 02 Brackets.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stack>

int main()
{
    const char OPENING_FIGURE_BRACKET = '{';
    const char OPENING_SQUARE_BRACKET = '[';
    const char OPENING_CURVED_BRACKET = '(';

    const std::string VALID = "valid";
    const std::string INVALID = "invalid";

    std::string brackets;
    std::getline(std::cin, brackets);

    std::stack<char> bracketsStack = std::stack<char>();

    bool isValid = true;

    for (int i = 0; i < brackets.length() && isValid; i++)
    {
        char currentBracket = brackets[i];
        bool isOpenBracket = (currentBracket == OPENING_FIGURE_BRACKET)
            || (currentBracket == OPENING_SQUARE_BRACKET)
            || (currentBracket == OPENING_CURVED_BRACKET);

        if (bracketsStack.size() > 0)
        {
            char topBracket = bracketsStack.top();

            bool isValidClosedBracket = (topBracket + 2 == currentBracket)
                || (topBracket + 1 == currentBracket);

            if (isOpenBracket && topBracket >= currentBracket)
            {
                bracketsStack.push(currentBracket);
            }
            else if (isValidClosedBracket)
            {
                bracketsStack.pop();
            }
            else
            {
                isValid = false;
            }
        }
        else
        {
            if (!isOpenBracket)
            {
                isValid = false;
            }
            else
            {
                bracketsStack.push(currentBracket);
            }
        }
    }

    if (isValid)
    {
        std::cout << VALID << std::endl;
    }
    else
    {
        std::cout << INVALID << std::endl;
    }
}

//Write a program that reads a single line from the console,
//containing brackets for a mathematical expression (only the brackets will appear in the input),
//and determine whether the brackets in the expression are correct.
//There are 3 types of brackets – {}, [] and ().
//{} can contain {}, [] and () brackets.
//Square brackets [] can contain [] and () brackets.
//Curved () brackets can contain only () brackets.
//Said simply, each type of brackets can contain the same type of brackets inside,
//or a "lower" type of brackets (() is lower than [] which is lower than {}).
//If a bracket of one type is opened, it needs to be closed before a bracket of another type is closed.
//Print valid if the brackets in the expression are valid and invalid if they are not.
