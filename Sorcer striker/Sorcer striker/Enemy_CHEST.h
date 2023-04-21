#ifndef __ENEMY_CHESS_H__
#define __ENEMY_CHESS_H__

#include "Enemy.h"
#include "Path.h"
class Enemy_CHESS : public Enemy
{
public:

	// Constructor (x y coordinates in the world)
	// Creates animation data and the collider
	Enemy_CHESS(int x, int y);

	// The enemy is going to perform a sinusoidal movement
	void Update() override;

private: //BROWNSHIP
	// A set of steps that define the position in the screen
		// And an animation for each step
	Path path;

	// This enemy has one sprite and one frame
	// We are keeping it an animation for consistency with other enemies
	Animation fly;
};

#endif // __ENEMY_CHESS_H__
