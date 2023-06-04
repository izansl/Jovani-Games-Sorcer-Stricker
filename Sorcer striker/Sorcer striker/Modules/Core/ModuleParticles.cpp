#include "ModuleParticles.h"

#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleCollisions.h"

#include "../../Application/Application.h"
#include "../../Application/FileNames.h"
#include "../Gameplay/SceneLevel1.h"

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
	laser1.speed = iPoint(0, -28);
	laser1.lifetime = 150;
	laser1.anim.speed = 0.01f;

	laser2.anim.PushBack({ 1820, 687, 86, 110 });
	laser2.anim.loop = false;
	laser2.speed = iPoint(0, -28);
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
	bomb.speed = iPoint(0, -23);
	bomb.anim.speed = 0.1f;
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
	axeleft.speed = iPoint(-6, -25);
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
	axeright.speed = iPoint(6, -25);
	axeright.lifetime = 100;
	
	//Pink
	knifeleft.anim.PushBack({ 1713, 873, 34, 62 });
	knifeleft.speed = iPoint(0, -33);
	knifeleft.lifetime = 115;

	kniferight.anim.PushBack({ 1864, 873, 34, 64 });
	kniferight.speed = iPoint(0, -33);
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
	sword.speed = iPoint(0, -30);
	sword.anim.speed = 0.35f;
	sword.lifetime = 60;

	//wizard
	wizardshoot.anim.PushBack({ 2699, 197, 95,81 });
	wizardshoot.anim.PushBack({ 2921, 199, 95,81 });
	wizardshoot.anim.PushBack({ 3067, 199, 95,81 });
	wizardshoot.anim.PushBack({ 2989, 199, 95,81 });
	wizardshoot.anim.PushBack({ 2789, 199, 95,81 });
	wizardshoot.anim.speed = 0.20;
	wizardshoot.lifetime = 100;
	minifireshot.speed = iPoint(0,  2);

	//goblin
	goblinshot.anim.PushBack({ 2651, 497, 45, 145 });
	goblinshot.anim.PushBack({ 2727, 497, 45, 145 });
	goblinshot.anim.PushBack({ 2801, 497, 45, 145 });
	goblinshot.anim.PushBack({ 2869, 497, 45, 145 });
	goblinshot.anim.PushBack({ 3049, 497, 45, 145 });
	goblinshot.anim.PushBack({ 3167, 497, 45, 145 });
	goblinshot.anim.speed = 0.20;
	goblinshot.lifetime = 100;
	goblinshot.speed = iPoint(0, 2);
	goblinshot.anim.loop = false;
	//minifireshot
	minifireshot.anim.PushBack({ 2699, 457, 31, 35 });
	minifireshot.anim.PushBack({ 2761, 457,31, 35 });
	minifireshot.anim.PushBack({ 2821, 457, 31, 35 });
	minifireshot.anim.PushBack({ 2883, 457, 31, 35 });
	minifireshot.anim.speed = 0.20;
	minifireshot.lifetime = 100;
	minifireshot.speed = iPoint(0, 1);

	minifireshottank.anim.PushBack({ 2699, 457, 31, 35 });
	minifireshottank.anim.PushBack({ 2761, 457,31, 35 });
	minifireshottank.anim.PushBack({ 2821, 457, 31, 35 });
	minifireshottank.anim.PushBack({ 2883, 457, 31, 35 });
	minifireshottank.anim.speed = 0.20;
	minifireshottank.lifetime = 100;
	minifireshottank.speed = iPoint(0, 5);

	//disparos para tortuga diagonales
	minifireshot1.anim.PushBack({ 2699, 457, 31, 35 });
	minifireshot1.anim.PushBack({ 2761, 457,31, 35 });
	minifireshot1.anim.PushBack({ 2821, 457, 31, 35 });
	minifireshot1.anim.PushBack({ 2883, 457, 31, 35 });
	minifireshot1.anim.speed = 0.20;
	minifireshot1.lifetime = 100;
	minifireshot1.speed = iPoint(0, 2);

	minifireshot2.anim.PushBack({ 2699, 457, 31, 35 });
	minifireshot2.anim.PushBack({ 2761, 457,31, 35 });
	minifireshot2.anim.PushBack({ 2821, 457, 31, 35 });
	minifireshot2.anim.PushBack({ 2883, 457, 31, 35 });
	minifireshot2.anim.speed = 0.20;
	minifireshot2.lifetime = 100;
	minifireshot2.speed = iPoint(4, 2);

	minifireshot3.anim.PushBack({ 2699, 457, 31, 35 });
	minifireshot3.anim.PushBack({ 2761, 457,31, 35 });
	minifireshot3.anim.PushBack({ 2821, 457, 31, 35 });
	minifireshot3.anim.PushBack({ 2883, 457, 31, 35 });
	minifireshot3.anim.speed = 0.20;
	minifireshot3.lifetime = 100;
	minifireshot3.speed = iPoint(4, -10);

	minifireshot4.anim.PushBack({ 2699, 457, 31, 35 });
	minifireshot4.anim.PushBack({ 2761, 457,31, 35 });
	minifireshot4.anim.PushBack({ 2821, 457, 31, 35 });
	minifireshot4.anim.PushBack({ 2883, 457, 31, 35 });
	minifireshot4.anim.speed = 0.20;
	minifireshot4.lifetime = 100;
	minifireshot4.speed = iPoint(-4, -10);

	minifireshot5.anim.PushBack({ 2699, 457, 31, 35 });
	minifireshot5.anim.PushBack({ 2761, 457,31, 35 });
	minifireshot5.anim.PushBack({ 2821, 457, 31, 35 });
	minifireshot5.anim.PushBack({ 2883, 457, 31, 35 });
	minifireshot5.anim.speed = 0.20;
	minifireshot5.lifetime = 100;
	minifireshot5.speed = iPoint(0, -10);

	minifireshot6.anim.PushBack({ 2699, 457, 31, 35 });
	minifireshot6.anim.PushBack({ 2761, 457,31, 35 });
	minifireshot6.anim.PushBack({ 2821, 457, 31, 35 });
	minifireshot6.anim.PushBack({ 2883, 457, 31, 35 });
	minifireshot6.anim.speed = 0.20;
	minifireshot6.lifetime = 100;
	minifireshot6.speed = iPoint(-4, 2);
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