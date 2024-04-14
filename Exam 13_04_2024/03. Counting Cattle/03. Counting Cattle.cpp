// Counting Cattle.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

class myString :public std::string
{
private:
	const std::string EMPTY = "";
	const std::string NEW_LINE = "\r\n";

public:
	myString(const char* s) :std::string(s)
	{

	}

	myString() :std::string()
	{

	}

	std::string Empty()
	{
		return this->EMPTY;
	}
	std::string NewLine()
	{
		return this->NEW_LINE;
	}

	std::string Join(char separator, std::queue<int>* q)
	{
		std::string result = std::string();

		std::queue<int> temp = std::queue<int>();

		bool isFirst = true;

		while (q->size() > 0)
		{
			int currentNum = q->front();
			q->pop();
			temp.push(currentNum);

			if (isFirst)
			{
				isFirst = false;
			}
			else
			{
				result.append(1, separator);
			}

			result.append(std::to_string(currentNum));
		}

		while (temp.size() > 0)
		{
			int currentNum = temp.front();
			temp.pop();
			q->push(currentNum);
		}

		return result;
	}

	std::string Join(std::string separator, std::vector<int>* v)
	{
		std::string result = std::string();
		bool isFirst = true;

		for (std::vector<int>::iterator it = v->begin(); it != v->end(); it++)
		{
			std::string s = std::to_string(*it);

			if (isFirst)
			{
				isFirst = false;
			}
			else
			{
				result.append(separator);
			}

			result.append(s);
		}

		return result;
	}

	std::queue<int> ConvertStringToIntQueue()
	{
		std::stringstream iss(*this);

		int number;

		std::queue<int> result = std::queue<int>();
		while (iss >> number)
		{
			result.push(number);
		}

		return result;
	}

	std::queue<std::string> ConvertStringToStringQueue()
	{
		std::stringstream iss(*this);

		std::string s;

		std::queue<std::string> result = std::queue<std::string>();
		while (iss >> s)
		{
			result.push(s);
		}

		return result;
	}

	std::stack<std::string> ConvertStringToStringStack()
	{
		std::stringstream iss(*this);

		std::string s;

		std::stack<std::string> result = std::stack<std::string>();
		while (iss >> s)
		{
			result.push(s);
		}

		return result;
	}

	std::stack<int> ConvertStringToIntStack()
	{
		std::stringstream iss(*this);

		int number;

		std::stack<int> result = std::stack<int>();
		while (iss >> number)
		{
			result.push(number);
		}

		return result;
	}

	std::vector<double> ConvertStringToDoubleVector()
	{
		std::stringstream iss(*this);

		double number;
		std::vector<double> result = std::vector<double>();
		while (iss >> number)
		{
			result.push_back(number);
		}

		return result;
	}

	std::vector<int> ConvertStringToIntVector()
	{
		std::stringstream iss(*this);

		int number;
		std::vector<int> result = std::vector<int>();
		while (iss >> number)
		{
			result.push_back(number);
		}

		return result;
	}

	bool TryParseInt(int& num)
	{
		try
		{
			num = stoi(*this);
		}
		catch (...)
		{
			return false;
		}

		return true;
	}

	bool TryParseDouble(double& num)
	{
		try
		{
			num = stod(*this);
		}
		catch (...)
		{
			return false;
		}

		return true;
	}

	std::vector<std::string> Split(char ch)
	{
		std::vector<std::string> result;
		std::string s = this->EMPTY;

		std::stringstream ss(*this);

		while (getline(ss, s, ch))
		{
			result.push_back(s);
		}

		return result;
	}

	std::vector<std::string> Split(std::string separator)
	{
		const std::string REPLACE_STRING_SEPARATOR = "\n";
		const char REPLACE_CHAR_SEPARATOR = REPLACE_STRING_SEPARATOR[0];

		std::vector<std::string> result;
		std::string s = std::string(*this);

		int idx = s.find(separator);

		while (idx > -1)
		{
			s.replace(idx, separator.length(), REPLACE_STRING_SEPARATOR);
			idx = s.find(separator);
		}

		std::stringstream ss(s);

		while (getline(ss, s, REPLACE_CHAR_SEPARATOR))
		{
			result.push_back(s);
		}

		return result;
	}

	bool Contains(std::string f)
	{
		int idx = this->find(f);
		return idx > -1;
	}

	bool Contains(char ch)
	{
		std::string s = std::string(1, ch);
		return this->Contains(s);
	}

	std::string ToLower()
	{
		std::string s = std::string("");

		std::string::iterator it;
		for (it = this->begin(); it != this->end(); it++)
		{
			s.append(1, tolower(*it));
		}

		return s;
	}

	std::string ToUpper()
	{
		std::string s = std::string("");

		std::string::iterator it;
		for (it = this->begin(); it != this->end(); it++)
		{
			s.append(1, toupper(*it));
		}

		return s;
	}

	~myString()
	{

	}
};




std::string FormatDoubleNum(double number, int precision);

std::string AvrStr(std::vector<int> v);

std::string ToList(std::string separator, std::string C, std::vector<int>* v);

std::string ToList1(std::string separator, std::vector<char>* c, std::vector<int>* v);

int main()
{
	std::map<char, std::vector<int>> list = std::map<char, std::vector<int>>();

	list['C'] = std::vector<int>();
	list['S'] = std::vector<int>();
	list['O'] = std::vector<int>();

	myString input;
	std::getline(std::cin, input);

	std::vector<std::string> cls = input.Split(" ");
	std::vector<char> oth = std::vector<char>();

	for (auto cl : cls)
	{
		int siz = cl[1] - '0';
		if (cl[0] == 'C')
		{
			list['C'].push_back(siz);
		}
		else if (cl[0] == 'S')
		{
			list['S'].push_back(siz);
		}
		else
		{
			list['O'].push_back(siz);
			oth.push_back(cl[0]);
		}
	}

	std::string output = std::string();

	if (list['C'].size() > 0)
	{
		output.append(std::to_string(list['C'].size()))
			.append(" cows: ")
			.append(ToList(" ", "C", &list['C']))
			.append(" with avg. size ")
			.append(AvrStr(list['C']))
			.append(myString().NewLine());
	}
	else
	{
		output.append("no cows!").append(myString().NewLine());
	}

	if (list['S'].size() > 0)
	{
		output.append(std::to_string(list['S'].size()))
			.append(" sheep: ")
			.append(ToList(" ", "S", &list['S']))
			.append(" with avg. size ")
			.append(AvrStr(list['S']))
			.append(myString().NewLine());
	}
	else
	{
		output.append("no sheep!").append(myString().NewLine());
	}

	if (list['O'].size() > 0)
	{
		output.append(std::to_string(list['O'].size()))
			.append(" others: ")
			.append(ToList1(" ", &oth, &list['O']))
			.append(" with avg. size ")
			.append(AvrStr(list['O']))
			.append(myString().NewLine());
	}
	else
	{
		output.append("no others!").append(myString().NewLine());
	}

	std::cout << output;
}

std::string FormatDoubleNum(double number, int precision)
{
	std::stringstream stream;

	stream.precision(precision);
	stream << std::fixed;

	stream << number;

	return stream.str();
}

std::string AvrStr(std::vector<int> v)
{
	int sumN = 0;

	for (auto i : v)
	{
		sumN += i;
	}


	return FormatDoubleNum(1.0 * sumN / v.size(), 2);
}

std::string ToList(std::string separator, std::string C, std::vector<int>* v)
{
	std::string result = std::string();
	bool isFirst = true;

	for (std::vector<int>::iterator it = v->begin(); it != v->end(); it++)
	{
		std::string s = C + std::to_string(*it);

		if (isFirst)
		{
			isFirst = false;
		}
		else
		{
			result.append(separator);
		}

		result.append(s);
	}

	return result;
}

std::string ToList1(std::string separator, std::vector<char>* c, std::vector<int>* v)
{
	std::string result = std::string();
	bool isFirst = true;

	for (size_t i = 0; i < v->size(); i++)
	{
		int d = *(v->begin() + i);
		std::string s = std::string();
		s.append(*(c->begin() + i) + std::to_string(d));

		if (isFirst)
		{
			isFirst = false;
		}
		else
		{
			result.append(separator);
		}

		result.append(s);

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
