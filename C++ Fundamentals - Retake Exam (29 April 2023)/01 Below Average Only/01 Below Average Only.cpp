// 01 Below Average Only.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <string>
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


int main()
{
    myString text;
    std::getline(std::cin, text);
    int n = stoi(text);

    std::getline(std::cin, text);

    std::vector<std::string> stringVec = text.Split(' ');

    int* arr = new int[n];

    double avrSum = .0;

    for (int i = 0; i < n; i++)
    {
        arr[i] = stoi(stringVec[i]);
        avrSum += arr[i];
    }

    avrSum = avrSum / n;

    std::vector<int> nums = std::vector<int>();

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= avrSum)
        {
            nums.push_back(arr[i]);
        }
    }

    int oddSum = 0, evenSum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        oddSum += nums[i] * (i % 2);
        evenSum += nums[i] * (1 - i % 2);
    }

    std::cout << oddSum * evenSum << std::endl;
}

//Given an array of integer numbers and its size, you will have to create a program for certain calculations.Your task is to find the average number for the given array then only get the numbers below or equal to that average.
//Create two sums from these numbers : a sum of the elements on even positions and a sum of the elements on odd positions.Then multiply those sums and print the final product on the console.
//Input
//•	On the first line you will receive an integer number – the length of the array.
//•	On the second line you will receive a sequence of integer numbers – the array.
//Output
//Print the expected number.
