#pragma once
#include "stdafx.h"

using namespace std;
using namespace arma;

class Crack
{
public:
	Crack(int = 1000, int = 500, double = 0.000001, double = 0.000001);

	vec analize(vec number);
	void learn();
	bool save_weights() const;

private:	
	static double normalizeAnswer(double answer);
	double gradFunc(double answer);
	void fill_tests();

	mat ins;
	mat values;

	int epoches;
	double learn_rate;
	double alpha_mom;
	int neur_count;

	vec inputs;
	vec outputs1;
	vec outputs2;

	mat w1;
	mat w2;
	mat wout;
};

