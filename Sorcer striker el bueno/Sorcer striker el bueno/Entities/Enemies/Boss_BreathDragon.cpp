#include "Boss_BreathDragon.h"

#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Gameplay/ModuleEnemies.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleRender.h"
#include"../../Modules/Core/ModuleTextures.h"


Boss_BreathDragon::Boss_BreathDragon(int x, int y, int wave) : Enemy(x, y) {

	vides[0] = 5; // Cabeza 0
	vides[1] = 15; // Cabeza 1
	vides[2] = 5; // Cabeza 2

	// General
	texture = App->textures->Load(FI_spriteEnemy_boss.c_str());

	//warning;
	arrow.PushBack({ 0,844, 155,155 });
	arrow.PushBack({ 400,844, 155,155 }); //Buit

	fan.PushBack({ 0, 230, 115, 115 });
	fan.PushBack({ 116, 230, 115, 115 });
	fan.speed = 0.1f;


	Animation body_center;
	Animation body_center_damaged;
	Animation body_left;
	Animation body_left_damaged;
	Animation body_right;
	Animation body_right_damaged;


	head.PushBack({ 1668, 70, 180, 180 });
	head.PushBack({ 1352, 70, 180, 180 });
	head.PushBack({ 1040, 70, 180, 180 });
	head.speed = 0.1f;

	head_damaged.PushBack({ 1668, 70, 180, 180 });
	head_damaged.PushBack({ 1352, 70, 180, 180 });
	head_damaged.PushBack({ 1040, 70, 180, 180 });
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

	currentAnim = &fan;


	// Path 1
	//pathchest.PushBack({ -1.0f, -0.5f }, 10);
	//pathchest.PushBack({ -0.9f, -0.8f }, 10);
	//pathchest.PushBack({ -0.8f, -0.2f }, 10);
	//pathchest.PushBack({ -0.7f, -1.0f }, 10);

	//currentPath = &fan;
	collider = App->collisions->AddCollider({ 0, 0, 118, 99 }, Collider::Type::ENEMY, (Module*)App->enemies);

}

void Boss_BreathDragon::Update() {

}

void Boss_BreathDragon::OnCollisionGeneral(Collider* c1) {
	if (c1->type == Collider::Type::PLAYER_SHOT)
	{
		if (vides[0] <= 0 && vides[1] <= 0 && vides[2] <= 0 && vides[3] <= 0)
			this->SetToDelete();
		else
			vides[0] -= 1;
	}
}

void Boss_BreathDragon::OnCollisionHead1(Collider* c1) {
	if (c1->type == Collider::Type::PLAYER_SHOT && !headDestroy)
	{
		if (vides[1] <= 0) {
			headDestroy = true;
		}
		else
			vides[1] -= 1;
	}
}

void Boss_BreathDragon::OnCollisionHead2(Collider* c1) {
	if (c1->type == Collider::Type::PLAYER_SHOT && !headDestroy2) {
		if (vides[2] <= 0) {
			headDestroy2 = true;
		}
		else
			vides[2] -= 1;
	}
}

void Boss_BreathDragon::OnCollisionHead3(Collider* c1)
{
	if (c1->type == Collider::Type::PLAYER_SHOT && !headDestroy3) {
		if (vides[3] <= 0) {
			headDestroy3 = true;
		}
		else
			vides[3] -= 1;
	}
}
