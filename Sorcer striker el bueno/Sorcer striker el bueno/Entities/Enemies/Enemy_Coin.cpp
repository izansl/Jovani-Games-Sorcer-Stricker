#include "Enemy_Coin.h"

#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Gameplay/ModuleEnemies.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleRender.h"
#include"../../Modules/Core/ModuleTextures.h"


Enemy_Coin::Enemy_Coin(int x, int y) : Enemy(x, y) {
	texture = App->textures->Load(FI_spritebonus_pickups.c_str());

	pickup.PushBack({ 384, 817, 46, 45 });
	pickup.PushBack({ 459, 818, 46, 45 });
	pickup.PushBack({ 530, 817, 46, 45 });
	pickup.PushBack({ 601, 816, 46, 45 });
	pickup.PushBack({ 659, 816, 46, 45 });
	pickup.PushBack({ 725, 815, 46, 45 });
	pickup.speed = 0.4f;
	currentAnim = &pickup;

	// Path 1

	pathbook.PushBack({ -1.0f, -0.5f }, 10);
	pathbook.PushBack({ -0.9f, -0.8f }, 10);
	pathbook.PushBack({ -0.8f, -0.2f }, 10);
	pathbook.PushBack({ -0.7f, -1.0f }, 10);
	pathbook.PushBack({ -0.6f, -0.4f }, 10);
	pathbook.PushBack({ -0.5f, -0.9f }, 10);
	pathbook.PushBack({ -0.4f, -0.3f }, 10);
	pathbook.PushBack({ -0.3f, -1.0f }, 10);
	pathbook.PushBack({ -0.2f, -0.5f }, 10);
	pathbook.PushBack({ -0.1f, -0.1f }, 10);
	pathbook.PushBack({ 0.0f, -0.6f }, 10);
	pathbook.PushBack({ 0.1f, -0.2f }, 10);
	pathbook.PushBack({ 0.2f, -0.8f }, 10);
	pathbook.PushBack({ 0.3f, -0.4f }, 10);
	pathbook.PushBack({ 0.4f, -0.9f }, 10);
	pathbook.PushBack({ 0.5f, -0.3f }, 10);
	pathbook.PushBack({ 0.6f, -1.0f }, 10);
	pathbook.PushBack({ 0.7f, -0.5f }, 10);
	pathbook.PushBack({ 0.8f, -0.1f }, 10);
	pathbook.PushBack({ 0.9f, -0.6f }, 10);
	pathbook.PushBack({ 1.0f, -0.2f }, 10);
	pathbook.PushBack({ 1.0f, -1.0f }, 0);

	currentPath = &pathbook;

	collider = App->collisions->AddCollider({ 0, 0, 46, 45 }, Collider::Type::POWER_UP, (Module*)App->enemies);

}

void Enemy_Coin::Update() {

	position = spawnPos + currentPath->GetRelativePosition();

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position 
	Enemy::Update();

}

void Enemy_Coin::OnCollision(Collider* c1) {
	if (c1->type == Collider::Type::PLAYER)
	{
		pickup.PushBack({ 1400, 25100, 118, 99 });
		currentAnim = &pickup;
	}
}


