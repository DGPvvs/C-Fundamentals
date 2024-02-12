// 07 Multiplication Table.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    string input;
    getline(cin, input);
    int theInteger = stoi(input);

    int times = 1;
    myString output = myString();

label: int product = theInteger * times;

    output.append(input)
        .append(" X ")
        .append(to_string(times))
        .append(" = ")
        .append(to_string(product))
        .append(myString().NewLine());

    times++;

    if (times < 11)
    {
        goto label;
    }

    cout << output;

    return 0;
}

//You will receive an integer as input from the console. Print the 10 times table for this integer. See the examples below for more information.
//Output
//Print every row of the table in the following format:
//{theInteger} X {times} = {product}
//Constraints
//•	The integer will be in the interval [1…100]