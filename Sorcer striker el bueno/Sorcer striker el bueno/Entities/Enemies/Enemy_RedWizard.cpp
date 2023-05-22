#include "Enemy_RedWizard.h"

#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Core/ModuleRender.h"
#include "../../Modules/Core/ModuleTextures.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleAudio.h"
#include "../../Modules/Core/ModuleParticles.h"

Enemy_RedWizard::Enemy_RedWizard(int x, int y, int wave, int miem) : Enemy(x, y) {
	texture = App->textures->Load(FI_spriteEnemy_reds.c_str());
	
	fly.PushBack({ 0, 798, 131, 132 });

//mago
//({0, 798, 131, 132})frente
//({0, 955, 131, 132})frente
//({159, 802, 131, 132})giro derecha inicio
//({320, 801, 131, 132})giro derecha medio
//({493, 802, 131, 132})giro derecha final
//({197, 956, 131, 132}) giro izquierda inicio
//({324, 956, 131, 132})giro izquierda medio
//({491, 957, 131, 132})giro izquierda final
// 
//mago herido
//({0, 487, 131, 132})frente
//({0, 635, 131, 132}) frente
//({170, 497, 131, 132})giro derecha inicio
//({325, 647, 131, 132})giro derecha medio
//({493, 648, 131, 132})giro derecha final
//({167, 650, 131, 132})giro izquierda inicio
//({329, 493, 131, 132})giro izquierda medio
//({491, 495, 131, 132})giro izquierda final
// 
// disparo mago
//({640, 521, 99, 79})
//({861, 521, 99, 79 })
//({1007, 528, 99, 79})
//({933, 528, 99, 79 })
//({731, 527, 99, 79})
// 

	currentAnim = &fly;
	fly.speed = 0.01f;
	fly.loop = true;
	
	

	if (wave == 1)
	{
		if (miem == 0)
		{
			path.PushBack({ 0.0, -0.25 }, 720);
			path.PushBack({ 0.0, -8.0 }, 120);
			path.PushBack({ 3, -12.0 }, 650);
		}
	}
	else if (wave == 2)
	{
		if (miem == 0)
		{
			path.PushBack({ 0.0, -0.5}, 835);
			path.PushBack({ 0.0, -8.0 }, 120);
			path.PushBack({ -3, -12.0 }, 650);
		}
	}
	else if (wave == 3)
	{
		if (miem == 0)
		{
			path.PushBack({ 0.0, -0.5}, 950);
			path.PushBack({ 0.0, -8.0 }, 120);
			path.PushBack({ 3, -12.0 }, 650);
		}
	}
	else if (wave == 4)
	{
		if (miem == 0)
		{
			path.PushBack({ 0.0, -0.5 }, 1040);
			path.PushBack({ 0.0, -8.0 }, 120);
			path.PushBack({ -3, -12.0 }, 650);
		}
		
	}
	else if (wave == 5)
	{
		if (miem == 0)
		{
			path.PushBack({ 0.0, -0.5 }, 1140);
			path.PushBack({ 0.0, -8.0 }, 120);
			path.PushBack({ 3, -12.0 }, 650);
		}
		
	}
	
	

	collider = App->collisions->AddCollider({ 0, 0, 131, 132 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_RedWizard::Update() {
	path.Update();
	position = spawnPos + path.GetRelativePosition();

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}


void Enemy_RedWizard::OnCollision(Collider* c1) {
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
}