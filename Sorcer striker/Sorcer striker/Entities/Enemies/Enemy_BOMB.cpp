#include "Enemy_Bomb.h"

#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Gameplay/ModuleEnemies.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleRender.h"
#include"../../Modules/Core/ModuleTextures.h"
#include "../../Modules/Gameplay/SceneLevel1.h"


Enemy_BOMB::Enemy_BOMB(int x, int y) : Enemy(x, y) {
	texture = App->textures->Load(FI_spritebonus_pickups.c_str());

	blue.PushBack({ 27, 898, 116, 122 });
	blue.PushBack({ 194, 899, 116, 122 });
	blue.speed = 0.1f;
	currentAnim = &blue;


	// Path 1

	pathchest.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell - 4 }, 10);
	pathchest.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell - 3 }, 10);
	pathchest.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell - 2 }, 10);
	pathchest.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell - 1 }, 10);
	pathchest.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell }, 10);
	pathchest.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell + 6.8f }, 10);
	pathchest.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell + 6.8f }, 10);
	pathchest.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell + 6.8f }, 10);
	pathchest.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell + 7 }, 10);
	pathchest.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell + 7 }, 10);
	pathchest.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell + 7.2f }, 10);
	pathchest.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell + 7.2f }, 10);
	pathchest.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell + 7.2f }, 10);
	pathchest.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell + 7.2f }, 10);
	pathchest.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell + 7.2f }, 10);
	pathchest.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell + 7.2f }, 10);
	pathchest.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell + 7.2f }, 10);
	pathchest.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell + 7.2f }, 10);
	pathchest.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell + 7.2f }, 10);
	pathchest.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell + 7.2f }, 10);
	pathchest.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell + 7.2f }, 10);
	pathchest.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell + 7.2f }, 10);
	pathchest.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell + 7.2f }, 10);
	pathchest.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell + 7.2f }, 10);
	pathchest.PushBack({ 0.0f, (float)App->sceneLevel_1->velocitatNivell + 7.2f }, 0);

	currentPath = &pathchest;
	collider = App->collisions->AddCollider({ 0, 0, 116, 122 }, Collider::Type::POWER_UP, (Module*)App->enemies);

}

void Enemy_BOMB::Update() {

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

void Enemy_BOMB::OnCollision(Collider* c1) {
	if (c1->type == Collider::Type::PLAYER)
	{
		pickup.PushBack({ 10000, 10000, 116, 122 });

		currentAnim = &pickup;
	}
}

