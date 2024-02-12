// 02 Operations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    int operand1, operand2;
    std::cin >> operand1 >> operand2;

    char oper;
    std::cin >> oper;

    auto CalkAddition = [](int a, int b) {return a + b;};
    auto CalkSubtraction = [](int a, int b) {return a - b;};
    auto CalkMultiplication = [](int a, int b) {return a * b;};
    auto CalkDivision = [](int a, int b) {return 1.0 * a / b;};

    switch (oper)
    {
    case '+':
        std::cout << CalkAddition(operand1, operand2) << std::endl;
        break;

    case '-':
        std::cout << CalkSubtraction(operand1, operand2) << std::endl;
        break;

    case '*':
        std::cout << CalkMultiplication(operand1, operand2) << std::endl;
        break;

    case '/':
        std::cout << CalkDivision(operand1, operand2) << std::endl;
        break;
    default:
        std::cout << "error" << std::endl;
        break;
    }    
}

//Write a program that :
//•	Read two integer numbers from the first line of the console separated by single space
//•	Read symbol(one of the following : +, -, *, / ) from the second line of the console
//o	The operations are as follows :
// + is addition
// - is subtraction
// * is multiplication
// / is division
//•	Create four functions(for each operation) and call the right one depending on the command
//•	Print result from the calculation