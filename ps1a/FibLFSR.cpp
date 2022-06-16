#include "FibLFSR.hpp"
#include <iostream>
#include <string>
#include <iostream>
using namespace std;

FibLFSR::FibLFSR(string seed)
{
	length = seed.size();
	data = seed;	
}

int FibLFSR::step()
{
	int xorResult;
	int i, j;
	string temp = data;

	xorResult = (data[0] - '0') ^ (data[2] - '0') ^ (data[3] - '0') ^ (data[5] - '0');

	for (i = 0, j = 1; j < length; i++, j++)
	{
		temp[i] = data[j];
	}

	temp.push_back(xorResult + '0');
	data = temp;
	return xorResult;
}

int FibLFSR::generate(int k)
{
	int temp = 0;

	for (int i = 0; i < k; i++)
	{
		temp = (2 * temp) + step();
	}

	return temp;
}

ostream& operator<<(std::ostream& out, const FibLFSR& right)
{
	return out << right.data;	
}
