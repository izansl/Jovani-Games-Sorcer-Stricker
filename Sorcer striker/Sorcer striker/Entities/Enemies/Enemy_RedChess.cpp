#include "Enemy_RedChess.h"

#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Gameplay/ModuleEnemies.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleRender.h"
#include"../../Modules/Core/ModuleTextures.h"

Enemy_RedChess::Enemy_RedChess(int x, int y) : Enemy(x, y) {
	texture = App->textures->Load(FI_spritebonus_pickups.c_str());

	red.PushBack({ 17, 501, 118, 99 });
	red.PushBack({ 135, 498, 118, 99 });
	red.PushBack({ 258, 493, 118, 99 });
	red.PushBack({ 135, 498, 118, 99 });
	red.speed = 0.1f;
	currentAnim = &red;

	// Path 1
	pathchest.PushBack({ -2.0f, -6.5f }, 10);
	pathchest.PushBack({ -1.9f, -6.8f }, 10);
	pathchest.PushBack({ -1.8f, -6.2f }, 10);
	pathchest.PushBack({ -1.7f, -7.0f }, 10);
	pathchest.PushBack({ -1.6f, -6.4f }, 10);
	pathchest.PushBack({ -1.5f, -6.9f }, 10);
	pathchest.PushBack({ -1.4f, -6.3f }, 10);
	pathchest.PushBack({ -1.3f, -7.0f }, 10);
	pathchest.PushBack({ -1.2f, -6.5f }, 10);
	pathchest.PushBack({ -1.1f, -6.1f }, 10);
	pathchest.PushBack({ 1.0f, -7.0f }, 10);
	pathchest.PushBack({ 1.1f, -6.2f }, 10);
	pathchest.PushBack({ 1.2f, -6.8f }, 10);
	pathchest.PushBack({ 1.3f, -6.4f }, 10);
	pathchest.PushBack({ 1.4f, -6.9f }, 10);
	pathchest.PushBack({ 1.5f, -6.3f }, 10);
	pathchest.PushBack({ 1.6f, -7.0f }, 10);
	pathchest.PushBack({ 1.7f, -6.5f }, 10);
	pathchest.PushBack({ 1.8f, -6.1f }, 10);
	pathchest.PushBack({ 1.9f, -6.6f }, 10);
	pathchest.PushBack({ 2.0f, -6.2f }, 10);
	pathchest.PushBack({ 2.0f, -7.0f }, 10);

	currentPath = &pathchest;

	collider = App->collisions->AddCollider({ 0, 0, 118, 99 }, Collider::Type::CHEST, (Module*)App->enemies);
}

void Enemy_RedChess::Update() {
	pathchest.Update();
	position = spawnPos + currentPath->GetRelativePosition();

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position 
	Enemy::Update();

}

void Enemy_RedChess::OnCollision(Collider* c1) {
	if (c1->type == Collider::Type::PLAYER_SHOT)
	{
		chestdestroy = true;
		pickup.PushBack({ 1400, 25100, 118, 99 });
		currentAnim = &pickup;

		App->enemies->AddEnemy(Enemy_Type::Redbook, position.x, position.y, 1);
	}
}