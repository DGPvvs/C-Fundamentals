// 02 Secret Message.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <string>
#include <climits>
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
    std::string text;
    std::getline(std::cin, text);

    int charSum = 0;    

    for (int i = 0; i < text.length(); i++)
    {
        if (isdigit(text[i]))
        {
            charSum += (text[i] - '0');
        }
    }

    if (isalpha((char)charSum))
    {
        std::cout << (char)charSum << std::endl;
    }
    else
    {
        std::cout << charSum << std::endl;
    }    
}

//We have discovered a new way that students use to cheat on exams involving single - answer questions.They send each other messages, which seem to have no correlation to the exam, but contain secret information about the correct answers to questions.
//Some messages contain the numbers of questions, others contain the letters corresponding to the answers.For example, if question 15’s correct answer is A, then one message will contain the number 15 encoded in it, and another will contain the letter A encoded in it.These values encoded in the messages we will call “secret values”.
//The encoding mechanism is simple – among the text, there will be digits.The sum of those digits is calculated, and if it corresponds to an ASCII code of a lowercase or uppercase English letter, then that letter is the secret value.Otherwise the sum itself is the secret value.
//For example, the text "Hi999, 999wh9at’s u2p." contains the sum 9 + 9 + 9 + 9 + 9 + 9 + 9 + 2 = 65, which is the ASCII code of the letter 'A' – so that is the encoded letter in the message.
//On the other hand, the message "No5 9mu1ch." contains the sum 5 + 9 + 1 = 15, which is not an ASCII code for a letter, so it is just an encoded number.
//You are given a single line of text(upper - and lowercase English letters, digits, punctuation, spaces, etc.) ending with a '.' (dot)character and not containing any other '.' (dot)character.
//Print whatever secret value is encoded in the message – a letter if the value is the ASCII code of a letter, or a number otherwise.
//Input
//A single line on the standard input will contain the text and will contain exactly one '.' (dot)character, which will be at the end of the text.
//Output
//A single line, containing the secret value.
//Restrictions
//The text will contain no more than 300 characters.
//The total running time of your program should be no more than 0.1s
//The total memory allowed for use by your program is 16MB
