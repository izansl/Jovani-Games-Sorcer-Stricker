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
	Path pathchest;
	Path* currentPath;

	bool headDestroy = false;
	bool headDestroy2 = false;

	SDL_Rect bodyCenter;
	SDL_Rect bodyCenter_Dead;
	SDL_Rect head1;
	SDL_Rect head1_Dead;
	SDL_Rect head2;
	SDL_Rect  head2_Dead;

	Animation head;
	Animation fan;
	Particle fire;
};

#endif
