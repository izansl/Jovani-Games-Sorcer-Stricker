#include "Enemy_RedBall.h"

#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Core/ModuleRender.h"
#include "../../Modules/Core/ModuleTextures.h"
#include "../../Application/FileNames.h"

Enemy_RedBall::Enemy_RedBall(int x, int y) : Enemy(x, y) {
	texture = App->textures->Load(FI_spriteEnemy_1.c_str());
	fly.PushBack({ 48, 12, 22,31 });
	fly.PushBack({ 76,12 ,26, 32 });
	currentAnim = &fly;
	fly.speed = 0.2;
	fly.loop = true;
	// Sescribe a path in the screen
	path.PushBack({ 0, 0.5f }, 100);
	
	

	collider = App->collisions->AddCollider({ 0, 0,22, 32 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_RedBall::Update() {
	path.Update();
	position = spawnPos + path.GetRelativePosition();

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
