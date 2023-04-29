#ifndef __ENEMY_CHESS_H__
#define __ENEMY_CHESS_H__

#include "Enemy.h"
#include "../../Utils/Path.h"


class Enemy_CHESS : public Enemy {

public:
	// Constructor (x y coordinates in the world)
	// Creates animation data and the collider
	Enemy_CHESS(int x, int y);

	// The enemy is going to perform a sinusoidal movement
	void Update() override;
	//void Draw() override;

	void OnCollision(Collider* collider)override;


private: //BROWNSHIP
	// A set of steps that define the position in the screen
		// And an animation for each step
	Path path1;
	Path path2;
	Path* currentPath;

	// This enemy has one sprite and one frame
	// We are keeping it an animation for consistency with other enemies
	Animation blue;
	Animation red;
};

#endif // __ENEMY_CHESS_H__