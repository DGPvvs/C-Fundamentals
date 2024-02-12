// 01 Merge Trains.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <string>
#include <climits>
#include <vector>
#include <queue>

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
    const std::string A = "A";
    const std::string B = "B";

    myString text;
    std::getline(std::cin, text);
    std::vector<std::string> list = text.Split(' ');

    std::queue<int> trainA = std::queue<int>();

    for (std::vector<std::string>::iterator it = list.begin(); it != list.end(); it++)
    {
        trainA.push(stoi(*it));
    }

    std::getline(std::cin, text);
    list = text.Split(' ');

    std::queue<int> trainB = std::queue<int>();

    for (std::vector<std::string>::iterator it = list.begin(); it != list.end(); it++)
    {
        trainB.push(stoi(*it));
    }

    std::queue<int> result = std::queue<int>();
    std::string output = std::string();

    while (trainA.size() > 0 || trainB.size() > 0)
    {
        bool isAFill = trainA.size() > 0;
        bool isBFill = trainB.size() > 0;

        if (isAFill && isBFill)
        {
            int a = trainA.front();
            int b = trainB.front();
            if ( a > b)
            {
                result.push(trainA.front());
                trainA.pop();
                output.insert(0, A);
            }
            else
            {
                result.push(trainB.front());
                output.insert(0, B);
                trainB.pop();
            }
        }
        else if (!isAFill)
        {
            result.push(trainB.front());
            output.insert(0, B);
            trainB.pop();
        }
        else if (!isBFill)
        {
            result.push(trainA.front());
            output.insert(0, A);
            trainA.pop();
        }
    }

    output.append(myString().NewLine());

    bool isFirst = true;
    while (result.size() > 0)
    {
        if (isFirst)
        {
            output.append(std::to_string(result.front()));
            isFirst = false;
        }
        else
        {
            output.append(" ").append(std::to_string(result.front()));
        }

        result.pop();
    }

    std::cout << output << std::endl;
}

//At a certain train station, trains arrive on two tracks – Track A and Track B – and are merged onto a single track.Each railcar has a number, and in each train, the railcars are ordered by number – the front railcar has the lowest number, the back railcar has the highest number.
//Given the railcar numbers on Track A and Track B, given from the back car to the front car, print the order in which railcars from Track A and Track B should be merged into the single track, then print the new train configuration, starting from the last railcar and finishing at the first railcar.Railcars are moved to start from the front to the back(i.e.you can only move the front car of a train).Each time you move a railcar from the parallel tracks A and B to the merge track, it pushes forward any railcars that are already there.
//Input
//•	The first line of the console will contain the numbers of the railcars on Track A, from the last railcar to the first railcar.
//•	The second line of the console will contain the numbers of the railcars on Track B, from the last railcar to the first railcar.
//Output
//•	If a railcar from Track A should be moved to the single track, print A.Otherwise, print B.
//•	On a separate line print the final configuration of the train(numbers separated by spaces, representing the railcar numbers from the last railcar to the first).
//The "input" railcars will always be correctly ordered(i.e.will be a line of descending positive integer numbers).The input will be such that the result will never have any railcars with the same numbers.
