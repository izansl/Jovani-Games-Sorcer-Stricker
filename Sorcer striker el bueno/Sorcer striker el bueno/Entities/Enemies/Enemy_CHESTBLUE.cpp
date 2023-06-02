#include "Enemy_CHESTBLUE.h"

#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Gameplay/ModuleEnemies.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleRender.h"
#include"../../Modules/Core/ModuleTextures.h"


Enemy_CHESS::Enemy_CHESS(int x, int y) : Enemy(x, y) {
	texture = App->textures->Load(FI_spritebonus_pickups.c_str());

	blue.PushBack({ 14, 251, 118, 99 });
	blue.PushBack({ 140, 257, 118, 99 });
	blue.PushBack({ 244, 246, 118, 99});
	blue.PushBack({ 140, 257, 118, 99 });
	blue.speed = 0.1f;
	currentAnim = &blue;


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
	collider = App->collisions->AddCollider({ 0, 0, 118, 99 }, Collider::Type::CHEST, (Module*)App->enemies);

}

void Enemy_CHESS::Update() {
	

	position = spawnPos + currentPath->GetRelativePosition();

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position 
	Enemy::Update();

}

void Enemy_CHESS::OnCollision(Collider* c1) {
	if (c1->type == Collider::Type::PLAYER_SHOT)
	{
		chestdestroy = true;
		pickup.PushBack({ 1400, 25100, 118, 99 });
		currentAnim = &pickup;

		App->enemies->AddEnemy(Enemy_Type::Bluebook, position.x, position.y, 1);
	}
}
