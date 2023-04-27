#include "ModulePlayer.h"

#include "../../Application/Application.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleTextures.h"
#include "../../Modules/Core/ModuleInput.h"
#include "../../Modules/Core/ModuleRender.h"
#include "../../Modules/Core/ModuleParticles.h"
#include "../../Modules/Core/ModuleAudio.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Core/ModuleFadeToBlack.h"
#include "../../Modules/Core/ModuleFonts.h"

#include <stdio.h>

ModulePlayer::ModulePlayer(bool startEnabled) : Module(startEnabled) {
	// TODO: Posar noves posicions player i borrar OLD

#pragma region OLD
	//// idle animation - just one sprite
	//idleAnim.PushBack({ 66, 1, 32, 14 });

	//// move upwards
	//upAnim.PushBack({ 100, 1, 32, 14 });
	//upAnim.PushBack({ 132, 0, 32, 14 });
	//upAnim.loop = false;
	//upAnim.speed = 0.1f;

	//// Move down
	//downAnim.PushBack({ 33, 1, 32, 14 });
	//downAnim.PushBack({ 0, 1, 32, 14 });
	//downAnim.loop = false;
	//downAnim.speed = 0.1f;
#pragma endregion

#pragma region NEW
	position.x = 150;
	position.y = 120;

	// idle animation - just one sprite
	idleAnim.PushBack({ 240, 16, 38, 44 });

	// move right
	rightAnim.PushBack({ 278, 17, 38, 44 });
	rightAnim.loop = false;
	rightAnim.speed = 0.1f;

	// Move left
	leftAnim.PushBack({ 200, 17, 38, 44 });
	leftAnim.loop = false;
	leftAnim.speed = 0.1f;
#pragma endregion	
}

ModulePlayer::~ModulePlayer() {
}

bool ModulePlayer::Start() {
	LOG("Loading player textures");

	bool ret = true;

	texture = App->textures->Load(FI_spritePlayer_player1.c_str());
	currentAnimation = &idleAnim;

	laserFx = App->audio->LoadFx(FI_spritePlayer_player1.c_str());
	explosionFx = App->audio->LoadFx(FI_spritePlayer_player1.c_str());

	position.x = 150;
	position.y = 150;

	destroyed = false;

	collider = App->collisions->AddCollider({ position.x, position.y, 38, 44 }, Collider::Type::PLAYER, this);


	// TODO: Per més endavant i en un altre lloc, servirà per fer les puntuacions
	/*char lookupTable[] = { "! @,_./0123456789$;< ?abcdefghijklmnopqrstuvwxyz" };
	scoreFont = App->fonts->Load(FTI_font_font3.c_str(), lookupTable, 2);*/

	return ret;
}

Update_Status ModulePlayer::Update() {

	// TODO: Cambiar a vertical

#pragma region OLD -> HORIZONTAL
	//// Moving the player with the camera scroll
	//App->player->position.y += 1;

	//if (App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_REPEAT)position.x -= speed;
	//if (App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_REPEAT)position.x += speed;
	//if (App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_REPEAT)position.y += speed;

	//if (currentAnimation != &downAnim) {
	//	downAnim.Reset();
	//	currentAnimation = &downAnim;
	//}

	//if (App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_REPEAT) {
	//	position.y -= speed;
	//	if (currentAnimation != &upAnim) {
	//		upAnim.Reset();
	//		currentAnimation = &upAnim;
	//	}
	//}

	//if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN) {
	//	Particle* newParticle = App->particles->AddParticle(App->particles->laser, position.x + 20, position.y, Collider::Type::PLAYER_SHOT);
	//	newParticle->collider->AddListener(this);
	//	App->audio->PlayFx(laserFx);
	//}

	//// If no up/down movement detected, set the current animation back to idle
	//if (App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_IDLE
	//	&& App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_IDLE)
	//	currentAnimation = &idleAnim;

	//collider->SetPos(position.x, position.y);

	//currentAnimation->Update();
#pragma endregion

#pragma region NEW -> VERTICAL
	// Moving the player with the camera scroll
	App->player->position.y -= 2;

	if (App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_REPEAT)
	{
		position.y -= speed;
	}

	if (App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_REPEAT)
	{
		position.y += speed;
	}

	if (App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_REPEAT && position.x < 300)
	{
		position.x += speed;
		if (currentAnimation != &rightAnim)
		{
			rightAnim.Reset();
			currentAnimation = &rightAnim;
		}
	}

	if (App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_REPEAT && position.x > 45)
	{
		position.x -= speed;
		if (currentAnimation != &leftAnim)
		{
			leftAnim.Reset();
			currentAnimation = &leftAnim;
		}
	}

	if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN)
	{
		App->particles->AddParticle(App->particles->laser, position.x, position.y, Collider::Type::PLAYER_SHOT, 0);
		App->particles->AddParticle(App->particles->laser, position.x+25, position.y, Collider::Type::PLAYER_SHOT, 0);
	}

	// Spawn explosion particles when pressing X
	if (App->input->keys[SDL_SCANCODE_X] == Key_State::KEY_DOWN)
	{
		App->particles->AddParticle(App->particles->explosion, position.x+ 13, position.y+5);
		if (App->particles->explosion.lifetime==0)
		{
			App->particles->AddParticle(App->particles->explosion2, position.x - 20, position.y-105);
			if (App->particles->explosion2.lifetime==0)
			{
				App->particles->AddParticle(App->particles->explosionfinal, position.x + 5, position.y - 200);
			}
		}

	}

	// If no up/down movement detected, set the current animation back to idle
	if (App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_IDLE)
		currentAnimation = &idleAnim;
	//update collider
	collider->SetPos(position.x, position.y);
	currentAnimation->Update();
#pragma endregion

	

	return Update_Status::UPDATE_CONTINUE;
}

Update_Status ModulePlayer::PostUpdate() {
	if (!destroyed) {
		SDL_Rect rect = currentAnimation->GetCurrentFrame();
		App->render->Blit(texture, position.x, position.y, &rect);
	}

	// TODO: BORRAR i posar-ho en un altre lloc
	// Draw UI (score) --------------------------------------
	/*sprintf_s(scoreText, 10, "%7d", score);
	App->fonts->BlitText(58, 248, scoreFont, scoreText);
	App->fonts->BlitText(150, 248, scoreFont, "this is just a font test");*/

	return Update_Status::UPDATE_CONTINUE;
}

void ModulePlayer::OnCollision(Collider* c1, Collider* c2) { 
	// TODO: Actualizar i cambiar colisions

#pragma region OLD
	//if (c1 == collider && destroyed == false) {
	//	App->particles->AddParticle(App->particles->explosion, position.x, position.y, Collider::Type::PLAYER_SHOT, 9);
	//	App->particles->AddParticle(App->particles->explosion, position.x + 8, position.y + 11, Collider::Type::NONE, 14);
	//	App->particles->AddParticle(App->particles->explosion, position.x - 7, position.y + 12, Collider::Type::NONE, 40);
	//	App->particles->AddParticle(App->particles->explosion, position.x + 5, position.y - 5, Collider::Type::NONE, 28);
	//	App->particles->AddParticle(App->particles->explosion, position.x - 4, position.y - 4, Collider::Type::NONE, 21);

	//	App->audio->PlayFx(explosionFx);
	//	App->fade->FadeToBlack((Module*)App->sceneLevel_1, (Module*)App->sceneIntro, 60);

	//	destroyed = true;
	//}

	//if (c1->type == Collider::Type::PLAYER_SHOT && c2->type == Collider::Type::ENEMY) {
	//	score += 23;
	//}
#pragma endregion

#pragma region NEW
	if (c1 == collider && destroyed == false)
	{
		App->particles->AddParticle(App->particles->explosion, position.x, position.y, Collider::Type::NONE, 9);
		App->particles->AddParticle(App->particles->explosion, position.x + 8, position.y + 11, Collider::Type::NONE, 14);
		App->particles->AddParticle(App->particles->explosion, position.x - 7, position.y + 12, Collider::Type::NONE, 40);
		App->particles->AddParticle(App->particles->explosion, position.x + 5, position.y - 5, Collider::Type::NONE, 28);
		App->particles->AddParticle(App->particles->explosion, position.x - 4, position.y - 4, Collider::Type::NONE, 21);



		destroyed = true;
	}
	else if (c1->Intersects(c2->rect) || c2->Intersects(c1->rect) && c1->type == Collider::Type::PLAYER || c2->type == Collider::Type::ENEMY)
	{
		// Change sprite
		idleAnim.PushBack({ 1595, 63, 62, 43 });
		idleAnim.PushBack({ 268, 63, 70, 43 });
		idleAnim.speed = 1.0f;

		//Move right
		rightAnim.PushBack({ 242, 61, 68, 44 });
		rightAnim.loop = false;
		rightAnim.speed = 0.1f;

		// Move left
		leftAnim.PushBack({ 9, 61, 68, 44 });
		leftAnim.loop = false;
		leftAnim.speed = 0.1f;



		//Change laser
		if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN)
		{
			App->particles->AddParticle(App->particles->laser, position.x + 29, position.y - 45, Collider::Type::PLAYER_SHOT, 0);
			App->particles->AddParticle(App->particles->laser, position.x + 7, position.y - 45, Collider::Type::PLAYER_SHOT, 0);
			App->particles->AddParticle(App->particles->laser, position.x + 15, position.y - 50, Collider::Type::PLAYER_SHOT, 0);
			App->particles->AddParticle(App->particles->ice, position.x + 29, position.y - 45, Collider::Type::PLAYER_SHOT, 0);
			App->particles->AddParticle(App->particles->ice, position.x + 7, position.y - 45, Collider::Type::PLAYER_SHOT, 0);
			App->particles->AddParticle(App->particles->ice, position.x + 15, position.y - 50, Collider::Type::PLAYER_SHOT, 0);
			App->particles->AddParticle(App->particles->ice, position.x + 29, position.y - 45, Collider::Type::PLAYER_SHOT, 0);
			App->particles->AddParticle(App->particles->ice, position.x + 7, position.y - 45, Collider::Type::PLAYER_SHOT, 0);
			App->particles->AddParticle(App->particles->ice, position.x + 15, position.y - 50, Collider::Type::PLAYER_SHOT, 0);
		}
	}
#pragma endregion
}