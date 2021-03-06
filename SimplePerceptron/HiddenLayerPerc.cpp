#include "stdafx.h"
#include "HiddenLayerPerc.h"
#include <iostream>
#include <armadillo>

using namespace arma;

HiddenLayerPerc::HiddenLayerPerc(void)
{
}


HiddenLayerPerc::~HiddenLayerPerc(void)
{
}

mat sig(mat& z)
{
    z.transform([] (double val) {
        val = 1 / (1 + exp(-val));
        return val;
    });
    return z;
}

double fRand(double fMin, double fMax)
{
    double f = double(rand()) / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

mat sig_der(mat& output)
{
    output.transform([] (double val)
    {
        val = val * (1 - val);
        return val;
    });
    return output;
}

int run()
{

    srand(unsigned(time(nullptr)));

    bool isAnd = true;
    const int n = 2; //���������� ��������
    const int epoches = 100000;
    double lr = 1.0;

	mat samples({ 0.0, 0.0, 1.0,
				  1.0, 0.0, 1.0,
				  0.0, 1.0, 1.0,
				  1.0, 1.0, 1.0 });
	samples.set_size(4, 3);
    //Answers
	mat targets{ 0.0, 0.0, 0.0, 1.0 };

    mat w; 
	w.set_size(3,1);
    //Randomize
    w.transform([](double val)
    {
        return fRand(1.0, -1.0);
    });

    for(int i = 0; i < epoches; i++)
    {
        mat z = samples * w; //Summator
        auto outputs = sig(z);
        //Gradient Descend
        w -= (lr*((outputs - targets) % sig_der(outputs)).t() * (samples) / samples.size ()).t();

    }
    //Activate function
    mat a = samples * w;
    mat result = round(sig(a));

    cout << result;
    return 0;
}
