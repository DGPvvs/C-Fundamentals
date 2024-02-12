// 08 Orders.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>

std::string FormatDoubleNum(double, int);
double GetPrice(std::string, int);

int main()
{
    std::string product, input;
    std::getline(std::cin, product);
    std::getline(std::cin, input);

    int quantity = std::stoi(input);

    std::cout << FormatDoubleNum(GetPrice(product, quantity), 2) << std::endl;
}

std::string FormatDoubleNum(double number, int precision)
{
    std::stringstream stream;

    stream.precision(precision);
    stream << std::fixed;

    stream << number;

    return stream.str();
}

double GetPrice(std::string product, int quantity)
{
    const std::string COFFE = "coffee", WATER = "water", COKE = "coke", SNACKS = "snacks";
    const double PRICE_COFFE = 1.5, PRICE_WATER = 1.0, PRICE_COKE = 1.4, PRICE_SNACKS = 2.0;

    double result = .0;

    if (product == COFFE)
    {
        result = PRICE_COFFE * quantity;
    }
    else if (product == WATER)
    {
        result = PRICE_WATER * quantity;
    }
    else if (product == COKE)
    {
        result = PRICE_COKE * quantity;
    }
    else if (product == SNACKS)
    {
        result = PRICE_SNACKS * quantity;
    }

    return result;
}


//Write a program that :
//•	Reads a string on the first line from the console, representing a product - "coffee", "water", "coke" or "snacks"
//•	Reads an integer on the second line from the console, representing the quantity of the product
//•	Create a function that calculatesand prints the total price of an order
//•	The function should receive two parameters : product and quantity
//•	The prices for a single item of each product are :
//	coffee – 1.50
//	water – 1.00
//	coke – 1.40
//	snacks – 2.00
//•	Print the result, formatted to the second digit
