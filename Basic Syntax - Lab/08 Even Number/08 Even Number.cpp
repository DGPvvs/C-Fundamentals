// 08 Even Number.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cmath>

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
    string input;

    int times = 1;
    myString output = myString();

label: getline(cin, input);
    int number = stoi(input);

    if (number % 2 != 0)
    {
        output.append("Please write an even number.")
              .append(myString().NewLine());
        goto label;
    }

    output.append("The number is: ")
        .append(to_string(abs(number)))
        .append(myString().NewLine());


    cout << output;

    return 0;
}

//Take as an input an even number and print its absolute value with a message: "The number is: {absoluteValue}".
//If the number is odd, print "Please write an even number." and continue reading numbers. 