#include "ModuleEnemies.h"

#include "../../Application/Application.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleRender.h"
#include "../../Modules/Core/ModuleTextures.h"
#include "../../Modules/Core/ModuleAudio.h"

#include "../../Entities/Enemies/Enemy.h"
#include "../../Entities/Enemies/Enemy_CHEST.h"
#include "../../Entities/Enemies/Enemy_Dragon.h"
#include "../../Entities/Enemies/Enemy_RedWizard.h"
#include "../../Entities/Enemies/Enemy_RedBall.h"

#define SPAWN_MARGIN 50

ModuleEnemies::ModuleEnemies(bool startEnabled) : Module(startEnabled) {
	for (uint i = 0; i < MAX_ENEMIES; ++i)
		enemies[i] = nullptr;
}

ModuleEnemies::~ModuleEnemies() {
}

bool ModuleEnemies::Start() {
	enemyDestroyedFx = App->audio->LoadFx(FA_Fx_explosion.c_str());
	return true;
}


Update_Status ModuleEnemies::PreUpdate() {
	// Remove all enemies scheduled for deletion
	for (uint i = 0; i < MAX_ENEMIES; ++i) {
		if (enemies[i] != nullptr && enemies[i]->pendingToDelete) {
			delete enemies[i];
			enemies[i] = nullptr;
		}
	}

	return Update_Status::UPDATE_CONTINUE;
}

Update_Status ModuleEnemies::Update() {
	HandleEnemiesSpawn();

	for (uint i = 0; i < MAX_ENEMIES; ++i) {
		if (enemies[i] != nullptr)
			enemies[i]->Update();
	}

	HandleEnemiesDespawn();

	return Update_Status::UPDATE_CONTINUE;
}

Update_Status ModuleEnemies::PostUpdate() {
	for (uint i = 0; i < MAX_ENEMIES; ++i) {
		if (enemies[i] != nullptr)
			enemies[i]->Draw();
	}

	return Update_Status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleEnemies::CleanUp() {
	LOG("Freeing all enemies");

	for (uint i = 0; i < MAX_ENEMIES; ++i) {
		if (enemies[i] != nullptr) {
			delete enemies[i];
			enemies[i] = nullptr;
		}
	}

	return true;
}

bool ModuleEnemies::AddEnemy(Enemy_Type type, int x, int y, int wave, int miem)
{
	bool ret = false;

	for (uint i = 0; i < MAX_ENEMIES; ++i) {
		if (spawnQueue[i].type == Enemy_Type::NO_TYPE) {
			spawnQueue[i].type = type;
			spawnQueue[i].x = x;
			spawnQueue[i].y = y;
			spawnQueue[i].wave = wave;
			spawnQueue[i].miem = miem;
			ret = true;
			break;
		}
	}

	return ret;
}

void ModuleEnemies::HandleEnemiesSpawn() {
	// Iterate all the enemies queue
	for (uint i = 0; i < MAX_ENEMIES; ++i) {
		if (spawnQueue[i].type != Enemy_Type::NO_TYPE) {
			// Spawn a new enemy if the screen has reached a spawn position
			if (spawnQueue[i].x * SCREEN_SIZE < App->render->camera.x + (App->render->camera.w * SCREEN_SIZE) + SPAWN_MARGIN) {
				LOG("Spawning enemy at %d", spawnQueue[i].x * SCREEN_SIZE);

				SpawnEnemy(spawnQueue[i]);
				spawnQueue[i].type = Enemy_Type::NO_TYPE; // Removing the newly spawned enemy from the queue
			}
		}
	}
}

void ModuleEnemies::HandleEnemiesDespawn() {
	// Iterate existing enemies
	for (uint i = 0; i < MAX_ENEMIES; ++i) {
		if (enemies[i] != nullptr) {
			// Delete the enemy when it has reached the end of the screen
			if (enemies[i]->position.x * SCREEN_SIZE < (App->render->camera.x) - SPAWN_MARGIN) {
				LOG("DeSpawning enemy at %d", enemies[i]->position.x * SCREEN_SIZE);

				enemies[i]->SetToDelete();
			}
		}
	}
}

void ModuleEnemies::SpawnEnemy(const EnemySpawnpoint& info) {
	// Find an empty slot in the enemies array
	for (uint i = 0; i < MAX_ENEMIES; ++i) {
		if (enemies[i] == nullptr) {
			switch (info.type) {
			case Enemy_Type::CHEST: 
				enemies[i] = new Enemy_CHESS(info.x, info.y); 
				break;
			case Enemy_Type::DRAGON: enemies[i] = new Enemy_Dragon(info.x, info.y, info.wave, info.miem);
				break;
			case Enemy_Type::REDWIZARD: enemies[i] = new Enemy_RedWizard(info.x, info.y, info.wave, info.miem);
				break;
			case Enemy_Type::RED_BALL: enemies[i] = new Enemy_RedBall(info.x, info.y, info.wave, info.miem);
				break;
			}
		
			//enemies[i]->destroyedFx = enemyDestroyedFx;
      
			break;
		}
	}
}

void ModuleEnemies::OnCollision(Collider* c1, Collider* c2) {
	for (uint i = 0; i < MAX_ENEMIES; ++i) {
		if (enemies[i] != nullptr && enemies[i]->GetCollider() == c1) {
			enemies[i]->OnCollision(c2); //Notify the enemy of a collision
			break;
		}
	}
}