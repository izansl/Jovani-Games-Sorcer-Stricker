#ifndef __ENEMY_TANK_H__
#define __ENEMY_TANK_H__

#include "Enemy.h"
#include "../../Utils/Path.h"

class Enemy_Tank : public Enemy {

public:
	// Constructor (x y coordinates in the world)
	// Creates animation and movement data and the collider
	Enemy_Tank(int x, int y, int wave);

	// The enemy is going to follow the different steps in the path
	// Position will be updated depending on the speed defined at each step
	void Update() override;

	void OnCollision(Collider* c1);

	bool destroyed = false;


private:
	// A set of steps that define the position in the screen
	// And an animation for each step
	Path path;

	// This enemy has one sprite and one frame
	// We are keeping it an animation for consistency with other enemies
	Animation de;
	Animation iz;
	Animation damage;
	Animation death;
	bool life = true;
	int hitcount = 0;

};

#endif // __ENEMY_BROWNSHIP_H__