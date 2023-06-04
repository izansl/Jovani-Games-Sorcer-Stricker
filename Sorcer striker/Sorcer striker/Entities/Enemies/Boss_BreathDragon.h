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
	void SetToDelete() override;

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
	Animation animaitonBodyDamaged;

	Particle particleFire;

	Path pathFan;
	Path pathCuerpo;
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
	bool canshoot = true;

};

#endif
