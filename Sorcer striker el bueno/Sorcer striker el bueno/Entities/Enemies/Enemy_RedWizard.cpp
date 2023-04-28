#include "Enemy_RedWizard.h"

#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Core/ModuleRender.h"
#include "../../Modules/Core/ModuleTextures.h"
#include "../../Application/FileNames.h"

Enemy_RedWizard::Enemy_RedWizard(int x, int y) : Enemy(x, y) {
	texture = App->textures->Load(FI_spriteEnemy_2.c_str());
	fly.PushBack({ 48, 12, 22,31 });
	fly.PushBack({ 114,32 ,26, 32 });
	currentAnim = &fly;
	fly.speed = 0.01f;

	path.PushBack({ 0.0, -0.3 }, 20);
	path.PushBack({ 0.0, 0.5 }, 100);

	collider = App->collisions->AddCollider({ 0, 0, 102, 95 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_RedWizard::Update() {
	path.Update();
	position = spawnPos + path.GetRelativePosition();

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
