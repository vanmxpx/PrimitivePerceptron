#include "stdafx.h"
#include "DigitsRecognazing.h"

using namespace std;

DigitsRecognazing::DigitsRecognazing(void)
	:bias(7), epoches(10000), weights(15,0)
{
	srand(time(NULL));
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
}


DigitsRecognazing::~DigitsRecognazing(void)
{

}


void DigitsRecognazing::step()
{
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
	step();
}

bool DigitsRecognazing::process(string number)
{
	int sum = 0;
	for(int i = 0; i < 15; i++)
		sum += int(number[i])*weights[i];
	return sum > bias;
}

void DigitsRecognazing::learning()
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

void DigitsRecognazing::print_res(bool answer)
{
	if(answer)
		cout << "True" << endl;
	else
		cout << "False" << endl;
}

void DigitsRecognazing::print_weights()
{
	for(int i = 0; i < 15; i++)
	{
		cout << weights[i] << " ";
		if((i + 1) % 3 == 0)
			cout << endl;
	}
}
