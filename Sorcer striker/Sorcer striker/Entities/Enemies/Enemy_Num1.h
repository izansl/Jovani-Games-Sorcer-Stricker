#ifndef __ENEMY_NUM1_H__
#define __ENEMY_NUM1_H__

#include "Enemy.h"
#include "../../Utils/Path.h"


class Enemy_Num1 : public Enemy {

public:
	// Constructor (x y coordinates in the world)
	// Creates animation data and the collider
	Enemy_Num1(int x, int y);

	// The enemy is going to perform a sinusoidal movement
	void Update() override;
	//void Draw() override;

	void OnCollision(Collider* c1);


private: //BROWNSHIP
	// A set of steps that define the position in the screen
		// And an animation for each step
	Path pathchest;
	Path* currentPath;
	bool activePart2 = false;

	bool chestdestroy = false;



	// This enemy has one sprite and one frame
	// We are keeping it an animation for consistency with other enemies
	Animation blue;
	Animation pickup;
};

#endif // __ENEMY_CHESS_H__