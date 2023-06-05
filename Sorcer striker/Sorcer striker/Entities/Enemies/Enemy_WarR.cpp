#include "Enemy_WarR.h"

#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Gameplay/ModuleEnemies.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleRender.h"
#include"../../Modules/Core/ModuleTextures.h"
#include"../../Modules/Core/ModuleAudio.h"


Enemy_WarnR::Enemy_WarnR(int x, int y) : Enemy(x, y) {
	texture = App->textures->Load(FI_spriteEnemy_boss.c_str());

	blue.PushBack({ 314, 0, 484, 77 });
	blue.PushBack({ 314, 75, 484, 77 });
	blue.speed = 0.1f;
	currentAnim = &blue;
	App->audio->PlayMusic(FA_Music_Boss1.c_str(), 1.0f);

	// Path 1
	pathchest.PushBack({ 0.0, -8 }, 40);
	pathchest.PushBack({ 0.0, -15 }, 100);
	pathchest.PushBack({ 6.0, -8 }, 400);

	currentPath = &pathchest;


}

void Enemy_WarnR::Update() {

	pathchest.Update();
	position = spawnPos + currentPath->GetRelativePosition();

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position 
	Enemy::Update();

}

void Enemy_WarnR::OnCollision(Collider* c1) {
}

