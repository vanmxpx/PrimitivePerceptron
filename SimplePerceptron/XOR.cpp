#include "stdafx.h"
#include "XOR.h"
#include <math.h>

using namespace arma;

XOR::XOR()
	: w({ 0.45, 0.78, -0.12, 0.13, 1.5, -2.3 }), wlast(5, fill::zeros),
		inputs({ {1, 0}, {0, 0}, {0, 1}, {1, 1} }), 
		globalError(0), learn_rate(0.3), alpha_mom(0.7)

{
}


XOR::~XOR()
{
}

void XOR::calcGlobalError()
{
	globalError = 0;
	for (auto &error : errors)
		globalError += error * error;

	globalError /= errors.size();
}

double XOR::normalizeAnswer(double answer) const
{
	return 1 / (1 + exp(-answer));
}
double XOR::gradFunc(double answer)
{
	return(1-answer)*answer;
}
vec delta(5);
vec Gradw(5);

void XOR::learn()
{
	double err = 1;
	double res = 0;
	for (int i = 0; i < epoches && err > 0.001; i++) 
	{
		double h1 = normalizeAnswer(inputs.at(0, 0)*w[0] + inputs.at(0, 1)*w[2]);
		double h2 = normalizeAnswer(inputs.at(0, 0)*w[1] + inputs.at(0, 1)*w[3]);

		double last_in = h1*w[4] + h2*w[5];
		res = normalizeAnswer(last_in);
		err = pow(1 - res, 2);

		delta[0] = (1 - res)*gradFunc(res);
		delta[1] = gradFunc(h1) * w[4] * delta[0];
		Gradw[4] = delta[0] * h1;
		delta[2] = gradFunc(h2) * w[5] * delta[0];
		Gradw[5] = delta[0] * h2;

		delta[3] = gradFunc(inputs.at(0, 0)) * (w[0] * delta[1] + w[1] * delta[2]);
		Gradw[0] = delta[1] * inputs.at(0, 0);
		Gradw[1] = delta[2] * inputs.at(0, 0);
		delta[4] = gradFunc(inputs.at(0, 1)) * (w[2] * delta[1] + w[3] * delta[2]);
		Gradw[2] = delta[1] * inputs.at(0, 1);
		Gradw[3] = delta[2] * inputs.at(0, 1);

		vec tmp(w);
		for (int i = 0; i < 5; i++)
		{
			w[i] += learn_rate * Gradw[i] + alpha_mom * wlast[i];
		}
		wlast = w;
		cout << err << endl;
	}

	cout << w << endl << endl;
	cout << res << endl;
}