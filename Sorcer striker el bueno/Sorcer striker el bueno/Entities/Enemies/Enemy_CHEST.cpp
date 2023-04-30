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
	blue.PushBack({ 47, 7, 43, 39 });
	blue.PushBack({ 94, 7, 43, 39 });
	blue.speed = 0.05f;
	currentAnim = &blue;

	// Path 1
	/*&path1.steps[1]->animation = blue;*/
	path1.PushBack({ -1.0f, -0.5f }, 10);
	path1.PushBack({ -1.0f, 0.0f }, 10);
	path1.PushBack({ -0.5f, 0.5f }, 10);
	path1.PushBack({ 0.0f, 1.0f }, 10);
	path1.PushBack({ 0.5f, 0.5f }, 10);
	path1.PushBack({ 1.0f, 0.0f }, 10);
	path1.PushBack({ 1.0f, -0.5f }, 10);
	path1.PushBack({ 1.0f, -1.0f }, 10);

	// Path 2
	path2.PushBack({ -0.5f, -1.0f }, 60); // velocidad reducida a 60
	path2.PushBack({ -0.5f, -1.0f }, 30); // permanece en su lugar durante 30 milisegundos
	path2.PushBack({ -0.5f, -2.0f }, 30); // se mueve hacia arriba durante 30 milisegundos
	path2.PushBack({ -0.5f, -3.0f }, 60); // se mueve hacia arriba durante 60 milisegundos
	path2.PushBack({ -0.5f, -2.0f }, 30); // se mueve hacia abajo durante 30 milisegundos
	path2.PushBack({ -0.5f, -1.0f }, 60); // se mueve hacia abajo durante 60 milisegundos

	currentPath = &path1;
	collider = App->collisions->AddCollider({ 0, 0, 43, 39 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_CHESS::Update() {
	if (!activePart2) 
		path1.Update();
	else 
		path2.Update();

	position = spawnPos + currentPath->GetRelativePosition();

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position 
	Enemy::Update();

}

//void Enemy_CHESS::Draw()
//{
//	if (currentAnim != nullptr)
//		App->render->Blit(texture, position.x, position.y, &(currentAnim->GetCurrentFrame()));
//}

void Enemy_CHESS::OnCollision(Collider* c1) {
	if (c1->type == Collider::Type::PLAYER_SHOT)
	{
		// Change sprite
		red.PushBack({ 58, 20, 15, 20 });
		red.PushBack({ 72, 54, 15, 20 });
		red.speed = 0.1f;
		currentAnim = &red;

		// Change path
		currentPath = &path2;

		//Change Collider type
		collider->type = static_cast<Collider::Type>(Collider::Type::OBJECT);
		collider->rect = { 0, 0, 15, 20 };

		// Active path2 update
		activePart2 = true;
	}
}
