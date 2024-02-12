// 03 Pipes.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

void FillArray(int*, int);

int main()
{
    std::string text;
    std::getline(std::cin, text);
    int n = stoi(text);

    int* installation = new int[n];
    int* checkup = new int[n];

    FillArray(checkup, n);
    FillArray(installation, n);

    int* lifetimes = new int[n];

    for (int i = 0; i < n; i++)
    {
        lifetimes[i] = floor(1.0 * installation[i] / (installation[i] - checkup[i]));
    }

    bool isFirst = true;
    std::string output = std::string();

    for (int it = 0; it < n; it++)
    {

        if (isFirst)
        {
            output.append(std::to_string(lifetimes[it]));
            isFirst = !isFirst;
        }
        else
        {
            output.append(" ").append(std::to_string(lifetimes[it]));
        }
    }


    std::cout << output << std::endl;
}

void FillArray(int* arr, int n)
{
    myString text;
    std::getline(std::cin, text);

    std::vector<std::string> stringVec = text.Split(' ');

    for (int i = 0; i < n; i++)
    {
        arr[i] = stoi(stringVec[i]);
    }
}

//The company "Water You Waiting For" provides hot water to houses in a village through a series of underground pipes,
//each house having its pipe for hot water. But the pipes corrode over periods of years and need to be replaced.
//Since the company wants to save money, it only does checkups of the pipes once a year, always on the same date (April 1st). Pipes are replaced only during checkups.
//But the company wants to save even more money by skipping checkups when they are not necessary.
//Since the pipes corrode at a constant speed, it is enough to have 2 measurements of a pipe’s strength and
//calculate how much time remains before it needs to be replaced. This needs to be rounded down to years since the repair
//can only happen during a checkup – so if a pipe is going to break after 2 years and 11 months, the company needs to replace
//it after 2 years, because otherwise the pipe will be broken and leak water for 1 month until the 3rd year checkup.
//Write a program which, given two arrays of consecutive strength measurements (measured when the pipes were installed and
//the year after that) of all the pipes, calculates the lifetimes of the pipes (i.e. how many years after it was installed it needs to be replaced).
//Input
//The first line of the standard input will contain a single positive integer number N – the number of pipes.
//The second line of the standard input will contain an array of N positive integer numbers, separated by single spaces, representing the measurements of each pipe,
//made during this year’s checkup – let’s call them a checkup. 
//The second line of the standard input is analogous to the first but contains the measurements from last year – when the pipes were installed – let’s call it installation.
//So, the strength of pipe i last year was installation[i] and this year it is checkup[i].
//Output
//A single line, containing integers separated by single spaces, represents the years remaining until the corresponding pipe described in the input arrays must be replaced
//(counting from installation). If we call this array lifetimes, then pipe i have to be replaced lifetimes[i] years after installation[i] was measured.
//Restrictions
//0 < installation[i] <= 1000000000;  0 <= checkup[i] < installation[i]; 
//N will be a positive number less than or equal to 500.
//The total running time of your program should be no more than 0.1s
//The total memory allowed for use by your program is 5MB