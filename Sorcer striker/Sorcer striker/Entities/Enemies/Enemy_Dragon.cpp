#include "Enemy_Dragon.h"

#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Core/ModuleRender.h"
#include "../../Modules/Core/ModuleTextures.h"
#include "../../Modules/Gameplay/SceneLevel1.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleAudio.h"

Enemy_Dragon::Enemy_Dragon(int x, int y, int wave) : Enemy(x, y) {
	texture = App->textures->Load(FI_spriteEnemy_dragon.c_str());

	fly.PushBack({ 1121, 1503 , 381, 451 });
	fly.PushBack({ 1579, 1503 , 381, 451 });
	fly.PushBack({ 2041, 1503 , 381, 451 });
	fly.PushBack({ 1579, 1503 , 381, 451 });
	fly.PushBack({ 1121, 1503 , 381, 451 });
	fly.PushBack({ 659, 1503 , 381, 451 });
	fly.PushBack({ 201, 1503 , 381, 451 });
	fly.loop = true;
	currentAnim = &fly;
	fly.speed = 0.1f;
	if (wave == 1)
	{
		
			path.PushBack({ 0, (float)App->sceneLevel_1->velocitatNivell + 5 }, 30);
			path.PushBack({ 0, (float)App->sceneLevel_1->velocitatNivell }, 150);
			path.PushBack({ 2, (float)App->sceneLevel_1->velocitatNivell }, 10);
			path.PushBack({ 0,(float)App->sceneLevel_1->velocitatNivell }, 70);
			path.PushBack({ -0.75,(float)App->sceneLevel_1->velocitatNivell - 2 }, 50);
			path.PushBack({ 0, (float)App->sceneLevel_1->velocitatNivell }, 30);
			path.PushBack({ 0, (float)App->sceneLevel_1->velocitatNivell + 4 }, 50);
			path.PushBack({ -2, (float)App->sceneLevel_1->velocitatNivell - 4 }, 400);
	
		

	}
	else if (wave == 2)
	{
		
			
		path.PushBack({ 0, (float)App->sceneLevel_1->velocitatNivell + 5 }, 30);
		path.PushBack({ 0, (float)App->sceneLevel_1->velocitatNivell }, 150);
		path.PushBack({ 2, (float)App->sceneLevel_1->velocitatNivell }, 10);
		path.PushBack({ 0,(float)App->sceneLevel_1->velocitatNivell }, 70);
		path.PushBack({ -0.75,(float)App->sceneLevel_1->velocitatNivell - 2 }, 50);
		path.PushBack({ 0, (float)App->sceneLevel_1->velocitatNivell }, 30);
		path.PushBack({ 0, (float)App->sceneLevel_1->velocitatNivell + 4 }, 50);
		path.PushBack({ -2, (float)App->sceneLevel_1->velocitatNivell - 4 }, 400);
		
	}
	
	

	collider = App->collisions->AddCollider({ 0, 0, 381, 451 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_Dragon::Update() {
		
	if (vida)
	{
		path.Update();
		position = spawnPos + path.GetRelativePosition();
		if (temp >= 150)
		{
			Particle* fireball = App->particles->AddParticle(App->particles->minifireshot, position.x + 119, position.y + 278, Collider::Type::ENEMY, 0);
			Particle* fireball2 = App->particles->AddParticle(App->particles->minifireshot, position.x + 254, position.y + 280, Collider::Type::ENEMY, 0);
			Particle* fireball3 = App->particles->AddParticle(App->particles->minifireshot, position.x + 132, position.y + 244, Collider::Type::ENEMY, 0);
			Particle* fireball4 = App->particles->AddParticle(App->particles->minifireshot, position.x + 238, position.y + 244, Collider::Type::ENEMY, 0);



			temp = 0;
		}
		temp++;
	}

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}

void Enemy_Dragon::OnCollision(Collider* c1) {	
	if (vida)
	{
	hitcount++;
	if (hitcount < 6)
		if (hitcount > 6)
		{
			damage.PushBack({ 1121, 1503 , 381, 451 });
			damage.PushBack({ 1121, 869 , 381, 451 });
			damage.PushBack({ 1579, 1503 , 381, 451 });
			damage.PushBack({ 1579, 869 , 381, 451 });
			damage.PushBack({ 1121, 1503 , 381, 451 });
			damage.PushBack({ 1121, 869 , 381, 451 });
			damage.PushBack({ 659, 1503 , 381, 451 });
			damage.PushBack({ 659, 869 , 381, 451 });
			damage.speed = 0.25f;
			damage.loop = true;
			currentAnim = &damage;
			collider = App->collisions->AddCollider({ 0, 0, 381, 451 }, Collider::Type::ENEMY, (Module*)App->enemies);
		}
		else {
			death.PushBack({ 973, 339, 331, 329 });
			death.PushBack({ 1405, 339, 331, 329 });
			death.PushBack({ 1789, 339, 331, 329 });
			death.PushBack({ 973, 339, 331, 329 });
			death.PushBack({ 1405, 339, 331, 329 });
			death.PushBack({ 1789, 339, 331, 329 });
			death.PushBack({ 0, 0, 0, 0 });
			death.speed = 0.3f;
			death.loop = false;
			App->audio->PlayFx(destroyedFx);
			currentAnim = &death;
			vida = false;
			App->player->score += 1000;
			
		}
	}

}
	