#pragma once
#include "Neuron.h"

class NeuralNetwork
{
public:

	/*Создание подвида нейрона: входной нейрон, который только
	передает входной сигнал дальше*/
	class InputNeuron : public Neuron {
	public:

		float kernelFunction() override
		{
			return value;
		}

	};

	NeuralNetwork();
	std::vector<Neuron*> inNeurons;
	std::vector<Neuron> outNeurons;
//	int handle(QImage);
//
//private:
//	/*Функция обучения нейрона*/
//	void study(Neuron &n, QImage pic);
//
//	/*Картинки с цифрами для обучения*/
//	QString names[9] = { "0.bmp", "1.bmp", "2.bmp", "3.bmp","4.bmp","5.bmp","6.bmp","7.bmp", "8.bmp" };
//	const uint numNumbers = 9;
};

