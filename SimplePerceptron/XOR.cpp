#include "stdafx.h"
#include "XOR.h"
#include <math.h>

using namespace arma;

XOR::XOR()
	: outputs(15,2), wlast(15, 2, fill::zeros),
		globalError(0), learn_rate(0.3), alpha_mom(0.7)
{
	srand(time(nullptr));
	for (int i = 0; i < 15; i++) 
		for (int j = 0; j < 2; j++) 
			for (int k = 0; k < 15; k++) 
				w[i][j][k] = fRand(0,1);

	numbers = { "111101101101111",
				"001001001001001",
				"111001111100111",
				"111001111001111",
				"101101111001001",
				"111100111001111",
				"111100111101111",
				"111001001001001",
				"111101111101111",
				"111101111001111" },

	fives = { "111100111000111",
				"111100010001111",
				"111100011001111",
				"110100111001111",
				"110100111001011",
				"111100101001111" };

}

void XOR::calcGlobalError()
{
	globalError = 0;
	for (auto &error : errors)
		globalError += error * error;

	globalError /= errors.size();
}

void XOR::processDigit(string number)
{
	int sum = 0;
	for (int i = 0; i < 15; i++)
		outputs[i, 0] = number[i] - '0';

}

double XOR::normalizeAnswer(double answer) const
{
	return 1 / (1 + exp(-answer));
}
double XOR::gradFunc(double answer)
{
	return(1-answer)*answer;
}
double XOR::fRand(double fMin, double fMax)
{
	double f = double(rand()) / RAND_MAX;
	return fMin + f * (fMax - fMin);
}
vec delta(5);
vec Gradw(5);

void XOR::learn()
{
	double err = 1;
	double res = 0;
	for (int i = 0; i < epoches && err > 0.001; i++) 
	{
		for (int k = 0; i < 10; k++)
		{
			processDigit(numbers[i]);
			double tmp = 0;
			for (int row = 0; row < 15; row++)
			{
				for (int row2 = 0; row2 < 15; row2++)
					tmp += outputs[row, 0] * w[row][0][row2];
				outputs[row, 1] = normalizeAnswer(tmp);
			}

			tmp = 0;
			for (int row = 0; row < 15; row++)
			{
				tmp += outputs[row, 1] * w[row][1][row];
			}
			res = normalizeAnswer(tmp);
			err = pow(1 - res, 2);
		}
	}

		//double h1 = normalizeAnswer(inputs.at(0, 0)*w[0] + inputs.at(0, 1)*w[2]);
		//double h2 = normalizeAnswer(inputs.at(0, 0)*w[1] + inputs.at(0, 1)*w[3]);

		//double last_in = h1*w[4] + h2*w[5];
		//res = normalizeAnswer(last_in);
		//err = pow(1 - res, 2);

		//delta[0] = (1 - res)*gradFunc(res);
		//delta[1] = gradFunc(h1) * w[4] * delta[0];
		//Gradw[4] = delta[0] * h1;
		//delta[2] = gradFunc(h2) * w[5] * delta[0];
		//Gradw[5] = delta[0] * h2;

		//delta[3] = gradFunc(inputs.at(0, 0)) * (w[0] * delta[1] + w[1] * delta[2]);
		//Gradw[0] = delta[1] * inputs.at(0, 0);
		//Gradw[1] = delta[2] * inputs.at(0, 0);
		//delta[4] = gradFunc(inputs.at(0, 1)) * (w[2] * delta[1] + w[3] * delta[2]);
		//Gradw[2] = delta[1] * inputs.at(0, 1);
		//Gradw[3] = delta[2] * inputs.at(0, 1);

		//vec tmp(w);
		//for (int i = 0; i < 5; i++)
		//{
		//	w[i] += learn_rate * Gradw[i] + alpha_mom * wlast[i];
		//}
		//wlast = w;
		//cout << err << endl;

		cout << w << endl << endl;
		cout << res << endl;
	}

