#pragma once

using namespace std;
using namespace arma;

class XOR
{
public:
	XOR();

	void learn();
private:
	void calcGlobalError();
	void processDigit(string number);
	double normalizeAnswer(double) const;
	static double gradFunc(double answer);
	static double fRand(double fMin, double fMax);
	double w[15][2][15];
	mat outputs;
	mat wlast;

	const double epoches = 10000;
	double globalError;
	double learn_rate;
	int alpha_mom;
	vector<string> numbers;
	vector<string> fives;
	vector<double> errors;
};
