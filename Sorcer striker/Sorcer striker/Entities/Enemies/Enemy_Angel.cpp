#include "Enemy_Angel.h"

#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Gameplay/ModuleEnemies.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleRender.h"
#include"../../Modules/Core/ModuleTextures.h"
#include "../../Modules/Gameplay/SceneLevel1.h"

#include <SDL_timer.h>


Enemy_Angel::Enemy_Angel(int x, int y) : Enemy(x, y) {
	texture = App->textures->Load(FI_spritebonus_special.c_str());

	blue.PushBack({ 0, 23, 223, 212 });
	blue.PushBack({ 223, 23, 223, 212 });
	blue.PushBack({ 465, 23, 223, 212 });
	blue.PushBack({ 694, 23, 223, 212 });
	blue.speed = 0.075f;
	currentAnim = &blue;


	// Path 1

	pathchest.PushBack({ -2.0f, (float)App->sceneLevel_1->velocitatNivell + 1.5f }, 10);
	pathchest.PushBack({ -1.9f, (float)App->sceneLevel_1->velocitatNivell + 1.8f }, 10);
	pathchest.PushBack({ -1.8f, (float)App->sceneLevel_1->velocitatNivell + 1.2f }, 10);
	pathchest.PushBack({ -1.7f, (float)App->sceneLevel_1->velocitatNivell + 1.0f }, 10);
	pathchest.PushBack({ -1.6f, (float)App->sceneLevel_1->velocitatNivell + 1.4f }, 10);
	pathchest.PushBack({ -1.5f, (float)App->sceneLevel_1->velocitatNivell + 1.9f }, 10);
	pathchest.PushBack({ -1.4f, (float)App->sceneLevel_1->velocitatNivell + 1.3f }, 10);
	pathchest.PushBack({ -1.3f, (float)App->sceneLevel_1->velocitatNivell + 1.0f }, 10);
	pathchest.PushBack({ -1.2f, (float)App->sceneLevel_1->velocitatNivell + 1.5f }, 10);
	pathchest.PushBack({ -1.1f, (float)App->sceneLevel_1->velocitatNivell + 1.1f }, 10);
	pathchest.PushBack({ 1.0f, (float)App->sceneLevel_1->velocitatNivell + 1.0f }, 10);
	pathchest.PushBack({ 1.1f, (float)App->sceneLevel_1->velocitatNivell + 1.2f }, 10);
	pathchest.PushBack({ 1.2f, (float)App->sceneLevel_1->velocitatNivell + 1.8f }, 10);
	pathchest.PushBack({ 1.3f, (float)App->sceneLevel_1->velocitatNivell + 1.4f }, 10);
	pathchest.PushBack({ 1.4f, (float)App->sceneLevel_1->velocitatNivell + 1.9f }, 10);
	pathchest.PushBack({ 1.5f, (float)App->sceneLevel_1->velocitatNivell + 1.3f }, 10);
	pathchest.PushBack({ 1.6f, (float)App->sceneLevel_1->velocitatNivell + 1.0f }, 10);
	pathchest.PushBack({ 1.7f, (float)App->sceneLevel_1->velocitatNivell + 1.5f }, 10);
	pathchest.PushBack({ 1.8f, (float)App->sceneLevel_1->velocitatNivell + 1.1f }, 10);
	pathchest.PushBack({ 1.9f, (float)App->sceneLevel_1->velocitatNivell + 1.6f }, 10);
	pathchest.PushBack({ 2.0f, (float)App->sceneLevel_1->velocitatNivell + 1.2f }, 10);
	pathchest.PushBack({ 2.0f, (float)App->sceneLevel_1->velocitatNivell + 1.0f }, 10);

	currentPath = &pathchest;

	start_time = SDL_GetTicks();
}

void Enemy_Angel::Update() {

	pathchest.Update();
	position = spawnPos + currentPath->GetRelativePosition();

	if (SDL_GetTicks() - start_time >= 400 && !bluebookAdded)
	{
		App->enemies->AddEnemy(Enemy_Type::Bluebook, position.x + 50, position.y, 1);
		bluebookAdded = true;
	}
	if (SDL_GetTicks() - start_time >= 800 && !redbookAdded)
	{
		App->enemies->AddEnemy(Enemy_Type::Redbook, position.x - 50, position.y, 1);
		redbookAdded = true;
	}
	if (SDL_GetTicks() - start_time >= 1200 && !greenbookAdded)
	{
		App->enemies->AddEnemy(Enemy_Type::Greenbook, position.x, position.y - 50, 1);
		greenbookAdded = true;
	}
	if (SDL_GetTicks() - start_time >= 1600 && !bluebookAdded2)
	{
		App->enemies->AddEnemy(Enemy_Type::Bluebook, position.x+100, position.y, 1);
		bluebookAdded2 = true;

	}
	if (SDL_GetTicks() - start_time >= 2200 && !pickupUpdated)
	{
		pickup.PushBack({ 500, 500, 118, 99 });
		currentAnim = &pickup;
		pickupUpdated = true;
	}

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position 
	Enemy::Update();

}

void Enemy_Angel::OnCollision(Collider* c1) {
}
