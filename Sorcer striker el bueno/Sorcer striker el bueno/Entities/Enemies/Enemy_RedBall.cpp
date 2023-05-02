#include "Enemy_RedBall.h"

#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Core/ModuleRender.h"
#include "../../Modules/Core/ModuleTextures.h"
#include "../../Application/FileNames.h"

Enemy_RedBall::Enemy_RedBall(int x, int y, int wave, int miem) : Enemy(x, y) {
	texture = App->textures->Load(FI_spriteEnemy_1.c_str());
	fly.PushBack({ 48, 12, 22,31 });
	fly.PushBack({ 76,12 ,26, 32 });
	currentAnim = &fly;
	fly.speed = 0.2;
	fly.loop = true;
	// Sescribe a path in the screen
	if (wave == 1)
	{
		if (miem == 1)
		{
			path.PushBack({ 0, 0.5f }, 60);
			path.PushBack({ 5.0, 0.5 },45);
			path.PushBack({ -3, -8.0 }, 55);
			path.PushBack({ 2, -12.0 }, 600);
		}
		if (miem == 2)
		{
			path.PushBack({ 0, 0.5f }, 65);
			path.PushBack({ 5.0, 0.5 }, 45);
			path.PushBack({ -3, -8.0 }, 55);
			path.PushBack({ 2, -12.0 }, 600);
		}
		if (miem == 3)
		{
			path.PushBack({ 0, 0.5f }, 70);
			path.PushBack({ 5.0, 0.5 }, 45);
			path.PushBack({ -3, -8.0 }, 55);
			path.PushBack({ 2, -12.0 }, 600);
		}
		if (miem == 4)
		{
			path.PushBack({ 0, 0.5f }, 75);
			path.PushBack({ 5.0, 0.5 }, 45);
			path.PushBack({ -3, -8.0 }, 55);
			path.PushBack({ 2, -12.0 }, 600);
		}
		if (miem == 5)
		{
			path.PushBack({ 0, 0.5f }, 80);
			path.PushBack({ 5.0, 0.5 }, 45);
			path.PushBack({ -3, -8.0 }, 55);
			path.PushBack({ 2, -12.0 }, 600);
		}
		if (miem == 6)
		{
			path.PushBack({ 0, 0.5f }, 85);
			path.PushBack({ 5.0, 0.5 }, 45);
			path.PushBack({ -3, -8.0 }, 55);
			path.PushBack({ 2, -12.0 }, 600);
		}
		if (miem == 7)
		{
			path.PushBack({ 0, 0.5f }, 90);
			path.PushBack({ 5.0, 0.5 }, 45);
			path.PushBack({ -3, -8.0 }, 55);
			path.PushBack({ 2, -12.0 }, 600);
		}
		if (miem == 8)
		{
			path.PushBack({ 0, 0.5f }, 95);
			path.PushBack({ 5.0, 0.5 }, 45);
			path.PushBack({ -3, -8.0 }, 55);
			path.PushBack({ 2, -12.0 }, 600);
		}
		
	}
	else if (wave == 2)
	{
		if (miem == 1)
		{
			path.PushBack({ 0, 0.5f }, 95);
			path.PushBack({ -4.0, 0.5 }, 50);
			path.PushBack({ 2, -9.0 }, 60);
			path.PushBack({ -2, -12.0 }, 600);
		}
		if (miem == 2)
		{
			path.PushBack({ 0, 0.5f }, 100);
			path.PushBack({ -4.0, 0.5 }, 50);
			path.PushBack({ 2, -9.0 }, 60);
			path.PushBack({ -2, -12.0 }, 600);
		}
		if (miem == 3)
		{
			path.PushBack({ 0, 0.5f }, 105);
			path.PushBack({ -4.0, 0.5 }, 50);
			path.PushBack({ 2, -9.0 }, 60);
			path.PushBack({ -2, -12.0 }, 600);
		}
		if (miem == 4)
		{
			path.PushBack({ 0, 0.5f }, 110);
			path.PushBack({ -4.0, 0.5 }, 50);
			path.PushBack({ 2, -9.0 }, 60);
			path.PushBack({ -2, -12.0 }, 600);
		}
		if (miem == 5)
		{
			path.PushBack({ 0, 0.5f }, 115);
			path.PushBack({ -4.0, 0.5 }, 50);
			path.PushBack({ 2, -9.0 }, 60);
			path.PushBack({ -2, -12.0 }, 600);
		}
		if (miem == 6)
		{
			path.PushBack({ 0, 0.5f }, 120);
			path.PushBack({ -4.0, 0.5 }, 50);
			path.PushBack({ 2, -9.0 }, 60);
			path.PushBack({ -2, -12.0 }, 600);
		}
		if (miem == 7)
		{
			path.PushBack({ 0, 0.5f }, 125);
			path.PushBack({ -4.0, 0.5 }, 50);
			path.PushBack({ 2, -9.0 }, 60);
			path.PushBack({ -2, -12.0 }, 600);
		}
		if (miem == 8)
		{
			path.PushBack({ 0, 0.5f }, 130);
			path.PushBack({ -4.0, 0.5 }, 50);
			path.PushBack({ 2, -9.0 }, 60);
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
		path.PushBack({ 0, 0.5f }, 170);
		path.PushBack({ 3.0, 0.5 }, 30);
		path.PushBack({ -2.0, 0.5 }, 30);
		path.PushBack({ 3.0, 0.5 }, 30);
		path.PushBack({ -2.0, 0.5 }, 100);
	}
	if (miem == 2)
	{
		path.PushBack({ 0, 0.75f }, 175);
		path.PushBack({ 3.0, 0.5 }, 30);
		path.PushBack({ -2.0, 0.5 }, 30);
		path.PushBack({ 3.0, 0.5 }, 30);
		path.PushBack({ -2.0, 0.5 }, 100);
	}
	if (miem == 3)
	{
		path.PushBack({ 0, 0.75f }, 180);
		path.PushBack({ 3.0, 0.5 }, 30);
		path.PushBack({ -2.0, 0.5 }, 30);
		path.PushBack({ 3.0, 0.5 }, 30);
		path.PushBack({ -2.0, 0.5 }, 100);
	}
	if (miem == 4)
	{
		path.PushBack({ 0, 0.75f }, 185);
		path.PushBack({ 3.0, 0.5 }, 30);
		path.PushBack({ -2.0, 0.5 }, 30);
		path.PushBack({ 3.0, 0.5 }, 30);
		path.PushBack({ -2.0, 0.5 }, 100);
	}
	if (miem == 5)
	{
		path.PushBack({ 0, 0.75f }, 190);
		path.PushBack({ 3.0, 0.5 }, 30);
		path.PushBack({ -2.0, 0.5 }, 30);
		path.PushBack({ 3.0, 0.5 }, 30);
		path.PushBack({ -2.0, 0.5 }, 100);
	}
	if (miem == 6)
	{
		path.PushBack({ 0, 0.75f }, 195);
		path.PushBack({ 3.0, 0.5 }, 30);
		path.PushBack({ -2.0, 0.5 }, 30);
		path.PushBack({ 3.0, 0.5 }, 30);
		path.PushBack({ -2.0, 0.5 }, 100);
	}
	if (miem == 7)
	{
		path.PushBack({ 0, 0.75f }, 200);
		path.PushBack({ 3.0, 0.5 }, 30);
		path.PushBack({ -2.0, 0.5 }, 30);
		path.PushBack({ 3.0, 0.5 }, 30);
		path.PushBack({ -2.0, 0.5 }, 100);
	}
	if (miem == 8)
	{
		path.PushBack({ 0, 0.75f }, 205);
		path.PushBack({ 3.0, 0.5 }, 30);
		path.PushBack({ -2.0, 0.5 }, 30);
		path.PushBack({ 3.0, 0.5 }, 30);
		path.PushBack({ -2.0, 0.5 }, 100);
	}
		
	}
	else if (wave == 4)
	{

	if (miem == 1)
	{
		path.PushBack({ 0, 1 }, 290);
		path.PushBack({ -2.0, -8.0 }, 35);
		path.PushBack({ 0, -13.0 }, 90);
		path.PushBack({ -4, -2 }, 300);
	}
	if (miem == 2)
	{
		path.PushBack({ 0, 1 }, 295);
		path.PushBack({ -2.0, -8.0 }, 35);
		path.PushBack({ 0, -13.0 }, 90);
		path.PushBack({ -4, -2 }, 300);
	}
	if (miem == 3)
	{
		path.PushBack({ 0, 1 }, 300);
		path.PushBack({ -2.0, -8.0 }, 35);
		path.PushBack({ 0, -13.0 }, 90);
		path.PushBack({ -4, -2 }, 300);
	}
	if (miem == 4)
	{
		path.PushBack({ 0, 1 }, 305);
		path.PushBack({ -2.0, -8.0 }, 35);
		path.PushBack({ 0, -13.0 }, 90);
		path.PushBack({ -4, -2 }, 300);
	}
	if (miem == 5)
	{
		path.PushBack({ 0, 1 }, 310);
		path.PushBack({ -2.0, -8.0 }, 35);
		path.PushBack({ 0, -13.0 }, 90);
		path.PushBack({ -4, -2 }, 300);;
	}
	if (miem == 6)
	{
		path.PushBack({ 0, 1 }, 315);
		path.PushBack({ -2.0, -8.0 }, 35);
		path.PushBack({ 0, -13.0 }, 90);
		path.PushBack({ -4, -2 }, 300);
	}
	if (miem == 7)
	{
		path.PushBack({ 0, 1 }, 320);
		path.PushBack({ -2.0, -8.0 }, 35);
		path.PushBack({ 0, -13.0 }, 90);
		path.PushBack({ -4, -2 }, 300);
	}
	if (miem == 8)
	{
		path.PushBack({ 0, 1 }, 325);
		path.PushBack({ -2.0, -8.0 }, 35);
		path.PushBack({ 0, -13.0 }, 90);
		path.PushBack({ -4, -2 }, 300);
	}
		
	}
	else if (wave == 5)
	{

	if (miem == 1)
	{
		path.PushBack({ 0, 0.5f }, 250);
		path.PushBack({ 3.0, 2.0 }, 60);
		path.PushBack({ -3, -8.0 }, 60);
		path.PushBack({ 3, -12.0 }, 600);
	}
	if (miem == 2)
	{
		path.PushBack({ 0, 0.5f }, 255);
		path.PushBack({ 3.0, 2.0 }, 60);
		path.PushBack({ -3, -8.0 }, 60);
		path.PushBack({ 3, -12.0 }, 600);
	}
	if (miem == 3)
	{
		path.PushBack({ 0, 0.5f }, 260);
		path.PushBack({ 3.0, 2.0 }, 60);
		path.PushBack({ -3, -8.0 }, 60);
		path.PushBack({ 3, -12.0 }, 600);
	}
	if (miem == 4)
	{
		path.PushBack({ 0, 0.5f }, 265);
		path.PushBack({ 3.0, 2.0 }, 60);
		path.PushBack({ -3, -8.0 }, 60);
		path.PushBack({ 3, -12.0 }, 600);
	}
	if (miem == 5)
	{
		path.PushBack({ 0, 0.5f }, 270);
		path.PushBack({ 3.0, 2.0 }, 60);
		path.PushBack({ -3, -8.0 }, 60);
		path.PushBack({ 3, -12.0 }, 600);
	}
	if (miem == 6)
	{
		path.PushBack({ 0, 0.5f }, 275);
		path.PushBack({ 3.0, 2.0 }, 60);
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
		path.PushBack({ 0, 1.0f }, 500);
		path.PushBack({ -4.0, -8.0f }, 20);
		path.PushBack({ -3, -12 }, 1300);
	}
	if (miem == 2)
	{
		path.PushBack({ 0, 1.0f }, 505);
		path.PushBack({ -4.0, -8.0f }, 20);
		path.PushBack({ -3, -12 }, 1300);
	}
	if (miem == 3)
	{
		path.PushBack({ 0, 1.0f }, 510);
		path.PushBack({ -4.0, -8.0f }, 20);
		path.PushBack({ -3, -12 }, 1300);
	}
	if (miem == 4)
	{
		path.PushBack({ 0, 1.0f }, 515);
		path.PushBack({ -4.0, -8.0f }, 20);
		path.PushBack({ -3, -12 }, 1300);
	}
	if (miem == 5)
	{
		path.PushBack({ 0, 1.0f }, 520);
		path.PushBack({ -4.0, -8.0f }, 20);
		path.PushBack({ -3, -12 }, 1300);
	}
	if (miem == 6)
	{
		path.PushBack({ 0, 1.0f }, 525);
		path.PushBack({ -4.0, -8.0f }, 20);
		path.PushBack({ -3, -12 }, 1300);
	}
	if (miem == 7)
	{
		path.PushBack({ 0, 1.0f }, 530);
		path.PushBack({ -4.0, -8.0f }, 20);
		path.PushBack({ -3, -12 }, 1300);
	}
	if (miem == 8)
	{
		path.PushBack({ 0, 1.0f }, 535);
		path.PushBack({ -4.0, -8.0f }, 20);
		path.PushBack({ -3, -12 }, 1300);
	}
		
	}
	else if (wave == 7)
	{

	if (miem == 1)
	{
		path.PushBack({ 0, 1.0f }, 540);
		path.PushBack({ 4.0, -8.0f }, 20);
		path.PushBack({ 3, -6 }, 1300);
	}
	if (miem == 2)
	{
		path.PushBack({ 0, 1.0f }, 545);
		path.PushBack({ 4.0, -8.0f }, 20);
		path.PushBack({ 3, -6 }, 1300);
	}
	if (miem == 3)
	{
		path.PushBack({ 0, 1.0f }, 550);
		path.PushBack({ 4.0, -8.0f }, 20);
		path.PushBack({ 3, -6 }, 1300);
	}
	if (miem == 4)
	{
		path.PushBack({ 0, 1.0f }, 555);
		path.PushBack({ 4.0, -8.0f }, 20);
		path.PushBack({ 3, -6 }, 1300);
	}
	if (miem == 5)
	{
		path.PushBack({ 0, 1.0f }, 560);
		path.PushBack({ 4.0, -8.0f }, 20);
		path.PushBack({ 3, -6 }, 1300);
	}
	if (miem == 6)
	{
		path.PushBack({ 0, 1.0f }, 565);
		path.PushBack({ 4.0, -8.0f }, 20);
		path.PushBack({ 3, -6 }, 1300);
	}
	if (miem == 7)
	{
		path.PushBack({ 0, 1.0f }, 570);
		path.PushBack({ 4.0, -8.0f }, 20);
		path.PushBack({ 3, -6 }, 1300);
	}
	if (miem == 8)
	{
		path.PushBack({ 0, 1.0f }, 575);
		path.PushBack({ 4.0, -8.0f }, 20);
		path.PushBack({ 3, -6 }, 1300);
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
	
	
	
	

	collider = App->collisions->AddCollider({ 0, 0,22, 32 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_RedBall::Update() {
	path.Update();
	position = spawnPos + path.GetRelativePosition();

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
