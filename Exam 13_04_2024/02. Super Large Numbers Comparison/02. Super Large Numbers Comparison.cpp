// Super Large Numbers Comparison.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <climits>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <map>
#include <cmath>

std::vector<std::string> RetVec(std::string);

bool OnliZero(std::string s)
{
	bool result = true;

	for (size_t i = 0; i < s.length(); i++)
	{
		if (s[i] != 0)
		{
			return false;
		}
	}

	return result;
}

int main()
{
	std::string input;
	std::getline(std::cin, input);
	std::vector<std::string> v1 = RetVec(input);

	std::getline(std::cin, input);
	std::vector<std::string> v2 = RetVec(input);
	std::string output = std::string();



	for (size_t i = 0; i < std::min(v1.size(), v2.size()); i++)
	{
		std::string s1 = v1[i];
		std::string s2 = v2[i];

		bool isOnliZero1 = OnliZero(s1);
		bool isOnliZero2 = OnliZero(s2);


		if (isOnliZero1 && isOnliZero2)
		{
			output.append("=");
		}
		else if (isOnliZero1 && !isOnliZero2)
		{
			output.append(">");
		}
		else if (!isOnliZero1 && isOnliZero2)
		{
			output.append("<");
		}
		else if (s1.length() > s2.length())
		{
			output.append("<");
		}
		else if (s1.length() < s2.length())
		{
			output.append(">");
		}
		else
		{
			bool isEqual = true;

			for (size_t j = 0; j < s1.length() && isEqual; j++)
			{
				if (s1[j] > s2[j])
				{
					output.append("<");
					isEqual = false;
				}
				else if (s1[j] < s2[j])
				{
					output.append(">");
					isEqual = false;
				}
			}

			if (isEqual)
			{
				output.append("=");
			}
		}
	}

	if (v1.size() > v2.size())
	{
		for (size_t i = v2.size(); i < v1.size(); i++)
		{
			output.append("+");
		}
	}

	if (v1.size() < v2.size())
	{
		for (size_t i = v1.size(); i < v2.size(); i++)
		{
			output.append("-");
		}
	}


	std::cout << output << std::endl;
}

std::vector<std::string> RetVec(std::string input)
{
	bool isLoopExit = false;

	std::vector<std::string> result = std::vector<std::string>();
	int i = 0;
	std::string s = std::string();
	while (i < input.length() && !isLoopExit)
	{
		if (input[i] >= '0' && input[i] <= '9')
		{
			s.append(1, input[i]);
		}
		else if (s.length() > 0)
		{
			result.push_back(s);
			s = std::string();
		}
		else
		{
			s = std::string();
		}
		i++;
	}
	if (s.length() > 0)
	{
		result.push_back(s);
	}

	return result;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
