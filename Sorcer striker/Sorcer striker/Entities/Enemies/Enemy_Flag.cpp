#include "Enemy_Flag.h"

#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Gameplay/ModuleEnemies.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleRender.h"
#include"../../Modules/Core/ModuleTextures.h"


Enemy_Flag::Enemy_Flag(int x, int y) : Enemy(x, y) {
	texture = App->textures->Load(FI_HUD_stage1.c_str());

	blue.PushBack({ 144, 328, 350, 124 });
	blue.speed = 0.1f;
	currentAnim = &blue;


	// Path 1
	pathchest.PushBack({ 0.0f, -8.0f }, 30);
	pathchest.PushBack({ -6.0f, -15.0f }, 42);
	pathchest.PushBack({ 0.0f, -15.0f }, 40);
	pathchest.PushBack({ 12.0f, -15.0f }, 300);

	currentPath = &pathchest;

}

void Enemy_Flag::Update() {

	pathchest.Update();
	position = spawnPos + currentPath->GetRelativePosition();

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position 
	Enemy::Update();

}

void Enemy_Flag::OnCollision(Collider* c1) {
}
