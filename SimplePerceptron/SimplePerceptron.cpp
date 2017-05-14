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
	//er.learn();
	//er.load_weights();
	//er.start_test();

	digneu.learn();
	//digneu.load_weights();
	digneu.start_test();

	char at;
	cout << "Want to save weights? y/n" << endl;
	cin >> at;
	if (at == 'y') {
		digneu.save_weights();
		//er.save_weights();
	}
	system("pause");
	return 0;
}
