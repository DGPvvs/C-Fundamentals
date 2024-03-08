// 06 Equal Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

int main()
{
    int n;
    std::cin >> n;

    int* arr1 = new int[n];
    int* arr2 = new int[n];
        
    for (int i = 0; i < n; ++i)
    {
        int inputNum;
        std::cin >> inputNum;
        arr1[i] = inputNum;
    }

    for (int i = 0; i < n; ++i)
    {
        int inputNum;
        std::cin >> inputNum;
        arr2[i] = inputNum;
    }

    int index = 0, sum = 0;
    bool isEqual = true;

    label:if (index < n && isEqual)
    {
        sum += arr1[index];
        isEqual = arr1[index] == arr2[index++];
        goto label;
    }

    std::string output = std::string();

    if (isEqual)
    {
        output.append("Arrays are identical. Sum: ")
              .append(std::to_string(sum));        
    }
    else
    {
        output.append("Arrays are not identical. Found difference at ")
              .append(std::to_string(--index))
              .append(" index.");
    }

    std::cout << output << std::endl;

    delete[] arr1;
    delete[] arr2;
}

//Write a program that :
//•	Read an integer number(< 100), which represents size of the arrays, from the first line of the console
//	•	Read two integer arrays from the next two lines of the console
	/*•	Arrays are identical if their elements are equal
	•	Print on the console whether they are identical or not*/
	/*•	If the arrays are identical, find the sum of the first one and print on the console the following message :*/
//"Arrays are identical. Sum: {sum}"
//•	Otherwise find the first index where the arrays differ and print on the console following message :
//"Arrays are not identical. Found difference at {index} index."