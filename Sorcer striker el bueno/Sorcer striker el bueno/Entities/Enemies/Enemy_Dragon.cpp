#include "Enemy_Dragon.h"

#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Core/ModuleRender.h"
#include "../../Modules/Core/ModuleTextures.h"
#include "../../Application/FileNames.h"

Enemy_Dragon::Enemy_Dragon(int x, int y) : Enemy(x, y) {
	texture = App->textures->Load(FI_spriteEnemy_3.c_str());

	fly.PushBack({ 16, 24 , 85, 89 });
	fly.PushBack({ 117, 27 , 85, 89 });
	fly.loop = true;
	currentAnim = &fly;
	fly.speed = 0.1f;

	// Describe a path in the screen
	path.PushBack({ 0, -2.0f }, 100);
	

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
void Enemy_Dragon::OnCollision(Collider* c1, Collider* c2) {
	if (c1->Intersects(c2->rect) || c2->Intersects(c1->rect)) {
		texture = App->textures->Load(FI_spriteEnemy_3.c_str());
		explosion.PushBack({ 17, 121, 90, 90 });
		explosion.PushBack({ 111, 124, 90, 90 });
		explosion.PushBack({ 204, 123, 90, 90 });
		explosion.speed = 0.3;
		
		
	}
}