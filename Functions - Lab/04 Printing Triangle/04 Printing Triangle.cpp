// 04 Printing Triangle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void ConstructTriangle(int, int);
void PrintRow(int);

int main()
{
    int n;
    cin >> n;

    ConstructTriangle(1, n);

    return 0;
}

void ConstructTriangle(int n, int base)
{
    if (n > base)
    {
        return;
    }

    PrintRow(n);

    ConstructTriangle(n + 1, base);

    PrintRow(n - 1);
}

void PrintRow(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
    }

    cout << endl;
}

//Create a function for printing triangle as shown in the examples below.
//Examples
//Input	Output
//3	1
//1 2
//1 2 3
//1 2
//1
//4	1
//1 2
//1 2 3
//1 2 3 4
//1 2 3
//1 2
//1