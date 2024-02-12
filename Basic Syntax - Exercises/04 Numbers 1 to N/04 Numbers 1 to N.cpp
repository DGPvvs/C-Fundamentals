// 04 Numbers 1 to N.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <string>
#include <climits>
#include <vector>

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


int main()
{
    int n;
    cin >> n;

    string output = string();

    int i = 1;
label: output.append(to_string(i)).append(" ");

    i++;
    if (i <= n)
    {
        goto label;
    }
    
    cout << output << endl;
}

//Write a program that :
//•	Read the integer number N from the console
//•	Print all numbers from 1 to N(inclusively) to the console on a single line
//Note : The number N will always be larger than or equal to 1.
