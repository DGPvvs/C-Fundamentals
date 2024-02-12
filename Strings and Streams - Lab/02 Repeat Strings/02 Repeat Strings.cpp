// 02 Repeat Strings.cpp : This file contains the 'main' function. Program execution begins and ends there.
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


int main()
{
    myString input;
    std::getline(std::cin, input);

    std::vector<std::string> words = input.Split(' ');

    std::string output = std::string();

    for (int i = 0; i < words.size(); i++)
    {
        std::string word = words[i];
        for (int j = 0; j < word.length(); j++)
        {
            output.append(word);
        }
    }

    std::cout << output << std::endl;
}

//Write a program that :
//•	Read an space - separated number of strings from the console
//•	Each string has to be repeated N times in the output, where N is the length of the string
//•	Print the resulting string
//Note : Do not use separator or new line between the strings.
