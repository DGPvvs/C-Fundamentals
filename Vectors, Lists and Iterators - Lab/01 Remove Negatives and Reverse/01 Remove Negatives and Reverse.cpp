// 01 Remove Negatives and Reverse.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>
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
    const std::string EMPTY = "empty";

    myString text;
    std::getline(std::cin, text);

    std::vector<std::string> words = text.Split(' ');

    std::list<int> result = std::list<int>();

    for (int i = 0; i < words.size(); i++)
    {
        int num = 0;
        if (TryParse(words[i], num) && num >= 0)
        {
            result.push_back(num);
        }
    }

    std::string output = std::string();

    if (result.size() == 0)
    {
        output.append(EMPTY);
    }
    else
    {
        result.reverse();
        bool isFirst = true;

        for (std::list<int>::iterator it = result.begin(); it != result.end(); it++)
        {
            if (isFirst)
            {
                output.append(std::to_string(*it));
                isFirst = !isFirst;
            }
            else
            {
                output.append(" ").append(std::to_string(*it));
            }
        }
    }

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
//•	Read a sequence of numbers, separated with single space 
//•	Remove all negative numbers from given sequence
//•	Print the remaining elements in reversed order
//Note: In case of no elements left in the list, print "empty".