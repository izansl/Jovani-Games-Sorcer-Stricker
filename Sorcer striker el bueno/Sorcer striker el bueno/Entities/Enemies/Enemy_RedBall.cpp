#include "Enemy_RedBall.h"

#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Core/ModuleRender.h"
#include "../../Modules/Core/ModuleTextures.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleAudio.h"

Enemy_RedBall::Enemy_RedBall(int x, int y, int wave, int miem) : Enemy(x, y) {
	texture = App->textures->Load(FI_spriteEnemy_reds.c_str());
	fly.PushBack({ 29, 357, 82, 104 });
	fly.PushBack({ 140, 357, 82, 104 });
	currentAnim = &fly;
	fly.speed = 0.2;
	fly.loop = true;

	// Sescribe a path in the screen
	if (wave == 1)
	{
		if (miem == 1)
		{
			path.PushBack({ 0, 7 }, 230);
			path.PushBack({ 4.0, -1 },55);
			path.PushBack({ -3, -8.0 }, 55);
			path.PushBack({ 2, -12.0 }, 600);
		}
		if (miem == 2)
		{
			path.PushBack({ 0, 7 }, 234);
			path.PushBack({ 4.0, -1 }, 55);
			path.PushBack({ -3, -8.0 }, 55);
			path.PushBack({ 2, -12.0 }, 600);
		}
		if (miem == 3)
		{
			path.PushBack({ 0, 7 }, 238);
			path.PushBack({ 4.0, -1 }, 55);
			path.PushBack({ -3, -8.0 }, 55);
			path.PushBack({ 2, -12.0 }, 600);
		}
		if (miem == 4)
		{
			path.PushBack({ 0, 7 }, 242);
			path.PushBack({ 4.0, -1 }, 55);
			path.PushBack({ -3, -8.0 }, 55);
			path.PushBack({ 2, -12.0 }, 600);
		}
		if (miem == 5)
		{
			path.PushBack({ 0, 7 }, 246);
			path.PushBack({ 4.0, -1 }, 55);
			path.PushBack({ -3, -8.0 }, 55);
			path.PushBack({ 2, -12.0 }, 600);
		}
		if (miem == 6)
		{
			path.PushBack({ 0, 7 }, 250);
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
			path.PushBack({ 0, 3 }, 350);
			path.PushBack({ -4.0, -1 }, 55);
			path.PushBack({ 3, -8.0 }, 55);
			path.PushBack({ -2, -12.0 }, 600);
		}
		if (miem == 2)
		{
			path.PushBack({ 0, 3 }, 355);
			path.PushBack({ -4.0, -1 }, 55);
			path.PushBack({ 3, -8.0 }, 55);
			path.PushBack({ -2, -12.0 }, 600);
		}
		if (miem == 3)
		{
			path.PushBack({ 0, 3 }, 360);
			path.PushBack({ -4.0, -1 }, 55);
			path.PushBack({ 3, -8.0 }, 55);
			path.PushBack({ -2, -12.0 }, 600);
		}
		if (miem == 4)
		{
			path.PushBack({ 0, 3 }, 365);
			path.PushBack({ -4.0, -1 }, 55);
			path.PushBack({ 3, -8.0 }, 55);
			path.PushBack({ -2, -12.0 }, 600);
		}
		if (miem == 5)
		{
			path.PushBack({ 0, 3 }, 370);
			path.PushBack({ -4.0, -1 }, 55);
			path.PushBack({ 3, -8.0 }, 55);
			path.PushBack({ -2, -12.0 }, 600);
		}
		if (miem == 6)
		{
			path.PushBack({ 0, 3 }, 275);
			path.PushBack({ -4.0, -1 }, 55);
			path.PushBack({ 3, -8.0 }, 55);
			path.PushBack({ -2, -12.0 }, 600);
		}
		if (miem == 7)
		{
			path.PushBack({ 0, -3 }, 290);
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
		path.PushBack({ 0, 3 }, 395);
		path.PushBack({ 4.0, -4 }, 30);
		path.PushBack({ -4.0, -4 }, 30);
		path.PushBack({ 4.0, -4 }, 30);
		path.PushBack({ -4.0, -4 }, 30);
		path.PushBack({ 4.0, -4 }, 30);
		path.PushBack({ -2.0, -4 }, 100);
	}
	if (miem == 2)
	{
		path.PushBack({ 0, 3 }, 400);
		path.PushBack({ 4.0, -4 }, 30);
		path.PushBack({ -4.0, -4 }, 30);
		path.PushBack({ 4.0, -4 }, 30);
		path.PushBack({ -4.0, -4 }, 30);
		path.PushBack({ 4.0, -4 }, 30);
		path.PushBack({ -2.0, -4 }, 100);
	}
	if (miem == 3)
	{
		path.PushBack({ 0, 3 }, 405);
		path.PushBack({ 4.0, -4 }, 30);
		path.PushBack({ -4.0, -4 }, 30);
		path.PushBack({ 4.0, -4 }, 30);
		path.PushBack({ -4.0, -4 }, 30);
		path.PushBack({ 4.0, -4 }, 30);
		path.PushBack({ -2.0, -4 }, 100);
	}
	if (miem == 4)
	{
		path.PushBack({ 0, 3 }, 410);
		path.PushBack({ 4.0, -4 }, 30);
		path.PushBack({ -4.0, -4 }, 30);
		path.PushBack({ 4.0, -4 }, 30);
		path.PushBack({ -4.0, -4 }, 30);
		path.PushBack({ 4.0, -4 }, 30);
		path.PushBack({ -2.0, -4 }, 100);
	}
	if (miem == 5)
	{
		path.PushBack({ 0, 3 }, 415);
		path.PushBack({ 4.0, -4 }, 30);
		path.PushBack({ -4.0, -4 }, 30);
		path.PushBack({ 4.0, -4 }, 30);
		path.PushBack({ -4.0, -4 }, 30);
		path.PushBack({ 4.0, -4 }, 30);
		path.PushBack({ -2.0, -4 }, 100);
	}
	if (miem == 6)
	{
		path.PushBack({ 0, 3 }, 420);
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
		path.PushBack({ 0, 1 }, 625);
		path.PushBack({ -2.0, -8.0 }, 35);
		path.PushBack({ 0, -13.0 }, 60);
		path.PushBack({ -4, -4 }, 300);
	}
	if (miem == 2)
	{
		path.PushBack({ 0, 1 }, 632);
		path.PushBack({ -2.0, -8.0 }, 35);
		path.PushBack({ 0, -13.0 }, 60);
		path.PushBack({ -4, -4 }, 300);
	}
	if (miem == 3)
	{
		path.PushBack({ 0, 1 }, 639);
		path.PushBack({ -2.0, -8.0 }, 35);
		path.PushBack({ 0, -13.0 }, 60);
		path.PushBack({ -4, -4 }, 300);
	}
	if (miem == 4)
	{
		path.PushBack({ 0, 1 }, 646);
		path.PushBack({ -2.0, -8.0 }, 35);
		path.PushBack({ 0, -13.0 }, 60);
		path.PushBack({ -4, -4 }, 300);
	}
	if (miem == 5)
	{
		path.PushBack({ 0, 1 }, 653);
		path.PushBack({ -2.0, -8.0 }, 35);
		path.PushBack({ 0, -13.0 }, 60);
		path.PushBack({ -4, -4 }, 300);
	}
	if (miem == 6)
	{
		path.PushBack({ 0, 1 }, 660);
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
		path.PushBack({ 0, 0 }, 730);
		path.PushBack({ 2.0, -2.0 }, 70);
		path.PushBack({ -3, -8.0 }, 60);
		path.PushBack({ 3, -12.0 }, 600);
	}
	if (miem == 2)
	{
		path.PushBack({ 0, 0 }, 737);
		path.PushBack({ 2.0, -2.0 }, 70);
		path.PushBack({ -3, -8.0 }, 60);
		path.PushBack({ 3, -12.0 }, 600);
	}
	if (miem == 3)
	{
		path.PushBack({ 0, 0 }, 744);
		path.PushBack({ 2.0, -2.0 }, 70);
		path.PushBack({ -3, -8.0 }, 60);
		path.PushBack({ 3, -12.0 }, 600);
	}
	if (miem == 4)
	{
		path.PushBack({ 0, 0 }, 751);
		path.PushBack({ 2.0, -2.0 }, 70);
		path.PushBack({ -3, -8.0 }, 60);
		path.PushBack({ 3, -12.0 }, 600);
	}
	if (miem == 5)
	{
		path.PushBack({ 0, 0 }, 758);
		path.PushBack({ 2.0, -2.0 }, 70);
		path.PushBack({ -3, -8.0 }, 60);
		path.PushBack({ 3, -12.0 }, 600);
	}
	if (miem == 6)
	{
		path.PushBack({ 0,  0 }, 765);
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
		path.PushBack({ 0, -2.5f }, 1630);
		path.PushBack({ -2.0, -8.0f }, 40);
		path.PushBack({ -3, -12 }, 1300);
	}
	if (miem == 2)
	{
		path.PushBack({ 0, -2.5f }, 1640);
		path.PushBack({ -2.0, -8.0f }, 40);
		path.PushBack({ -3, -12 }, 1300);
	}
	if (miem == 3)
	{
		path.PushBack({ 0, -2.5f }, 1650);
		path.PushBack({ -2.0, -8.0f }, 40);
		path.PushBack({ -3, -12 }, 1300);
	}
	if (miem == 4)
	{
		path.PushBack({ 0, -2.5f }, 1660);
		path.PushBack({ -2.0, -8.0f }, 40);
		path.PushBack({ -3, -12 }, 1300);
	}
	if (miem == 5)
	{
		path.PushBack({ 0, -2.5f }, 1670);
		path.PushBack({ -2.0, -8.0f }, 40);
		path.PushBack({ -3, -12 }, 1300);
	}
	if (miem == 6)
	{
		path.PushBack({ 0,-2.5f }, 1680);
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
		path.PushBack({ 0, -3.0f }, 1930);
		path.PushBack({ 2.0, -8.0f }, 40);
		path.PushBack({ 3, -12 }, 1300);
	}
	if (miem == 2)
	{
		path.PushBack({ 0, -3.0f }, 1945);
		path.PushBack({ 2.0, -8.0f }, 40);
		path.PushBack({ 3, -12 }, 1300);
	}
	if (miem == 3)
	{
		path.PushBack({ 0, -3.0f }, 1960);
		path.PushBack({ 2.0, -8.0f }, 40);
		path.PushBack({ 3, -12 }, 1300);
	}
	if (miem == 4)
	{
		path.PushBack({ 0, -3.0f }, 1975);
		path.PushBack({ 2.0, -8.0f }, 40);
		path.PushBack({ 3, -12 }, 1300);
	}
	if (miem == 5)
	{
		path.PushBack({ 0, -3.0f }, 1990);
		path.PushBack({ 2.0, -8.0f }, 40);
		path.PushBack({ 3, -12 }, 1300);
	}
	if (miem == 6)
	{
		path.PushBack({ 0, -3.0f }, 2005);
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
	
	
	
	

	collider = App->collisions->AddCollider({ 0, 0,82, 104 }, Collider::Type::ENEMY, (Module*)App->enemies);
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
	fly.PushBack({ 1, 136, 139, 137 });
	fly.PushBack({ 155, 140, 139, 137 });
	fly.PushBack({ 335, 142, 139, 137 });
	fly.PushBack({ 586, 139, 139, 137 });
	fly.PushBack({ 644, 142, 139, 137 });
	fly.PushBack({ 798, 142, 139, 137 });

	currentAnim = &fly;
	fly.speed = 0.2;
	fly.loop = false;
	App->audio->PlayFx(destroyedFx);
}