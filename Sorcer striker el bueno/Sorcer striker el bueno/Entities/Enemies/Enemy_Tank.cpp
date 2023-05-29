#include "Enemy_Tank.h"
#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Gameplay/ModuleEnemies.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleRender.h"
#include"../../Modules/Core/ModuleTextures.h"
#include"../../Modules/Core/ModuleAudio.h"

Enemy_Tank::Enemy_Tank(int x, int y, int wave) : Enemy(x, y) {
	texture = App->textures->Load(FI_spriteEnemy_tank.c_str());
	fly.PushBack({ 634, 935, 133, 128 });
	currentAnim = &fly;
	fly.speed = 0.2;
	fly.loop = true;
	if (wave == 1)
	{
		path.PushBack({4, -6}, 100);
	}


	collider = App->collisions->AddCollider({ 0, 0,133, 128 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_Tank::Update() {
	

	if (life)
	{
		path.Update();
		position = spawnPos + path.GetRelativePosition();
	}
	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
//
void Enemy_Tank::OnCollision(Collider* c1) {
	if (life)
	{
		hitcount++;
		if (hitcount < 3)
		{
			damage.PushBack({ 0, 487, 131, 132 });
			damage.PushBack({ 0, 798, 131, 132 });
			damage.speed = 0.25f;
			currentAnim = &damage;
			collider = App->collisions->AddCollider({ 0, 0,131, 132 }, Collider::Type::ENEMY, (Module*)App->enemies);
		}
		else {

			fly.PushBack({ 1, 136, 139, 137 });
			fly.PushBack({ 155, 140, 139, 137 });
			fly.PushBack({ 335, 142, 139, 137 });
			fly.PushBack({ 586, 139, 139, 137 });
			fly.PushBack({ 644, 142, 139, 137 });
			fly.PushBack({ 798, 142, 139, 137 });
			fly.PushBack({ 1000, 400, 139, 137 });

			currentAnim = &fly;
			fly.speed = 0.2;
			fly.loop = false;
			App->audio->PlayFx(destroyedFx);
			life = false;

		}


	}
	
}