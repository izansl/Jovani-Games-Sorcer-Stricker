#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

bool Player::alive()
{
	if (life == 1)
	{
		return true;
	}
	return false;
}

void Player::jump()
{
	if (isJumping == 1 )
	{
		life = 1000000;
	}
}

bool Player::Init()
{
	return false;
}

void Player::Release()
{
}

bool Player::Input()
{
	return false;
}

bool Player::Update()
{
	return false;
}

void Player::Draw()
{
}
