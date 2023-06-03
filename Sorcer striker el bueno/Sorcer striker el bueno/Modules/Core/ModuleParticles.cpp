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
	texture = App->textures->Load(FI_particles_.c_str());

	// Laser particle
	laser1.anim.PushBack({ 1732, 727, 47, 67 });
	laser1.anim.loop = false;
	laser1.speed = iPoint(0, -15);
	laser1.lifetime = 150;
	laser1.anim.speed = 0.01f;

	laser2.anim.PushBack({ 1820, 687, 86, 110 });
	laser2.anim.loop = false;
	laser2.speed = iPoint(0, -15);
	laser2.lifetime = 100;
	laser2.anim.speed = 0.01f;

	//PLayer dead + bomb
	playerdead.anim.PushBack({ 1697, 209, 160, 162 });
	playerdead.anim.PushBack({ 1893, 209, 160, 162});
	playerdead.anim.PushBack({ 2109, 209, 160, 162 });
	playerdead.anim.PushBack({ 2302, 209, 160, 162 });
	playerdead.anim.PushBack({ 1699, 419, 160, 162 });
	playerdead.anim.PushBack({ 1898, 411, 160, 162 });
	playerdead.anim.PushBack({ 2105, 407, 160, 162});
	playerdead.anim.PushBack({ 2294, 422, 160, 162});
	playerdead.speed.y = -8;
	playerdead.anim.speed = 0.1f;
	playerdead.lifetime = 80;

	bomb.anim.PushBack({ 53, 1418, 424, 424 });
	bomb.anim.PushBack({ 89, 600, 424, 424 });
	bomb.anim.PushBack({ 1002, 109, 424, 424 });
	bomb.anim.PushBack({ 1249, 447, 424, 424 });
	bomb.anim.PushBack({ 691, 815, 424, 424 });
	bomb.anim.PushBack({ 977, 1360, 424, 424 });
	bomb.speed = iPoint(0, -12);
	bomb.anim.speed = 0.05f;
	bomb.lifetime = 115;

	//Powe up atacks
	//Blue
	axeleft.anim.PushBack({ 1707, 947, 93, 89 });
	axeleft.anim.PushBack({ 1804, 947, 93, 89 });
	axeleft.anim.PushBack({ 2129-233, 947, 93, 89 });
	axeleft.anim.PushBack({ 2225-233, 947, 93, 89 });
	axeleft.anim.PushBack({ 2317-233, 947, 93, 89 });
	axeleft.anim.PushBack({ 2400-233, 947, 93, 89 });
	axeleft.anim.PushBack({ 2488-233, 947, 93, 89 });
	axeleft.anim.PushBack({ 2584-233, 947, 93, 89 });
	axeleft.anim.speed = 0.2f;
	axeleft.speed = iPoint(-4, -13);
	axeleft.lifetime = 100;

	axeright.anim.PushBack({ 2587-226, 1062, 93, 89 });
	axeright.anim.PushBack({ 2490-226, 1064, 93, 89});
	axeright.anim.PushBack({ 2398-226, 1062, 93, 89 });
	axeright.anim.PushBack({ 2301-226, 1062, 93, 89 });
	axeright.anim.PushBack({ 2209-226, 1062, 93, 89 });
	axeright.anim.PushBack({ 2131-226, 1062, 93, 89 });
	axeright.anim.PushBack({ 2040-226, 1052, 93, 89 });
	axeright.anim.PushBack({ 1944-226, 1062, 93, 89 });
	axeright.anim.speed = 0.2f;
	axeright.speed = iPoint(4, -13);
	axeright.lifetime = 100;
	
	//Pink
	knifeleft.anim.PushBack({ 1713, 873, 34, 62 });
	knifeleft.speed = iPoint(0, -16);
	knifeleft.lifetime = 115;

	kniferight.anim.PushBack({ 1864, 873, 34, 64 });
	kniferight.speed = iPoint(0, -16);
	kniferight.lifetime = 115;

	//Green
	sword.anim.PushBack({ 1617, 744, 80, 765 });
	sword.anim.PushBack({ 1618, 849, 80, 765 });
	sword.anim.PushBack({ 1617, 976, 80, 765});
	sword.anim.PushBack({ 1617, 1166, 80, 765});
	sword.anim.PushBack({ 1617, 1166, 80, 765 });
	sword.anim.PushBack({ 1617, 1166, 80, 765 });
	sword.anim.PushBack({ 1617, 1166, 80, 765 });
	sword.anim.PushBack({ 1617, 1166, 80, 765 });
	sword.anim.PushBack({ 1617, 1166, 80, 765 });
	sword.anim.PushBack({ 1617, 1166, 80, 765 });
	sword.anim.PushBack({ 1617, 1166, 80, 765 });
	sword.anim.PushBack({ 1617, 1166, 80, 765 });
	sword.anim.PushBack({ 1617, 1166, 80, 765 });
	sword.anim.PushBack({ 1617, 1166, 80, 765 });
	sword.anim.PushBack({ 1617, 1166, 80, 765 });
	sword.anim.PushBack({ 1617, 1166, 80, 765 });
	sword.anim.PushBack({ 1617, 1166, 80, 765 });
	sword.anim.PushBack({ 1617, 1166, 80, 765 });
	sword.anim.PushBack({ 1617, 1166, 80, 765 });
	sword.anim.PushBack({ 1617, 1166, 80, 765 });
	sword.anim.PushBack({ 1617, 1166, 80, 765 });
	sword.anim.PushBack({ 1617, 1166, 80, 765 });
	sword.anim.PushBack({ 1617, 1166, 80, 765 });
	sword.anim.PushBack({ 1617, 1166, 80, 765 });
	sword.speed = iPoint(0, -15);
	sword.anim.speed = 0.35f;
	sword.lifetime = 60;


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