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

	if (!activePart2)
		pathchest.Update();
	else
		pathchest.Update();

	position = spawnPos + currentPath->GetRelativePosition();

	Enemy::Update();

}

void Enemy_Gold::OnCollision(Collider* c1) {
	if (c1->type == Collider::Type::PLAYER_SHOT	)
	{
		collider = App->collisions->AddCollider({ 0, 0, 46, 45 }, Collider::Type::POWER_UP, (Module*)App->enemies);

		pickup.PushBack({ 384, 817, 46, 45 });
		pickup.PushBack({ 459, 818, 46, 45 });
		pickup.PushBack({ 530, 817, 46, 45 });
		pickup.PushBack({ 601, 816, 46, 45 });
		pickup.PushBack({ 659, 816, 46, 45 });
		pickup.PushBack({ 725, 815, 46, 45 });
		pickup.speed = 0.1f;

		currentAnim = &pickup;
		
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
	}
}


