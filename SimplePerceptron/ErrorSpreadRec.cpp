#include "stdafx.h"
#include "ErrorSpreadRec.h"
#include <math.h>

using namespace arma;

ErrorSpreadRec::ErrorSpreadRec()
	: outputs(15, 2, fill::zeros), w(15, 15, fill::randu), wout(15, 1, fill::randu ),
	epoches(10000), learn_rate(0.7), alpha_mom(0.00009)
{
	numbers = { { 1,0,1,1,1,1,1,1,1,1 },
	{ 1,0,1,1,0,1,1,1,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,0,0,1,1,1,0,1,1 },
	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 1,1,1,1,1,0,0,1,1,1 },
	{ 1,0,1,1,1,1,1,0,1,1 },
	{ 0,0,1,1,1,1,1,0,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,1,0,0,0,1,0,1,0 },
	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 1,1,0,1,1,1,1,1,1,1 },
	{ 1,0,1,1,0,1,1,0,1,1 },
	{ 1,0,1,1,0,1,1,0,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1 } };

	fives = { { 1,1,1,1,1,1 },
	{ 1,1,1,1,1,1 },
	{ 1,1,1,0,0,1 },
	{ 1,1,1,1,1,1 },
	{ 0,0,0,0,0,0 },
	{ 0,0,0,0,0,0 },
	{ 1,0,0,1,1,1 },
	{ 1,1,1,1,1,0 },
	{ 1,0,1,1,1,1 },
	{ 0,0,0,0,0,0 },
	{ 0,0,0,0,0,0 },
	{ 0,1,1,1,1,1 },
	{ 1,1,1,1,0,1 },
	{ 1,1,1,1,1,1 },
	{ 1,1,1,1,1,1 } };
}

double ErrorSpreadRec::analize(vec number)
{
	outputs.col(0) = number;
	double tmp;
	for (int row = 0; row < 15; row++)
	{
		//inputs sinapses
		tmp = 0;
		for (int col = 0; col < 15; col++)
			tmp += outputs.at(col, 0) * w.at(col, row);
		outputs.at(row, 1) = normalizeAnswer(tmp);
	}
	//cout << outputs;
	//hidden sinapses
	tmp = 0;
	for (int row = 0; row < 15; row++)
		tmp += outputs.at(row, 1) * wout.at(row);

	return normalizeAnswer(tmp);
}

void ErrorSpreadRec::start()
{
	//Test
	for (int i = 0; i < 10; i++)
	{
		cout << "Is number[" << i << "] == 5?" << "  ";

		double res = analize(numbers.col(i));
		double answ = i == 5;
		double err = pow(answ - res, 2);
		cout << res << " result" << endl;
		cout << err << " error" << endl;
	}
	//Control
	for (int i = 0; i < 6; i++)
	{
		cout << "Is fives[" << i << "] == 5?" << "  ";
		double res = analize(fives.col(i));
		double err = pow(1 - res, 2);
		cout << res << " result" << endl;
		cout << err << " error" << endl;
	}
	system("pause");
}

double ErrorSpreadRec::normalizeAnswer(double answer) const
{
	return 1 / (1 + exp(-answer));
}
double ErrorSpreadRec::gradFunc(double answer)
{
	return(1 - answer)*answer;
}

void ErrorSpreadRec::learn()
{
	mat delta(15, 2);
	mat grad(15, 15);
	vec gradout(15);
	mat wlast(15, 15, fill::zeros);
	mat woutlast(15, 1, fill::zeros);

	double err = 1;
	double res = 0;
	for (int i = 0; i < epoches ; i++) //&& err != 0
	{
		for (int k = 0; k < 10; k++)
		{
			delta.fill(fill::zeros);
			grad.fill(fill::zeros);
			gradout.fill(fill::zeros);
			//analize
			res = analize(numbers.col(k));

			double isFive = k == 5;
			err = pow(isFive - res, 2);
			//
#ifndef DEBUG
			cout << err << endl;
#endif
			//Error spread
			//Calc errors
			double deltamain = (isFive - res)*gradFunc(res);//OUT

			for (int row = 0; row < 15; row++) //only one weidht binding
				delta.at(row, 1) = gradFunc(outputs.at(row, 1)) * wout.at(row) * deltamain;

			//for (int col = 0; col < 15; col++) //for input neirons
			//{
			//	delta.at(col, 0) = gradFunc(tmp);
			//	for (int row = 0; row < 15; row++)
			//		delta.at(col, 0) += w.at(row, col) * delta.at(col, 1);
			//}

			//Calc grad

			for (int row = 0; row < 15; row++)
			{
				gradout.at(row) = outputs.at(row, 1) * deltamain;

				wout.at(row) += learn_rate * gradout.at(row) + alpha_mom * woutlast.at(row);
				for (int col = 0; col < 15; col++)
				{
					
					grad.at(row, col) = outputs.at(row, 0) * delta.at(col, 1);
					double tmp1 = learn_rate * grad.at(row, col);
					double tmp2 = alpha_mom * wlast.at(row, col);
					w.at(row, col) += tmp1 + tmp2;
				}
			}

			wlast = w;
			woutlast = wout;
		}
	}
}

