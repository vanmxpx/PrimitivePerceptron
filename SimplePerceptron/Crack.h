#pragma once

using namespace std;
using namespace arma;

class Crack
{
public: 
	Crack(int = 50, int = 3000, double = 0.1, double = 0.00000);

	vec analize(vec number);
	void test();
	void learn();
	bool save_weights() const;

private:	
	static double normalizeAnswer(double answer);
	double gradFunc(double answer);
	double normalaizeInput(double answer);
	void fill_tests();

	mat ins;
	mat instest;
	vec valuesP;
	mat valuesCrack;

	int epoches;
	double learn_rate;
	double alpha_mom;
	int neur_count;
	int result_count;

	vec inputs;
	vec outputs1;
	vec outputs2;

	mat w1;
	mat w2;
	mat wout;

};

