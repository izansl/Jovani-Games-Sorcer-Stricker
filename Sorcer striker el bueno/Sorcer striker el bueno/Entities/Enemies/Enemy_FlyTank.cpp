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
	fly.PushBack({ 17, 5, 279, 275 });
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
				damage.PushBack({ 317, 7, 279, 275 });
				damage.PushBack({ 17, 5, 279, 275 });
				damage.speed = 0.25f;
				currentAnim = &damage;
				collider = App->collisions->AddCollider({ 0, 0,279, 275 }, Collider::Type::ENEMY, (Module*)App->enemies);
			}
			else {
				death.PushBack({ 195, 935, 329, 333 });
				death.PushBack({ 373, 657, 329, 333 });
				death.PushBack({ 281, 173, 329, 333 });
				death.PushBack({ 1525, 499, 329, 333 });
				death.PushBack({ 837, 499, 329, 333 });
				death.PushBack({ 0, 0, 0, 0 });
				death.speed = 0.3f;
				death.loop = false;
				App->audio->PlayFx(destroyedFx);
				currentAnim = &death;
				life = false;

			}
		

	}
	
	
	
}
