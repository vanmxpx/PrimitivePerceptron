#pragma once

using namespace std;
using namespace arma;

class ErrorSpreadRec
{
public:
	ErrorSpreadRec();

	double analize(vec number);
	void learn();

	void start_test();
	bool load_weights();
	bool save_weights() const;
private:
	double normalizeAnswer(double) const;
	static double gradFunc(double answer);
	mat outputs;
	mat w;
	vec wout;

	const double epoches;
	double learn_rate;
	double alpha_mom;
	mat numbers;
	mat fives;
};
