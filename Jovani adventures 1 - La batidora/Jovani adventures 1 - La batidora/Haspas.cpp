#include "Haspas.h"

Helice::Helice()
{
}

Helice::~Helice()
{
}

int Helice::direccion(int variable)
{
	int i = variable;
	while (i != 0) {
		variable = (i * M_PI) / 180;
		if (variable == 360)
		{
			i = 0;
		}
		i++;
	}
	return variable;
}

int Helice::changespeed(int newspeed)
{
	speed = speed + newspeed;
}

int Helice::changehigh(int newhigh)
{
	high = high + newhigh;
}

int Helice::changewidth(int newwidth)
{
	width = width + newwidth;
}

bool Helice::Init()
{
	return false;
}

void Helice::Release()
{
}

bool Helice::Input()
{
	return false;
}

bool Helice::Update()
{
	return false;
}

void Helice::Draw()
{
}