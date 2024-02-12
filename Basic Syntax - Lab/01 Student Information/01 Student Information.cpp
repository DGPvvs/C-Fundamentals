// 01 Student Information.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string FormatDoubleNum(double, int);

int main()
{
    string name;
    getline(cin, name);

    string input;
    getline(cin, input);
    int age = stoi(input);

    getline(cin, input);
    double averageGrade = stod(input);

    string output = string("Name: ")
        .append(name)
        .append(", Age: ")
        .append(to_string(age))
        .append(", Grade: ")
        .append(FormatDoubleNum(averageGrade, 2));

    cout << output << endl;
}

string FormatDoubleNum(double number, int precision)
{
    stringstream stream;

    stream.precision(precision);
    stream << fixed;

    stream << number;

    return stream.str();
}

//You will be given 3 lines of input – student name(string), age(integer number), and average grade(floating - point number).Your task is to print all the info about the student in the following format, where grade is formatted with 2 digits:
//"Name: {student name}, Age: {student age}, Grade: {student grade}".
