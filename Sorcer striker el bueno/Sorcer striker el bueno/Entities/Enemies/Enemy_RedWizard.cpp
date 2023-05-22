#include "Enemy_RedWizard.h"

#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Core/ModuleRender.h"
#include "../../Modules/Core/ModuleTextures.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleAudio.h"
#include "../../Modules/Core/ModuleParticles.h"

Enemy_RedWizard::Enemy_RedWizard(int x, int y, int wave, int miem) : Enemy(x, y) {
	texture = App->textures->Load(FI_spriteEnemy_reds.c_str());
	
	fly.PushBack({ 0, 798, 131, 132 });
	fly.PushBack({ 0, 955, 131, 132 });
	currentAnim = &fly;
	fly.speed = 0.01f;
	fly.loop = true;
	
	

	if (wave == 1)
	{
		if (miem == 0)
		{
			path.PushBack({ 0.0, -0.25 }, 720);
			path.PushBack({ 0.0, -8.0 }, 120);
			path.PushBack({ 3, -12.0 }, 650);
		}
	}
	else if (wave == 2)
	{
		if (miem == 0)
		{
			path.PushBack({ 0.0, -0.5}, 835);
			path.PushBack({ 0.0, -8.0 }, 120);
			path.PushBack({ -3, -12.0 }, 650);
		}
	}
	else if (wave == 3)
	{
		if (miem == 0)
		{
			path.PushBack({ 0.0, -0.5}, 950);
			path.PushBack({ 0.0, -8.0 }, 120);
			path.PushBack({ 3, -12.0 }, 650);
		}
	}
	else if (wave == 4)
	{
		if (miem == 0)
		{
			path.PushBack({ 0.0, -0.5 }, 1040);
			path.PushBack({ 0.0, -8.0 }, 120);
			path.PushBack({ -3, -12.0 }, 650);
		}
		
	}
	else if (wave == 5)
	{
		if (miem == 0)
		{
			path.PushBack({ 0.0, -0.5 }, 1140);
			path.PushBack({ 0.0, -8.0 }, 120);
			path.PushBack({ 3, -12.0 }, 650);
		}
		
	}
	
	

	collider = App->collisions->AddCollider({ 0, 0, 36, 36 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_RedWizard::Update() {
	path.Update();
	position = spawnPos + path.GetRelativePosition();

	if (temp >= 30)
	{
		Particle* fireball = App->particles->AddParticle(App->particles->wizardshoot, position.x, position.y, Collider::Type::ENEMY_SHOOT, 0) ;
			/*if (fireball == nullptr)
			{

			}*/
	}
	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}


void Enemy_RedWizard::OnCollision(Collider* c1) {
	fly.PushBack({ 3, 71, 36, 36 });
	fly.PushBack({ 39, 72, 36, 36 });
	fly.PushBack({ 75, 72, 36, 36 });
	fly.PushBack({ 111, 71, 36, 36 });
	fly.PushBack({ 111, 120, 36, 36 });

	currentAnim = &fly;
	fly.speed = 0.2;
	fly.loop = false;
}