#include "Boss_BreathDragon.h"

#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Gameplay/ModuleEnemies.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleRender.h"
#include"../../Modules/Core/ModuleTextures.h"


Boss_BreathDragon::Boss_BreathDragon(int x, int y, int wave) : Enemy(x, y) {

	// General
	texture = App->textures->Load(FI_spriteEnemy_boss.c_str());

	// Parts
	bodyCenter = {};
	bodyCenter_Dead = {};
	head1 = {};
	head1_Dead = {};
	head2 = {};
	head2_Dead = {};


	

	fan.PushBack({ 1100, 282, 108, 94 });
	fan.PushBack({ 1210, 280, 114, 96 });
	fan.speed = 0.1f;

	head.PushBack({ 1668, 70, 128, 160 });
	head.PushBack({ 1352, 70, 128, 180 });
	head.PushBack({ 1040, 70, 128, 180 });
	head.speed = 0.1f;

	fire.anim.PushBack({ 1207, 1377, 424, 421 });
	fire.anim.PushBack({ 1207, 1377, 424, 421 });
	fire.speed = iPoint(0, -12);
	fire.anim.speed = 0.05f;
	fire.lifetime = 115;
	
	currentAnim = &fan;


	// Path 1
	pathchest.PushBack({ -1.0f, -0.5f }, 10);
	pathchest.PushBack({ -0.9f, -0.8f }, 10);
	pathchest.PushBack({ -0.8f, -0.2f }, 10);
	pathchest.PushBack({ -0.7f, -1.0f }, 10);
	pathchest.PushBack({ -0.6f, -0.4f }, 10);
	pathchest.PushBack({ -0.5f, -0.9f }, 10);
	pathchest.PushBack({ -0.4f, -0.3f }, 10);
	pathchest.PushBack({ -0.3f, -1.0f }, 10);
	pathchest.PushBack({ -0.2f, -0.5f }, 10);
	pathchest.PushBack({ -0.1f, -0.1f }, 10);
	pathchest.PushBack({ 0.0f, -0.6f }, 10);
	pathchest.PushBack({ 0.1f, -0.2f }, 10);
	pathchest.PushBack({ 0.2f, -0.8f }, 10);
	pathchest.PushBack({ 0.3f, -0.4f }, 10);
	pathchest.PushBack({ 0.4f, -0.9f }, 10);
	pathchest.PushBack({ 0.5f, -0.3f }, 10);
	pathchest.PushBack({ 0.6f, -1.0f }, 10);
	pathchest.PushBack({ 0.7f, -0.5f }, 10);
	pathchest.PushBack({ 0.8f, -0.1f }, 10);
	pathchest.PushBack({ 0.9f, -0.6f }, 10);
	pathchest.PushBack({ 1.0f, -0.2f }, 10);
	pathchest.PushBack({ 1.0f, -1.0f }, 0);

	currentPath = &pathchest;
	collider = App->collisions->AddCollider({ 0, 0, 118, 99 }, Collider::Type::ENEMY, (Module*)App->enemies);

}

void Boss_BreathDragon::Update()
{
}

void Boss_BreathDragon::OnCollisionGeneral(Collider* c1)
{
}

void Boss_BreathDragon::OnCollisionHead1(Collider* c1)
{
}

void Boss_BreathDragon::OnCollisionHead2(Collider* c1)
{
}

void Boss_BreathDragon::OnCollisionHead3(Collider* c1)
{
}
