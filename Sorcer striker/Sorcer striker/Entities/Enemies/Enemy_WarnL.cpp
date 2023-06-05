#include "Enemy_WarnL.h"

#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Gameplay/ModuleEnemies.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleRender.h"
#include"../../Modules/Core/ModuleTextures.h"


Enemy_WarnL::Enemy_WarnL(int x, int y) : Enemy(x, y) {
	texture = App->textures->Load(FI_spriteEnemy_boss.c_str());

	blue.PushBack({ 0, 0, 296, 75 });
	blue.PushBack({ 0, 80, 296, 75 });
	blue.speed = 0.1f;
	currentAnim = &blue;


	// Path 1
	path.PushBack({0.0, -8}, 40);
	path.PushBack({ 0.0, -15 }, 100);
	path.PushBack({ -6.0, -8 }, 400);

	currentPath = &path;


}

void Enemy_WarnL::Update() {

	path.Update();
	position = spawnPos + currentPath->GetRelativePosition();

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position 
	Enemy::Update();

}

void Enemy_WarnL::OnCollision(Collider* c1) {
}
