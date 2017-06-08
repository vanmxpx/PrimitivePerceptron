// SimplePerceptron.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DigitsRecognazing.h"
#include "ErrorSpread.h"
#include "ErrorSpreadRec.h"
#include "Crack.h"
using namespace std;
DigitsRecognazing digneu;
ErrorSpread errspr;
ErrorSpreadRec er;
Crack cr;

int _tmain(int argc, _TCHAR* argv[])
{
	//er.learn();
	//er.load_weights();
	//er.start_test();

	//digneu.learn();
	//digneu.load_weights();
	//digneu.start_test();
	cr.learn();
	char at;
	cout << "Want to save weights? y/n" << endl;
	cin >> at;
	if (at == 'y') {
		cr.save_weights();
		//digneu.save_weights();
		//er.save_weights();
	}
	system("pause");
	return 0;
}
