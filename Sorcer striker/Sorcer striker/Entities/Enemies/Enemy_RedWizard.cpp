#include "Enemy_RedWizard.h"

#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Core/ModuleRender.h"
#include "../../Modules/Gameplay/SceneLevel1.h"
#include "../../Modules/Core/ModuleTextures.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleAudio.h"
#include "../../Modules/Core/ModuleParticles.h"

Enemy_RedWizard::Enemy_RedWizard(int x, int y, int wave) : Enemy(x, y) {
	texture = App->textures->Load(FI_spriteEnemy_reds.c_str());
	//vuelo frente
	fly.PushBack({ 0, 798, 131, 132 });
	fly.PushBack({ 0, 955, 131, 132 });
	currentAnim = &fly;
	fly.speed = 0.2f;
	fly.loop = true;
	//vuelo izquierda
	izquierda.PushBack({ 197, 956, 131, 132 });// giro izquierda inicio
	izquierda.PushBack({ 324, 956, 131, 132 }); //giro izquierda medio
	izquierda.PushBack({ 491, 957, 131, 132 });//giro izquierda final
	izquierda.speed = 0.2f;
	izquierda.loop = false;
	//vuelo derecha
	derecha.PushBack({ 159, 802, 131, 132 });// giro derecha inicio
	derecha.PushBack({ 320, 801, 131, 132 });//giro derecha medio
	derecha.PushBack({ 493, 802, 131, 132 });//giro derecha final
	derecha.speed = 0.2f;
	derecha.loop = false;
	
		if (wave == 1)
		{

			de.PushBack({ 0.0,(float)App->sceneLevel_1->velocitatNivell + 8 }, 20, &fly);
			de.PushBack({ 0.0, (float)App->sceneLevel_1->velocitatNivell }, 120, &fly);
			de.PushBack({ 3,  (float)App->sceneLevel_1->velocitatNivell - 7}, 650, &derecha);

		}
		else if (wave == 2)
		{

			de.PushBack({ 0.0,(float)App->sceneLevel_1->velocitatNivell +8}, 20, &fly);
			de.PushBack({ 0.0, (float)App->sceneLevel_1->velocitatNivell }, 120, &fly);
			de.PushBack({ -3, (float)App->sceneLevel_1->velocitatNivell - 7 }, 650, &izquierda);

		}
		else if (wave == 3)
		{

			de.PushBack({ 0.0,(float)App->sceneLevel_1->velocitatNivell +8}, 20, &fly);
			de.PushBack({ 0.0, (float)App->sceneLevel_1->velocitatNivell }, 120, &fly);
			de.PushBack({ 3, (float)App->sceneLevel_1->velocitatNivell - 7 }, 650, &derecha);

		}
		else if (wave == 4)
		{

			de.PushBack({ 0.0,(float)App->sceneLevel_1->velocitatNivell +8}, 20, &fly);
			de.PushBack({ 0.0, (float)App->sceneLevel_1->velocitatNivell }, 120, &fly);
			de.PushBack({ -3,(float)App->sceneLevel_1->velocitatNivell - 7 }, 650, &izquierda);


		}
		else if (wave == 5)
		{

			de.PushBack({ 0.0, (float)App->sceneLevel_1->velocitatNivell +8 }, 20, &fly);
			de.PushBack({ 0.0, (float)App->sceneLevel_1->velocitatNivell }, 120, &fly);
			de.PushBack({ 3, (float)App->sceneLevel_1->velocitatNivell - 7 }, 650, &derecha);

		}
		if (wave == 6)
		{
			de.PushBack({ 0, (float)App->sceneLevel_1->velocitatNivell * 0}, 25, &fly);
			de.PushBack({ 5, 9 }, 45, &fly);
			de.PushBack({ 0, (float)App->sceneLevel_1->velocitatNivell }, 40, &fly);
			de.PushBack({ -5, -14 }, 100, &izquierda);
	}
		if (wave == 7)
		{
			de.PushBack({ 0, (float)App->sceneLevel_1->velocitatNivell * 0}, 45, &fly);
			de.PushBack({ -5, 9 }, 45, &fly);
			de.PushBack({ 0, (float)App->sceneLevel_1->velocitatNivell }, 40, &fly);
			de.PushBack({ 5, -14 }, 100, &derecha);
		}
	
	
	

	collider = App->collisions->AddCollider({ 0, 0, 131, 132 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_RedWizard::Update() {
	
	

	if (life)
	{
		de.Update();
		position = spawnPos + de.GetRelativePosition();
		currentAnim = de.GetCurrentAnimation();

		if (temp >= 100)
		{
			Particle* fireball = App->particles->AddParticle(App->particles->wizardshoot, position.x + 30, position.y + 65, Collider::Type::ENEMY, 0);
			temp = 0;
		}
		

	}
	
	
	temp++;
	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}


void Enemy_RedWizard::OnCollision(Collider* c1) {
	if (life)
	{
		hitcount++;
		if (hitcount < 3)
		{
			damage.PushBack({ 0, 487, 131, 132 });
			damage.PushBack({ 0, 798, 131, 132 });
			damage.speed = 0.25f;
			currentAnim = &damage;
			App->audio->PlayFx(destroyedFx);
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
			App->player->score += 200;
		}


	}
	
	
}