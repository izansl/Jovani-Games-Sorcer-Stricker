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
	pathFan.PushBack({ 1.0 ,(float)App->sceneLevel_1->velocitatNivell + 3 }, 10, &animationFan);
	pathFan.PushBack({ -1.0 ,(float)App->sceneLevel_1->velocitatNivell + 3 }, 30, &animationFan);
	pathFan.PushBack({ 1.0,(float)App->sceneLevel_1->velocitatNivell +2 }, 10, &animationFan);
	pathFan.PushBack({ -1.0,(float)App->sceneLevel_1->velocitatNivell - 2 }, 10, &animationFan);
	pathFan.PushBack({ 1.0,(float)App->sceneLevel_1->velocitatNivell - 3 }, 30, &animationFan);
	pathFan.PushBack({ -1.0,(float)App->sceneLevel_1->velocitatNivell - 3 }, 10, &animationFan);
	pathFan.PushBack({ 0,(float)App->sceneLevel_1->velocitatNivell + 3 }, 10, &animationFan);
	

	animationHead.PushBack({ 0, 502, 180, 180 });
	animationHead.PushBack({ 180 * 2, 502, 180, 180 });
	animationHead.PushBack({ 180 * 4, 502, 180, 180 });
	animationHead.speed = 0.1f;
	animationHead.loop = true;

	pathCabeza.PushBack({ 0, (float)App->sceneLevel_1->velocitatNivell }, 20, &animationHead);
	pathCabeza.PushBack({ 1.0 ,(float)App->sceneLevel_1->velocitatNivell + 3 }, 10, &animationHead);
	pathCabeza.PushBack({ -1.0 ,(float)App->sceneLevel_1->velocitatNivell + 3 }, 30, &animationHead);
	pathCabeza.PushBack({ 1.0,(float)App->sceneLevel_1->velocitatNivell + 2 }, 10, &animationHead);
	pathCabeza.PushBack({ -1.0,(float)App->sceneLevel_1->velocitatNivell - 2 }, 10, &animationHead);
	pathCabeza.PushBack({ 1.0,(float)App->sceneLevel_1->velocitatNivell - 3 }, 30, &animationHead);
	pathCabeza.PushBack({ -1.0,(float)App->sceneLevel_1->velocitatNivell - 3 }, 10, &animationHead);
	pathCabeza.PushBack({ 0,(float)App->sceneLevel_1->velocitatNivell  + 3 }, 10, &animationHead);

	animationHeadDamaged.PushBack({ 180 * 1, 502, 180, 180 });
	animationHeadDamaged.PushBack({ 180 * 3, 502, 180, 180 });
	animationHeadDamaged.PushBack({ 180 * 5, 502, 180, 180 });
	animationHeadDamaged.speed = 0.1f;
	animationHeadDamaged.loop = true;

	animationBody.PushBack({ 0, 1045, 1200, 400 });
	animationBody.speed = 0.1f;
	animationBody.loop = true;
	pathCuerpo.PushBack({ 0, (float)App->sceneLevel_1->velocitatNivell }, 20, &animationBody);
	pathCuerpo.PushBack({ 1.0 ,(float)App->sceneLevel_1->velocitatNivell + 3 }, 10, &animationBody);
	pathCuerpo.PushBack({ -1.0 ,(float)App->sceneLevel_1->velocitatNivell + 3 }, 30, &animationBody);
	pathCuerpo.PushBack({ 1.0,(float)App->sceneLevel_1->velocitatNivell + 2 }, 10, &animationBody);
	pathCuerpo.PushBack({ -1.0,(float)App->sceneLevel_1->velocitatNivell - 2 }, 10, &animationBody);
	pathCuerpo.PushBack({ 1.0,(float)App->sceneLevel_1->velocitatNivell - 3 }, 30, &animationBody);
	pathCuerpo.PushBack({ -1.0,(float)App->sceneLevel_1->velocitatNivell - 3 }, 10, &animationBody);
	pathCuerpo.PushBack({ 0,(float)App->sceneLevel_1->velocitatNivell + 3 }, 10, &animationBody);

	// Load particles
	particleFire.anim.PushBack({ 2674, 843, 157, 157 });
	particleFire.anim.PushBack({ 2837, 843, 157, 157 });
	particleFire.anim.PushBack({ 2986, 843, 157, 157 });
	particleFire.anim.PushBack({ 2640, 1122, 157, 157 });
	particleFire.anim.PushBack({ 2791, 1122, 157, 157 });
	particleFire.anim.PushBack({ 2951, 1117, 157, 157 });
	particleFire.anim.PushBack({ 3111, 1113, 157, 157 });
	particleFire.speed = iPoint(0, -10);
	particleFire.anim.speed = 0.25f;
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
	if (SDL_GetTicks() - start_Time >= 7000 && canshoot1)
	{
		// TODO: lanzar particulas de fuego al mismo tiempo que path va para atras y luego para adelante
		
		Particle* fuego = App->particles->AddParticle(particleFire, position.x + 200, position.y + 381, Collider::Type::ENEMY, 0);
		Particle* fuego2 = App->particles->AddParticle(particleFire, position.x + -20, position.y + 350, Collider::Type::ENEMY, 0);
		Particle* fuego3 = App->particles->AddParticle(particleFire, position.x + -300, position.y + 381, Collider::Type::ENEMY, 0);
		Particle* fuego4 = App->particles->AddParticle(particleFire, position.x + 200, position.y + 381, Collider::Type::ENEMY, 0);
		Particle* fuego5 = App->particles->AddParticle(particleFire, position.x + -20, position.y + 350, Collider::Type::ENEMY, 0);
		Particle* fuego6 = App->particles->AddParticle(particleFire, position.x + -300, position.y + 381, Collider::Type::ENEMY, 0);
		canshoot1 = false;

	}
	// Primer atac - EJAMBREEE
	if (SDL_GetTicks() - start_Time >= 8000 && !spawned9) { App->enemies->AddEnemy(Enemy_Type::REDBAT, position.x - 50, position.y, 1); spawned9 = true; }
	if (SDL_GetTicks() - start_Time >= 8500 && !spawned10) { App->enemies->AddEnemy(Enemy_Type::REDBAT, position.x + 50, position.y, 1); spawned10 = true; }
	if (SDL_GetTicks() - start_Time >= 9000 && !spawned11) { App->enemies->AddEnemy(Enemy_Type::REDBAT, position.x - 100, position.y, 1); spawned11 = true; }
	if (SDL_GetTicks() - start_Time >= 9500 && !spawned12) { App->enemies->AddEnemy(Enemy_Type::REDBAT, position.x + 100, position.y, 1); spawned12 = true; }
	if (SDL_GetTicks() - start_Time >= 10000 && !spawned13) { App->enemies->AddEnemy(Enemy_Type::REDBAT, position.x - 150, position.y, 1); spawned13 = true; }
	if (SDL_GetTicks() - start_Time >= 10500 && !spawned14) { App->enemies->AddEnemy(Enemy_Type::REDBAT, position.x + 150, position.y, 1); spawned14 = true; }
	if (SDL_GetTicks() - start_Time >= 11000 && !spawned15) { App->enemies->AddEnemy(Enemy_Type::REDBAT, position.x - 200, position.y, 1); spawned15 = true; }
	if (SDL_GetTicks() - start_Time >= 11500 && !spawned16) { App->enemies->AddEnemy(Enemy_Type::REDBAT, position.x + 200, position.y, 1); spawned16 = true; }

	// Segon atac - FUEEEEGO 
	if (SDL_GetTicks() - start_Time >= 14000 && canshoot2)
	{
		// TODO: lanzar particulas de fuego al mismo tiempo que path va para atras y luego para adelante
		Particle* fuego = App->particles->AddParticle(particleFire, position.x + 200, position.y + 381, Collider::Type::ENEMY, 0);
		Particle* fuego2 = App->particles->AddParticle(particleFire, position.x + -20, position.y + 350, Collider::Type::ENEMY, 0);
		Particle* fuego3 = App->particles->AddParticle(particleFire, position.x + -300, position.y + 381, Collider::Type::ENEMY, 0);
		Particle* fuego4 = App->particles->AddParticle(particleFire, position.x + 200, position.y + 381, Collider::Type::ENEMY, 0);
		Particle* fuego5 = App->particles->AddParticle(particleFire, position.x + -20, position.y + 350, Collider::Type::ENEMY, 0);
		Particle* fuego6 = App->particles->AddParticle(particleFire, position.x + -300, position.y + 381, Collider::Type::ENEMY, 0);
		canshoot2 = false;

	}
	// Primer atac - EJAMBREEE
	if (SDL_GetTicks() - start_Time >= 15000 && !spawned17) { App->enemies->AddEnemy(Enemy_Type::REDBAT, position.x - 50, position.y, 1); spawned17 = true; }
	if (SDL_GetTicks() - start_Time >= 15500 && !spawned18) { App->enemies->AddEnemy(Enemy_Type::REDBAT, position.x + 50, position.y, 1); spawned18 = true; }
	if (SDL_GetTicks() - start_Time >= 16000 && !spawned19) { App->enemies->AddEnemy(Enemy_Type::REDBAT, position.x - 100, position.y, 1); spawned19 = true; }
	if (SDL_GetTicks() - start_Time >= 16500 && !spawned20) { App->enemies->AddEnemy(Enemy_Type::REDBAT, position.x + 100, position.y, 1); spawned20 = true; }
	if (SDL_GetTicks() - start_Time >= 17000 && !spawned21) { App->enemies->AddEnemy(Enemy_Type::REDBAT, position.x - 150, position.y, 1); spawned21 = true; }
	if (SDL_GetTicks() - start_Time >= 17500 && !spawned22) { App->enemies->AddEnemy(Enemy_Type::REDBAT, position.x + 150, position.y, 1); spawned22 = true; }
	if (SDL_GetTicks() - start_Time >= 18000 && !spawned23) { App->enemies->AddEnemy(Enemy_Type::REDBAT, position.x - 200, position.y, 1); spawned23 = true; }
	if (SDL_GetTicks() - start_Time >= 18500 && !spawned24) { App->enemies->AddEnemy(Enemy_Type::REDBAT, position.x + 200, position.y, 1); spawned24 = true; }

	// Segon atac - FUEEEEGO 
	if (SDL_GetTicks() - start_Time >= 21000 && canshoot3)
	{
		// TODO: lanzar particulas de fuego al mismo tiempo que path va para atras y luego para adelante
		Particle* fuego = App->particles->AddParticle(particleFire, position.x + 200, position.y + 381, Collider::Type::ENEMY, 0);
		Particle* fuego2 = App->particles->AddParticle(particleFire, position.x + -20, position.y + 350, Collider::Type::ENEMY, 0);
		Particle* fuego3 = App->particles->AddParticle(particleFire, position.x + -300, position.y + 381, Collider::Type::ENEMY, 0);
		Particle* fuego4 = App->particles->AddParticle(particleFire, position.x + 200, position.y + 381, Collider::Type::ENEMY, 0);
		Particle* fuego5 = App->particles->AddParticle(particleFire, position.x + -20, position.y + 350, Collider::Type::ENEMY, 0);
		Particle* fuego6 = App->particles->AddParticle(particleFire, position.x + -300, position.y + 381, Collider::Type::ENEMY, 0);
		canshoot3 = false;

	}
	// Primer atac - EJAMBREEE
	if (SDL_GetTicks() - start_Time >= 22000 && !spawned25) { App->enemies->AddEnemy(Enemy_Type::REDBAT, position.x - 50, position.y, 1); spawned25 = true; }
	if (SDL_GetTicks() - start_Time >= 22500 && !spawned26) { App->enemies->AddEnemy(Enemy_Type::REDBAT, position.x + 50, position.y, 1); spawned26 = true; }
	if (SDL_GetTicks() - start_Time >= 23000 && !spawned27) { App->enemies->AddEnemy(Enemy_Type::REDBAT, position.x - 100, position.y, 1); spawned27 = true; }
	if (SDL_GetTicks() - start_Time >= 23500 && !spawned28) { App->enemies->AddEnemy(Enemy_Type::REDBAT, position.x + 100, position.y, 1); spawned28 = true; }
	if (SDL_GetTicks() - start_Time >= 24000 && !spawned29) { App->enemies->AddEnemy(Enemy_Type::REDBAT, position.x - 150, position.y, 1); spawned29 = true; }
	if (SDL_GetTicks() - start_Time >= 24500 && !spawned30) { App->enemies->AddEnemy(Enemy_Type::REDBAT, position.x + 150, position.y, 1); spawned30 = true; }
	if (SDL_GetTicks() - start_Time >= 25000 && !spawned31) { App->enemies->AddEnemy(Enemy_Type::REDBAT, position.x - 200, position.y, 1); spawned31 = true; }
	if (SDL_GetTicks() - start_Time >= 25500 && !spawned32) { App->enemies->AddEnemy(Enemy_Type::REDBAT, position.x + 200, position.y, 1); spawned32 = true; }

	// Segon atac - FUEEEEGO 
	if (SDL_GetTicks() - start_Time >= 28000 && canshoot4)
	{
		// TODO: lanzar particulas de fuego al mismo tiempo que path va para atras y luego para adelante
		Particle* fuego = App->particles->AddParticle(particleFire, position.x + 200, position.y + 381, Collider::Type::ENEMY, 0);
		Particle* fuego2 = App->particles->AddParticle(particleFire, position.x + -20, position.y + 350, Collider::Type::ENEMY, 0);
		Particle* fuego3 = App->particles->AddParticle(particleFire, position.x + -300, position.y + 381, Collider::Type::ENEMY, 0);
		Particle* fuego4 = App->particles->AddParticle(particleFire, position.x + 200, position.y + 381, Collider::Type::ENEMY, 0);
		Particle* fuego5 = App->particles->AddParticle(particleFire, position.x + -20, position.y + 350, Collider::Type::ENEMY, 0);
		Particle* fuego6 = App->particles->AddParticle(particleFire, position.x + -300, position.y + 381, Collider::Type::ENEMY, 0);
		canshoot4 = false;

	}
	// Primer atac - EJAMBREEE
	if (SDL_GetTicks() - start_Time >= 27000 && !spawned33) { App->enemies->AddEnemy(Enemy_Type::REDBAT, position.x - 50, position.y, 1); spawned33 = true; }
	if (SDL_GetTicks() - start_Time >= 27500 && !spawned34) { App->enemies->AddEnemy(Enemy_Type::REDBAT, position.x + 50, position.y, 1); spawned34 = true; }
	if (SDL_GetTicks() - start_Time >= 28000 && !spawned35) { App->enemies->AddEnemy(Enemy_Type::REDBAT, position.x - 100, position.y, 1); spawned35 = true; }
	if (SDL_GetTicks() - start_Time >= 28500 && !spawned36) { App->enemies->AddEnemy(Enemy_Type::REDBAT, position.x + 100, position.y, 1); spawned36 = true; }
	if (SDL_GetTicks() - start_Time >= 29000 && !spawned37) { App->enemies->AddEnemy(Enemy_Type::REDBAT, position.x - 150, position.y, 1); spawned37 = true; }
	if (SDL_GetTicks() - start_Time >= 29500 && !spawned38) { App->enemies->AddEnemy(Enemy_Type::REDBAT, position.x + 150, position.y, 1); spawned38 = true; }
	if (SDL_GetTicks() - start_Time >= 30000 && !spawned39) { App->enemies->AddEnemy(Enemy_Type::REDBAT, position.x - 200, position.y, 1); spawned39 = true; }
	if (SDL_GetTicks() - start_Time >= 30500 && !spawned40) { App->enemies->AddEnemy(Enemy_Type::REDBAT, position.x + 200, position.y, 1); spawned40 = true; }

	// Segon atac - FUEEEEGO 
	if (SDL_GetTicks() - start_Time >= 33000 && canshoot5)
	{
		// TODO: lanzar particulas de fuego al mismo tiempo que path va para atras y luego para adelante
		Particle* fuego = App->particles->AddParticle(particleFire, position.x + 200, position.y + 381, Collider::Type::ENEMY, 0);
		Particle* fuego2 = App->particles->AddParticle(particleFire, position.x + -20, position.y + 350, Collider::Type::ENEMY, 0);
		Particle* fuego3 = App->particles->AddParticle(particleFire, position.x + -300, position.y + 381, Collider::Type::ENEMY, 0);
		Particle* fuego4 = App->particles->AddParticle(particleFire, position.x + 200, position.y + 381, Collider::Type::ENEMY, 0);
		Particle* fuego5 = App->particles->AddParticle(particleFire, position.x + -20, position.y + 350, Collider::Type::ENEMY, 0);
		Particle* fuego6 = App->particles->AddParticle(particleFire, position.x + -300, position.y + 381, Collider::Type::ENEMY, 0);
		canshoot5 = false;

	}

	// KILL BOSS
	if (SDL_GetTicks() - start_Time >= 34000) {
		SetToDelete();
	}
}

void Boss_BreathDragon::Draw() {
	if (!headDestroy && !headDestroy2 && !headDestroy3)
	{
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
	else if (!headDestroy2 && !headDestroy3)
	{
		if (pathCuerpo.GetCurrentAnimation() != nullptr) {
			App->render->Blit(texturaBoss, position.x - 600, position.y, &(pathCuerpo.GetCurrentAnimation()->GetCurrentFrame()));
		}

		if (pathCabeza.GetCurrentAnimation() != nullptr) {
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
	else if (!headDestroy3)
	{
		if (pathCuerpo.GetCurrentAnimation() != nullptr) {
			App->render->Blit(texturaBoss, position.x - 600, position.y, &(pathCuerpo.GetCurrentAnimation()->GetCurrentFrame()));
		}

		if (pathCabeza.GetCurrentAnimation() != nullptr) {
			App->render->Blit(texturaBoss, position.x - 85, position.y + 230, &(pathCabeza.GetCurrentAnimation()->GetCurrentFrame()));
		}

		if (pathFan.GetCurrentAnimation() != nullptr) {
			App->render->Blit(texturaBoss, position.x - 400, position.y + 250, &(pathFan.GetCurrentAnimation()->GetCurrentFrame()));
			App->render->Blit(texturaBoss, position.x - 150, position.y + 200, &(pathFan.GetCurrentAnimation()->GetCurrentFrame()));
			App->render->Blit(texturaBoss, position.x + 40, position.y + 200, &(pathFan.GetCurrentAnimation()->GetCurrentFrame()));
			App->render->Blit(texturaBoss, position.x + 270, position.y + 230, &(pathFan.GetCurrentAnimation()->GetCurrentFrame()));
		}
	}
	else
	{

	}
}

void Boss_BreathDragon::OnCollision(Collider* collider)
{
	if (life)
	{
		hitcount++;
		if (hitcount < 5)
		{
			headDestroy = true;
		}
		else if (hitcount < 10)
		{
			headDestroy2 = true;
		}
		else {
			life = false;
			//SetToDelete();
		}
	}
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
