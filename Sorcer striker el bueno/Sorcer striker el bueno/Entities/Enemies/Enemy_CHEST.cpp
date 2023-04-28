#include "Enemy_CHEST.h"

#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Gameplay/ModuleEnemies.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleRender.h"
#include"../../Modules/Core/ModuleTextures.h"


Enemy_CHESS::Enemy_CHESS(int x, int y) : Enemy(x, y) {
	texture = App->textures->Load(FI_spritechest_blue.c_str());

	blue.PushBack({ 2, 7, 43, 39 });
	//blue.PushBack({ 47, 7, 43, 39 });
	//blue.PushBack({ 94, 7, 43, 39 });
	currentAnim = &blue;

	// Path 1
	path1.PushBack({ -1.0f, -0.5f }, 10);
	path1.PushBack({ -1.0f, 0.0f }, 10);
	path1.PushBack({ -0.5f, 0.5f }, 10);
	path1.PushBack({ 0.0f, 1.0f }, 10);
	path1.PushBack({ 0.5f, 0.5f }, 10);
	path1.PushBack({ 1.0f, 0.0f }, 10);
	path1.PushBack({ 1.0f, -0.5f }, 10);
	path1.PushBack({ 1.0f, -1.0f }, 10);

	// Path 2
	path2.PushBack({ -0.5f, -1.0f }, 100);
	path2.PushBack({ -0.5f, -0.5f }, 30);
	path2.PushBack({ -0.5f, -0.3f }, 20);
	path2.PushBack({ -0.5f, -0.1f }, 20);
	path2.PushBack({ -0.5f, 0.1f }, 20);
	path2.PushBack({ -0.5f, 0.3f }, 20);
	path2.PushBack({ -0.5f, 0.5f }, 20);
	path2.PushBack({ -0.5f, 1.5f }, 20);
	path2.PushBack({ -0.5f, 3.0f }, 50);

	currentPath = &path1;
	collider = App->collisions->AddCollider({ 0, 0, 43, 39 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_CHESS::Update() {
	path1.Update();
	position = spawnPos + currentPath->GetRelativePosition();

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position 
	Enemy::Update();
}

void Enemy_CHESS::Draw()
{
	if (currentAnim != nullptr)
		App->render->Blit(texture, position.x, position.y, &(currentAnim->GetCurrentFrame()));
}

void Enemy_CHESS::OnCollision(Collider* c1, Collider* c2) {
	if (c1->Intersects(c2->rect) || c2->Intersects(c1->rect)) {
		// Change sprite
		red.PushBack({ 58, 20, 15, 20 });
		red.PushBack({ 72, 54, 15, 20 });
		currentAnim = &red;

		//Change collider
		collider->rect.x = 32;
		collider->rect.w = 41;

		// Change path
		if (currentPath == &path1) {
			currentPath = &path2;
		}
		else {
			currentPath = &path1;
		}
	}
}
