// 01 Fun Sequence.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <string>
#include <climits>
#include <vector>
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

    std::vector<int> ConvertVecFromStringToInt()
    {
        std::stringstream iss(*this);

        int number;
        std::vector<int> result = std::vector<int>();
        while (iss >> number)
        {
            result.push_back(number);
        }

        return result;
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

std::vector<int> ConvertVecFromStringToInt(std::string);

int main()
{
    myString text;
    std::getline(std::cin, text);
    std::getline(std::cin, text);

    std::vector<int> intList = text.ConvertVecFromStringToInt();

    std::sort(intList.begin(), intList.end(), [](int& a, int& b) {return a > b;});

    double avrSum = .0;

    for (int i = 0; i < intList.size(); i++)
    {
        avrSum += intList[i];
    }

    avrSum /= intList.size();
    bool isNoPresent = true;
    
    for (int i = 0; i < intList.size(); i++)
    {
        if (intList[i] < avrSum && intList[i] % 2 == 0)
        {
            if (isNoPresent)
            {
                std::cout << intList[i];
                isNoPresent = false;
            }
            else
            {
                std::cout << " " << intList[i];
            }
        }
    }

    if (!isNoPresent)
    {
        std::cout << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }
}

//Write a program which reads a sequence of integers, then finds and prints the numbers that are even and are lower than the average value in the sequence.Sort the numbers in descending order.
//Input
//Read from the console :
//•	An integer number – size of the array.
//•	A sequence of numbers – the elements of the array.
//Output
//Print the described above numbers on a single line, space separated.Print “No” if no numbers hold the above property or if the size of the array is a non - positive number.
//Constraints
//All input numbers are integers in range[-1 000 000 … 1 000 000].The count of numbers is in range[1…50].