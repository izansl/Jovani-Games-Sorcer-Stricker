#include "Enemy_GreenChess.h"

#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Gameplay/ModuleEnemies.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleRender.h"
#include"../../Modules/Core/ModuleTextures.h"
#include "../../Modules/Gameplay/SceneLevel1.h"


Enemy_GreenChess::Enemy_GreenChess(int x, int y) : Enemy(x, y) {
	texture = App->textures->Load(FI_spritebonus_pickups.c_str());

	green.PushBack({ 15, 25, 118, 99 });
	green.PushBack({ 132, 20, 118, 99 });
	green.PushBack({ 260, 17, 118, 99 });
	green.PushBack({ 132, 20, 118, 99 });
	green.speed = 0.1f;
	currentAnim = &green;

	// Path 1
	pathchest.PushBack({ -2.0f, (float)App->sceneLevel_1->velocitatNivell +1.5f }, 10);
	pathchest.PushBack({ -1.9f, (float)App->sceneLevel_1->velocitatNivell +1.8f }, 10);
	pathchest.PushBack({ -1.8f, (float)App->sceneLevel_1->velocitatNivell +1.2f }, 10);
	pathchest.PushBack({ -1.7f, (float)App->sceneLevel_1->velocitatNivell +1.0f }, 10);
	pathchest.PushBack({ -1.6f, (float)App->sceneLevel_1->velocitatNivell +1.4f }, 10);
	pathchest.PushBack({ -1.5f, (float)App->sceneLevel_1->velocitatNivell +1.9f }, 10);
	pathchest.PushBack({ -1.4f, (float)App->sceneLevel_1->velocitatNivell +1.3f }, 10);
	pathchest.PushBack({ -1.3f, (float)App->sceneLevel_1->velocitatNivell +1.0f }, 10);
	pathchest.PushBack({ -1.2f, (float)App->sceneLevel_1->velocitatNivell +1.5f }, 10);
	pathchest.PushBack({ -1.1f, (float)App->sceneLevel_1->velocitatNivell +1.1f }, 10);
	pathchest.PushBack({ 1.0f, (float)App->sceneLevel_1->velocitatNivell +1.0f }, 10);
	pathchest.PushBack({ 1.1f, (float)App->sceneLevel_1->velocitatNivell +1.2f }, 10);
	pathchest.PushBack({ 1.2f, (float)App->sceneLevel_1->velocitatNivell +1.8f }, 10);
	pathchest.PushBack({ 1.3f, (float)App->sceneLevel_1->velocitatNivell +1.4f }, 10);
	pathchest.PushBack({ 1.4f, (float)App->sceneLevel_1->velocitatNivell +1.9f }, 10);
	pathchest.PushBack({ 1.5f, (float)App->sceneLevel_1->velocitatNivell +1.3f }, 10);
	pathchest.PushBack({ 1.6f, (float)App->sceneLevel_1->velocitatNivell +1.0f }, 10);
	pathchest.PushBack({ 1.7f, (float)App->sceneLevel_1->velocitatNivell +1.5f }, 10);
	pathchest.PushBack({ 1.8f, (float)App->sceneLevel_1->velocitatNivell +1.1f }, 10);
	pathchest.PushBack({ 1.9f, (float)App->sceneLevel_1->velocitatNivell +1.6f }, 10);
	pathchest.PushBack({ 2.0f, (float)App->sceneLevel_1->velocitatNivell +1.2f }, 10);
	pathchest.PushBack({ 2.0f, (float)App->sceneLevel_1->velocitatNivell +1.0f }, 10);

	currentPath = &pathchest;
	
	collider = App->collisions->AddCollider({ 0, 0, 118, 99 }, Collider::Type::CHEST, (Module*)App->enemies);
}

void Enemy_GreenChess::Update() {
	pathchest.Update();
	position = spawnPos + currentPath->GetRelativePosition();

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position 
	Enemy::Update();

}

void Enemy_GreenChess::OnCollision(Collider* c1) {
	if (c1->type == Collider::Type::PLAYER_SHOT)
	{
		chestdestroy = true;
		pickup.PushBack({ 1400, 25100, 118, 99 });
		currentAnim = &pickup;

		App->enemies->AddEnemy(Enemy_Type::Greenbook, position.x, position.y, 1);
	}
}