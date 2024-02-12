// 03 Quadratic Equation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a, b, c;
    cin >> a >> b >> c;

    double discriminant = b * b - 4 * a * c;
    double root1 = discriminant >= 0 ? (- b + sqrt(discriminant)) / (2 * a) : .0;
    double root2 = discriminant > 0 ? (- b - sqrt(discriminant)) / (2 * a) : .0;

    string output = string();

    if (discriminant < 0)
    {
        cout << "no roots" << endl;
    }
    else if (discriminant == 0)
    {
        cout << root1 << endl;
    }
    else
    {
        cout << root1 << " " << root2 << endl;
    }
}

//Write a program that enters the coefficients a, b, and c of a quadratic equation a* x2 + b * x + c = 0 and calculates and prints its real solutions.Note that quadratic equations may have 0, 1, or 2 real solutions.
//You can check your program against this: https://www.mathsisfun.com/quadratic-equation-solver.html
//The numbers a, b, and c will be entered on a single line from the console, separated by spaces.
//•	If the quadratic equation has no real roots(e.g. if the Discriminant is less than 0), print "no roots".
//•	If it has one real root print it.
//•	If it has two roots, print them on a single line, separated by a single space.
//On the first place, print the root calculated by formula(-b + sqrt(D)) / 2
//În the second place, print the root calculated by the formula(-b - sqrt(D)) / 2