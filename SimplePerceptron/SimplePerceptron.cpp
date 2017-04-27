// SimplePerceptron.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DigitsRecognazing.h"
#include "ErrorSpread.h"

using namespace std;
DigitsRecognazing digneu;
ErrorSpread errspr;

int _tmain(int argc, _TCHAR* argv[])
{
	//digneu.step();
	errspr.run();
	return 0;
}
