#include "Enemy_Stageclear.h"

#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Gameplay/ModuleEnemies.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleRender.h"
#include"../../Modules/Core/ModuleTextures.h"


Enemy_Sclear::Enemy_Sclear(int x, int y) : Enemy(x, y) {
	texture = App->textures->Load(FI_imageplayer_kill.c_str());

	blue.PushBack({ 47, 1037, 688, 875 });
	blue.speed = 0.1f;
	currentAnim = &blue;


	// Path 1
	pathchest.PushBack({ 0.0f, -15 }, 10);

	currentPath = &pathchest;


}

void Enemy_Sclear::Update() {

	pathchest.Update();
	position = spawnPos + currentPath->GetRelativePosition();

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position 
	Enemy::Update();

}

void Enemy_Sclear::OnCollision(Collider* c1) {
}

