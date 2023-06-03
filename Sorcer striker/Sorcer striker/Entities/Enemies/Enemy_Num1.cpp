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

	pathchest.PushBack({ centerX, 8.0f }, 10);
	pathchest.PushBack({ centerX, 6.0f }, 10);
	pathchest.PushBack({ centerX, 4.0f }, 10);
	pathchest.PushBack({ centerX, 2.0f }, 10);
	pathchest.PushBack({ centerX, -8.0f }, 200);
	pathchest.PushBack({ centerX, -25.0f }, 10);
	pathchest.PushBack({ centerX, -50.0f }, 10);
	pathchest.PushBack({ centerX, -75.0f }, 10);
	pathchest.PushBack({ centerX, -100.0f }, 10);

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
