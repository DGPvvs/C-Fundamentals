// 04 Bus.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

void FillArray(int arr[], int);
int DifferenseMinutes(int, int);

int main()
{
    std::string text;
    std::getline(std::cin, text);
    int n = stoi(text);

    int* busTimes = new int[n];

    FillArray(busTimes, n);

    std::getline(std::cin, text);
    int trainTime = stoi(text);

    int bestPosition = 0;
    int currentDiff = 0;

    bool isFirst = true;
    for (int i = 0; i < n; i++)
    {
        int diff = DifferenseMinutes(busTimes[i], trainTime);

        if (isFirst && diff >= 0)
        {
            currentDiff = diff;
            isFirst = false;
            bestPosition = i;
        }
        else if (diff >= 0 && currentDiff > diff)
        {
            currentDiff = diff;
            bestPosition = i;
        }
    }

    std::cout << bestPosition + 1 << std::endl;
}

int DifferenseMinutes(int bus, int train)
{
    int busMinute = (bus / 100) * 60 + bus % 100;
    int trainMinute = (train / 100) * 60 + train % 100;

    return trainMinute - busMinute;
}

void FillArray(int arr[], int n)
{
    myString text;
    std::getline(std::cin, text);

    std::vector<std::string> stringVec = text.Split(' ');

    for (int i = 0; i < n; i++)
    {
        arr[i] = stoi(stringVec[i]);
    }
}

//Captain Grant needs your help. He’s currently on leave but needs to get back to his ship soon. To do that, he needs to catch a bus to the train station,
//and from there take a train to the naval base. But Captain Grant hates waiting – he has a certain train he has to catch but can pick from several busses,
//and he wants to pick a bus which arrives as close to the train departure as possible.
//The transport company, which operates the busses to the station and the trains at the station, has a list of bus arrival times at the station,
//as well as information on the train departure time. Of course, since the company works with the military, the arrival times and the train departure
//time are in military time format – 4-digit numbers, the first two digits represent the hours (00 to 23), the next two digits represent the
//minutes (00 to 59). For example, two o’clock in the morning is 0200, twenty minutes past four in the afternoon is 1620, two minutes to midnight
//(the time, not the Iron Maiden song) is 2358, etc.
//Write a program which, given a list of bus arrival times and a train departure time, in military time format, finds the minimum amount of
//time – in minutes – between bus arrival and the train departure (i.e. the time Grant would have to wait if he picks the "best" bus) and prints the position of the bus in the bus arrival times list. 
//Note that 0 waits are possible, but negative wait times aren’t possible.
//Hint: you can convert the military time format numbers into minutes (minutes elapsed since midnight) before calculating the time between an arrival time and the train time
//Input
//The first line of the standard input will contain the number N – the number of bus arrival times.
//The first line of the standard input will contain a sequence of bus arrival times, in military time format, separated by single spaces.
//The second line of the standard input will contain the train departure time, in military time format.
//Output
//A single line containing a single non-negative integer – the number/position of the bus in the input sequence of bus arrival times, for which the wait time is minimal.
//Restrictions
//N will be at least 1 and at most 20.
//The input data will be such that there will always be a valid (non-negative) minimum wait time. There will always be a bus that arrives before the train leaves.
//The total running time of your program should be no more than 0.1s.
//The total memory allowed for use by your program is 5MB.