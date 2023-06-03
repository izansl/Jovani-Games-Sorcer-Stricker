#include "Enemy_MiniDragon.h"
#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Gameplay/ModuleEnemies.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleRender.h"
#include"../../Modules/Core/ModuleTextures.h"
#include"../../Modules/Core/ModuleAudio.h"

Enemy_MiniDragon::Enemy_MiniDragon(int x, int y, int wave) : Enemy(x, y) {
	//movimiento hacie abajo
	texture = App->textures->Load(FI_spriteEnemy_enemiesvar_1.c_str());
	down.PushBack({ 621, 327, 93, 85 });
	down.PushBack({ 759, 327, 93, 85 });
	down.PushBack({ 892, 327, 93, 85 });
	down.PushBack({ 1053, 327, 93, 85 });
	down.PushBack({ 1196, 327, 93, 85 });
	currentAnim = &down;
	down.speed = 0.075;
	down.loop = false;
	//movimiento hacia arriba
	/*up.PushBack({ 759, 327, 93, 85 });
	up.PushBack({ 892, 327, 93, 85 });
	up.PushBack({ 1053, 327, 93, 85 });
	up.PushBack({ 1196, 327, 93, 85 });
	up.speed = 1;
	up.loop = false;*/

	path.PushBack({ 0, 0 }, 70, &down);
	path.PushBack({ 1, -12 }, 600, &down);

	collider = App->collisions->AddCollider({ 0, 0, 93, 85}, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_MiniDragon::Update() {
	
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
void Enemy_MiniDragon::OnCollision(Collider* c1) {
	death.PushBack({ 683, 106, 34, 33 });
	death.PushBack({ 683, 188, 32, 32 });
	death.PushBack({ 683, 106, 34, 33 });
	death.PushBack({ 0, 0, 0, 0 });

	currentAnim = &death;
	death.speed = 0.2;
	death.loop = false;
	App->audio->PlayFx(destroyedFx);
	life = false;
}