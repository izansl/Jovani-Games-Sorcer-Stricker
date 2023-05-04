#ifndef __ENEMY_DRAGON_H__
#define __ENEMY_DRAGON_H__

#include "Enemy.h"
#include "../../Utils/Path.h"

class Enemy_Dragon : public Enemy {

public:
	// Constructor (x y coordinates in the world)
	// Creates animation and movement data and the collider
	Enemy_Dragon(int x, int y, int wave, int miem);

	// The enemy is going to follow the different steps in the path
	// Position will be updated depending on the speed defined at each step
	void Update() override;

	void OnCollision(Collider* c1) override;
	/*void Draw() override;*/
private:
	// A set of steps that define the position in the screen
	// And an animation for each step
	Path path;
	int life = 5;
	// This enemy has one sprite and one frame
	// We are keeping it an animation for consistency with other enemies
	Animation fly;
	Animation explosion;
};

#endif // __ENEMY_BROWNSHIP_H__

