// 04 Foreign Languages.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

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
    myString englandandUSA = myString("EnglandUSA");
    myString spainArgentinaMexico = myString("SpainArgentinaMexico");

    string input;
    getline(cin, input);

    string output = string();

    if (englandandUSA.Contains(input))
    {
        output.append("English");
    }
    else if (spainArgentinaMexico.Contains(input))
    {
        output.append("Spanish");
    }
    else
    {
        output.append("unknown");
    }

    cout << output << endl;
}

//Write a program that prints the language that a given country speaks.You can receive only the following combinations :
//•	English is spoken in England and USA
//•	Spanish is spoken in Spain, Argentina and Mexico
//•	For the others we should print "unknown"
//Input
//You will receive a single country name on a single line.
//Output
//Print the language, which the country speaks, or if it is unknown for your program, print "unknown".
