#include "Enemy_Dragon.h"

#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Core/ModuleRender.h"
#include "../../Modules/Core/ModuleTextures.h"
#include "../../Application/FileNames.h"

Enemy_Dragon::Enemy_Dragon(int x, int y, int wave, int miem) : Enemy(x, y) {
	texture = App->textures->Load(FI_spriteEnemy_3.c_str());

	fly.PushBack({ 16, 24 , 85, 89 });
	fly.PushBack({ 117, 27 , 85, 89 });
	fly.loop = true;
	currentAnim = &fly;
	fly.speed = 0.1f;
	if (wave == 1)
	{
		if (miem == 0)
		{
			path.PushBack({ 0, -3 }, 1050);
			path.PushBack({ 0, -8.0 }, 100);
			path.PushBack({ 2, -8.0 }, 10);
			path.PushBack({ 0, -8.0 }, 50);
			path.PushBack({ -0.75, -10.0 }, 50);
			path.PushBack({ 0, -8.0 }, 10);
			path.PushBack({ 0, -3.0 }, 50);
			path.PushBack({ -1, -12.0 }, 200);
		}
		

	}
	else if (wave == 2)
	{
		if (miem == 0)
		{
			
			path.PushBack({ 0, -3 }, 1200);
			path.PushBack({ 0, -8.0 }, 100);
			path.PushBack({ -2, -8.0 }, 10);
			path.PushBack({ 0, -8.0 }, 50);
			path.PushBack({ 0.75, -10.0 }, 50);
			path.PushBack({ 0, -8.0 }, 10);
			path.PushBack({ 0, -3.0 }, 50);
			path.PushBack({ 1, -12.0 }, 200);
		}
	}
	// Describe a path in the screen
	path.PushBack({ 0, 0.5f }, 100);
	

	collider = App->collisions->AddCollider({ 0, 0, 85, 89 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_Dragon::Update() {
	path.Update();
	position = spawnPos + path.GetRelativePosition();

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
//void Enemy_Dragon::Draw()
//{
//	if (currentAnim != nullptr)
//	{
//		App->render->Blit(texture, position.x, position.y, &(currentAnim->GetCurrentFrame()));
//	}
//}

void Enemy_Dragon::OnCollision(Collider* c1) {
	

	fly.PushBack({ 20, 121, 85, 89 });
	fly.PushBack({ 113, 125, 85, 89});
	fly.PushBack({ 207, 122, 85, 89 });
	fly.PushBack({ 15, 211, 85, 89 });
	currentAnim = &fly;
	fly.speed = 0.2;
	fly.loop = false;

}