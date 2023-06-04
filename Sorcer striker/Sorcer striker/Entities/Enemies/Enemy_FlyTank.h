#ifndef __ENEMY_FLYTANK_H__
#define __ENEMY_FLYTANK_H__

#include "Enemy.h"
#include "../../Utils/Path.h"
#include "../../Modules/Core/ModuleParticles.h"

class Enemy_FlyTank : public Enemy {

public:
	// Constructor (x y coordinates in the world)
	// Creates animation and movement data and the collider
	Enemy_FlyTank(int x, int y, int wave);

	// The enemy is going to follow the different steps in the path
	// Position will be updated depending on the speed defined at each step
	void Update() override;

	void OnCollision(Collider* c1);

	bool destroyed = false;


private:
	SDL_Texture* texture2 = nullptr;
	// A set of steps that define the position in the screen
	// And an animation for each step
	Path path;
	int hitcount = 0;
	bool life = true;
	// This enemy has one sprite and one frame
	// We are keeping it an animation for consistency with other enemies
	Animation fly;
	Animation damage;
	Animation death;

	int temp = 0;
};

#endif // __ENEMY_BROWNSHIP_H__