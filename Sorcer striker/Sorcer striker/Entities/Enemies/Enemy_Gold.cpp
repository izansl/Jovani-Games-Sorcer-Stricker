#include "Enemy_Gold.h"

#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Gameplay/ModuleEnemies.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleRender.h"
#include"../../Modules/Core/ModuleTextures.h"


Enemy_Gold::Enemy_Gold(int x, int y) : Enemy(x, y) {
	texture = App->textures->Load(FI_spritebonus_pickups.c_str());

	blue.PushBack({ 20, 776, 114, 103 });
	blue.PushBack({ 191, 774, 114, 103 });
	blue.speed = 0.1f;
	currentAnim = &blue;

	// Path 1
	pathchest.PushBack({ 0.0f, 0.5f }, 10);
	pathchest.PushBack({ 0.0f, -2.0f }, 10);
	pathchest.PushBack({ 0.0f, -2.5f }, 10);
	pathchest.PushBack({ 0.0f, -2.0f }, 10);
	pathchest.PushBack({ 0.0f, -1.5f }, 10);
	pathchest.PushBack({ 0.0f, -2.0f }, 10);
	pathchest.PushBack({ 0.0f, -2.5f }, 10);
	pathchest.PushBack({ 0.0f, -2.0f }, 10);
	pathchest.PushBack({ 0.0f, -1.5f }, 10);
	pathchest.PushBack({ 0.0f, -2.0f }, 10);
	pathchest.PushBack({ 0.0f, -2.5f }, 10);
	pathchest.PushBack({ 0.0f, -2.0f }, 10);
	pathchest.PushBack({ 0.0f, -1.5f }, 10);
	pathchest.PushBack({ 0.0f, -2.0f }, 10);
	pathchest.PushBack({ 0.0f, -2.5f }, 10);
	pathchest.PushBack({ 0.0f, -2.0f }, 10);
	pathchest.PushBack({ 0.0f, -1.5f }, 10);
	pathchest.PushBack({ 0.0f, -2.0f }, 10);
	pathchest.PushBack({ 0.0f, -2.5f }, 10);
	pathchest.PushBack({ 0.0f, -2.0f }, 10);
	pathchest.PushBack({ 0.0f, 0.5f }, 10);

	currentPath = &pathchest;
	collider = App->collisions->AddCollider({ 0, 0, 114, 103 }, Collider::Type::CHEST, (Module*)App->enemies);

}

void Enemy_Gold::Update() {


	position = spawnPos + currentPath->GetRelativePosition();

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position 

	Enemy::Update();

}

void Enemy_Gold::OnCollision(Collider* c1) {
	if (c1->type == Collider::Type::PLAYER_SHOT	)
	{
		chestdestroy = true;
		pickup.PushBack({ 1400, 25100, 118, 99 });
		currentAnim = &pickup;

		App->enemies->AddEnemy(Enemy_Type::COIN, position.x, position.y, 1);
		App->enemies->AddEnemy(Enemy_Type::COIN, position.x-50, position.y+20, 1);
		App->enemies->AddEnemy(Enemy_Type::COIN, position.x+50, position.y+20, 1);
	}
}


