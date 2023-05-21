#include "Enemy_GreenChess.h"

#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Gameplay/ModuleEnemies.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleRender.h"
#include"../../Modules/Core/ModuleTextures.h"


Enemy_GreenChess::Enemy_GreenChess(int x, int y) : Enemy(x, y) {
	texture = App->textures->Load(FI_spritebonus_pickups.c_str());

	green.PushBack({ 15, 25, 118, 99 });
	green.PushBack({ 132, 20, 118, 99 });
	green.PushBack({ 260, 17, 118, 99 });
	green.speed = 0.05f;
	currentAnim = &green;

	

	
	collider = App->collisions->AddCollider({ 0, 0, 118, 99 }, Collider::Type::CHEST, (Module*)App->enemies);
}

void Enemy_GreenChess::Update() {

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

void Enemy_GreenChess::OnCollision(Collider* c1) {
	
}