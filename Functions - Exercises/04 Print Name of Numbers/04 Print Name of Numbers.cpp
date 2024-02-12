// 04 Print Name of Numbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#define SPACE " "

std::string Thousands(int);
std::string Hundreds(int);
std::string Dozens(int);
std::string Digits(int);

int main()
{
    int num;
    std::cin >> num;

    std::string output = std::string().append(Thousands(num));

    std::cout << output << std::endl;
}

std::string Digits(int num)
{
    std::string digits[] = {
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine"
    };

    return digits[num % 10];
}

std::string Dozens(int num)
{
    std::string tenDigits[] =
    {
        "ten",
        "eleven",
        "twelve",
        "thirteen",
        "fourteen",
        "fifteen",
        "sixteen",
        "seventeen",
        "eighteen",
        "nineteen"
    };

    std::string digits[] = {
        "",
        "",
        "twenty",
        "thirty",
        "forty",
        "fifty",
        "sixty",
        "seventy",
        "eighty",
        "ninety"
    };

    std::string output = "";

    if (num == 0)
    {
        return output;
    }

    if (num >= 10 && num < 20)
    {
        return output.append(tenDigits[num % 10]);
    }

    int n = num / 10;

    output.append(digits[n]);

    if (num % 10 > 0)
    {
        output.append(SPACE);
    }

    num -= (n * 10);

    if (num == 0)
    {
        return output;
    }

    return output.append(Digits(num));
}

std::string Hundreds(int num)
{
    const std::string HUNDRED = "hundred";
    std::string output = "";

    if (num == 0)
    {
        return output;
    }

    int n = num / 100;

    if (n > 0)
    {
        output.append(Digits(n))
              .append(SPACE)
              .append(HUNDRED);

        if ((num % 100 > 10))
        {
            output.append(SPACE);
        }

        num -= (n * 100);
    }    

    return output.append(Dozens(num));
}

std::string Thousands(int num)
{
    const std::string THOUSAND = "thousand";

    std::string output = "";

    if (num == 0)
    {
        return output.append(Digits(num));
    }    

    int n = num / 1000;
    
    if (n > 0)
    {
        output.append(Digits(n))
              .append(SPACE)
              .append(THOUSAND);

        if ((num % 1000 >= 10))
        {
            output.append(SPACE);
        }

        num -= (n * 1000);
    }    

    return output.append(Hundreds(num));
}

//Write a program that :
//•	Read an integer number in the range[0, 9999]
//•	Prints the name of that number in English
//Hints :
//•	Use lowercase English letters only
//•	Don't place "and" (957 is nine hundred fifty-seven, NOT nine hundred and fifty-seven)
//•	Skip 0 digits, except for the number 0 (0->zero; 101->one hundred one; 1001->one thousand one)
//•	Don't print dashes (print 75 as seventy five, NOT seventy-five)
