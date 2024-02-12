// 04 Character Multiplier.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

std::string MultiplyStrings(std::string, std::string);

int main()
{
    myString input;
    std::getline(std::cin, input);

    std::vector<std::string> words = input.Split(' ');

    std::string output;

    if (words[0].length() >= words[1].length())
    {
        output = MultiplyStrings(words[0], words[1]);
    }
    else
    {
        output = MultiplyStrings(words[1], words[0]);
    }

    std::cout << output << std::endl;
}

std::string MultiplyStrings(std::string s1, std::string s2)
{
    int sum = 0;
    std::string diffString = s1.substr(s2.length());

    for (int i = 0; i < diffString.length(); i++)
    {
        sum += (int)diffString[i];
    }

    for (int i = 0; i < s2.length(); i++)
    {
        sum += (int)s1[i] * (int)s2[i];
    }

    return std::string(std::to_string(sum));
}

//Write a program that :
//•	Reads two strings from the console, separated by single space
//•	Calculate the sum of strings character codes multiplied(multiply str1[0] with str2[0] and add to the total sum) and continue with the next two characters
//•	Print the calculated sum
//Note : If one of the strings is longer than the other, add the remaining character codes to the total sum without multiplication.
