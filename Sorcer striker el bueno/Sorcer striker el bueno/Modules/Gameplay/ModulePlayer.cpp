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
#include "../../Modules/Gameplay/SceneLevel1.h"

#include <stdio.h>

ModulePlayer::ModulePlayer(bool startEnabled) : Module(startEnabled) {

	// idle animation - just one sprite
	idleAnim.PushBack({ 264, 16, 40, 42 });

	// move right
	rightAnim.PushBack({ 305, 16, 38, 44 });
	rightAnim.loop = false;
	rightAnim.speed = 0.1f;

	// Move left
	leftAnim.PushBack({ 226, 16, 38, 44 });
	leftAnim.loop = false;
	leftAnim.speed = 0.1f;

	// Change sprite
	blueBUFF.PushBack({ 1595, 63, 62, 43 });
	blueBUFF.PushBack({ 268, 63, 70, 43 });
	blueBUFF.speed = 1.0f;

	//Move right
	blueright.PushBack({ 242, 61, 68, 44 });
	blueright.loop = false;
	blueright.speed = 0.1f;

	// Move left
	blueleft.PushBack({ 9, 61, 68, 44 });
	blueleft.loop = false;
	blueleft.speed = 0.1f;
}

ModulePlayer::~ModulePlayer() {
}

bool ModulePlayer::Start() {
	LOG("Loading player textures");

	bool ret = true;

	texture = App->textures->Load(FI_spritePlayer_player1.c_str());
	currentAnimation = &idleAnim;

	explosionjugadorFx = App->audio->LoadFx(FA_Fx_explosionJ.c_str()); ;

	position.x = 150;
	position.y = 3150;

	destroyed = false;

	collider = App->collisions->AddCollider({ position.x, position.y, 38, 44 }, Collider::Type::PLAYER, this);

	return ret;
}

Update_Status ModulePlayer::Update() {

	// Moving the player with the camera scroll
	App->player->position.y -= 8;
	if (App->input->keys[SDL_SCANCODE_F1] == KEY_DOWN)
		godMode = !godMode;

	if (App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_REPEAT) position.y -= speed;
	if (App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_REPEAT) position.y += speed;
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
		App->particles->AddParticle(App->particles->laser, position.x + 25, position.y, Collider::Type::PLAYER_SHOT, 0);
	}

	// Spawn explosion particles when pressing X
	if (App->input->keys[SDL_SCANCODE_X] == Key_State::KEY_DOWN)
	{
		App->particles->AddParticle(App->particles->explosion, position.x - 25, position.y, Collider::Type::PLAYER_SHOT, 0);
	}

	// If no up/down movement detected, set the current animation back to idle
	if (App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_IDLE && App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_IDLE)
		currentAnimation = &idleAnim;

	//update collider
	collider->SetPos(position.x, position.y);
	currentAnimation->Update();


	return Update_Status::UPDATE_CONTINUE;
}

Update_Status ModulePlayer::PostUpdate() {
	if (!destroyed) {
		SDL_Rect rect = currentAnimation->GetCurrentFrame();
		App->render->Blit(texture, position.x, position.y, &rect);
	}
	else
	{
		if (destroyedCountdown <= 0)
		{
			position.x = backupPosition.x;
			position.y = backupPosition.y;
			destroyed = false;
		}
		else
		{
			position.x = 50000;
			position.y = -50000;
			destroyedCountdown--;
		}
	}

	// WIN CONDITION
	if (kills == 58 || App->input->keys[SDL_SCANCODE_F3] == Key_State::KEY_DOWN)
	{
		App->fade->FadeToBlack((Module*)App->sceneLevel_1, (Module*)App->sceneIntro, 60); //Menu start no intro

		//App->collisions->RemoveCollider(collider);
		
	}

	// LOSE CONDITION
	if (lives == 0 || App->input->keys[SDL_SCANCODE_F4] == Key_State::KEY_DOWN)
	{
		App->fade->FadeToBlack((Module*)App->sceneLevel_1, (Module*)App->sceneIntro, 60); //Menu start no intro
		//App->collisions->RemoveCollider(collider);
		
		
	}

	return Update_Status::UPDATE_CONTINUE;
}

void ModulePlayer::OnCollision(Collider* c1, Collider* c2) {

	// TODO: POWERUP, pendiente a resolver
	//if (c1->Intersects(c2->rect) || c2->Intersects(c1->rect) && c1->type == Collider::Type::OBJECTCHEST)
	//{
	//	// Change sprite
	//	currentAnimation = &blueBUFF;

	if (c1 == collider && destroyed == false)
	{
		// A�adir part�cula de muerte del jugador
		App->particles->AddParticle(App->particles->playerdead, position.x, position.y, Collider::Type::NONE, 0);
		c1->type = Collider::Type::PLAYER;
		//App->particles->AddParticle(App->particles->explosion2, position.x, position.y, Collider::Type::NONE, 9);
		//App->audio->PlayFx(explosionjugadorFx);

		destroyed = true;
	}
	else if (c1->type == Collider::Type::PLAYER && c2->type == Collider::Type::ENEMY && destroyed == false /*&& !godMode*/)//Cuando tengamos godmode se le dara uso
	{
		destroyed = true;
		if (!godMode) lives--;
	}
	else if (c1->Intersects(c2->rect) || c2->Intersects(c1->rect) && c1->type == Collider::Type::PLAYER || c2->type == Collider::Type::ENEMY)
	{
		// Change sprite
		idleAnim.PushBack({ 337, 69, 66, 45 });
		idleAnim.PushBack({ 343, 132, 66, 45 });
		idleAnim.speed = 1.0f;

		//Move right
		rightAnim.PushBack({ 445, 134, 73, 46 });
		rightAnim.loop = false;
		rightAnim.speed = 0.1f;

		// Move left
		leftAnim.PushBack({ 14, 37, 73, 46 });
		leftAnim.loop = false;
		leftAnim.speed = 0.1f;

		if (App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_REPEAT && position.x < 300)
		{
			position.x += speed;
			if (currentAnimation != &blueright)
			{
				rightAnim.Reset();
				currentAnimation = &blueright;
			}
		}
		if (App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_REPEAT && position.x > 45)
		{
			position.x -= speed;
			if (currentAnimation != &blueleft)
			{
				leftAnim.Reset();
				currentAnimation = &blueleft;
			}
		}


		//Change laser
		if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN)
		{
			App->particles->AddParticle(App->particles->laser, position.x + 29, position.y - 45, Collider::Type::PLAYER_SHOT, 0);
			App->particles->AddParticle(App->particles->laser, position.x + 7, position.y - 45, Collider::Type::PLAYER_SHOT, 0);
			App->particles->AddParticle(App->particles->laser, position.x + 13, position.y + 5, Collider::Type::PLAYER_SHOT, 0);
			App->particles->AddParticle(App->particles->ice, position.x, position.y - 5, Collider::Type::PLAYER_SHOT, 0);
			App->particles->AddParticle(App->particles->ice, position.x, position.y - 10, Collider::Type::PLAYER_SHOT, 0);
			App->particles->AddParticle(App->particles->ice, position.x, position.y - 15, Collider::Type::PLAYER_SHOT, 0);
			App->particles->AddParticle(App->particles->ice, position.x + 16, position.y + 5, Collider::Type::PLAYER_SHOT, 0);
			App->particles->AddParticle(App->particles->ice, position.x + 16, position.y + 10, Collider::Type::PLAYER_SHOT, 0);
			App->particles->AddParticle(App->particles->ice, position.x + 16, position.y + 15, Collider::Type::PLAYER_SHOT, 0);
		}
	}
	else if (c1 == collider && destroyed == false)
	{
		// A�adir part�cula de muerte del jugador
		App->particles->AddParticle(App->particles->playerdead, position.x, position.y, Collider::Type::NONE, 0);
		c1->type = Collider::Type::NONE;
		//App->particles->AddParticle(App->particles->explosion2, position.x, position.y, Collider::Type::NONE, 9);
		//App->audio->PlayFx(explosionjugadorFx);

		destroyed = true;
	}
	else if (c1->type == Collider::Type::PLAYER && c2->type == Collider::Type::ENEMY && destroyed == false /*&& !godMode*/)//Cuando tengamos godmode se le dara uso
	{
		destroyed = true;
		//	lives--;
	}
}