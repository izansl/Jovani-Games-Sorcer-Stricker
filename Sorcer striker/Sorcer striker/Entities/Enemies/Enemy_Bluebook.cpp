#include "Enemy_Bluebook.h"

#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Gameplay/ModuleEnemies.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleRender.h"
#include"../../Modules/Core/ModuleTextures.h"
#include "../../Modules/Gameplay/SceneLevel1.h"


Enemy_Bluebook::Enemy_Bluebook(int x, int y) : Enemy(x, y) {
	texture = App->textures->Load(FI_spritebonus_pickups.c_str());

	book.PushBack({ 42, 369, 62, 78 });
	book.PushBack({ 161, 365, 62, 78 });
	book.speed = 0.1f;
	currentAnim = &book;

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

	collider = App->collisions->AddCollider({ 0, 0, 62, 78 }, Collider::Type::POWER_UP, (Module*)App->enemies);

}

void Enemy_Bluebook::Update() {
	pathbook.Update();
	position = spawnPos + currentPath->GetRelativePosition();

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position 
	Enemy::Update();

}

void Enemy_Bluebook::OnCollision(Collider* c1) {
	if (c1->type == Collider::Type::PLAYER)
	{
		pickup.PushBack({ 1400, 25100, 118, 99 });
		currentAnim = &pickup;
	}
}

