#pragma once
#include "stdafx.h"

using namespace arma;

class HiddenLayerPerc
{
public:
	HiddenLayerPerc(void);
	~HiddenLayerPerc(void);
	int run();
private:
	mat sig(mat&);
	double fRand(double, double);
	mat sig_der(mat&);
};

