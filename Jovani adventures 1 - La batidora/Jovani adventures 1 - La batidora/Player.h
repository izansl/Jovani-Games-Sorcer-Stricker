#include <SDL.h>
#include <SDL_image.h>
#include<time.h>

class Player
{
public:

	Player();
	~Player();
	
	bool alive();
	void jump();

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