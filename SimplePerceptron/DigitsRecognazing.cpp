#include "stdafx.h"
#include "DigitsRecognazing.h"

using namespace std;

DigitsRecognazing::DigitsRecognazing()
	:bias(7), epoches(100000)
{
	srand(unsigned(time(nullptr)));
	weights.set_size(15, 3);
	weights.transform([](double val)
	{
		return rand() % 5;
	});

	numbers = { "111101101101111",
				"001001001001001",
				"111001111100111",
				"111001111001111",
				"101101111001001",
				"111100111001111",
				"111100111101111",
				"111001001001001",
				"111101111101111",
				"111101111001111" };

	fives = { "111100111000111",
			  "111100010001111",
			  "111100011001111",
		  	  "110100111001111",
			  "110100111001011",
			  "111100101001111" };
}


DigitsRecognazing::~DigitsRecognazing()
{

}


void DigitsRecognazing::step()
{
	learning();
	print_weights();

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


	system("pause");
}

bool DigitsRecognazing::process(string number)
{
	int sum = 0;
	for (int i = 0; i < 15; i++)
	{
		int x = number[i] - '0';
		int y = weights[i];
		sum += x*y;
	}
	return sum > bias;
}

void DigitsRecognazing::learning()
{
	for(int i = 0; i < epoches; i++)
	{
		for (int num = 0; num < 10; num++)
		{
			string diget = numbers[num];
			bool answer = process(diget);

			if (num != 5 && answer)
			{
				for (int k = 0; k < 15; k++)
					if (diget[k] == '1')
						weights[k] -= 1;
			}
			else if (num == 5 && !answer)
			{
				for (int k = 0; k < 15; k++)
					if (diget[k] == '1')
						weights[k] += 1;
			}
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
