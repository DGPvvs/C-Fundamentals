// 03 Punctuation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>

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
    myString input;
    std::getline(std::cin, input);

    std::vector<std::string> text = input.Split('|');
    std::map<int, int> output = std::map<int, int>();

    for (int i = 0; i < text.size(); i++)
    {
        int punctuationSymbols = 0;
        std::string s = text[i];
        for (int j = 0; j < s.length(); j++)
        {
            char ch = s[j];
            if (ispunct(ch))
            {
                punctuationSymbols++;
            }
        }

        if (output.find(punctuationSymbols) != output.end())
        {
            output[punctuationSymbols]++;
        }
        else
        {
            output.insert(std::pair<char, int>(punctuationSymbols, 1));
        }
    }

    std::string finalString = std::string();

    for (auto& it : output)
    {
        finalString.append(std::to_string(it.first))
            .append(" symbol sentences: ")
            .append(std::to_string(it.second))
            .append(myString().NewLine());
    }

    std::cout << finalString;
}

//The young 24 - year - old graduate Maria has just received her university degree.She wants to become a literature teacher.The girl was one of the few people that had NOT actually written “åñå” in the comments section for that game several years ago.She managed to write the whole stuff.
//Maria was chosen among a few to continue to the next round of the competition.
//She was asked to make a statistic of the punctuation used in her essay.Help her out!
//Your task is to write program, which reads a single string from the standard input(Maria’s essay).
//Then counts how many punctuation signs each sentence has and groups the sentences by their punctuation count.
//Sentences with the same number of characters should be grouped together(see Examples).
//The punctuation occurrences should be sorted in ascending order.
//The end of each sentence will be marked by the “ | ” character(without the quotes).
//Important note : Do NOT count the separator symbol “ | ” as a punctuation sign.
//Symbols !"#$%&'()*+,-./:;<=>?@[]^_`{}~ are considered as punctuation signs.
//Hint : there is a build - in function in the C / C++ standard for this.
//Input
//Read a single Line of data that will hold the whole essay.
//Restrictions
//Time limit : 250ms(0.25s)
//Memory limit : 16 MB
