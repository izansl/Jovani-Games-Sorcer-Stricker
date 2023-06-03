#include "Enemy_FlyTank.h"
#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Gameplay/ModuleEnemies.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleRender.h"
#include"../../Modules/Core/ModuleTextures.h"
#include"../../Modules/Core/ModuleAudio.h"

Enemy_FlyTank::Enemy_FlyTank(int x, int y, int wave) : Enemy(x, y) {
	texture = App->textures->Load(FI_spriteEnemy_enemiesvar_1.c_str());
	fly.PushBack({ 54, 38, 279, 275 });
	currentAnim = &fly;
	
	if (wave == 1)
	{
		path.PushBack({ 0, -2 }, 20);
		path.PushBack({ 2, -8 }, 200);
		path.PushBack({ -2, -8 }, 200);

	}



	collider = App->collisions->AddCollider({ 0, 0,279, 275 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_FlyTank::Update() {
	
	if(life)
	{
		path.Update();
		position = spawnPos + path.GetRelativePosition();
	}
	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
//
void Enemy_FlyTank::OnCollision(Collider* c1) {
	if (life)
	{
		hitcount++;
			if (hitcount < 6)
			{
				damage.PushBack({ 350, 38, 279, 275 });
				damage.PushBack({ 54, 38, 279, 275 });
				damage.speed = 0.25f;
				currentAnim = &damage;
				collider = App->collisions->AddCollider({ 0, 0,279, 275 }, Collider::Type::ENEMY, (Module*)App->enemies);
			}
			else {
				texture = App->textures->Load(FI_particles_.c_str());
				death.PushBack({ 1293, 485, 329, 333 });
				death.PushBack({ 151, 641, 329, 333 });
				death.PushBack({ 57, 163, 329, 333 });
				death.PushBack({ 1299, 487, 329, 333 });
				death.PushBack({ 735, 863, 329, 333 });
				death.PushBack({ 0, 0, 0, 0 });
				death.speed = 0.3f;
				death.loop = false;
				App->audio->PlayFx(destroyedFx);
				currentAnim = &death;
				life = false;

			}
		

	}
	
	
	
}
