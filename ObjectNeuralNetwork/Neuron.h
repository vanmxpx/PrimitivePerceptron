#pragma once
#include <vector>

class Neuron
{

public:

	/*����� - �������� ����� �������, ������� �������� ���������
	������� ������, ������������ �������� ���������*/
	class Akson {
	public:
		float getSignal() const;//������� ���������
		Neuron *ownerNeuron;
	};

	/*������� - ���� �� ������� ����� �������. �������� ������� �����������.
	� ������ ����������� ������ ������� �������� ��������� �� �������������� ���
	�����, � �������� �� � �������� ������.*/
	class Dendrit {
	public:
		float weight = 0.1;
		Akson *inputAkson;
	};


	Neuron();
	/*������, ���������� ������� ��������, �.�. �� ����� ���� ������ ����������*/
	std::vector<Dendrit> dendrits;
	Akson akson;
	/*����������� �������, ������� ���������(� ����� ������� ������)
	������� �������*/
	virtual float kernelFunction();
	/*��������� �������*/
	float value;
};

