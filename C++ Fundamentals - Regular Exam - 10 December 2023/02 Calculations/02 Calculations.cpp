// 02 Calculations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>
#include <stack>

class myString :public std::string
{
private:
    const std::string EMPTY = "";
    const std::string NEW_LINE = "\r\n";

public:
    myString(const char* s) :std::string(s)
    {

    }

    myString() :std::string()
    {

    }

    std::string Empty()
    {
        return this->EMPTY;
    }
    std::string NewLine()
    {
        return this->NEW_LINE;
    }

    std::vector<std::string> Split(char ch)
    {
        std::vector<std::string> result;
        std::string s = this->EMPTY;

        std::stringstream ss(*this);

        while (getline(ss, s, ch))
        {
            result.push_back(s);
        }

        return result;
    }

    std::vector<std::string> Split(std::string separator)
    {
        const std::string REPLACE_STRING_SEPARATOR = "\n";
        const char REPLACE_CHAR_SEPARATOR = REPLACE_STRING_SEPARATOR[0];

        std::vector<std::string> result;
        std::string s = std::string(*this);

        int idx = s.find(separator);

        while (idx > -1)
        {
            s.replace(idx, separator.length(), REPLACE_STRING_SEPARATOR);
            idx = s.find(separator);
        }

        std::stringstream ss(s);

        while (getline(ss, s, REPLACE_CHAR_SEPARATOR))
        {
            result.push_back(s);
        }

        return result;
    }

    bool Contains(std::string f)
    {
        int idx = this->find(f);
        return idx > -1;
    }

    bool Contains(char ch)
    {
        std::string s = std::string(1, ch);

        return this->Contains(s);
    }

    std::string ToLower()
    {
        std::string s = std::string("");

        std::string::iterator it;
        for (it = this->begin(); it != this->end(); it++)
        {
            s.append(1, tolower(*it));
        }

        return s;
    }

    std::string ToUpper()
    {
        std::string s = std::string("");

        std::string::iterator it;
        for (it = this->begin(); it != this->end(); it++)
        {
            s.append(1, toupper(*it));
        }

        return s;
    }

    ~myString()
    {

    }
};

bool TryParse(std::string, int&);

int main()
{
    std::string PLUS = "+";
    std::string MINUS = "-";
    std::string MULTYPLI = "*";
    std::string DIVIDE = "/";

    myString text;
    std::getline(std::cin, text);

    int currentValue = 0, previousValue = 0, num = 0, result = 0;

    std::vector<std::string> list = text.Split(' ');


    for (int i = 0; i < list.size(); i++)
    {
        if (TryParse(list[i], num))
        {
            previousValue = currentValue;
            currentValue = num;
        }
        else if (list[i] == PLUS)
        {
            result = previousValue + currentValue;
            previousValue = currentValue;
            currentValue = result;
        }
        else if (list[i] == MINUS)
        {
            result = previousValue - currentValue;
            previousValue = currentValue;
            currentValue = result;
        }
        else if (list[i] == MULTYPLI)
        {
            result = previousValue * currentValue;
            previousValue = currentValue;
            currentValue = result;
        }
        else if (list[i] == DIVIDE)
        {
            result = previousValue / currentValue;
            previousValue = currentValue;
            currentValue = result;
        }
    }

    std::cout << currentValue << " " << previousValue << std::endl;
}

bool TryParse(std::string s, int& num)
{
    try
    {
        num = stoi(s);
    }
    catch (...)
    {
        return false;
    }

    return true;
}

//Your task is to read a line of N elements (separated by space) and perform calculations, based on this line. 
//Each element in the line can be:
//•	integer number (which will fit long)
//•	one of the chars +, *, - or /, which indicate the operation you must do
//Your calculator has two variables: "current value" and "previous value" which both start from 0.
//If an operation comes, you use it to perform the calculation: previous value operation current value.
//If a number comes, first your previous value becomes the current value, and then the new number becomes your new current value.
//When the input operations end, you should print the two values: current value and previous value.
//Hints: 
//•	The / operation is integer division, so the result must be integer. 
//•	You should not handle the 'Division by zero' case, as the input will be correct all the time.
