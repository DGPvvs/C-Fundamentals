// 01 Order Two Numbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

class myString :public string
{
private:
    const string EMPTY = "";
    const string NEW_LINE = "\r\n";

public:

    myString(const char* s) :string(s)
    {

    }

    myString() :string()
    {

    }

    string Empty()
    {
        return this->EMPTY;
    }
    string NewLine()
    {
        return this->NEW_LINE;
    }

    vector<string> Split(char ch)
    {
        vector<string> result;
        string s = this->EMPTY;

        stringstream ss(*this);

        while (getline(ss, s, ch))
        {
            result.push_back(s);
        }

        return result;
    }

    bool Contains(string f)
    {
        int idx = this->find(f);
        return idx > -1;
    }

    string ToLower()
    {
        string s = string("");

        string::iterator it;
        for (it = this->begin(); it != this->end(); it++)
        {
            s.append(1, tolower(*it));
        }

        return s;
    }

    string ToUpper()
    {
        string s = string("");

        string::iterator it;
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

bool TryParseInt(string);

int main()
{
    //myString input;
    //getline(cin, input);

    //vector<string> stringVector = input.Split(' ');
    vector<string> stringVector;

    for (size_t i = 0; i < 2; i++)
    {
        string input;
        cin >> input;
        stringVector.push_back(input);
        cin.ignore();
    }

    vector<int> nums;
    vector<string>::iterator it;

    while (stringVector.size() > 0)
    {
        string s = stringVector.back();
        stringVector.pop_back();

        if (TryParseInt(s))
        {
            nums.push_back(stoi(s));
        }
    }

    sort(nums.begin(), nums.end(), [](int& a, int& b) { return a < b; });

    string output = string();

    for (auto i = nums.begin(); i < nums.end(); i++)
    {
        output.append(to_string(*i)).append(" ");
    }

    cout << output << endl;
}

bool TryParseInt(string num)
{
    try
    {
        int n = stoi(num);
    }

    catch (exception& e)
    {
        return false;
    }

    return true;
}

//Write a program that :
//•	Read two integers from the console
//•	Print the two numbers in increasing order
