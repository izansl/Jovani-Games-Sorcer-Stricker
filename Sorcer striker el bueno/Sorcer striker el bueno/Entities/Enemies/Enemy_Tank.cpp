#include "Enemy_Tank.h"
#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Gameplay/ModuleEnemies.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleRender.h"
#include"../../Modules/Core/ModuleTextures.h"

Enemy_Tank::Enemy_Tank(int x, int y, int wave, int miem) : Enemy(x, y) {
	texture = App->textures->Load(FI_spriteEnemy_reds.c_str());
	fly.PushBack({ 29, 357, 82, 104 });
	fly.PushBack({ 140, 357, 82, 104 });
	currentAnim = &fly;
	fly.speed = 0.2;
	fly.loop = true;
	


	collider = App->collisions->AddCollider({ 0, 0,82, 104 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_Tank::Update() {
	path.Update();
	position = spawnPos + path.GetRelativePosition();

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
//
void Enemy_Tank::OnCollision(Collider* c1) {
	fly.PushBack({ 7, 50, 32, 32 });
	fly.PushBack({ 42, 50, 32, 32 });
	fly.PushBack({ 77, 51, 32, 32 });
	fly.PushBack({ 111, 52, 32, 32 });
	fly.PushBack({ 200, 200, 32, 32 });

	currentAnim = &fly;
	fly.speed = 0.2;
	fly.loop = false;
	App->audio->PlayFx(destroyedFx);
}