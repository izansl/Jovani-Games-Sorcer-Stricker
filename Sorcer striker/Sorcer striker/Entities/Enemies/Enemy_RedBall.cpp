#include "Enemy_RedBall.h"

#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Core/ModuleRender.h"
#include "../../Modules/Gameplay/SceneLevel1.h"
#include "../../Modules/Core/ModuleTextures.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleAudio.h"

Enemy_RedBall::Enemy_RedBall(int x, int y, int wave) : Enemy(x, y) {
	texture = App->textures->Load(FI_spriteEnemy_reds.c_str());
	fly.PushBack({ 29, 357, 82, 104 });
	fly.PushBack({ 140, 357, 82, 104 });
	currentAnim = &fly;
	fly.speed = 0.2;
	fly.loop = true;

	// Sescribe a path in the screen
	if (wave == 1)
	{

			path.PushBack({0, (float)App->sceneLevel_1->velocitatNivell + 5 }, 20);
			path.PushBack({ 7.0, (float)App->sceneLevel_1->velocitatNivell + 8 },80);
			path.PushBack({ -6, (float)App->sceneLevel_1->velocitatNivell }, 80);
			path.PushBack({ 5, (float)App->sceneLevel_1->velocitatNivell*2 }, 600);
		
	}
	else if (wave == 2)
	{
		
		path.PushBack({ 0, (float)App->sceneLevel_1->velocitatNivell + 5 }, 20);
		path.PushBack({ -7.0, (float)App->sceneLevel_1->velocitatNivell + 8 }, 80);
		path.PushBack({ 6, (float)App->sceneLevel_1->velocitatNivell }, 80);
		path.PushBack({ -5, (float)App->sceneLevel_1->velocitatNivell * 2 }, 600);
		
		
	}
	else if (wave == 3)
	{

	
		path.PushBack({ 0, (float)App->sceneLevel_1->velocitatNivell + 5  /*-3*/ }, 10);
		path.PushBack({ 8.0, (float)App->sceneLevel_1->velocitatNivell + 4 }, 60);
		path.PushBack({ -8.0,(float)App->sceneLevel_1->velocitatNivell + 4 }, 60);
		path.PushBack({ 8.0, (float)App->sceneLevel_1->velocitatNivell + 4 }, 60);
		path.PushBack({ -8.0,(float)App->sceneLevel_1->velocitatNivell + 4 }, 60);
		path.PushBack({ 8.0, (float)App->sceneLevel_1->velocitatNivell + 4 }, 60);
		path.PushBack({ -8.0,(float)App->sceneLevel_1->velocitatNivell + 4 }, 100);
	
		
	}
	else if (wave == 4)
	{

	
		path.PushBack({ 0, (float)App->sceneLevel_1->velocitatNivell +7 }, 100);
		path.PushBack({ -6.0, (float)App->sceneLevel_1->velocitatNivell }, 20);
		path.PushBack({ 0, (float)App->sceneLevel_1->velocitatNivell -8 }, 70);
		path.PushBack({ -8, (float)App->sceneLevel_1->velocitatNivell + 4 }, 300);
		
	}
	else if (wave == 5)
	{

	
		path.PushBack({ 0, (float)App->sceneLevel_1->velocitatNivell + 5 }, 20);
		path.PushBack({ 7.0, (float)App->sceneLevel_1->velocitatNivell + 8 }, 80);
		path.PushBack({ -6, (float)App->sceneLevel_1->velocitatNivell }, 80);
		path.PushBack({ 5, (float)App->sceneLevel_1->velocitatNivell * 2 }, 600);
	
		
	}
	else if (wave == 6)
	{

	
		path.PushBack({ 0, (float)App->sceneLevel_1->velocitatNivell +8  }, 90);
		path.PushBack({ -2.0, (float)App->sceneLevel_1->velocitatNivell }, 40);
		path.PushBack({ -4, (float)App->sceneLevel_1->velocitatNivell - 4 }, 1300);
	
	
		
	}
	else if (wave == 7)
	{

		path.PushBack({ 0, (float)App->sceneLevel_1->velocitatNivell + 8 }, 90);
		path.PushBack({ 2.0, (float)App->sceneLevel_1->velocitatNivell }, 40);
		path.PushBack({ 4, (float)App->sceneLevel_1->velocitatNivell - 4 }, 1300);
	
	}
	else if (wave == 8)
	{

		path.PushBack({ 0, (float)App->sceneLevel_1->velocitatNivell + 5 }, 20);
		path.PushBack({ 7.0, (float)App->sceneLevel_1->velocitatNivell + 8 }, 80);
		path.PushBack({ -6, (float)App->sceneLevel_1->velocitatNivell }, 80);
		path.PushBack({ 5, (float)App->sceneLevel_1->velocitatNivell * 2 }, 600);

	}
	else if (wave == 9)
	{
		path.PushBack({ 0, (float)App->sceneLevel_1->velocitatNivell + 5 }, 20);
		path.PushBack({ -7.0, (float)App->sceneLevel_1->velocitatNivell + 8 }, 80);
		path.PushBack({ 6, (float)App->sceneLevel_1->velocitatNivell }, 80);
		path.PushBack({ -5, (float)App->sceneLevel_1->velocitatNivell * 2 }, 600);
	}
	
	
	
	

	collider = App->collisions->AddCollider({ 0, 0,82, 104 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_RedBall::Update() {
	

	if (life)
	{
		path.Update();
		position = spawnPos + path.GetRelativePosition();

	}
	
	
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
	fly.PushBack({ 1000, 300, 139, 137 });

	currentAnim = &fly;
	fly.speed = 0.2;
	fly.loop = false;
	App->audio->PlayFx(destroyedFx);
	life = false;
}