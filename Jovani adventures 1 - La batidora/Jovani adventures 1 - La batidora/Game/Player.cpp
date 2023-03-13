#include "Player.h"

Player::Player(VideoManager* video, ImageManager* imageManager)
{
	_video = video;
	_imageManager = imageManager;

	_posPlayerX = 160;
	_posPlayerY = 160;

	_actualDirection = SOUTH;
	_numFrameAnimation = 0;

	_actualDraw.h = 0;
	_actualDraw.w = 0;
	_actualDraw.x = 0;
	_actualDraw.y = 0;

	_idImageMngPlayer = _imageManager->loadAndGetGraphicID("ruta.png");
}

void Player::Draw(int posX, int posY)
{
	Xywh desti{};
	desti.x = posX;
	desti.y = posY;
	desti.w = _actualDraw.w;
	desti.h = _actualDraw.h;

	_video->renderGraphic(_idImageMngPlayer, &_actualDraw, &desti);
}

void Player::Update()
{
}

bool Player::IsAlive()
{
	return false;
}

void Player::Jump()
{
}

Player::~Player()
{
}