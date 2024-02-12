// 07 Password Validator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

std::string IsPasswordValid(std::string);
bool IsCountValid(std::string);
bool IsLetersValid(std::string);
bool Is2DigitsValid(std::string);

int main()
{
    std::string input;
    std::getline(std::cin, input);

    std::cout << IsPasswordValid(input);
}

std::string IsPasswordValid(std::string pass)
{
    const std::string NEW_LINE = "\r\n";

    std::string result = std::string();
    bool isNotValid = false;

    if (!IsCountValid(pass))
    {
        result.append("Password must be between 6 and 10 characters")
            .append(NEW_LINE);
        isNotValid = true;
    }

    if (!IsLetersValid(pass))
    {
        result.append("Password must consist only of letters and digits")
            .append(NEW_LINE);
        isNotValid = true;
    }

    if (!Is2DigitsValid(pass))
    {
        result.append("Password must have at least 2 digits")
            .append(NEW_LINE);
        isNotValid = true;
    }

    if (!isNotValid)
    {
        result.append("Password is valid")
            .append(NEW_LINE);        
    }

    return result;
}

bool IsCountValid(std::string pass)
{
    int count = pass.length();

    return count >= 6 && count <= 10;
}

bool IsLetersValid(std::string pass)
{
    bool result = true;
    for (int i = 0; i < pass.length(); i++)
    {
        char ch = pass[i];
        result = result
            && ((ch >= '0' && ch <= '9')
                || (ch >= 'a' && ch <= 'z')
                || (ch >= 'A' && ch <= 'Z'));
        if (!result)
        {
            return result;
        }
    }

    return result;

}

bool Is2DigitsValid(std::string pass)
{    
    int count = 2;
    for (int i = 0; i < pass.length(); i++)
    {
        char ch = pass[i];
        bool isDigit = (ch >= '0' && ch <= '9');

        if (isDigit)
        {
            count--;
            if (count == 0)
            {
                return true;
            }
        }
    }

    return false;
}

//Write a program that checks if a given password is valid.
//The password validation rules are :
//•	It should contain 6 – 10 characters(inclusive)
//•	It should contain only letters and digits
//•	It should contain at least 2 digits
//If it is not valid, for any unfulfilled rule print the corresponding message :
//•	"Password must be between 6 and 10 characters"
//•	"Password must consist only of letters and digits"
//•	"Password must have at least 2 digits"
