#include "stdafx.h"
#include "Neuron.h"
#include <cmath>

/*В качестве функции активации используется т.н. сигма-функция,
которая обрабатывает сигнал, полученный суммирующей функцией нейрона*/
float Neuron::Akson::getSignal() const
{
	return 1 / (1 + exp(-ownerNeuron->kernelFunction()));
}

/*Конструктор устанавливает для в качестве нейрона-владельца
аксона свой объект*/
Neuron::Neuron()
{
	akson.ownerNeuron = this;
}

/*Нейрон запрашивает сигнал у каждого своего дендрита,
тем самым обращаясь к аксонам нейронов предыдущего слоя,
которые в свою очередь обращаются к своим нейронам и.т.д,
то есть сбор сигналов идет цепочкой от самого первого слоя*/
float Neuron::kernelFunction()
{
	float result(0.);
	for (Dendrit d : dendrits) {
		result += d.inputAkson->getSignal() * d.weight;
	}
	return result;
}

