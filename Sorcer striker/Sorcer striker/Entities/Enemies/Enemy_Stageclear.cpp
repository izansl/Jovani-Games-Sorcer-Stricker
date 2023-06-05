#include "Enemy_Stageclear.h"

#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Gameplay/ModuleEnemies.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleRender.h"
#include"../../Modules/Core/ModuleTextures.h"
#include "../../Modules/Core/ModuleAudio.h"


#include <SDL_timer.h>



Enemy_Sclear::Enemy_Sclear(int x, int y) : Enemy(x, y) {
	texture = App->textures->Load(FI_imageplayer_kill.c_str());

	blue.PushBack({ 47, 1037, 688, 875 });
	blue.speed = 0.1f;
	currentAnim = &blue;
	App->audio->PlayMusic(FA_Music_Clear.c_str(), 1.0f);


	// Path 1
	pathchest.PushBack({ 0.0f, -15 }, 10);

	currentPath = &pathchest;

	start_time = SDL_GetTicks();
}

void Enemy_Sclear::Update() {

	pathchest.Update();
	position = spawnPos + currentPath->GetRelativePosition();

	if (SDL_GetTicks() - start_time >= 8000)
	{
		pickup.PushBack({ 10000, 1037, 688, 875 });
		currentAnim = &pickup;
	}
	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position 
	Enemy::Update();

}

void Enemy_Sclear::OnCollision(Collider* c1) {
}

