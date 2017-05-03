#pragma once

using namespace std;
using namespace arma;

class XOR
{
public:
	XOR();
	~XOR();

	void learn();
private:
	void calcGlobalError();
	double normalizeAnswer(double) const;
	static double gradFunc(double answer);
	vec w;
	vector<double> errors;
	vec wlast;

	mat inputs;
	const double epoches = 10000;
	double globalError;
	double learn_rate;
	int alpha_mom;
};
