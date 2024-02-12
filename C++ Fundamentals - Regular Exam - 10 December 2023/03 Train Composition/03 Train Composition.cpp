// 03 Train Composition.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

bool TryParse(std::string, int&);

int main()
{
    const std::string EMPTY = "empty";
    const std::string END = "end";

    const std::string EMPTY_SYMBOL = " ";
    const std::string SLASH_SYMBOL = "|";

    std::vector<std::string> list = std::vector<std::string>();

    bool isLoopExit = false;

    while (!isLoopExit)
    {
        myString text;
        std::getline(std::cin, text);

        if (text == EMPTY)
        {
            list.push_back(EMPTY_SYMBOL);
        }
        else if (text == END)
        {
            isLoopExit = true;
        }
        else
        {
            list.push_back(text);
        }
    }

    isLoopExit = false;

    while (!isLoopExit)
    {
        myString text;
        std::getline(std::cin, text);

        if (text == "E")
        {
            isLoopExit = true;
        }
        else if (text == "P")
        {
            std::string output = std::string().append(SLASH_SYMBOL);
            for (int i = 0; i < list.size(); i++)
            {
                output.append(list[i]).append(SLASH_SYMBOL);
            }
            std::cout << output << std::endl;
        }
        else if (text[0] == 'L')
        {
            std::vector<std::string> commands = text.Split(' ');
            int pos = stoi(commands[1]) - 1;
            list.erase(list.begin() + pos);
            std::string output = std::string().append(SLASH_SYMBOL);
            for (int i = 0; i < list.size(); i++)
            {
                output.append(list[i]).append(SLASH_SYMBOL);
            }
            std::cout << output << std::endl;
        }
        else if (text[0] == 'M')
        {
            std::vector<std::string> commands = text.Split(' ');
            int oldWagonPosition = stoi(commands[1]) - 1;
            int newWagonPosition = stoi(commands[2]) - 1;
            std::string temp = list[oldWagonPosition];
            list.erase(list.begin() + oldWagonPosition);
            list.insert(list.begin() + newWagonPosition, temp);
            std::string output = std::string().append(SLASH_SYMBOL);
            for (int i = 0; i < list.size(); i++)
            {
                output.append(list[i]).append(SLASH_SYMBOL);
            }
            std::cout << output << std::endl;
        }
    }
}

//Let's have a train! The train consists of wagons, which can have content in them, or can be empty.
//We need to make a program, which will allow shuffling the contents of our wagons.
//Your program must read the train’s composition, and then process each command, printing out the train composition after each command. 
//The input is the following:
//•	First: the train composition is the content of each wagon:
//o	Each wagon’s contents are given on a separate line, describing the contents of the wagon; 
//o	If the line reads "empty", then the wagon is empty.
//o	If the line reads "end", then this is not a wagon, but the end of our train, so we're done with the reading the wagons' contents.
//•	Then: we start processing commands. Each command is on a separate line and can have parameters! 
//Here's the list of the commands:
//o	P – print the current train structure:
//	We start with '|', then we print the contents of each wagon, followed by another '|'
//o	M oldWagonPosition newWagonPosition 
//	Move the wagon at position oldWagonPosition to the newWagonPosition.
//	The moving happens as in the real world: the locomotive pulls the wagon from position oldWagonoPosition, then pushes it in a way to become at the newWagonPosition.
//o	L wagonPosition: leave the wagon at position wagonPosition at the station (e.g., remove the wagon from the train)
//o	E: end
//	The last command, we're done with the commands processing.
//	Note: after this command we do not print out the contents of the train!
//Hints:
//•	You will never be given an empty train, or commands, which will lead to train becoming empty.