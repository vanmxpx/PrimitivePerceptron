#pragma once

#include "stdafx.h"

using namespace std;
using namespace arma;

class DigitsRecognazing
{
public:
	DigitsRecognazing(void);
	~DigitsRecognazing(void);
	bool process(string);
	void learning();
	void print_res(bool);
	void step();
	void print_weights();
private:
	const int bias;
	const int epoches;
	vector<string> numbers;
	vector<string> fives;
	vector<int> weights;
};

