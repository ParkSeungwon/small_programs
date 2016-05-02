#pragma once
#include <vector>

class BoolArray
{
public:
	bool operator[](int x);

private:
	std::vector<bool> bs;

};



