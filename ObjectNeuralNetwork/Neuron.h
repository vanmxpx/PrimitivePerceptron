#pragma once
#include <vector>

class Neuron
{

public:

	/*Аксон - выходная часть нейрона, которая передает состояние
	нейрона дальше, обработанное функцией активации*/
	class Akson {
	public:
		float getSignal() const;//Функция активации
		Neuron *ownerNeuron;
	};

	/*Дендрит - одна из входных линий нейрона. Содержит весовой коэффициент.
	В данной архитектуре каждый дендрит содержит указатель на предшествующий ему
	аксон, с которого он и получает сигнал.*/
	class Dendrit {
	public:
		float weight = 0.1;
		Akson *inputAkson;
	};


	Neuron();
	/*Вектор, содержащий входные дендриты, т.к. их может быть разное количество*/
	std::vector<Dendrit> dendrits;
	Akson akson;
	/*Суммирующая функция, которая суммирует(В самом простом случае)
	входные сигналы*/
	virtual float kernelFunction();
	/*Состояние нейрона*/
	float value;
};

