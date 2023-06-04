#include "Enemy_Num1.h"

#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Gameplay/ModuleEnemies.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleRender.h"
#include"../../Modules/Core/ModuleTextures.h"


Enemy_Num1::Enemy_Num1(int x, int y) : Enemy(x, y) {
	texture = App->textures->Load(FI_HUD_stage1.c_str());

	blue.PushBack({ 476, 166, 67, 155 });
	blue.speed = 0.1f;
	currentAnim = &blue;


	// Path 1
	float centerX = 0.0f; // Valor constante en el eje X (centro de la pantalla)

	pathchest.PushBack({ 0.0, -8.0 }, 20);
	pathchest.PushBack({ 0.0, -15.0 }, 80);
	pathchest.PushBack({ 0.0, -40.0 }, 100);
	pathchest.PushBack({ 40.0, -40.0 }, 400);
	currentPath = &pathchest;

}

void Enemy_Num1::Update() {

	pathchest.Update();
	position = spawnPos + currentPath->GetRelativePosition();

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position 
	Enemy::Update();

}

void Enemy_Num1::OnCollision(Collider* c1) {
}
