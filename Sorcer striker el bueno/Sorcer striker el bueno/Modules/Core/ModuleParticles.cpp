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
	laser1.anim.PushBack({ 1951, 739, 65, 67 });
	laser1.anim.loop = false;
	laser1.speed = iPoint(0, -15);
	laser1.lifetime = 100;
	laser1.anim.speed = 0.01f;

	laser2.anim.PushBack({ 2048, 700, 85, 110 });
	laser2.anim.loop = false;
	laser2.speed = iPoint(0, -15);
	laser2.lifetime = 100;
	laser2.anim.speed = 0.01f;

	//PLayer dead + bomb
	playerdead.anim.PushBack({ 1926, 226, 160, 162 });
	playerdead.anim.PushBack({ 2122, 223, 160, 162});
	playerdead.anim.PushBack({ 2331, 223, 160, 162 });
	playerdead.anim.PushBack({ 2525, 227, 160, 162 });
	playerdead.anim.PushBack({ 1926, 427, 160, 162 });
	playerdead.anim.PushBack({ 2121, 426, 160, 162 });
	playerdead.anim.PushBack({ 2333, 426, 160, 162});
	playerdead.anim.PushBack({ 2530, 433, 160, 162});
	playerdead.speed.y = -8;
	playerdead.anim.speed = 0.1f;
	playerdead.lifetime = 80;

	bomb.anim.PushBack({ 289, 1420, 424, 421 });
	bomb.anim.PushBack({ 289, 1420, 424, 421 });
	bomb.anim.PushBack({ 149, 906, 424, 421 });
	bomb.anim.PushBack({ 1467, 458, 424, 421 });
	bomb.anim.PushBack({ 923, 829, 424, 421 });
	bomb.anim.PushBack({ 1207, 1377, 424, 421 });
	bomb.speed = iPoint(0, -12);
	bomb.anim.speed = 0.05f;
	bomb.lifetime = 115;

	//Powe up atacks
	//Blue
	axeleft.anim.PushBack({ 1940, 956, 93, 89 });
	axeleft.anim.PushBack({ 2037, 962, 93, 89 });
	axeleft.anim.PushBack({ 2129, 956, 93, 89 });
	axeleft.anim.PushBack({ 2225, 956, 93, 89 });
	axeleft.anim.PushBack({ 2317, 956, 93, 89 });
	axeleft.anim.PushBack({ 2400, 956, 93, 89 });
	axeleft.anim.PushBack({ 2488, 948, 93, 89 });
	axeleft.anim.PushBack({ 2584, 956, 93, 89 });
	axeleft.anim.speed = 0.1f;
	axeleft.speed = iPoint(-4, -13);
	axeleft.lifetime = 100;

	axeright.anim.PushBack({ 2587, 1074, 93, 89 });
	axeright.anim.PushBack({ 2490, 1076, 93, 89});
	axeright.anim.PushBack({ 2398, 1074, 93, 89 });
	axeright.anim.PushBack({ 2301, 1071, 93, 89 });
	axeright.anim.PushBack({ 2209, 1071, 93, 89 });
	axeright.anim.PushBack({ 2131, 1071, 93, 89 });
	axeright.anim.PushBack({ 2040, 1063, 93, 89 });
	axeright.anim.PushBack({ 1944, 1073, 93, 89 });
	axeright.anim.speed = 0.1f;
	axeright.speed = iPoint(4, -13);
	axeright.lifetime = 100;
	

	
	
	texture5 = App->textures->Load(FI_spriteEnemy_reds.c_str());
	wizardshoot.anim.PushBack({ 640, 521, 99, 79 });
	wizardshoot.anim.PushBack({ 861, 521, 99, 79 });
	wizardshoot.anim.PushBack({ 1007, 528, 99, 79 });
	wizardshoot.anim.PushBack({ 933, 528, 99, 79 });
	wizardshoot.anim.PushBack({ 731, 527, 99, 79 });
	wizardshoot.anim.speed = 0.2;
	wizardshoot.anim.loop = false;


	
	//Pink
	knifeleft.anim.PushBack({ 1938, 881, 34, 62 });
	knifeleft.speed = iPoint(0, -16);

	kniferight.anim.PushBack({ 2086, 883, 34, 62 });
	kniferight.speed = iPoint(0, -16);

	//Green
	sword.anim.PushBack({ 2276, 1220, 110, 550 });//Arreglarlo
	sword.speed = iPoint(0, -15);

	greenpart.anim.PushBack({ 2418, 1218, 110, 550 });
	greenpart.speed = iPoint(0, -13);
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