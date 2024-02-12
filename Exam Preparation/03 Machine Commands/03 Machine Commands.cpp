// 03 Machine Commands.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

bool TryParseInt(std::string);

int main()
{
    const std::string SUM = "sum";
    const std::string SUBTRACT = "subtract";
    const std::string CONCAT = "concat";
    const std::string DISCARD = "discard";
    const std::string END = "end";

    bool isLoopExit = false;
    std::stack<int> list = std::stack<int>();
    while (!isLoopExit)
    {
        std::string text;
        std::getline(std::cin, text);

        if (TryParseInt(text))
        {
            list.push(stoi(text));
        }
        else if (text == SUM)
        {
            int first = list.top();
            list.pop();

            int second = list.top();
            list.pop();

            list.push(first + second);
        }
        else if (text == SUBTRACT)
        {
            int a = list.top();
            list.pop();

            int b = list.top();
            list.pop();

            list.push(a - b);
        }
        else if (text == CONCAT)
        {
            int a = list.top();
            list.pop();

            int b = list.top();
            list.pop();

            std::string s = std::to_string(b);
            s.append(std::to_string(a));
            list.push(stoi(s));
        }
        else if (text == DISCARD)
        {
            list.pop();
        }
        else if (text == END)
        {
            isLoopExit = true;
        }
    }

    std::string output = std::string();
    bool isFirst = true;

    while (list.size() > 0)
    {
        if (isFirst)
        {
            output.append(std::to_string(list.top()));
            list.pop();
            isFirst = false;
        }
        else
        {
            output.insert(0, myString().NewLine()).insert(0, std::to_string(list.top()));
            list.pop();
        }
    }

    std::cout << output << std::endl;
}

bool TryParseInt(std::string s)
{
    int n = 0;
    try
    {
        n = stoi(s);
    }
    catch (...)
    {
        return false;
    }

    return true;
}

//You are tasked with implementing software for a computational machine, which does basic operations with integer numbers.
//The machine has memory in the form of a sequence of numbers.
//When it does an operation, it takes (removes) numbers from the end of the sequence, calculates the result using those numbers and puts it back at the end of the sequence.
//There are also some operations which only add at the end or only remove from the end of the sequence. 
//List of operation command:
//•	{number} – Inserting a number: number is a single integer number (can be positive, negative or 0).  Inserts a number at the end of the sequence (appends to the end of the sequence).
//•	sum - Removes the last two numbers in the sequence, calculates their sum and adds it back to the end of the sequence.
//•	subtract - Removes the last element from the sequence (a) then removes the next last element (b). Subtracts the two (a – b) and adds the result to the end of the sequence. 
//Example: If the sequence is (1, 4, 7), the command subtract will remove 7 and 4, calculate 7 - 4 and add it back to the sequence. The result sequence will be (1, 3).
//•	concat - Concatenates the last two elements in the sequence (as if they were strings), in the order they were added to it, evaluates the result to an integer and adds it to the end of the sequence.
//Example: If the sequence is (1, 4, 7), then concat will remove 7 and 4, concatenate 4 and 7, resulting in 47, and add it to the sequence. The result sequence will be (1, 47).
//•	discard - Removes the last element from the sequence.
//•	end – End of program.
//Write a program which executes the operations described above and prints the final sequence of numbers in the order in which they were added.
//Input
//Two or more lines, each indicating an operation to be done with the machine (note that a line containing a single integer is the {number} operation).
//The final line will not contain numbers and will only contain the string "end"
//Output
//One or more lines, each containing a single integer, representing the numbers in the final sequence.
//Restrictions
//There will be no more than 50 lines of operations in the input.
//The concat operation will never be done when the last element in the sequence is negative.
//All operations will be valid – there will always be enough numbers in the sequence for an operation to be executed correctly.
//There will always be at least 1 number in the final sequence.
