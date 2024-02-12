// 01 Center Point.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cmath>

void PrintClosest(double, double, double, double);
double DistanseFromStart(double, double);

int main()
{
    double x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

    PrintClosest(x1, y1, x2, y2);
}

void PrintClosest(double x1, double y1, double x2, double y2)
{
    double d1 = DistanseFromStart(x1, y1);
    double d2 = DistanseFromStart(x2, y2);

    std::string output = std::string();
    std::cout << "(";

    if (d1 > d2)
    {        
        x1 = x2;
        y1 = y2;
    }

    std::cout << x1 << ", " << y1;
    std::cout << ")" << std::endl;    
}

double DistanseFromStart(double x, double y)
{
    return std::sqrt(x * x + y * y);
}

//Write a program that :
//•	Read four floating - point numbers(coordinates of two points on a Cartesian coordinate system)
//o	From the first line – coordinate X of the first point
//o	From the second line – coordinate Y of the first point
//o	From the third line – coordinate X of the second point
//o	From the forth line – coordinate Y of the second point
//•	Create a method that prints coordinates of the given point that is closest to the center of the coordinate system(0, 0) in the format : (X, Y)
//Note : If the points are at the same distance from the center, print only the first point coordinates.