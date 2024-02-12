// 05 Manipulations.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

int main()
{
    const std::string END = "end";
    const std::string ADD = "Add";
    const std::string REMOVE = "Remove";
    const std::string REMOVEAT = "RemoveAt";
    const std::string INSERT = "Insert";

    myString text;
    std::getline(std::cin, text);
    std::vector<std::string> stringVec = text.Split(' ');

    std::vector<int> list = std::vector<int>();

    for (std::vector<std::string>::iterator it = stringVec.begin(); it != stringVec.end(); it++)
    {
        list.push_back(stoi(*it));
    }

    bool isLoopExit = false;

    while (!isLoopExit)
    {
        std::getline(std::cin, text);
        std::vector<std::string> commands = text.Split(' ');
        std::string command = commands[0];

        if (command == END)
        {
            isLoopExit = true;
        }
        else
        {
            int val = stoi(commands[1]);
            if (command == ADD)
            {                
                list.push_back(val);
            }
            else if (command == REMOVE)
            {
                int idx = 0;
                bool exitRemove = false;

                while (idx < list.size() && !exitRemove)
                {
                    if (list[idx] == val)
                    {
                        list.erase(list.begin() + idx);
                        exitRemove = true;
                    }

                    idx++;
                }
            }
            else if (command == REMOVEAT)
            {
                list.erase(list.begin() + val);
            }
            else if (command == INSERT)
            {
                int index = stoi(commands[2]);
                list.insert(list.begin() + index, val);
            }            
        }
    }

    std::string output = std::string();

    bool isFirst = true;
    for (int i = 0; i < list.size(); i++)
    {
        if (isFirst)
        {
            output.append(std::to_string(list[i]));
            isFirst = false;
        }
        else
        {
            output.append(" ").append(std::to_string(list[i]));
        }
    }

    std::cout << output << std::endl;
}

/// Write a program that :
//•	Read a list of integers from the first line of the console
//•	Then until you receive "end", you will be given different commands :
//o	Add{ number } – add a number to the end of the list
//o	Remove{ number } – remove a number from the list
//o	RemoveAt{ index } – remove a number at a given index
//o	Insert{ number }{ index } – insert a number at a given index
//Note : All the indices will be valid!
//•	When you receive the "end" command, print the final state of the list(separated by spaces).