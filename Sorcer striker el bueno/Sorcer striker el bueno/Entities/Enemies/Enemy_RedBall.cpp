#include "Enemy_RedBall.h"

#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Core/ModuleRender.h"
#include "../../Modules/Core/ModuleTextures.h"
#include "../../Application/FileNames.h"

Enemy_RedBall::Enemy_RedBall(int x, int y, int wave, int miem) : Enemy(x, y) {
	texture = App->textures->Load(FI_spriteEnemy_1.c_str());
	fly.PushBack({ 46, 12, 32,32 });
	fly.PushBack({ 75,12 ,32, 32 });
	currentAnim = &fly;
	fly.speed = 0.2;
	fly.loop = true;
	// Sescribe a path in the screen
	if (wave == 1)
	{
		if (miem == 1)
		{
			path.PushBack({ 0, -3 }, 105);
			path.PushBack({ 4.0, -1 },55);
			path.PushBack({ -3, -8.0 }, 55);
			path.PushBack({ 2, -12.0 }, 600);
		}
		if (miem == 2)
		{
			path.PushBack({ 0, -3 }, 115);
			path.PushBack({ 4.0, -1 }, 55);
			path.PushBack({ -3, -8.0 }, 55);
			path.PushBack({ 2, -12.0 }, 600);
		}
		if (miem == 3)
		{
			path.PushBack({ 0, -3 }, 125);
			path.PushBack({ 4.0, -1 }, 55);
			path.PushBack({ -3, -8.0 }, 55);
			path.PushBack({ 2, -12.0 }, 600);
		}
		if (miem == 4)
		{
			path.PushBack({ 0, -3 }, 135);
			path.PushBack({ 4.0, -1 }, 55);
			path.PushBack({ -3, -8.0 }, 55);
			path.PushBack({ 2, -12.0 }, 600);
		}
		if (miem == 5)
		{
			path.PushBack({ 0, -3 }, 145);
			path.PushBack({ 4.0, -1 }, 55);
			path.PushBack({ -3, -8.0 }, 55);
			path.PushBack({ 2, -12.0 }, 600);
		}
		if (miem == 6)
		{
			path.PushBack({ 0, -3 }, 155);
			path.PushBack({ 4.0, -1 }, 55);
			path.PushBack({ -3, -8.0 }, 55);
			path.PushBack({ 2, -12.0 }, 600);
		}
		if (miem == 7)
		{
			path.PushBack({ 0, -3 }, 165);
			path.PushBack({ 4.0, -1 }, 55);
			path.PushBack({ -3, -8.0 }, 55);
			path.PushBack({ 2, -12.0 }, 600);
		}
		if (miem == 8)
		{
			path.PushBack({ 0, -3 }, 175);
			path.PushBack({ 4.0, -1 }, 55);
			path.PushBack({ -3, -8.0 }, 55);
			path.PushBack({ 2, -12.0 }, 600);
		}
		
	}
	else if (wave == 2)
	{
		if (miem == 1)
		{
			path.PushBack({ 0, -3 }, 175);
			path.PushBack({ -4.0, -1 }, 55);
			path.PushBack({ 3, -8.0 }, 55);
			path.PushBack({ -2, -12.0 }, 600);
		}
		if (miem == 2)
		{
			path.PushBack({ 0, -3 }, 185);
			path.PushBack({ -4.0, -1 }, 55);
			path.PushBack({ 3, -8.0 }, 55);
			path.PushBack({ -2, -12.0 }, 600);
		}
		if (miem == 3)
		{
			path.PushBack({ 0, -3 }, 195);
			path.PushBack({ -4.0, -1 }, 55);
			path.PushBack({ 3, -8.0 }, 55);
			path.PushBack({ -2, -12.0 }, 600);
		}
		if (miem == 4)
		{
			path.PushBack({ 0, -3 }, 205);
			path.PushBack({ -4.0, -1 }, 55);
			path.PushBack({ 3, -8.0 }, 55);
			path.PushBack({ -2, -12.0 }, 600);
		}
		if (miem == 5)
		{
			path.PushBack({ 0, -3 }, 215);
			path.PushBack({ -4.0, -1 }, 55);
			path.PushBack({ 3, -8.0 }, 55);
			path.PushBack({ -2, -12.0 }, 600);
		}
		if (miem == 6)
		{
			path.PushBack({ 0, -3 }, 225);
			path.PushBack({ -4.0, -1 }, 55);
			path.PushBack({ 3, -8.0 }, 55);
			path.PushBack({ -2, -12.0 }, 600);
		}
		if (miem == 7)
		{
			path.PushBack({ 0, -3 }, 235);
			path.PushBack({ -4.0, -1 }, 55);
			path.PushBack({ 3, -8.0 }, 55);
			path.PushBack({ -2, -12.0 }, 600);
		}
		if (miem == 8)
		{
			path.PushBack({ 0, -3 }, 245);
			path.PushBack({ -4.0, -1 }, 55);
			path.PushBack({ 3, -8.0 }, 55);
			path.PushBack({ -2, -12.0 }, 600);
		}
		path.PushBack({ 0, 0.5f }, 250);
		path.PushBack({ -2.0, 1.0 }, 100);
		path.PushBack({ 1.0, -3.0 }, 50);
		path.PushBack({ 0.75, -6.0 }, 600);
	}
	else if (wave == 3)
	{

	if (miem == 1)
	{
		path.PushBack({ 0, -3 }, 350);
		path.PushBack({ 4.0, -4 }, 30);
		path.PushBack({ -4.0, -4 }, 30);
		path.PushBack({ 4.0, -4 }, 30);
		path.PushBack({ -4.0, -4 }, 30);
		path.PushBack({ 4.0, -4 }, 30);
		path.PushBack({ -2.0, -4 }, 100);
	}
	if (miem == 2)
	{
		path.PushBack({ 0, -3 }, 360);
		path.PushBack({ 4.0, -4 }, 30);
		path.PushBack({ -4.0, -4 }, 30);
		path.PushBack({ 4.0, -4 }, 30);
		path.PushBack({ -4.0, -4 }, 30);
		path.PushBack({ 4.0, -4 }, 30);
		path.PushBack({ -2.0, -4 }, 100);
	}
	if (miem == 3)
	{
		path.PushBack({ 0, -3 }, 370);
		path.PushBack({ 4.0, -4 }, 30);
		path.PushBack({ -4.0, -4 }, 30);
		path.PushBack({ 4.0, -4 }, 30);
		path.PushBack({ -4.0, -4 }, 30);
		path.PushBack({ 4.0, -4 }, 30);
		path.PushBack({ -2.0, -4 }, 100);
	}
	if (miem == 4)
	{
		path.PushBack({ 0, -3 }, 380);
		path.PushBack({ 4.0, -4 }, 30);
		path.PushBack({ -4.0, -4 }, 30);
		path.PushBack({ 4.0, -4 }, 30);
		path.PushBack({ -4.0, -4 }, 30);
		path.PushBack({ 4.0, -4 }, 30);
		path.PushBack({ -2.0, -4 }, 100);
	}
	if (miem == 5)
	{
		path.PushBack({ 0, -3 }, 390);
		path.PushBack({ 4.0, -4 }, 30);
		path.PushBack({ -4.0, -4 }, 30);
		path.PushBack({ 4.0, -4 }, 30);
		path.PushBack({ -4.0, -4 }, 30);
		path.PushBack({ 4.0, -4 }, 30);
		path.PushBack({ -2.0, -4 }, 100);
	}
	if (miem == 6)
	{
		path.PushBack({ 0, -3 }, 400);
		path.PushBack({ 4.0, -4 }, 30);
		path.PushBack({ -4.0, -4 }, 30);
		path.PushBack({ 4.0, -4 }, 30);
		path.PushBack({ -4.0, -4 }, 30);
		path.PushBack({ 4.0, -4 }, 30);
		path.PushBack({ -2.0, -4 }, 100);
	}
	if (miem == 7)
	{
		path.PushBack({ 0, -3 }, 410);
		path.PushBack({ 4.0, -4 }, 30);
		path.PushBack({ -4.0, -4 }, 30);
		path.PushBack({ 4.0, -4 }, 30);
		path.PushBack({ -4.0, -4 }, 30);
		path.PushBack({ 4.0, -4 }, 30);
		path.PushBack({ -2.0, -4 }, 100);
	}
	if (miem == 8)
	{
		path.PushBack({ 0, -3 }, 420);
		path.PushBack({ 4.0, -4 }, 30);
		path.PushBack({ -4.0, -4 }, 30);
		path.PushBack({ 4.0, -4 }, 30);
		path.PushBack({ -4.0, -4 }, 30);
		path.PushBack({ 4.0, -4 }, 30);
		path.PushBack({ -2.0, -4 }, 100);
	}
		
	}
	else if (wave == 4)
	{

	if (miem == 1)
	{
		path.PushBack({ 0, -3 }, 525);
		path.PushBack({ -2.0, -8.0 }, 35);
		path.PushBack({ 0, -13.0 }, 60);
		path.PushBack({ -4, -4 }, 300);
	}
	if (miem == 2)
	{
		path.PushBack({ 0, -3 }, 535);
		path.PushBack({ -2.0, -8.0 }, 35);
		path.PushBack({ 0, -13.0 }, 60);
		path.PushBack({ -4, -4 }, 300);
	}
	if (miem == 3)
	{
		path.PushBack({ 0, -3 }, 545);
		path.PushBack({ -2.0, -8.0 }, 35);
		path.PushBack({ 0, -13.0 }, 60);
		path.PushBack({ -4, -4 }, 300);
	}
	if (miem == 4)
	{
		path.PushBack({ 0, -3 }, 555);
		path.PushBack({ -2.0, -8.0 }, 35);
		path.PushBack({ 0, -13.0 }, 60);
		path.PushBack({ -4, -4 }, 300);
	}
	if (miem == 5)
	{
		path.PushBack({ 0, -3 }, 565);
		path.PushBack({ -2.0, -8.0 }, 35);
		path.PushBack({ 0, -13.0 }, 60);
		path.PushBack({ -4, -4 }, 300);
	}
	if (miem == 6)
	{
		path.PushBack({ 0, -3 }, 575);
		path.PushBack({ -2.0, -8.0 }, 35);
		path.PushBack({ 0, -13.0 }, 60);
		path.PushBack({ -4, -4 }, 300);
	}
	if (miem == 7)
	{
		path.PushBack({ 0, -3 }, 575);
		path.PushBack({ -2.0, -8.0 }, 35);
		path.PushBack({ 0, -13.0 }, 60);
		path.PushBack({ -4, -4 }, 300);
	}
	if (miem == 8)
	{
		path.PushBack({ 0, -3 }, 585);
		path.PushBack({ -2.0, -8.0 }, 35);
		path.PushBack({ 0, -13.0 }, 60);
		path.PushBack({ -4, -4 }, 300);
	}
		
	}
	else if (wave == 5)
	{

	if (miem == 1)
	{
		path.PushBack({ 0, -2.75f }, 440);
		path.PushBack({ 2.0, -2.0 }, 70);
		path.PushBack({ -3, -8.0 }, 60);
		path.PushBack({ 3, -12.0 }, 600);
	}
	if (miem == 2)
	{
		path.PushBack({ 0, -2.75f }, 450);
		path.PushBack({ 2.0, -2.0 }, 70);
		path.PushBack({ -3, -8.0 }, 60);
		path.PushBack({ 3, -12.0 }, 600);
	}
	if (miem == 3)
	{
		path.PushBack({ 0, -2.75f }, 460);
		path.PushBack({ 2.0, -2.0 }, 70);
		path.PushBack({ -3, -8.0 }, 60);
		path.PushBack({ 3, -12.0 }, 600);
	}
	if (miem == 4)
	{
		path.PushBack({ 0, -2.75f }, 470);
		path.PushBack({ 2.0, -2.0 }, 70);
		path.PushBack({ -3, -8.0 }, 60);
		path.PushBack({ 3, -12.0 }, 600);
	}
	if (miem == 5)
	{
		path.PushBack({ 0, -2.75f }, 480);
		path.PushBack({ 2.0, -2.0 }, 70);
		path.PushBack({ -3, -8.0 }, 60);
		path.PushBack({ 3, -12.0 }, 600);
	}
	if (miem == 6)
	{
		path.PushBack({ 0, -2.75f }, 490);
		path.PushBack({ 2.0, -2.0 }, 70);
		path.PushBack({ -3, -8.0 }, 60);
		path.PushBack({ 3, -12.0 }, 600);
	}
	if (miem == 7)
	{
		path.PushBack({ 0, 0.5f }, 280);
		path.PushBack({ 3.0, 2.0 }, 60);
		path.PushBack({ -3, -8.0 }, 60);
		path.PushBack({ 3, -12.0 }, 600);
	}
	if (miem == 8)
	{
		path.PushBack({ 0, 0.5f }, 285);
		path.PushBack({ 3.0, 2.0 }, 60);
		path.PushBack({ -3, -8.0 }, 60);
		path.PushBack({ 3, -12.0 }, 600);
	}
		
	}
	else if (wave == 6)
	{

	if (miem == 1)
	{
		path.PushBack({ 0, -3.0f }, 1125);
		path.PushBack({ -2.0, -8.0f }, 40);
		path.PushBack({ -3, -12 }, 1300);
	}
	if (miem == 2)
	{
		path.PushBack({ 0, -3.0f }, 1135);
		path.PushBack({ -2.0, -8.0f }, 40);
		path.PushBack({ -3, -12 }, 1300);
	}
	if (miem == 3)
	{
		path.PushBack({ 0, -3.0f }, 1145);
		path.PushBack({ -2.0, -8.0f }, 40);
		path.PushBack({ -3, -12 }, 1300);
	}
	if (miem == 4)
	{
		path.PushBack({ 0, -3.0f }, 1155);
		path.PushBack({ -2.0, -8.0f }, 40);
		path.PushBack({ -3, -12 }, 1300);
	}
	if (miem == 5)
	{
		path.PushBack({ 0, -3.0f }, 1165);
		path.PushBack({ -2.0, -8.0f }, 40);
		path.PushBack({ -3, -12 }, 1300);
	}
	if (miem == 6)
	{
		path.PushBack({ 0, -3.0f }, 1175);
		path.PushBack({ -2.0, -8.0f }, 40);
		path.PushBack({ -3, -12 }, 1300);
	}
	if (miem == 7)
	{
		path.PushBack({ 0, -3.0f }, 1185);
		path.PushBack({ -2.0, -8.0f }, 40);
		path.PushBack({ -3, -12 }, 1300);
	}
	if (miem == 8)
	{
		path.PushBack({ 0, -3.0f }, 1125);
		path.PushBack({ -2.0, -8.0f }, 40);
		path.PushBack({ -3, -12 }, 1300);
	}
		
	}
	else if (wave == 7)
	{

	if (miem == 1)
	{
		path.PushBack({ 0, -3.0f }, 1270);
		path.PushBack({ 2.0, -8.0f }, 40);
		path.PushBack({ 3, -12 }, 1300);
	}
	if (miem == 2)
	{
		path.PushBack({ 0, -3.0f }, 1280);
		path.PushBack({ 2.0, -8.0f }, 40);
		path.PushBack({ 3, -12 }, 1300);
	}
	if (miem == 3)
	{
		path.PushBack({ 0, -3.0f }, 1290);
		path.PushBack({ 2.0, -8.0f }, 40);
		path.PushBack({ 3, -12 }, 1300);
	}
	if (miem == 4)
	{
		path.PushBack({ 0, -3.0f }, 1300);
		path.PushBack({ 2.0, -8.0f }, 40);
		path.PushBack({ 3, -12 }, 1300);
	}
	if (miem == 5)
	{
		path.PushBack({ 0, -3.0f }, 1310);
		path.PushBack({ 2.0, -8.0f }, 40);
		path.PushBack({ 3, -12 }, 1300);
	}
	if (miem == 6)
	{
		path.PushBack({ 0, -3.0f }, 1320);
		path.PushBack({ 2.0, -8.0f }, 40);
		path.PushBack({ 3, -12 }, 1300);
	}
	if (miem == 7)
	{
		path.PushBack({ 0, -3.0f }, 1270);
		path.PushBack({ 2.0, -8.0f }, 40);
		path.PushBack({ 3, -12 }, 1300);
	}
	if (miem == 8)
	{
		path.PushBack({ 0, -3.0f }, 1270);
		path.PushBack({ 2.0, -8.0f }, 40);
		path.PushBack({ 3, -12 }, 1300);
	}
	path.PushBack({ 0, 1.0f }, 1305);
	path.PushBack({ 1.0, -3.0f }, 60);
	path.PushBack({ 3, -6 }, 1300);
	
	}
	else if (wave == 8)
	{

	if (miem == 1)
	{
		path.PushBack({ 0, 0.5f }, 1325);
		path.PushBack({ -1.0, 0.5 }, 100);
		path.PushBack({ 1.0, -0.5 }, 50);
		path.PushBack({ -1.5 , -6.0 }, 600);
	}
	if (miem == 2)
	{
		path.PushBack({ 0, 0.5f }, 1340);
		path.PushBack({ 1.0, 0.5 }, 100);
		path.PushBack({ -1.0, -0.5 }, 50);
		path.PushBack({ 1.5 , -6.0 }, 600);
	}
	if (miem == 3)
	{
		path.PushBack({ 0, 0.5f }, 1365);
		path.PushBack({ -1.0, 0.5 }, 100);
		path.PushBack({ 1.0, -0.5 }, 50);
		path.PushBack({ -1.5 , -6.0 }, 600);
	}
	if (miem == 4)
	{
		path.PushBack({ 0, 0.5f }, 1380);
		path.PushBack({ 1.0, 0.5 }, 100);
		path.PushBack({ -1.0, -0.5 }, 50);
		path.PushBack({ 1.5 , -6.0 }, 600);
	}
	if (miem == 5)
	{
		path.PushBack({ 0, 0.5f }, 1395);
		path.PushBack({ -1.0, 0.5 }, 100);
		path.PushBack({ 1.0, -0.5 }, 50);
		path.PushBack({ -1.5 , -6.0 }, 600);
	}
	if (miem == 6)
	{
		path.PushBack({ 0, 0.5f }, 1410);
		path.PushBack({ 1.0, 0.5 }, 100);
		path.PushBack({ -1.0, -0.5 }, 50);
		path.PushBack({ 1.5 , -6.0 }, 600);
	}
	if (miem == 7)
	{
		path.PushBack({ 0, 0.5f }, 1425);
		path.PushBack({ -1.0, 0.5 }, 100);
		path.PushBack({ 1.0, -0.5 }, 50);
		path.PushBack({ -1.5 , -6.0 }, 600);
	}
	if (miem == 8)
	{
		path.PushBack({ 0, 0.5f }, 1440);
		path.PushBack({ 1.0, 0.5 }, 100);
		path.PushBack({ -1.0, -0.5 }, 50);
		path.PushBack({ 1.5 , -6.0 }, 600);
	}

	}
	
	
	
	

	collider = App->collisions->AddCollider({ 0, 0,32, 32 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_RedBall::Update() {
	path.Update();
	position = spawnPos + path.GetRelativePosition();

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
//
void Enemy_RedBall::OnCollision(Collider* c1) {
	fly.PushBack({ 7, 50, 32, 32 });
	fly.PushBack({ 42, 50, 32, 32 });
	fly.PushBack({ 77, 51, 32, 32 });
	fly.PushBack({ 111, 52, 32, 32 });
	fly.PushBack({ 4, 6, 32, 32 });
	currentAnim = &fly;
	fly.speed = 0.2;
	fly.loop = false;
}