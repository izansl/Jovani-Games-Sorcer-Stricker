#include "Boss_BreathDragon.h"

#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Gameplay/ModuleEnemies.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleRender.h"
#include"../../Modules/Core/ModuleTextures.h"


Boss_BreathDragon::Boss_BreathDragon(int x, int y, int wave) : Enemy(x, y) {

	vides[0] = 15; // Cuerpo 0
	vides[1] = 5; // Cabeza 1
	vides[2] = 5; // Cabeza 2
	vides[3] = 5; // Cabeza 2

	// General
	texture = App->textures->Load(FI_spriteEnemy_boss.c_str());

	//warning;
	//arrow.PushBack({ 0,844, 155,155 });
	//arrow.PushBack({ 400,844, 155,155 }); //Buit

	fan.PushBack({ 0, 230, 115, 115 });
	fan.PushBack({ 116, 230, 115, 115 });
	fan.speed = 0.2;
	fan.loop = true;

	head.PushBack({ 0, 502, 180, 180 });
	head.PushBack({ 180 * 2, 502, 180, 180 });
	head.PushBack({ 180 * 4, 502, 180, 180 });
	head.speed = 0.1f;

	head_damaged.PushBack({ 180 * 1, 502, 180, 180 });
	head_damaged.PushBack({ 180 * 3, 502, 180, 180 });
	head_damaged.PushBack({ 180 * 5, 502, 180, 180 });
	head_damaged.speed = 0.1f;

	fire.anim.PushBack({ 0, 690, 157, 157 });
	fire.anim.PushBack({ 157, 690, 157, 157 });
	fire.anim.PushBack({ 157 * 2, 690, 157, 157 });
	fire.anim.PushBack({ 157 * 3, 690, 157, 157 });
	fire.anim.PushBack({ 157 * 4, 690, 157, 157 });
	fire.anim.PushBack({ 157 * 5, 690, 157, 157 });
	fire.anim.PushBack({ 157 * 6, 690, 157, 157 });
	fire.speed = iPoint(0, -12);
	fire.anim.speed = 0.05f;
	fire.lifetime = 115;

	currentAnim = &head_damaged;
	path.PushBack({ 0, 0 }, 20);

	collider = App->collisions->AddCollider({ 0, 0,1200, 400 }, Collider::Type::ENEMY, (Module*)App->enemies);
	colliderCabeza1 = App->collisions->AddCollider({ 0, 0,180, 180 }, Collider::Type::ENEMY, (Module*)App->enemies);
	colliderCabeza2 = App->collisions->AddCollider({ 0, 0,180, 180 }, Collider::Type::ENEMY, (Module*)App->enemies);
	colliderCabeza3 = App->collisions->AddCollider({ 0, 0,180, 180 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Boss_BreathDragon::Update() {
	path.Update();
	position = spawnPos + path.GetRelativePosition();
	Enemy::Update();
}

void Boss_BreathDragon::OnCollisionGeneral(Collider* c1) {
	if (c1->type == Collider::Type::PLAYER_SHOT)
	{
		// Si cuerpo tiene 0 vidas muere || las tres cabezas tienen 0 vidas muere
		if ((vides[0] <= 0) || (vides[1] <= 0 && vides[2] <= 0 && vides[3] <= 0))
			this->SetToDelete();
		else
			vides[0] -= 1;
	}
}

void Boss_BreathDragon::OnCollisionHead1(Collider* c1) {
	if (c1->type == Collider::Type::PLAYER_SHOT && !headDestroy) {

		if ((vides[0] <= 0) || (vides[1] <= 0 && vides[2] <= 0 && vides[3] <= 0))
			this->SetToDelete();
		else {
			if (vides[1] <= 0) headDestroy = true;
			else vides[1] -= 1;
		}
	}
}

void Boss_BreathDragon::OnCollisionHead2(Collider* c1) {
	if (c1->type == Collider::Type::PLAYER_SHOT && !headDestroy2) {

		if ((vides[0] <= 0) || (vides[1] <= 0 && vides[2] <= 0 && vides[3] <= 0))
			this->SetToDelete();
		else {
			if (vides[2] <= 0) headDestroy2 = true;
			else vides[2] -= 1;
		}
	}
}

void Boss_BreathDragon::OnCollisionHead3(Collider* c1)
{
	if (c1->type == Collider::Type::PLAYER_SHOT && !headDestroy3) {

		if ((vides[0] <= 0) || (vides[1] <= 0 && vides[2] <= 0 && vides[3] <= 0))
			this->SetToDelete();
		else {
			if (vides[3] <= 0) headDestroy3 = true;
			else vides[3] -= 1;
		}
	}
}
