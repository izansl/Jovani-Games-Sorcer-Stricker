#include "Enemy_Turtle.h"
#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Gameplay/ModuleEnemies.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleRender.h"
#include"../../Modules/Core/ModuleTextures.h"
#include"../../Modules/Core/ModuleAudio.h"

Enemy_Turtle::Enemy_Turtle(int x, int y, int wave) : Enemy(x, y) {
	texture = App->textures->Load(FI_spriteEnemy_enemiesvar_1.c_str());
	fly.PushBack({ 15, 498, 196, 167 });
	fly.PushBack({ 252, 498, 196, 167 });
	fly.PushBack({ 488, 498, 196, 167 });
	fly.PushBack({ 722, 498, 196, 167 });
	fly.PushBack({ 956, 498, 196, 167 });
	fly.PushBack({ 1170, 498, 196, 167 });
	fly.PushBack({ 1380, 498, 196, 167 });
	currentAnim = &fly;
	fly.speed = 0.075;
	fly.loop = false;

	if (wave == 1)
	{
		path.PushBack({ 3, -0 }, 60);
		path.PushBack({ 0, -0 }, 200);
	}
	if (wave == 2)
	{
		path.PushBack({ 0, 0 }, 100);
	}
	

	collider = App->collisions->AddCollider({ 0, 0, 196, 167 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_Turtle::Update() {
	
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
void Enemy_Turtle::OnCollision(Collider* c1) {
	if (life)
	{
		hitcount++;
		if (hitcount < 5)
		{
			damage.PushBack({ 14, 764, 198, 167});
			damage.PushBack({ 252, 498, 196, 167 });
			damage.PushBack({ 490, 764, 198, 167 });
			damage.PushBack({ 722, 498, 196, 167 });
			damage.speed = 0.25f;
			currentAnim = &damage;
			collider = App->collisions->AddCollider({ 0, 0,133, 128 }, Collider::Type::ENEMY, (Module*)App->enemies);
		}

		else {

			death.PushBack({ 350, 38, 133, 128 });
			currentAnim = &death;
			death.speed = 0.2;
			death.loop = false;
			App->audio->PlayFx(destroyedFx);
			life = false;

		}


	}
}