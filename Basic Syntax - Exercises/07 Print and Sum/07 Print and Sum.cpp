// 07 Print and Sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::stringstream;
using std::to_string;

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
    int startRange, endRange;
    cin >> startRange >> endRange;

    int sum = 0;
    auto AddString = [](string a, int b) -> string { return a.append(to_string(b)).append(" "); };

    string output = myString().Empty();

    for (int i = startRange; i <= endRange; i++)
    {        
        sum += i;
        output = AddString(output, i);
    }

    output.append(myString().NewLine()).append("Sum: ");

    output = AddString(output, sum);

    cout << output << endl;
}

//Write a program that :
//•	Read an integer number(start number) on the first line from the console
//•	Read an integer number(end number) on the second line from the console
//•	Print numbers from given start number to given end number
//•	Print their sum in the following format : "Sum: {sum}"
//Note : All the numbers will be integers.