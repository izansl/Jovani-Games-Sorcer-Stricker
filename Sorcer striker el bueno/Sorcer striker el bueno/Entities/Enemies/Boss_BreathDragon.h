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
	Path* currentPath;	// Per totes les parts amb el mateix path pero llavors 
						// tenir en comptes el posicionament de cada una d'elles

	bool headDestroy = false;
	bool headDestroy2 = false;
	bool headDestroy3 = false;
		
	Animation warning;
	Animation arrow;
	Animation fan;

	Animation head; // Repetit x3
	Animation head_damaged;// Repetit x3

	Animation body; // 
	Animation body_damaged;

	Particle fire;

	int vides[4];
};

#endif
