#include "Boss_BreathDragon.h"

#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Gameplay/ModuleEnemies.h"
#include "../../Modules/Gameplay/SceneLevel1.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleRender.h"
#include"../../Modules/Core/ModuleTextures.h"
#include <SDL_timer.h>


Boss_BreathDragon::Boss_BreathDragon(int x, int y, int wave) : Enemy(x, y) {
	// Set vides
	vides[0] = 15; // Cuerpo 0
	vides[1] = 5; // Cabeza 1
	vides[2] = 5; // Cabeza 2
	vides[3] = 5; // Cabeza 2

	// Reset temporitzadors
	temporitzador_CosDanyat = 0;
	temporitzador_Cap1Danyat = 0;
	temporitzador_Cap2Danyat = 0;
	temporitzador_Cap3Danyat = 0;

	// Load texture
	texturaBoss = App->textures->Load(FI_spriteEnemy_boss.c_str());

	// Load animations and load path
	animationFan.PushBack({ 0, 230, 115, 115 });
	animationFan.PushBack({ 116, 230, 115, 115 });
	animationFan.speed = 0.2;
	animationFan.loop = true;
	pathFan.PushBack({ 0, (float)App->sceneLevel_1->velocitatNivell }, 20, &animationFan);

	animationHead.PushBack({ 0, 502, 180, 180 });
	animationHead.PushBack({ 180 * 2, 502, 180, 180 });
	animationHead.PushBack({ 180 * 4, 502, 180, 180 });
	animationHead.speed = 0.1f;
	animationHead.loop = true;
	pathCabeza.PushBack({ 0,(float)App->sceneLevel_1->velocitatNivell }, 20, &animationHead);

	animationHeadDamaged.PushBack({ 180 * 1, 502, 180, 180 });
	animationHeadDamaged.PushBack({ 180 * 3, 502, 180, 180 });
	animationHeadDamaged.PushBack({ 180 * 5, 502, 180, 180 });
	animationHeadDamaged.speed = 0.1f;
	animationHeadDamaged.loop = true;

	animationBody.PushBack({ 0, 1045, 1200, 400 });
	animationBody.speed = 0.1f;
	animationBody.loop = true;
	pathCuerpo.PushBack({ 0,(float)App->sceneLevel_1->velocitatNivell }, 20, &animationBody);

	// Load particles
	particleFire.anim.PushBack({ 0, 690, 157, 157 });
	particleFire.anim.PushBack({ 157, 690, 157, 157 });
	particleFire.anim.PushBack({ 157 * 2, 690, 157, 157 });
	particleFire.anim.PushBack({ 157 * 3, 690, 157, 157 });
	particleFire.anim.PushBack({ 157 * 4, 690, 157, 157 });
	particleFire.anim.PushBack({ 157 * 5, 690, 157, 157 });
	particleFire.anim.PushBack({ 157 * 6, 690, 157, 157 });
	particleFire.speed = iPoint(0, -12);
	particleFire.anim.speed = 0.05f;
	particleFire.lifetime = 115;

	// Collisions
	colliderCuerpo = App->collisions->AddCollider({ 0, 0, 1200, 200 }, Collider::Type::ENEMY, (Module*)App->enemies);
	colliderCabeza1 = App->collisions->AddCollider({ 0, 0, 110, 150 }, Collider::Type::ENEMY, (Module*)App->enemies);
	colliderCabeza2 = App->collisions->AddCollider({ 0, 0, 110, 150 }, Collider::Type::ENEMY, (Module*)App->enemies);
	colliderCabeza3 = App->collisions->AddCollider({ 0, 0, 110, 150 }, Collider::Type::ENEMY, (Module*)App->enemies);

	start_Time = SDL_GetTicks();
}

void Boss_BreathDragon::Update() {
	// Update path position
	pathFan.Update();
	pathCabeza.Update();
	pathCuerpo.Update();

	// Update animations
	pathFan.GetCurrentAnimation()->Update();
	pathCabeza.GetCurrentAnimation()->Update();
	pathCuerpo.GetCurrentAnimation()->Update();

	// Update object position
	position = spawnPos + pathCuerpo.GetRelativePosition();

	// Update colliders positions
	colliderCuerpo->SetPos(position.x - 600, position.y + 50);
	colliderCabeza1->SetPos(position.x - 270, position.y + 220);
	colliderCabeza2->SetPos(position.x - 50, position.y + 250);
	colliderCabeza3->SetPos(position.x + 165, position.y + 220);


	// Primer atac - EJAMBREEE
	if (SDL_GetTicks() - start_Time >= 1000 && !spawned1) { App->enemies->AddEnemy(Enemy_Type::REDBAT, position.x - 50, position.y, 1); spawned1 = true; }
	if (SDL_GetTicks() - start_Time >= 1500 && !spawned2) { App->enemies->AddEnemy(Enemy_Type::REDBAT, position.x + 50, position.y, 1); spawned2 = true; }
	if (SDL_GetTicks() - start_Time >= 2000 && !spawned3) { App->enemies->AddEnemy(Enemy_Type::REDBAT, position.x - 100, position.y, 1); spawned3 = true; }
	if (SDL_GetTicks() - start_Time >= 2500 && !spawned4) { App->enemies->AddEnemy(Enemy_Type::REDBAT, position.x + 100, position.y, 1); spawned4 = true; }
	if (SDL_GetTicks() - start_Time >= 3000 && !spawned5) { App->enemies->AddEnemy(Enemy_Type::REDBAT, position.x - 150, position.y, 1); spawned5 = true; }
	if (SDL_GetTicks() - start_Time >= 3500 && !spawned6) { App->enemies->AddEnemy(Enemy_Type::REDBAT, position.x + 150, position.y, 1); spawned6 = true; }
	if (SDL_GetTicks() - start_Time >= 4000 && !spawned7) { App->enemies->AddEnemy(Enemy_Type::REDBAT, position.x - 200, position.y, 1); spawned7 = true; }
	if (SDL_GetTicks() - start_Time >= 4500 && !spawned8) { App->enemies->AddEnemy(Enemy_Type::REDBAT, position.x + 200, position.y, 1); spawned8 = true; }

	// Segon atac - FUEEEEGO 
	if (SDL_GetTicks() - start_Time >= 7000)
	{
		// TODO: lanzar particulas de fuego al mismo tiempo que path va para atras y luego para adelante

	}
}

void Boss_BreathDragon::Draw() {

	if (pathCuerpo.GetCurrentAnimation() != nullptr) {
		App->render->Blit(texturaBoss, position.x - 600, position.y, &(pathCuerpo.GetCurrentAnimation()->GetCurrentFrame()));
	}

	if (pathCabeza.GetCurrentAnimation() != nullptr) {
		App->render->Blit(texturaBoss, position.x - 300, position.y + 200, &(pathCabeza.GetCurrentAnimation()->GetCurrentFrame()));
		App->render->Blit(texturaBoss, position.x - 85, position.y + 230, &(pathCabeza.GetCurrentAnimation()->GetCurrentFrame()));
		App->render->Blit(texturaBoss, position.x + 130, position.y + 200, &(pathCabeza.GetCurrentAnimation()->GetCurrentFrame()));
	}

	if (pathFan.GetCurrentAnimation() != nullptr) {
		App->render->Blit(texturaBoss, position.x - 400, position.y + 250, &(pathFan.GetCurrentAnimation()->GetCurrentFrame()));
		App->render->Blit(texturaBoss, position.x - 150, position.y + 200, &(pathFan.GetCurrentAnimation()->GetCurrentFrame()));
		App->render->Blit(texturaBoss, position.x + 40, position.y + 200, &(pathFan.GetCurrentAnimation()->GetCurrentFrame()));
		App->render->Blit(texturaBoss, position.x + 270, position.y + 230, &(pathFan.GetCurrentAnimation()->GetCurrentFrame()));
	}
}

void Boss_BreathDragon::SetToDelete() {
	/*pendingToDelete = true;

	if (collider != nullptr)
		collider->pendingToDelete = true;*/
}

void Boss_BreathDragon::OnCollisionGeneral(Collider* c1) {
	if (c1->type == Collider::Type::PLAYER_SHOT)
	{
		// Si cuerpo tiene 0 vidas muere || las tres cabezas tienen 0 vidas muere
		if ((vides[0] <= 0) || (vides[1] <= 0 && vides[2] <= 0 && vides[3] <= 0))
			this->SetToDelete();
		else
			vides[0] -= 1;
	}
}

void Boss_BreathDragon::OnCollisionHead1(Collider* c1) {
	if (c1->type == Collider::Type::PLAYER_SHOT && !headDestroy)
	{
		if ((vides[0] <= 0) || (vides[1] <= 0 && vides[2] <= 0 && vides[3] <= 0))
			this->SetToDelete();
		else {
			if (vides[1] <= 0) headDestroy = true;
			else vides[1] -= 1;
		}
	}
}

void Boss_BreathDragon::OnCollisionHead2(Collider* c1) {
	if (c1->type == Collider::Type::PLAYER_SHOT && !headDestroy2) {

		if ((vides[0] <= 0) || (vides[1] <= 0 && vides[2] <= 0 && vides[3] <= 0))
			this->SetToDelete();
		else {
			if (vides[2] <= 0) headDestroy2 = true;
			else vides[2] -= 1;
		}
	}
}

void Boss_BreathDragon::OnCollisionHead3(Collider* c1)
{
	if (c1->type == Collider::Type::PLAYER_SHOT && !headDestroy3) {

		if ((vides[0] <= 0) || (vides[1] <= 0 && vides[2] <= 0 && vides[3] <= 0))
			this->SetToDelete();
		else {
			if (vides[3] <= 0) headDestroy3 = true;
			else vides[3] -= 1;
		}
	}
}
