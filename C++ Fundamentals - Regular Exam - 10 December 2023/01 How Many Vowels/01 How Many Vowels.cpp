// 01 How Many Vowels.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

int main()
{
    myString vowels = "aeiouyAEIOUY";

    myString text;
    std::getline(std::cin, text);
    std::getline(std::cin, text);

    std::vector<std::string> list = text.Split(' ');

    int vowelsCount = 0, nonVowelsCount = 0;

    for (int i = 0; i < list.size(); i++)
    {
        if (vowels.Contains(list[i]))
        {
            vowelsCount++;
        }
        else if (isalpha(list[i][0]))
        {
            nonVowelsCount++;
        }
    }

    std::cout << vowelsCount << " " << nonVowelsCount << std::endl;
}

//Write a program that:
//•	Read integer number N, which is the number of space-separated characters that will follow
//•	Count the vowels letters from the input and the non-vowels letters from the input
//•	Print the number of vowels, followed by a space and the number of non-vowels
//Hints:
//1.	Vowels are the letters a, e, i, o, u and y
//2.	Be careful of the capitalization, as you may get capital letters
//3.	You may get characters, which are not letters (for example:(, +, -, @, $)