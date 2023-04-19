#include "ModuleParticles.h"

#include "Application.h"

#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleCollisions.h"

#include "../SDLs/SDL/include/SDL_timer.h"

ModuleParticles::ModuleParticles()
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
		particles[i] = nullptr;
}

ModuleParticles::~ModuleParticles()
{

}

bool ModuleParticles::Start()
{
	LOG("Loading particles");
	texture = App->textures->Load("../Assets/Sprites.png");

	// Explosion particle
	explosion.anim.PushBack({171, 243, 11, 10});
	explosion.anim.PushBack({193, 241, 12, 14});
	
	explosion.anim.loop = false;
	explosion.speed = iPoint(0, -2);
	explosion.anim.speed = 0.05f;

	explosion2.anim.PushBack({ 210, 209, 76, 75 });
	explosion2.anim.PushBack({ 288, 194, 99, 98 });
	explosion2.anim.loop = false;
	explosion2.speed = iPoint(0, -1);
	explosion2.anim.speed = 0.03f;

	laser.anim.PushBack({155, 239, 8, 18});
	laser.speed = iPoint(0, -2);
	laser.lifetime = 1000;
	laser.anim.speed = 0.01f;

	return true;
}

bool ModuleParticles::CleanUp()
{
	LOG("Unloading particles");

	// Delete all remaining active particles on application exit 
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if(particles[i] != nullptr)
		{
			delete particles[i];
			particles[i] = nullptr;
		}
	}

	return true;
}
void ModuleParticles::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		// Always destroy particles that collide
		if (particles[i] != nullptr && particles[i]->collider == c1)
		{
			// TODO 6: Make so every time a particle hits a wall it triggers an explosion particle
			AddParticle(explosion, particles[i]->position.x, particles[i]->position.y);

			delete particles[i];
			particles[i] = nullptr;
			break;
		}
	}
}
update_status ModuleParticles::Update()
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		Particle* particle = particles[i];

		if(particle == nullptr)	continue;

		// Call particle Update. If it has reached its lifetime, destroy it
		if(particle->Update() == false)
		{
			delete particle;
			particles[i] = nullptr;
		}
	}

	return update_status::UPDATE_CONTINUE;
}

update_status ModuleParticles::PostUpdate()
{
	//Iterating all particle array and drawing any active particles
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		Particle* particle = particles[i];

		if (particle != nullptr && particle->isAlive)
		{
			App->render->Blit(texture, particle->position.x, particle->position.y, &(particle->anim.GetCurrentFrame()));
		}
	}

	return update_status::UPDATE_CONTINUE;
}

void ModuleParticles::AddParticle(const Particle& particle, int x, int y, Collider::Type colliderType, uint delay)
{
	Particle* p = new Particle(particle);
	
	p->frameCount = -(int)delay;			// We start the frameCount as the negative delay
	p->position.x = x;						// so when frameCount reaches 0 the particle will be activated
	p->position.y = y;						

	//Adding the particle's collider
	if (colliderType != Collider::Type::NONE)
		p->collider = App->collisions->AddCollider(p->anim.GetCurrentFrame(), colliderType, this);
	particles[lastParticle++] = p;
	lastParticle %= MAX_ACTIVE_PARTICLES;
}