#include "Enemy_RedWizard.h"

#include "Application.h"
#include "ModuleCollisions.h"

Enemy_RedWizard::Enemy_RedWizard(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 58,1219,102,95 });
	fly.PushBack({ 163,1216,102,95 });
	currentAnim = &fly;
	fly.speed = 0.01f;

	path.PushBack({ 0.0, -0.3 }, 20);
	path.PushBack({ 0.0, 0.5 }, 100);
	// TODO 3: Have the Brown Cookies describe a path in the screen

	collider = App->collisions->AddCollider({ 0, 0, 102, 95 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_RedWizard::Update()
{
	path.Update();
	position = spawnPos + path.GetRelativePosition();

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
