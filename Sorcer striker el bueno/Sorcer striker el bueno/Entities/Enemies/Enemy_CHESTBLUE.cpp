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
	
	if (!activePart2)
		pathchest.Update();
	else
		pathchest.Update();

	//if (chestdestroy==true && collider->type != Collider::Type::CHEST)
	//{
	//	collider->pendingToDelete = false;
	//	collider->type = Collider::Type::POWER_UP;
	//}

	position = spawnPos + currentPath->GetRelativePosition();

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position 
	Enemy::Update();

}

void Enemy_CHESS::OnCollision(Collider* c1) {
	if (c1->type == Collider::Type::PLAYER_SHOT)
	{
		//chestdestroy = true;

		collider = App->collisions->AddCollider({ 0, 0, 62, 78 }, Collider::Type::POWER_UP, (Module*)App->enemies);

		// Change sprite
		pickup.PushBack({ 42, 369, 62, 78 });
		pickup.PushBack({ 161, 365, 62, 78 });
		pickup.speed = 0.1f;
		currentAnim = &pickup;

		////Change Collider type
		//collider->rect = { 0, 0, 25, 35 };

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

		//// Active path2 update
		activePart2 = true;
	}
}
