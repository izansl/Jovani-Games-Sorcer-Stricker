#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include<time.h>

class Player
{
public:
	Player();
	~Player();
	bool alive()
	{
		if (life==1)
		{
			return true;
		}
		return false;
	};
	int jump()
	{
		if (isJumping==1&&)
		{
			life = 1000000;
		}
	}

	bool Init();
	void Release();

	bool Input();
	bool Update();
	void Draw();

private:
	int high;
	int withd;
	int posx, posy;
	bool life, isJumping;
};

