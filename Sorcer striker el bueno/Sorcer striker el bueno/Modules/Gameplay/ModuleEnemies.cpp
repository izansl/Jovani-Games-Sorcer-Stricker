#include "ModuleEnemies.h"

#include "../../Application/Application.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleRender.h"
#include "../../Modules/Core/ModuleTextures.h"
#include "../../Modules/Core/ModuleAudio.h"

#include "../../Entities/Enemies/Enemy.h"
#include "../../Entities/Enemies/Enemy_CHESTBLUE.h"
#include "../../Entities/Enemies/Enemy_Bluebook.h"
#include "../../Entities/Enemies/Enemy_Dragon.h"
#include "../../Entities/Enemies/Enemy_RedWizard.h"
#include "../../Entities/Enemies/Enemy_RedBall.h"
#include "../../Entities/Enemies/Enemy_Tank.h"
#include "../../Entities/Enemies/Enemy_RedChess.h"
#include "../../Entities/Enemies/Enemy_RedBook.h"
#include "../../Entities/Enemies/Enemy_GreenChess.h"
#include "../../Entities/Enemies/Enemy_GreenBook.h"
#include "../../Entities/Enemies/Enemy_Turtle.h"
#include "../../Entities/Enemies/Enemy_MiniDragon.h"
#include "../../Entities/Enemies/Enemy_Bomb.h"
#include "../../Entities/Enemies/Enemy_Gold.h"
#include "../../Entities/Enemies/Enemy_Coin.h"
#include "../../Entities/Enemies/Enemy_FlyTank.h"
#include "../../Entities/Enemies/Enemy_RedBat.h"
#include "../../Entities/Enemies/Enemy_Angel.h"

#define SPAWN_MARGIN 100


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

bool ModuleEnemies::AddEnemy(Enemy_Type type, int x, int y, int wave)
{
	bool ret = false;

	for (uint i = 0; i < MAX_ENEMIES; ++i) {
		if (spawnQueue[i].type == Enemy_Type::NO_TYPE) {
			spawnQueue[i].type = type;
			spawnQueue[i].x = x;
			spawnQueue[i].y = y;
			spawnQueue[i].wave = wave;
			
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
			if (spawnQueue[i].y > App->render->camera.y) {
				//LOG("Spawning enemy at %d", spawnQueue[i].x * SCREEN_SIZE);

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
				//LOG("DeSpawning enemy at %d", enemies[i]->position.x * SCREEN_SIZE);

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
			//Props
			//Blue
			case Enemy_Type::CHESTBLUE: 
				enemies[i] = new Enemy_CHESS(info.x, info.y); 
				break;
			case Enemy_Type::Bluebook:
				enemies[i] = new Enemy_Bluebook(info.x, info.y);
				break;
			//Green
			case Enemy_Type::CHEST_GREEN:
				enemies[i] = new Enemy_GreenChess(info.x, info.y);
				break;
			case Enemy_Type::Greenbook:
				enemies[i] = new Enemy_GreenBook(info.x, info.y);
				break;
			//Red
			case Enemy_Type::CHEST_RED:
				enemies[i] = new Enemy_RedChess(info.x, info.y);
				break;
			case Enemy_Type::Redbook:
				enemies[i] = new Enemy_Redbook(info.x, info.y);
				break;
			//Angel
			case Enemy_Type::ANGEL:
				enemies[i] = new Enemy_Angel(info.x, info.y);
				break;
			//Bomb
			case Enemy_Type::BOMB:
				enemies[i] = new Enemy_BOMB(info.x, info.y);
				break;
			//Gold
			case Enemy_Type::GOLD:
				enemies[i] = new Enemy_Gold(info.x, info.y);
				break;
			case Enemy_Type::COIN:
				enemies[i] = new Enemy_Coin(info.x, info.y);
				break;

			//Enemies
			case Enemy_Type::DRAGON: enemies[i] = new Enemy_Dragon(info.x, info.y, info.wave);
				break;
			case Enemy_Type::REDWIZARD: enemies[i] = new Enemy_RedWizard(info.x, info.y, info.wave);
				break;
			case Enemy_Type::RED_BALL: enemies[i] = new Enemy_RedBall(info.x, info.y, info.wave);
				break;
			case Enemy_Type::TANK: enemies[i] = new Enemy_Tank(info.x, info.y, info.wave);
				break;
			case Enemy_Type::TURTLE: enemies[i] = new Enemy_Turtle(info.x, info.y, info.wave);
				break;
			case Enemy_Type::MINIDRAGON: enemies[i] = new Enemy_MiniDragon(info.x, info.y, info.wave);
				break;
			case Enemy_Type::FLYTANK: enemies[i] = new Enemy_FlyTank(info.x, info.y, info.wave);
				break;
			case Enemy_Type::REDBAT: enemies[i] = new Enemy_RedBat(info.x, info.y, info.wave);
				break;
			}
			

			enemies[i]->destroyedFx = enemyDestroyedFx;
      
			break;
		}
	}
}

void ModuleEnemies::OnCollision(Collider* c1, Collider* c2) {
	for (uint i = 0; i < MAX_ENEMIES; ++i) {
		if (enemies[i] != nullptr && enemies[i]->GetCollider() == c1) {
			enemies[i]->OnCollision(c2); //Notify the enemy of a collision
			c1->pendingToDelete = true;
			/*if (c2->type == Collider::Type::PLAYER_SHOT)
			{

				delete enemies[i];
				enemies[i] = nullptr;
			}*/
			break;
		}
	}
}