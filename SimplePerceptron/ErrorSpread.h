#pragma once

#include "stdafx.h"
using namespace arma;

class ErrorSpread
{
public:
	ErrorSpread(void);
	~ErrorSpread(void);
	void run();
	double process(double) const;
	void learning();
private:
	static double fRand(double, double);
	const int epoches;
	double k;
	double c;
	mat data;
	double lrnrate;
};

