#pragma once

using namespace std;
using namespace arma;

class ErrorSpreadRec
{
public:
	ErrorSpreadRec();

	double analize(vec number);

	void start();

	void learn();
private:
	double normalizeAnswer(double) const;
	static double gradFunc(double answer);
	mat outputs;
	mat w;
	mat wout;

	const double epoches;
	double learn_rate;
	double alpha_mom;
	mat numbers;
	mat fives;
};
