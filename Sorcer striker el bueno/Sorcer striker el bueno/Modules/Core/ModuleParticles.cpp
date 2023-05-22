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
	texture = App->textures->Load(FI_spritePlayer_player1.c_str());

	// Explosion particle
	explosion.anim.PushBack({ 34, 273, 88, 89 });
	explosion.anim.PushBack({ 132, 273, 88, 89 });
	explosion.anim.PushBack({ 237, 273, 88, 89 });
	explosion.anim.PushBack({ 337, 273, 89, 90 });
	explosion.anim.loop = false;
	explosion.speed = iPoint(0, -10);
	explosion.lifetime = 100;
	explosion.anim.speed = 0.05f;

	laser.anim.PushBack({ 356, 23, 12, 30 });
	laser.anim.loop = false;
	laser.speed = iPoint(0, -15);
	laser.lifetime = 100;
	laser.anim.speed = 0.01f;


	playerdead.anim.PushBack({ 45, 128, 60, 60 });
	playerdead.anim.PushBack({ 110, 123, 60, 60 });
	playerdead.anim.PushBack({ 180, 125, 60, 60 });
	playerdead.anim.PushBack({ 246, 125, 60, 60 });
	playerdead.anim.PushBack({ 44, 193, 60, 60 });
	playerdead.anim.PushBack({ 110, 193, 60, 60 });
	playerdead.anim.PushBack({ 181, 193, 60, 60});
	playerdead.anim.PushBack({ 246, 193, 60, 60});
	playerdead.speed.y = -8;
	playerdead.anim.speed = 0.1f;
	playerdead.lifetime = 80;

	iceleft.anim.PushBack({449, 72, 17, 19});
	iceleft.anim.PushBack({467, 72, 17, 19});
	iceleft.anim.speed = 0.1f;
	iceleft.speed = iPoint(-4, -13);
	iceleft.lifetime = 100;

	iceright.anim.PushBack({ 449, 72, 17, 19 });
	iceright.anim.PushBack({ 467, 72, 17, 19 });
	iceright.anim.speed = 0.1f;
	iceright.speed = iPoint(4, -13);
	iceright.lifetime = 100;


	texture2 = App->textures->Load(FI_spriteExplosion_enemies.c_str());
	explosion2.anim.PushBack({ 3, 71, 36, 36 });
	explosion2.anim.PushBack({ 39, 72, 36, 36 });
	explosion2.anim.PushBack({ 75, 72, 36, 36 });
	explosion2.anim.PushBack({ 111, 71, 36, 36 });
	explosion2.anim.speed = 0.2f;
	
	explosion2.anim.loop = false;
	
	texture3 = App->textures->Load(FI_spriteEnemy_reds.c_str());
	wizardshoot.anim.PushBack({ 640, 521, 99, 79 });
	wizardshoot.anim.PushBack({ 861, 521, 99, 79 });
	wizardshoot.anim.PushBack({ 1007, 528, 99, 79 });
	wizardshoot.anim.PushBack({ 933, 528, 99, 79 });
	wizardshoot.anim.PushBack({ 731, 527, 99, 79 });
	wizardshoot.anim.speed = 0.2;
	explosion.anim.loop = false;


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