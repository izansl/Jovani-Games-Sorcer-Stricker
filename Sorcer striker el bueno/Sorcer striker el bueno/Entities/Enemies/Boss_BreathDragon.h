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
	int vides[4];
	
	bool headDestroy = false;
	bool headDestroy2 = false;
	bool headDestroy3 = false;

	/*Animation warning;
	Animation arrow;*/
	Animation animationFan;
	Animation animationHead; // Repetit x3
	Animation animationHeadDamaged;// Repetit x3
	Animation animationBody; // 
	Animation animaitonBodyDamaged;

	Particle particleFire;

	Path pathFan1;
	Path pathFan2;
	Path pathFan3;
	Path pathFan4;
	Path pathCuerpo;
	Path pathCabeza1;
	Path pathCabeza2;
	Path pathCabeza3;
	Path pathFire;

	Collider* colliderCuerpo;
	Collider* colliderCabeza1;
	Collider* colliderCabeza2;
	Collider* colliderCabeza3;

};

#endif
