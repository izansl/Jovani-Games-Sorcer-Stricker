#include "Enemy_BigTank.h"
#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Core/ModuleRender.h"
#include "../../Modules/Gameplay/SceneLevel1.h"
#include "../../Modules/Core/ModuleTextures.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleAudio.h"

Enemy_BigTank::Enemy_BigTank(int x, int y, int wave) : Enemy(x, y) {
	texture = App->textures->Load(FI_spriteEnemy_enemiesvar_1.c_str());
	de.PushBack({ 1627, 562, 277, 168 });
	currentAnim = &de;
	de.speed = 0.2;
	de.loop = true;
	
	iz.PushBack({ 2012, 115, 277, 168 });
	iz.speed = 1;
	iz.loop = true;

	if (wave == 1)
	{
		path.PushBack({5, (float)App->sceneLevel_1->velocitatNivell * 0}, 40, &de);
	}
	if (wave == 2)
	{
		path.PushBack({ 5, (float)App->sceneLevel_1->velocitatNivell * 0}, 30, &de);
		path.PushBack({ 0, (float)App->sceneLevel_1->velocitatNivell * 0 }, 200, &de);
		path.PushBack({ 5, (float)App->sceneLevel_1->velocitatNivell * 0 }, 300, &de);

	}
	if (wave == 3)
	{
		path.PushBack({ -5, (float)App->sceneLevel_1->velocitatNivell * 0}, 30,&iz);
		path.PushBack({ 0, (float)App->sceneLevel_1->velocitatNivell * 0 }, 200, &de);
		path.PushBack({ -5, (float)App->sceneLevel_1->velocitatNivell * 0 }, 300, &de);
	}




	collider = App->collisions->AddCollider({ 0, 0,277, 168 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_BigTank::Update() {


	if (life)
	{
		path.Update();
		position = spawnPos + path.GetRelativePosition();
		currentAnim = path.GetCurrentAnimation();

		if (temp >= 120)
		{
			Particle* fireball = App->particles->AddParticle(App->particles->minifireshottank, position.x + 83, position.y + 88, Collider::Type::ENEMY_SHOOT, 0);
			Particle* fireball2 = App->particles->AddParticle(App->particles->minifireshottank, position.x + 226, position.y + 88, Collider::Type::ENEMY_SHOOT, 0);

			temp = 0;
		}
		temp++;
	}
	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
//
void Enemy_BigTank::OnCollision(Collider* c1) {
	if (life)
	{
		hitcount++;
		if (hitcount < 6)
		{
			damage.PushBack({ 350, 38, 279, 275 });
			damage.PushBack({ 54, 38, 279, 275 });
			damage.speed = 0.25f;
			currentAnim = &damage;
			collider = App->collisions->AddCollider({ 0, 0,277, 168 }, Collider::Type::ENEMY, (Module*)App->enemies);
		}
		else {
			texture = App->textures->Load(FI_particles_.c_str());
			death.PushBack({ 145, 651, 329, 333 });
			death.PushBack({ 1293, 493, 329, 333 });
			death.PushBack({ 53, 157, 329, 333 });
			death.PushBack({ 1299, 485, 329, 333 });
			death.PushBack({ 0, 0, 0, 0 });
			death.speed = 0.3f;
			death.loop = false;
			App->audio->PlayFx(destroyedFx);
			currentAnim = &death;
			life = false;
			App->player->score += 500;
		}


	}
}
