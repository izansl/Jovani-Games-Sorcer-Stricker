#include "Enemy_Dragon.h"

#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"

Enemy_Dragon::Enemy_Dragon(int x, int y) : Enemy(x, y) {
	fly.PushBack({ 24, 398 ,252,270 });
	fly.PushBack({ 333, 398 ,252,270 });
	currentAnim = &fly;

	// Describe a path in the screen
	path.PushBack({ 0, -0.5f }, 100);
	path.PushBack({ 0, 0.5f }, 80);
	path.PushBack({ 0, 1.0f }, 80);

	collider = App->collisions->AddCollider({ 0, 0, 252, 270 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_Dragon::Update() {
	path.Update();
	position = spawnPos + path.GetRelativePosition();

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
