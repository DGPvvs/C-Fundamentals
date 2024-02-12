// 01 Day of Week.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    std::string days[] =
    {
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday",
        "Sunday"
    };

    int num;
    std::cin >> num;

    switch (num)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        std::cout << days[num - 1] << std::endl;
        break;
    default:
        std::cout << "Invalid day!" << std::endl;
        break;
    }
}

//Write a program that :
//•	Reads an integer number from the console
//•	If the number is in range[1; 7] you have to print :
//o	Monday if the number is 1
//o	Tuesday if the number is 2
//o	Wednesday if the number is 3
//o	Thursday if the number is 4
//o	Friday if the number is 5
//o	Saturday if the number is 6
//o	Sunday if the number is 7
//•	If the number is out of the given range above print : "Invalid day!"