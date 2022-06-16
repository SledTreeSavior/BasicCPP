#include "FibLFSR.hpp"
#include <iostream>
#include <string>
#include <iostream>
using namespace std;

FibLFSR::FibLFSR(string seed)
{
	length = seed.size();
	data = std::vector<short>(length);
	for (char i: seed)
	{
		data.at(length - 1) = i - '0';
		length--;
	}
}

int FibLFSR::step()
{
	short xorResult;

	xorResult = (data.at(15) ^ data.at(13) ^ data.at(12) ^ data.at(10));

	data.insert(data.begin(), xorResult);
	data.pop_back();
	return xorResult;
}

int FibLFSR::generate(int k)
{
	int temp = 0;

	for (int i = 0; i < k; i++)
	{
		temp = temp << 1;
	        temp |=	step();
	}

	return temp;
}

ostream& operator<<(std::ostream& out, const FibLFSR& right)
{
	string output = "";

	for (int i = right.data.size() - 1; i >= 0; i--)
	{
		out << right.data.at(i);
	}
	return out;
}
