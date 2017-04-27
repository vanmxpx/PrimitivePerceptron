#include "stdafx.h"
#include "ErrorSpread.h"
#include <iostream>

using namespace std;
using namespace arma;
ErrorSpread::ErrorSpread(void)
	:epoches(100000), k(fRand(-5, 5)), c(fRand(-5, 5)), lrnrate(0.01)
{
	srand(unsigned(time(nullptr)));

	data << 1	<< 2	<< endr
		 << 2   << 4.2  << endr
		 << 2.5 << 5    << endr
		 << 3.8 << 7.9  << endr
		 << 4   << 9    << endr
	 	 << 6   << 10.2 << endr
	 	 << 6.6 << 13   << endr
		 << 7.2 << 15.3 << endr
		 << 8   << 17.1 << endr
		 << 8.5 << 19.5 << endr;
}
ErrorSpread::~ErrorSpread(void)
{
}

void ErrorSpread::run()
{
	cout << "Started line: "<< k <<"* X + " << c << endl;
	learning();
	cout << "Ended line: "<< k <<"* X + " << c << endl;
	system("pause");
}

double ErrorSpread::process(double x) const
{
	return k*x + c;
}

void ErrorSpread::learning()
{
	for(int i = 0; i < epoches; i++)
	{
		int nrund = rand() % 10;

		double tresx = data.at(nrund, 0);
		double tresy = data.at(nrund, 1);

		auto out = process(tresx);

		auto delta = tresy - out; //web error

		k += delta*lrnrate*tresx; // delta rule
		c += delta*lrnrate;
	}
}

double ErrorSpread::fRand(double fMin, double fMax)
{
    double f = double(rand()) / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

