#ifndef __BOSS_BREATHDRAGON_H__
#define __BOSS_BREATHDRAGON_H__

#include "Enemy.h"
#include "../../Utils/Path.h"
#include "../../Modules/Core/ModuleParticles.h"


class Boss_BreathDragon : public Enemy {

public:
	Boss_BreathDragon(int x, int y, int wave);

	void Update() override;
	void Draw() override;
	void OnCollision(Collider* collider) override;

	void OnCollisionGeneral(Collider* colisionEntrante);
	void OnCollisionHead1(Collider* colisionEntrante);
	void OnCollisionHead2(Collider* colisionEntrante);
	void OnCollisionHead3(Collider* colisionEntrante);


private:
	SDL_Texture* texturaBoss;

	int vides[4];

	bool headDestroy = false;
	bool headDestroy2 = false;
	bool headDestroy3 = false;

	/*Animation warning;
	Animation arrow;*/
	Animation animationFan;
	Animation animationHead; // Repetit x3
	Animation animationHeadDamaged;// Repetit x3
	Animation animationBody;
	Animation animationBody2;
	Animation animationBody3;
	Animation animaitonBodyDamaged;

	Particle particleFire;

	Path pathFan;
	Path pathCuerpo;
	Path pathCuerpo2;
	Path pathCuerpo3;
	Path pathCabeza;
	Path pathFire;

	Collider* colliderCuerpo;
	Collider* colliderCabeza1;
	Collider* colliderCabeza2;
	Collider* colliderCabeza3;

	int start_Time;	

	int temporitzador_CosDanyat;
	int temporitzador_Cap1Danyat;
	int temporitzador_Cap2Danyat;
	int temporitzador_Cap3Danyat;

	bool spawned1 = false;
	bool spawned2 = false;
	bool spawned3 = false;
	bool spawned4 = false;
	bool spawned5 = false;
	bool spawned6 = false;
	bool spawned7 = false;
	bool spawned8 = false;
	bool spawned9 = false;
	bool spawned10 = false;
	bool spawned11 = false;
	bool spawned12 = false;
	bool spawned13 = false;
	bool spawned14 = false;
	bool spawned15 = false;
	bool spawned16 = false;
	bool spawned17 = false;
	bool spawned18 = false;
	bool spawned19 = false;
	bool spawned20 = false;
	bool spawned21 = false;
	bool spawned22 = false;
	bool spawned23 = false;
	bool spawned24 = false;
	bool spawned25 = false;
	bool spawned26 = false;
	bool spawned27 = false;
	bool spawned28 = false;
	bool spawned29 = false;
	bool spawned30 = false;
	bool spawned31 = false;
	bool spawned32 = false;
	bool spawned33 = false;
	bool spawned34 = false;
	bool spawned35 = false;
	bool spawned36 = false;
	bool spawned37 = false;
	bool spawned38 = false;
	bool spawned39 = false;
	bool spawned40 = false;
	bool canshoot1 = true;
	bool canshoot2 = true;
	bool canshoot3 = true;
	bool canshoot4 = true;
	bool canshoot5 = true;

	int hitcount = 0;
	bool life = true;
	int temp = 0;
};

#endif
