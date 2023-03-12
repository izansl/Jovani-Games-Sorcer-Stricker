#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include<math.h>

#define _USE_MATH_DEFINES

class Helice
{
public:
	Helice();
	~Helice();

	int direccion(int variable);
	int changespeed(int newspeed);
	int changehigh(int newhigh);
	int changewidth(int newwidth);

	bool Init();
	void Release();

	bool Input();
	bool Update();
	void Draw();

private:

	int speed;
	int high;
	int width;
};

