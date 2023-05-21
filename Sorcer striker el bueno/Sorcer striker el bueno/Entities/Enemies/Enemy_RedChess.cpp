#include "Enemy_RedChess.h"

#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Gameplay/ModuleEnemies.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleRender.h"
#include"../../Modules/Core/ModuleTextures.h"

Enemy_RedChess::Enemy_RedChess(int x, int y) : Enemy(x, y) {
	texture = App->textures->Load(FI_spritebonus_pickups.c_str());

	red.PushBack({ 17, 501, 118, 99 });
	red.PushBack({ 135, 498, 118, 99 });
	red.PushBack({ 258, 493, 118, 99 });
	red.speed = 0.05f;
	currentAnim = &red;




	collider = App->collisions->AddCollider({ 0, 0, 118, 99 }, Collider::Type::CHEST, (Module*)App->enemies);
}

void Enemy_RedChess::Update() {

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

void Enemy_RedChess::OnCollision(Collider* c1) {

}