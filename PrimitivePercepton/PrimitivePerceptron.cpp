// PrimitivePercepton.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <armadillo>

using namespace std;

const int bias = 7;
const int epoches = 100000;
vector<string> numbers;
vector<string> fives;
vector<int> weights(15, 0);

bool process(string number)
{
	int sum = 0;
	for(int i = 0; i < 15; i++)
		sum += int(number[i])*weights[i];
	return sum > bias;
}

void learning()
{
	for(int i = 0; i < epoches; i++)
	{
		int num = rand() % 10;
		string diget = numbers[num];
		bool answer = process(diget);

		if(num != 5 && answer)
		{
			for(int k = 0; k < 15; k++)
				if(diget[k] == '1')
					weights[k] -= 1;
		}

		else if(num == 5 && !answer)
		{
			for(int k = 0; k < 15; k++)
				if(diget[k] == '1')
					weights[k] += 1;
		}
	}
}

void print_res(bool answer)
{
	if(answer)
		cout << "True" << endl;
	else
		cout << "False" << endl;
}

void print_weights()
{
	for(int i = 0; i < 15; i++)
	{
		cout << weights[i] << " ";
		if((i + 1) % 3 == 0)
			cout << endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(0));

	numbers.push_back("111101101101111");
	numbers.push_back("001001001001001");
	numbers.push_back("111001111100111");
	numbers.push_back("111001111001111");
	numbers.push_back("101101111001001");
	numbers.push_back("111100111001111");
	numbers.push_back("111100111101111");
	numbers.push_back("111001001001001");
	numbers.push_back("111101111101111");
	numbers.push_back("111101111001111");

	fives.push_back("111100111000111");
	fives.push_back("111100010001111");
	fives.push_back("111100011001111");
	fives.push_back("110100111001111");
	fives.push_back("110100111001011");
	fives.push_back("111100101001111");

	 learning();

	//Test
	for(int i = 0; i < 10; i++)
	{
		cout << "Is number["<< i <<"] == 5?"<< "  ";
		print_res(process(numbers[i]));
	}
	//Control
	for(int i = 0; i < 6; i++)
	{
		cout << "Is fives["<< i <<"] == 5?"<< "  ";
		print_res(process(fives[i]));
	}
	print_weights();

	system("pause");
	return 0;
}


