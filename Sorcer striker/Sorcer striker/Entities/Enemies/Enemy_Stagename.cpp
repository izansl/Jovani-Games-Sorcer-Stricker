#include "Enemy_Stagename.h"

#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Gameplay/ModuleEnemies.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleRender.h"
#include"../../Modules/Core/ModuleTextures.h"


Enemy_Stage::Enemy_Stage(int x, int y) : Enemy(x, y) {
	texture = App->textures->Load(FI_HUD_stage1.c_str());

	blue.PushBack({ 139, 171, 318, 141 });
	blue.speed = 0.1f;
	currentAnim = &blue;


	// Path 1
	pathchest.PushBack({ 2.0f, -8.0f }, 10);
	pathchest.PushBack({ 4.0f, -8.0f }, 10);
	pathchest.PushBack({ 6.0f, -8.0f }, 10);
	pathchest.PushBack({ 8.0f, -8.0f }, 10);
	pathchest.PushBack({ 0.0f, -8.0f }, 100);
	pathchest.PushBack({ -25.0f, -8.0f }, 10);
	pathchest.PushBack({ -50.0f, -8.0f }, 10);
	pathchest.PushBack({ -75.0f, -8.0f }, 10);
	pathchest.PushBack({ -100.0f, -8.0f }, 10);

	currentPath = &pathchest;
	collider = App->collisions->AddCollider({ 0, 0, 118, 99 }, Collider::Type::CHEST, (Module*)App->enemies);

}

void Enemy_Stage::Update() {

	pathchest.Update();
	position = spawnPos + currentPath->GetRelativePosition();

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position 
	Enemy::Update();

}

void Enemy_Stage::OnCollision(Collider* c1) {
}