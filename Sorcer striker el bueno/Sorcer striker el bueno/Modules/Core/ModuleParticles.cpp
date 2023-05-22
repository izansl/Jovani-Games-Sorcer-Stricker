#include "ModuleParticles.h"

#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleCollisions.h"

#include "../../Application/Application.h"
#include "../../Application/FileNames.h"

#include "../../../SDLs/SDL/include/SDL_timer.h"


ModuleParticles::ModuleParticles(bool startEnabled) : Module(startEnabled) {
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
		particles[i] = nullptr;
}

ModuleParticles::~ModuleParticles() {
}

bool ModuleParticles::Start() {
	LOG("Loading particles");
	texture = App->textures->Load(FI_spriteEnemy_reds.c_str());

	// Laser particle
	laser1.anim.PushBack({ 741, 967, 59, 74 });
	laser1.anim.loop = false;
	laser1.speed = iPoint(0, -15);
	laser1.lifetime = 100;
	laser1.anim.speed = 0.01f;

	laser2.anim.PushBack({ 826, 933, 106, 114 });
	laser2.anim.loop = false;
	laser2.speed = iPoint(0, -15);
	laser2.lifetime = 100;
	laser2.anim.speed = 0.01f;

	texture2 = App->textures->Load(FI_spritePlayer_explosions.c_str());
	//PLayer dead + bomb
	playerdead.anim.PushBack({ 21, 0, 158, 167 });
	playerdead.anim.PushBack({  218, 0, 158, 167});
	playerdead.anim.PushBack({ 423, 0, 158, 167 });
	playerdead.anim.PushBack({ 620, 0, 158, 167 });
	playerdead.anim.PushBack({ 23, 200, 158, 167 });
	playerdead.anim.PushBack({ 217, 199, 158, 167 });
	playerdead.anim.PushBack({ 429, 191, 158, 167});
	playerdead.anim.PushBack({ 628, 202, 158, 167});
	playerdead.speed.y = -8;
	playerdead.anim.speed = 0.1f;
	playerdead.lifetime = 80;

	texture3 = App->textures->Load(FI_Introimage_7.c_str());
	bomb.anim.PushBack({ 294, 1379, 468, 445 });
	bomb.anim.PushBack({ 166, 863, 468, 445 });
	bomb.anim.PushBack({ 351, 55, 468, 445 });
	bomb.anim.PushBack({ 937, 778, 468, 445 });
	bomb.anim.PushBack({ 1225, 1320, 468, 445 });
	bomb.anim.speed = 0.2f;

	texture4 = App->textures->Load(FI_spritePlayer_shoots.c_str());
	//Powe up atacks
	axeleft.anim.PushBack({24, 96, 98, 100});
	axeleft.anim.PushBack({121, 96, 98, 100});
	axeleft.anim.PushBack({ 215, 97, 98, 100 });
	axeleft.anim.PushBack({ 317, 95, 98, 100 });
	axeleft.anim.PushBack({ 407, 88, 98, 100 });
	axeleft.anim.PushBack({ 486, 89, 98, 100 });
	axeleft.anim.PushBack({ 577, 78, 98, 100 });
	axeleft.anim.PushBack({ 673, 87, 98, 100 });
	axeleft.anim.speed = 0.1f;
	axeleft.speed = iPoint(-4, -13);
	axeleft.lifetime = 100;

	axeright.anim.PushBack({ 679, 205, 98, 100 });
	axeright.anim.PushBack({ 576, 210, 98, 100});
	axeright.anim.PushBack({  486, 212, 98, 100});
	axeright.anim.PushBack({ 389, 206, 98, 100 });
	axeright.anim.PushBack({ 295, 204, 98, 100 });
	axeright.anim.PushBack({ 218, 205, 98, 100 });
	axeright.anim.PushBack({ 125, 198, 98, 100 });
	axeright.anim.PushBack({ 30, 202, 98, 100 });
	axeright.anim.speed = 0.1f;
	axeright.speed = iPoint(4, -13);
	axeright.lifetime = 100;
	

	explosion2.anim.loop = false;
	
	texture3 = App->textures->Load(FI_spriteEnemy_reds.c_str());
	wizardshoot.anim.PushBack({ 640, 521, 99, 79 });
	wizardshoot.anim.PushBack({ 861, 521, 99, 79 });
	wizardshoot.anim.PushBack({ 1007, 528, 99, 79 });
	wizardshoot.anim.PushBack({ 933, 528, 99, 79 });
	wizardshoot.anim.PushBack({ 731, 527, 99, 79 });
	wizardshoot.anim.speed = 0.2;
	explosion.anim.loop = false;


	
	//bomb.anim.loop = false;


	return true;
}

Update_Status ModuleParticles::PreUpdate() {
	// Remove all particles scheduled for deletion
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i) {
		if (particles[i] != nullptr && particles[i]->pendingToDelete) {
			delete particles[i];
			particles[i] = nullptr;
		}
	}

	return Update_Status::UPDATE_CONTINUE;
}

bool ModuleParticles::CleanUp() {
	LOG("Unloading particles");

	// Delete all remaining active particles on application exit 
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i) {
		if (particles[i] != nullptr) {
			delete particles[i];
			particles[i] = nullptr;
		}
	}

	return true;
}

void ModuleParticles::OnCollision(Collider* c1, Collider* c2) {
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i) {
		// Always destroy particles that collide
		if (particles[i] != nullptr && particles[i]->collider == c1) {
			particles[i]->pendingToDelete = true;
			particles[i]->collider->pendingToDelete = true;
			break;
		}
	}
}

Update_Status ModuleParticles::Update() {
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i) {
		Particle* particle = particles[i];

		if (particle == nullptr)
			continue;

		// Call particle Update. If it has reached its lifetime, destroy it
		if (particle->Update() == false)
			particles[i]->SetToDelete();
	}

	return Update_Status::UPDATE_CONTINUE;
}

Update_Status ModuleParticles::PostUpdate() {
	//Iterating all particle array and drawing any active particles
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i) {
		Particle* particle = particles[i];

		if (particle != nullptr && particle->isAlive) {
			App->render->Blit(texture, particle->position.x, particle->position.y, &(particle->anim.GetCurrentFrame()));
		}
	}

	return Update_Status::UPDATE_CONTINUE;
}

Particle* ModuleParticles::AddParticle(const Particle& particle, int x, int y, Collider::Type colliderType, uint delay) {
	Particle* newParticle = nullptr;

	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i) {
		//Finding an empty slot for a new particle
		if (particles[i] == nullptr) {
			newParticle = new Particle(particle);
			newParticle->frameCount = -(int)delay;			// We start the frameCount as the negative delay
			newParticle->position.x = x;						// so when frameCount reaches 0 the particle will be activated
			newParticle->position.y = y;

			//Adding the particle's collider
			if (colliderType != Collider::Type::NONE)
				newParticle->collider = App->collisions->AddCollider(newParticle->anim.GetCurrentFrame(), colliderType, this);

			particles[i] = newParticle;
			break;
		}
	}

	return newParticle;
}