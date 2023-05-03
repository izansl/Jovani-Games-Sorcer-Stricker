#include "Enemy_RedBall.h"

#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Core/ModuleRender.h"
#include "../../Modules/Core/ModuleTextures.h"
#include "../../Application/FileNames.h"

Enemy_RedBall::Enemy_RedBall(int x, int y, int wave, int miem) : Enemy(x, y) {
	texture = App->textures->Load(FI_spriteEnemy_1.c_str());
	fly.PushBack({ 46, 12, 26,32 });
	fly.PushBack({ 75,12 ,26, 32 });
	currentAnim = &fly;
	fly.speed = 0.2;
	fly.loop = true;
	// Sescribe a path in the screen
	if (wave == 1)
	{
		if (miem == 1)
		{
			path.PushBack({ 0, 0.5f }, 150);
			path.PushBack({ 2.0, 1.0 }, 125);
			path.PushBack({ -1.5, -5.0 }, 125);
			path.PushBack({ 1.5, -5.0 }, 600);
		}
		if (miem == 2)
		{
			path.PushBack({ 0, 0.5f }, 165);
			path.PushBack({ 2.0, 1.0 }, 125);
			path.PushBack({ -1.5, -5.0 }, 125);
			path.PushBack({ 1.5, -5.0 }, 600);
		}
		if (miem == 3)
		{
			path.PushBack({ 0, 0.5f }, 180);
			path.PushBack({ 2.0, 1.0 }, 125);
			path.PushBack({ -1.5, -5.0 }, 125);
			path.PushBack({ 1.5, -5.0 }, 600);
		}
		if (miem == 4)
		{
			path.PushBack({ 0, 0.5f }, 195);
			path.PushBack({ 2.0, 1.0 }, 125);
			path.PushBack({ -1.5, -5.0 }, 125);
			path.PushBack({ 1.5, -5.0 }, 600);
		}
		if (miem == 5)
		{
			path.PushBack({ 0, 0.5f }, 210);
			path.PushBack({ 2.0, 1.0 }, 125);
			path.PushBack({ -1.5, -5.0 }, 125);
			path.PushBack({ 1.5, -5.0 }, 600);
		}
		if (miem == 6)
		{
			path.PushBack({ 0, 0.5f }, 225);
			path.PushBack({ 2.0, 1.0 }, 125);
			path.PushBack({ -1.5, -5.0 }, 125);
			path.PushBack({ 1.5, -5.0 }, 600);
		}
		if (miem == 7)
		{
			path.PushBack({ 0, 0.5f }, 240);
			path.PushBack({ 2.0, 1.0 }, 125);
			path.PushBack({ -1.5, -5.0 }, 125);
			path.PushBack({ 1.5, -5.0 }, 600);
		}
		if (miem == 8)
		{
			path.PushBack({ 0, 0.5f }, 255);
			path.PushBack({ 2.0, 1.0 }, 125);
			path.PushBack({ -1.5, -5.0 }, 125);
			path.PushBack({ 1.5, -5.0 }, 600);
		}
		
	}
	else if (wave == 2)
	{
		if (miem == 1)
		{
			path.PushBack({ 0, 0.5f }, 250);
			path.PushBack({ -2.0, 1.0 }, 100);
			path.PushBack({ 1.0, -5.0 }, 50);
			path.PushBack({ 0.75, -6.0 }, 600);
		}
		if (miem == 2)
		{
			path.PushBack({ 0, 0.5f }, 265);
			path.PushBack({ -2.0, 1.0 }, 100);
			path.PushBack({ 1.0, -5.0 }, 50);
			path.PushBack({ 0.75, -6.0 }, 600);
		}
		if (miem == 3)
		{
			path.PushBack({ 0, 0.5f }, 280);
			path.PushBack({ -2.0, 1.0 }, 165);
			path.PushBack({ 1.0, -5.0 }, 50);
			path.PushBack({ 0.75, -6.0 }, 600);
		}
		if (miem == 4)
		{
			path.PushBack({ 0, 0.5f }, 295);
			path.PushBack({ -2.0, 1.0 }, 100);
			path.PushBack({ 1.0, -5.0 }, 50);
			path.PushBack({ 0.75, -6.0 }, 600);
		}
		if (miem == 5)
		{
			path.PushBack({ 0, 0.5f }, 310);
			path.PushBack({ -2.0, 1.0 }, 100);
			path.PushBack({ 1.0, -5.0 }, 50);
			path.PushBack({ 0.75, -6.0 }, 600);
		}
		if (miem == 6)
		{
			path.PushBack({ 0, 0.5f }, 325);
			path.PushBack({ -2.0, 1.0 }, 100);
			path.PushBack({ 1.0, -5.0 }, 50);
			path.PushBack({ 0.75, -6.0 }, 600);
		}
		if (miem == 7)
		{
			path.PushBack({ 0, 0.5f }, 340);
			path.PushBack({ -2.0, 1.0 }, 100);
			path.PushBack({ 1.0, -5.0 }, 50);
			path.PushBack({ 0.75, -6.0 }, 600);
		}
		if (miem == 8)
		{
			path.PushBack({ 0, 0.5f }, 355);
			path.PushBack({ -2.0, 1.0 }, 100);
			path.PushBack({ 1.0, -5.0 }, 50);
			path.PushBack({ 0.75, -6.0 }, 600);
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
		path.PushBack({ 0, 0.75f }, 500);
		path.PushBack({ 1.0, 0.5 }, 100);
		path.PushBack({ -1.0, 0.5 }, 100);
		path.PushBack({ 1.0, 0.5 }, 100);
		path.PushBack({ -1.0, 0.5 }, 100);
	}
	if (miem == 2)
	{
		path.PushBack({ 0, 0.75f }, 515);
		path.PushBack({ 1.0, 0.5 }, 100);
		path.PushBack({ -1.0, 0.5 }, 100);
		path.PushBack({ 1.0, 0.5 }, 100);
		path.PushBack({ -1.0, 0.5 }, 100);
	}
	if (miem == 3)
	{
		path.PushBack({ 0, 0.75f }, 530);
		path.PushBack({ 1.0, 0.5 }, 100);
		path.PushBack({ -1.0, 0.5 }, 100);
		path.PushBack({ 1.0, 0.5 }, 100);
		path.PushBack({ -1.0, 0.5 }, 100);
	}
	if (miem == 4)
	{
		path.PushBack({ 0, 0.75f }, 545);
		path.PushBack({ 1.0, 0.5 }, 100);
		path.PushBack({ -1.0, 0.5 }, 100);
		path.PushBack({ 1.0, 0.5 }, 100);
		path.PushBack({ -1.0, 0.5 }, 100);
	}
	if (miem == 5)
	{
		path.PushBack({ 0, 0.75f }, 560);
		path.PushBack({ 1.0, 0.5 }, 100);
		path.PushBack({ -1.0, 0.5 }, 100);
		path.PushBack({ 1.0, 0.5 }, 100);
		path.PushBack({ -1.0, 0.5 }, 100);
	}
	if (miem == 6)
	{
		path.PushBack({ 0, 0.75f }, 575);
		path.PushBack({ 1.0, 0.5 }, 100);
		path.PushBack({ -1.0, 0.5 }, 100);
		path.PushBack({ 1.0, 0.5 }, 100);
		path.PushBack({ -1.0, 0.5 }, 100);
	}
	if (miem == 7)
	{
		path.PushBack({ 0, 0.75f }, 590);
		path.PushBack({ 1.0, 0.5 }, 100);
		path.PushBack({ -1.0, 0.5 }, 100);
		path.PushBack({ 1.0, 0.5 }, 100);
		path.PushBack({ -1.0, 0.5 }, 100);
	}
	if (miem == 8)
	{
		path.PushBack({ 0, 0.75f }, 605);
		path.PushBack({ 1.0, 0.5 }, 100);
		path.PushBack({ -1.0, 0.5 }, 100);
		path.PushBack({ 1.0, 0.5 }, 100);
		path.PushBack({ -1.0, 0.5 }, 100);
	}
		
	}
	else if (wave == 4)
	{

	if (miem == 1)
	{
		path.PushBack({ 0, 1 }, 600);
		path.PushBack({ -1.5, -3.0 }, 75);
		path.PushBack({ 0, -6.0 }, 100);
		path.PushBack({ -2, 1 }, 300);
	}
	if (miem == 2)
	{
		path.PushBack({ 0, 1 }, 615);
		path.PushBack({ -1.5, -3.0 }, 75);
		path.PushBack({ 0, -6.0 }, 100);
		path.PushBack({ -2, 1 }, 300);
	}
	if (miem == 3)
	{
		path.PushBack({ 0, 1 }, 630);
		path.PushBack({ -1.5, -3.0 }, 75);
		path.PushBack({ 0, -6.0 }, 100);
		path.PushBack({ -2, 1 }, 300);
	}
	if (miem == 4)
	{
		path.PushBack({ 0, 1 }, 645);
		path.PushBack({ -1.5, -3.0 }, 75);
		path.PushBack({ 0, -6.0 }, 100);
		path.PushBack({ -2, 1 }, 300);
	}
	if (miem == 5)
	{
		path.PushBack({ 0, 1 }, 660);
		path.PushBack({ -1.5, -3.0 }, 75);
		path.PushBack({ 0, -6.0 }, 100);
		path.PushBack({ -2, 1 }, 300);
	}
	if (miem == 6)
	{
		path.PushBack({ 0, 1 }, 675);
		path.PushBack({ -1.5, -3.0 }, 75);
		path.PushBack({ 0, -6.0 }, 100);
		path.PushBack({ -2, 1 }, 300);
	}
	if (miem == 7)
	{
		path.PushBack({ 0, 1 }, 690);
		path.PushBack({ -1.5, -3.0 }, 75);
		path.PushBack({ 0, -6.0 }, 100);
		path.PushBack({ -2, 1 }, 300);
	}
	if (miem == 8)
	{
		path.PushBack({ 0, 1 }, 705);
		path.PushBack({ -1.5, -3.0 }, 75);
		path.PushBack({ 0, -6.0 }, 100);
		path.PushBack({ -2, 1 }, 300);
	}
		
	}
	else if (wave == 5)
	{

	if (miem == 1)
	{
		path.PushBack({ 0, 1.0f }, 700);
		path.PushBack({ 2.0, 1.0 }, 125);
		path.PushBack({ -1.5, -3.0 }, 125);
		path.PushBack({ 1.5, -5.0 }, 600);
	}
	if (miem == 2)
	{
		path.PushBack({ 0, 1.0f }, 715);
		path.PushBack({ 2.0, 1.0 }, 125);
		path.PushBack({ -1.5, -3.0 }, 125);
		path.PushBack({ 1.5, -5.0 }, 600);
	}
	if (miem == 3)
	{
		path.PushBack({ 0, 1.0f }, 730);
		path.PushBack({ 2.0, 1.0 }, 125);
		path.PushBack({ -1.5, -3.0 }, 125);
		path.PushBack({ 1.5, -5.0 }, 600);
	}
	if (miem == 4)
	{
		path.PushBack({ 0, 1.0f }, 745);
		path.PushBack({ 2.0, 1.0 }, 125);
		path.PushBack({ -1.5, -3.0 }, 125);
		path.PushBack({ 1.5, -5.0 }, 600);
	}
	if (miem == 5)
	{
		path.PushBack({ 0, 1.0f }, 760);
		path.PushBack({ 2.0, 1.0 }, 125);
		path.PushBack({ -1.5, -3.0 }, 125);
		path.PushBack({ 1.5, -5.0 }, 600);
	}
	if (miem == 6)
	{
		path.PushBack({ 0, 1.0f }, 775);
		path.PushBack({ 2.0, 1.0 }, 125);
		path.PushBack({ -1.5, -3.0 }, 125);
		path.PushBack({ 1.5, -5.0 }, 600);
	}
	if (miem == 7)
	{
		path.PushBack({ 0, 1.0f }, 790);
		path.PushBack({ 2.0, 1.0 }, 125);
		path.PushBack({ -1.5, -3.0 }, 125);
		path.PushBack({ 1.5, -5.0 }, 600);
	}
	if (miem == 8)
	{
		path.PushBack({ 0, 1.0f }, 805);
		path.PushBack({ 2.0, 1.0 }, 125);
		path.PushBack({ -1.5, -3.0 }, 125);
		path.PushBack({ 1.5, -5.0 }, 600);
	}
		
	}
	else if (wave == 6)
	{

	if (miem == 1)
	{
		path.PushBack({ 0, 1.0f }, 1100);
		path.PushBack({ -1.0, -3.0f }, 60);
		path.PushBack({ -3, -6 }, 1300);
	}
	if (miem == 2)
	{
		path.PushBack({ 0, 1.0f }, 1115);
		path.PushBack({ -1.0, -3.0f }, 60);
		path.PushBack({ -3, -6 }, 1300);
	}
	if (miem == 3)
	{
		path.PushBack({ 0, 1.0f }, 1130);
		path.PushBack({ -1.0, -3.0f }, 60);
		path.PushBack({ -3, -6 }, 1300);
	}
	if (miem == 4)
	{
		path.PushBack({ 0, 1.0f }, 1145);
		path.PushBack({ -1.0, -3.0f }, 60);
		path.PushBack({ -3, -6 }, 1300);
	}
	if (miem == 5)
	{
		path.PushBack({ 0, 1.0f }, 1160);
		path.PushBack({ -1.0, -3.0f }, 60);
		path.PushBack({ -3, -6 }, 1300);
	}
	if (miem == 6)
	{
		path.PushBack({ 0, 1.0f }, 1175);
		path.PushBack({ -1.0, -3.0f }, 60);
		path.PushBack({ -3, -6 }, 1300);
	}
	if (miem == 7)
	{
		path.PushBack({ 0, 1.0f }, 1190);
		path.PushBack({ -1.0, -3.0f }, 60);
		path.PushBack({ -3, -6 }, 1300);
	}
	if (miem == 8)
	{
		path.PushBack({ 0, 1.0f }, 1205);
		path.PushBack({ -1.0, -3.0f }, 60);
		path.PushBack({ -3, -6 }, 1300);
	}
		
	}
	else if (wave == 7)
	{

	if (miem == 1)
	{
		path.PushBack({ 0, 1.0f }, 1200);
		path.PushBack({ 1.0, -3.0f }, 60);
		path.PushBack({ 3, -6 }, 1300);
	}
	if (miem == 2)
	{
		path.PushBack({ 0, 1.0f }, 1215);
		path.PushBack({ 1.0, -3.0f }, 60);
		path.PushBack({ 3, -6 }, 1300);
	}
	if (miem == 3)
	{
		path.PushBack({ 0, 1.0f }, 1230);
		path.PushBack({ 1.0, -3.0f }, 60);
		path.PushBack({ 3, -6 }, 1300);
	}
	if (miem == 4)
	{
		path.PushBack({ 0, 1.0f }, 1245);
		path.PushBack({ 1.0, -3.0f }, 60);
		path.PushBack({ 3, -6 }, 1300);
	}
	if (miem == 5)
	{
		path.PushBack({ 0, 1.0f }, 1260);
		path.PushBack({ 1.0, -3.0f }, 60);
		path.PushBack({ 3, -6 }, 1300);
	}
	if (miem == 6)
	{
		path.PushBack({ 0, 1.0f }, 1275);
		path.PushBack({ 1.0, -3.0f }, 60);
		path.PushBack({ 3, -6 }, 1300);
	}
	if (miem == 7)
	{
		path.PushBack({ 0, 1.0f }, 1290);
		path.PushBack({ 1.0, -3.0f }, 60);
		path.PushBack({ 3, -6 }, 1300);
	}
	if (miem == 8)
	{
		path.PushBack({ 0, 1.0f }, 1305);
		path.PushBack({ 1.0, -3.0f }, 60);
		path.PushBack({ 3, -6 }, 1300);
	}
	
	
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

void Enemy_RedBall::OnCollision(Collider* c1) {
	space.PushBack({ 15, 6, 22, 36 });
	currentAnim = &space;

	//Change collider
	collider->rect.x = 0;
	collider->rect.w = 0;
}