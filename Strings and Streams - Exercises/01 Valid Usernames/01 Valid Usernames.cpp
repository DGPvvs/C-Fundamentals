// 01 Valid Usernames.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

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
        const char REPLACE_CHAR_SEPARATOR = '\n';
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


int main()
{
    myString input;
    std::getline(std::cin, input);

    std::vector<std::string> words = input.Split(", ");

    std::string output = std::string();

    for (int i = 0; i < words.size(); i++)
    {
        std::string word = words[i];

        bool isValid = word.length() >= 3 && word.length() <= 16;
        for (int j = 0; isValid && j < word.length(); j++)
        {
            bool isLetter = (word[j] >= 'a' && word[j] <= 'z')
                || (word[j] >= 'A' && word[j] <= 'Z')
                || word[j] == '-'
                || word[j] == '_';
            bool isDigit = word[j] >= '0' && word[j] <= '9';

            isValid = isValid && (isLetter || isDigit);
        }

        if (isValid)
        {
            output.append(word).append(myString().NewLine());
        }
    }

    std::cout << output << std::endl;
}

//Write a program that :
//•	Read usernames on a single line(joined by ", ")
//•	Prints all valid usernames
//A valid username is :
//•	Has a length of between 3 and 16 characters(inclusively)
//•	It contains only letters, numbers, hyphens(-) and underscores(_)
