#ifndef __BOSS_BREATHDRAGON_H__
#define __BOSS_BREATHDRAGON_H__

#include "Enemy.h"
#include "../../Utils/Path.h"
#include "../Particle.h"


class Boss_BreathDragon : public Enemy {

public:
	Boss_BreathDragon(int x, int y, int wave);

	void Update() override;

	void OnCollisionGeneral(Collider* colisionEntrante);
	void OnCollisionHead1(Collider* colisionEntrante);
	void OnCollisionHead2(Collider* colisionEntrante);
	void OnCollisionHead3(Collider* colisionEntrante);


private:
	Path* currentPath;

	bool headDestroy = false;
	bool headDestroy2 = false;
	bool headDestroy3 = false;
		
	Animation warning;
	Animation arrow;
	Animation fan;

	Animation head;
	Animation head_damaged;

	Animation body_center;
	Animation body_center_damaged;
	Animation body_left;
	Animation body_left_damaged;
	Animation body_right;
	Animation body_right_damaged;

	Particle fire;

	int vides[4];
};

#endif
