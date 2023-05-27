#ifndef __BOSS_BREATHDRAGON_H__
#define __BOSS_BREATHDRAGON_H__

#include "Enemy.h"
#include "../../Utils/Path.h"


class Boss_BreathDragon : public Enemy {

public:
	Boss_BreathDragon(int x, int y);

	void Update() override;

	void OnCollisionGeneral(Collider* c1);
	void OnCollisionHead1(Collider* c1);
	void OnCollisionHead2(Collider* c1);
	void OnCollisionHead3(Collider* c1);


private:
	Path pathchest;
	Path* currentPath;

	bool headDestroy = false;
	bool headDestroy2 = false;

	Animation head;
	Animation fan;
};

#endif
