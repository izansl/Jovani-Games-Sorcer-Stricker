#include "Enemy_RedBall.h"

#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Core/ModuleRender.h"
#include "../../Modules/Core/ModuleTextures.h"
#include "../../Application/FileNames.h"

Enemy_RedBall::Enemy_RedBall(int x, int y, int wave) : Enemy(x, y) {
	texture = App->textures->Load(FI_spriteEnemy_1.c_str());
	fly.PushBack({ 48, 12, 22,31 });
	fly.PushBack({ 76,12 ,26, 32 });
	currentAnim = &fly;
	fly.speed = 0.2;
	fly.loop = true;
	// Sescribe a path in the screen
	if (wave == 1)
	{
		path.PushBack({ 0, 0.5f }, 150);
		path.PushBack({ 2.0, 1.0 }, 125);
		path.PushBack({ -1.5, -3.0 }, 125);
		path.PushBack({ 1.5, -5.0 }, 600);

	}
	else if (wave == 2)
	{
		path.PushBack({ 0, 0.5f }, 250);
		path.PushBack({ -2.0, 1.0 }, 100);
		path.PushBack({ 1.0, -3.0 }, 50);
		path.PushBack({ 0.75, -6.0 }, 600);
	}
	else if (wave == 3)
	{
		path.PushBack({ 0, 0.75f }, 500);
		path.PushBack({1.0, 0.5 }, 100);
		path.PushBack({ -1.0, 0.5 }, 100);
		path.PushBack({ 1.0, 0.5 }, 100);
		path.PushBack({ -1.0, 0.5 }, 100);
	}
	else if (wave == 4)
	{
		path.PushBack({ 0, 1 }, 650);
		path.PushBack({-1.5, -3.0 }, 75);
		path.PushBack({ 0, -6.0 }, 100);
		path.PushBack({ -2, 1 }, 300);
		
	}
	else if (wave == 5)
	{
		path.PushBack({ 0, 1.0f }, 700);
		path.PushBack({ 2.0, 1.0 }, 125);
		path.PushBack({ -1.5, -3.0 }, 125);
		path.PushBack({ 1.5, -5.0 }, 600);
	}
	else if (wave == 6)
	{
		path.PushBack({ 0, 1.0f }, 1300);
		path.PushBack({ -1.0, -3.0f }, 60);
		path.PushBack({ -3, -6 }, 1300);
	}
	else if (wave == 7)
	{

	}
	else if (wave == 8)
	{

	}
	
	
	
	

	collider = App->collisions->AddCollider({ 0, 0,22, 32 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_RedBall::Update() {
	path.Update();
	position = spawnPos + path.GetRelativePosition();

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
