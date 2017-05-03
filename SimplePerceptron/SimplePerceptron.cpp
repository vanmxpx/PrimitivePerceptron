// SimplePerceptron.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DigitsRecognazing.h"
#include "ErrorSpread.h"
#include "XOR.h"
using namespace std;
DigitsRecognazing digneu;
ErrorSpread errspr;
XOR xor;

int _tmain(int argc, _TCHAR* argv[])
{
	//digneu.step();
	//errspr.run();
	xor.learn();

	system("pause");
	return 0;
}
