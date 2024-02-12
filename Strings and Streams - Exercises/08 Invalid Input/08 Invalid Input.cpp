// 08 Invalid Input.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <string>

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
    myString text;
    std::getline(std::cin, text);

    std::vector<std::string> words = text.Split(' ');

    int sum = 0;

    std::string invalidNums = std::string();
    bool isFirst = true;

    for (int i = 0; i < words.size(); i++)
    {
        int num = 0;
        if (TryParse(words[i], num))
        {
            sum += num;
        }
        else
        {
            if (isFirst)
            {
                invalidNums.append(words[i]);
                isFirst = false;
            }
            else
            {
                invalidNums.append(" ").append(words[i]);
            }
        }
    }

    std::string output = std::string().append(std::to_string(sum)).append(myString().NewLine()).append(invalidNums);

    std::cout << output << std::endl;
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

//Write a program that:
//•	Read a line containing integer numbers, separated by space from the console
//•	Calculate sum of the entered numbers
//•	Print the calcualated sum
//•	In addition to the numbers, each line will contain one or more words
//•	Print those words on a separate line, separated by spaces, after the sum, in the order, they were in the input