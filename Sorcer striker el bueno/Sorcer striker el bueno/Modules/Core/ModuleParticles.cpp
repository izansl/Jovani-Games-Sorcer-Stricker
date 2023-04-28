#include "ModuleParticles.h"

#include "../../Application/Application.h"
#include "../../Application/FileNames.h"

#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleCollisions.h"
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
	texture = App->textures->Load(FTI_sprites_particles.c_str());
	// TODO: ---> Posar be particles, comprobar que es mostri correctament i llavors borrar OLD + Els_Region

#pragma region OLD
	//// Explosion particle
	//explosion.anim.PushBack({ 274, 296, 33, 30 });
	//explosion.anim.PushBack({ 313, 296, 33, 30 });
	//explosion.anim.PushBack({ 346, 296, 33, 30 });
	//explosion.anim.PushBack({ 382, 296, 33, 30 });
	//explosion.anim.PushBack({ 419, 296, 33, 30 });
	//explosion.anim.PushBack({ 457, 296, 33, 30 });
	//explosion.anim.loop = false;
	//explosion.anim.speed = 0.3f;

	//laser.anim.PushBack({ 232, 103, 16, 12 });
	//laser.anim.PushBack({ 249, 103, 16, 12 });
	//laser.speed.x = 5;
	//laser.lifetime = 180;
	//laser.anim.speed = 0.2f;
#pragma endregion

#pragma region NEW
	LOG("Loading particles");
	texture = App->textures->Load(FI_spritePlayer_player1.c_str());

	// Explosion particle
	explosion.anim.PushBack({8, 318, 12, 12});
	explosion.anim.PushBack({31, 317, 12, 12 });
	explosion.anim.loop = false;
	explosion.speed = iPoint(0, -2);
	explosion2.lifetime = 100;
	explosion.anim.speed = 0.02f;

	explosion2.anim.PushBack({ 49, 283, 76, 75 });
	explosion2.anim.loop = false;
	explosion2.speed = iPoint(0, -2);
	explosion2.frameCount = -100;
	explosion2.lifetime = 100;


	explosionfinal.anim.PushBack({ 95, 94, 129, 271 });
	explosionfinal.anim.loop = false;
	explosionfinal.speed = iPoint(0, -1);
	explosionfinal.anim.speed = 0.03f;

	laser.anim.PushBack({ 331, 23, 12, 30 });
	laser.speed = iPoint(0, -3);
	laser.lifetime = 100;
	laser.anim.speed = 0.01f;
#pragma endregion


	

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

		if (particle == nullptr)	continue;

		// Call particle Update. If it has reached its lifetime, destroy it
		if (particle->Update() == false) particles[i]->SetToDelete();
	}
	if (App->particles->explosion.anim.speed==0)
	{
		explosion2.anim.PushBack({ 49, 283, 76, 75 });
		explosion2.anim.loop = false;
		explosion2.speed = iPoint(0, -1);
		explosion2.anim.speed = 0.03f;
		explosion2.lifetime = 100;
		if (explosion2.lifetime == 0)
		{
			explosionfinal.anim.PushBack({ 95, 94, 129, 271 });
			explosionfinal.anim.loop = false;
			explosionfinal.speed = iPoint(0, -1);
			explosionfinal.anim.speed = 0.03f;
		}
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