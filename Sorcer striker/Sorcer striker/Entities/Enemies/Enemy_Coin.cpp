#include "Enemy_Coin.h"

#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Gameplay/ModuleEnemies.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleRender.h"
#include"../../Modules/Core/ModuleTextures.h"
#include "../../Modules/Gameplay/SceneLevel1.h"


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
	pathbook.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell - 4 }, 10);
	pathbook.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell - 3 }, 10);
	pathbook.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell - 2 }, 10);
	pathbook.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell - 1 }, 10);
	pathbook.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell }, 10);
	pathbook.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell + 6.8f }, 10);
	pathbook.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell + 6.8f }, 10);
	pathbook.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell + 6.8f }, 10);
	pathbook.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell + 7 }, 10);
	pathbook.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell + 7 }, 10);
	pathbook.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell + 7.2f }, 10);
	pathbook.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell + 7.2f }, 10);
	pathbook.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell + 7.2f }, 10);
	pathbook.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell + 7.2f }, 10);
	pathbook.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell + 7.2f }, 10);
	pathbook.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell + 7.2f }, 10);
	pathbook.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell + 7.2f }, 10);
	pathbook.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell + 7.2f }, 10);
	pathbook.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell + 7.2f }, 10);
	pathbook.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell + 7.2f }, 10);
	pathbook.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell + 7.2f }, 10);
	pathbook.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell + 7.2f }, 10);
	pathbook.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell + 7.2f }, 10);
	pathbook.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell + 7.2f }, 10);
	pathbook.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell + 7.2f }, 0);

	currentPath = &pathbook;

	collider = App->collisions->AddCollider({ 0, 0, 46, 45 }, Collider::Type::POWER_UP, (Module*)App->enemies);

}

void Enemy_Coin::Update() {
	pathbook.Update();
	position = spawnPos + currentPath->GetRelativePosition();

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position 
	Enemy::Update();

}

void Enemy_Coin::OnCollision(Collider* c1) {
	if (c1->type == Collider::Type::PLAYER)
	{
		book.PushBack({ 1400, 25100, 118, 99 });
		currentAnim = &book;
	}
}


