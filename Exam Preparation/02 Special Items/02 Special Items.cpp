// 02 Special Items.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>

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
    myString vowels = myString("aeiouAEIOU");
    std::string text;
    std::getline(std::cin, text);

    char previousChar = '\0';
    std::string output = std::string();

    if (text.length() > 0)
    {
        previousChar = text[0];
        output.append(1, text[0]);
    }

    for (int i = 1; i < text.length(); i++)
    {
        bool isVowel = vowels.Contains(text[i]);
        bool isSame = text[i] == previousChar;

        if (isVowel || !isSame)
        {
            output.append(1, text[i]);
        }

        previousChar = text[i];
    }

    std::cout << output << std::endl;
}

//You are playing a game in which all symbols of a string are considered special items.
//Your goal is to print a sequence of different symbols and white spaces (write sentences) with no consecutive duplicates of the items unless they are "magical". White spaces should also be removed.
//Magical items are all the vowels: 'a', 'e', 'i', 'o', 'u'.
//Your task is to write a program that removes the unnecessary symbols and print the expected output.
//Input
//On a single line you will receive a string.
//Output
//Print the new string on the console.

