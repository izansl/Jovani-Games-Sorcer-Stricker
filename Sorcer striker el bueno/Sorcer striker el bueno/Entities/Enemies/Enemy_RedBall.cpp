#include "Enemy_RedBall.h"

#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"

Enemy_RedBall::Enemy_RedBall(int x, int y) : Enemy(x, y) {
	fly.PushBack({ 77, 1055 , 56, 76 });
	fly.PushBack({ 209, 1050 ,56, 76 });
	currentAnim = &fly;

	// Sescribe a path in the screen
	path.PushBack({ 0, -0.5f }, 100);
	path.PushBack({ 0, 0.5f }, 80);
	path.PushBack({ 0, 1.0f }, 80);

	collider = App->collisions->AddCollider({ 0, 0, 56, 76 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_RedBall::Update() {
	path.Update();
	position = spawnPos + path.GetRelativePosition();

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
