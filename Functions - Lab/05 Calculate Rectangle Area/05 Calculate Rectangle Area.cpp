// 05 Calculate Rectangle Area.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    auto Area = [](int a, int b) -> int {return a * b;};

    int length, width;
    std::cin >> length >> width;

    std::cout << Area(length, width) << std::endl;
}

// Create a function that calculates and returns the area of a rectangle by given width and height.
