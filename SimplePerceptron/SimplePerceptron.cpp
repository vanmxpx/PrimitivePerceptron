// SimplePerceptron.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DigitsRecognazing.h"
#include "ErrorSpread.h"
#include "ErrorSpreadRec.h"
using namespace std;
DigitsRecognazing digneu;
ErrorSpread errspr;
ErrorSpreadRec er;

int _tmain(int argc, _TCHAR* argv[])
{
	//digneu.step();
	//errspr.run();
	er.learn();
	er.start();

	system("pause");
	return 0;
}
