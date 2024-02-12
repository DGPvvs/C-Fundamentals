// 04 Merging Lists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

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

std::string MergeLists(std::vector<int>&, std::vector<int>&);
std::string MergeDifferent(std::vector<int>&, int, int);

int main()
{
    myString text;
    std::getline(std::cin, text);
    std::vector<std::string> stringVec = text.Split(' ');

    std::vector<int> firstVec = std::vector<int>();

    for (std::vector<std::string>::iterator it = stringVec.begin(); it != stringVec.end(); it++)
    {
        firstVec.push_back(stoi(*it));
    }

    std::getline(std::cin, text);
    stringVec = text.Split(' ');

    std::vector<int> secondVec = std::vector<int>();

    for (std::vector<std::string>::iterator it = stringVec.begin(); it != stringVec.end(); it++)
    {
        secondVec.push_back(stoi(*it));
    }

    std::string output = MergeLists(firstVec, secondVec);

    std::cout << output << std::endl;
}

std::string MergeDifferent(std::vector<int>& upper, int begin, int end)
{
    std::string result = std::string();

    for (int i = begin; i < end; i++)
    {
        result.append(" ").append(std::to_string(upper[i]));
    }

    return result;
}

std::string MergeLists(std::vector<int>& first, std::vector<int>& second)
{
    std::string result = std::string();

    int size = std::min(first.size(), second.size());

    bool isFirst = true;
    for (int i = 0; i < size; i++)
    {
        if (isFirst)
        {
            result.append(std::to_string(first[i]));
            isFirst = false;
        }
        else
        {
            result.append(" ").append(std::to_string(first[i]));
        }

        result.append(" ").append(std::to_string(second[i]));
    }

    if (first.size() > second.size())
    {
        result.append(MergeDifferent(first, second.size(), first.size()));
    }
    else
    {
        result.append(MergeDifferent(second, first.size(), second.size()));
    }

    return result;
}

//Write a program that:
//•	Read two sequences with numbers from the first two lines of the console
//•	Create a result sequence that contains the numbers from both of the lists
//•	The first element should be from the first list, the second from the second list and so on
//•	Print the resulting merged sequence
//Note: If the length of the two lists is not equal, just add the remaining elements at the end of the list.