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
	idleAnim.PushBack({ 97, 687, 119, 111});

	// move right
	rightAnim.PushBack({ 96, 364, 119, 111 });
	rightAnim.loop = false;
	rightAnim.speed = 0.5f;

	// Move left
	leftAnim.PushBack({ 98, 519, 119, 111 });
	leftAnim.loop = false;
	leftAnim.speed = 0.5f;

	//BLUE BUFF	
	// Change sprite
	blueBUFF.PushBack({ 50, 683, 217, 118});
	blueBUFF.speed = 0.1f;

	//Move right
	blueright.PushBack({ 445, 134, 73, 46 });
	blueright.loop = false;
	blueright.speed = 0.5f;

	// Move left
	blueleft.PushBack({ 45, 360, 217, 118});
	blueleft.loop = false;
	blueleft.speed = 0.5f;

	//PINK BUFF
	// Change sprite
	pinkBUFF.PushBack({ 300, 684, 217, 118 });
	pinkBUFF.speed = 0.1f;

	//Move right
	pinkright.PushBack({ 300, 360, 217, 118 });
	pinkright.loop = false;
	pinkright.speed = 0.5f;

	// Move left
	pinkleft.PushBack({ 298, 522, 217, 118 });
	pinkleft.loop = false;
	pinkleft.speed = 0.5f;

	pinkBUFF.PushBack({ 300, 684, 217, 118 });
	pinkBUFF.speed = 0.1f;

	//GREEN BUFF
	// Change sprite
	greenBUFF.PushBack({ 552, 618, 217, 188 });
	greenBUFF.speed = 0.1f;

	//Move right
	greenright.PushBack({ 553, 363, 217, 118 });
	greenright.loop = false;
	greenright.speed = 0.5f;

	// Move left
	greenleft.PushBack({ 552, 518, 217, 118 });
	greenleft.loop = false;
	greenleft.speed = 0.5f;

}

ModulePlayer::~ModulePlayer() {
}

bool ModulePlayer::Start() {
	LOG("Loading player textures");

	bool ret = true;

	texture = App->textures->Load(FI_spritePlayer_1.c_str());
	currentAnimation = &idleAnim;

	explosionjugadorFx = App->audio->LoadFx(FA_Fx_explosionJ.c_str()); ;

	position.x = 150;
	position.y = 3150;

	destroyed = false;

	collider = App->collisions->AddCollider({ position.x, position.y, 38, 44 }, Collider::Type::PLAYER, this);
	backupPosition.x = 100;
	backupPosition.y = position.y - SCREEN_HEIGHT;
	return ret;
}

Update_Status ModulePlayer::Update() {

	// Moving the player with the camera scroll
	App->player->position.y -= 8;
	if (App->input->keys[SDL_SCANCODE_F1] == KEY_DOWN)
		godMode = !godMode;

	if (App->input->keys[SDL_SCANCODE_W] == Key_State::KEY_REPEAT) position.y -= speed;
	if (App->input->keys[SDL_SCANCODE_S] == Key_State::KEY_REPEAT) position.y += speed;
	if (App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_REPEAT && position.x < 800)
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
		if (Powerupblue == false)
		{
			App->particles->AddParticle(App->particles->laser1, position.x, position.y, Collider::Type::PLAYER_SHOT, 0);
		}
		else if (Powerupblue == true)
		{
			App->particles->AddParticle(App->particles->laser2, position.x + 15, position.y, Collider::Type::PLAYER_SHOT, 0);

			App->particles->AddParticle(App->particles->axeleft, position.x - 5, position.y, Collider::Type::PLAYER_SHOT, 0);

			App->particles->AddParticle(App->particles->axeright, position.x + 55, position.y, Collider::Type::PLAYER_SHOT, 0);
		}
	}

	// Spawn explosion particles when pressing X
	if (App->input->keys[SDL_SCANCODE_X] == Key_State::KEY_DOWN)
	{
		App->particles->AddParticle(App->particles->bomb, position.x - 25, position.y, Collider::Type::PLAYER_SHOT, 0);
	}

	// If no up/down movement detected, set the current animation back to idle
	if (App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_IDLE && App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_IDLE)
		currentAnimation = &idleAnim;

	//update collider
	collider->SetPos(position.x, position.y);
	currentAnimation->Update();

	if (Powerupblue == true)
	{
		currentAnimation = &blueBUFF;
		collider->rect.w = 66;
		collider->rect.h = 45;

		if (App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_REPEAT && position.x < 300)
		{
			position.x += speed;
			if (currentAnimation != &blueright)
			{
				blueright.Reset();
				currentAnimation = &blueright;
			}
		}
		if (App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_REPEAT && position.x > 45)
		{
			position.x -= speed;
			if (currentAnimation != &blueleft)
			{
				blueleft.Reset();
				currentAnimation = &blueleft;
			}
		}
	}
	if (Powerupgreen == true)
	{
		currentAnimation = &blueBUFF;
		collider->rect.w = 66;
		collider->rect.h = 45;

		if (App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_REPEAT && position.x < 300)
		{
			position.x += speed;
			if (currentAnimation != &blueright)
			{
				blueright.Reset();
				currentAnimation = &blueright;
			}
		}
		if (App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_REPEAT && position.x > 45)
		{
			position.x -= speed;
			if (currentAnimation != &blueleft)
			{
				blueleft.Reset();
				currentAnimation = &blueleft;
			}
		}
	}
	if (Powerupred == true)
	{
		currentAnimation = &blueBUFF;
		collider->rect.w = 66;
		collider->rect.h = 45;

		if (App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_REPEAT && position.x < 300)
		{
			position.x += speed;
			if (currentAnimation != &blueright)
			{
				blueright.Reset();
				currentAnimation = &blueright;
			}
		}
		if (App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_REPEAT && position.x > 45)
		{
			position.x -= speed;
			if (currentAnimation != &blueleft)
			{
				blueleft.Reset();
				currentAnimation = &blueleft;
			}
		}
	}
	LOG("Countdown % d", destroyedCountdown);

	if (destroyed)
	{
		destroyedCountdown--;
		if (destroyedCountdown == 0)
		{
			destroyed = false;
			destroyedCountdown = 120;
			collider->type=Collider::Type::PLAYER;
		}
	}
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
	}

	// WIN CONDITION
	if (kills == 58 || App->input->keys[SDL_SCANCODE_F3] == Key_State::KEY_DOWN)
	{
		App->fade->FadeToBlack((Module*)App->sceneLevel_1, (Module*)App->sceneIntro, 60); //Menu start no intro



	}

	// LOSE CONDITION
	if (lives == 0 || App->input->keys[SDL_SCANCODE_F4] == Key_State::KEY_DOWN)
	{
		App->fade->FadeToBlack((Module*)App->sceneLevel_1, (Module*)App->sceneIntro, 60); //Menu start no intro



	}

	return Update_Status::UPDATE_CONTINUE;
}

void ModulePlayer::OnCollision(Collider* c1, Collider* c2) {

	// TODO: POWERUP, pendiente a resolver
	//if (c1->Intersects(c2->rect) || c2->Intersects(c1->rect) && c1->type == Collider::Type::OBJECTCHEST)
	//{
	//	// Change sprite
	//	currentAnimation = &blueBUFF;
	//Cuan colisiona el jugador amb l'enemic 
	if (c1->type == Collider::Type::PLAYER && c2->type == Collider::Type::ENEMY && !destroyed && !godMode)//Cuando tengamos godmode se le dara uso
	{

		App->particles->AddParticle(App->particles->playerdead, position.x, position.y, Collider::Type::NONE, 0);
		collider->type = Collider::Type::NONE;
		destroyed = true;
		LOG("player dead");
		position.x = 100;
		position.y = position.y + SCREEN_HEIGHT;
		Powerupblue = false;
		lives--;

	}
	 //Cuan colisiona amb Power up
	if (c1->type == Collider::Type::PLAYER && c2->type == Collider::Type::POWER_UP)
	{
		if (c2->rect.w=99)
		{
			Powerupgreen = true;
		}
		if (c2->rect.w=100)
		{
			Powerupblue = true;
		}
		if (c2->rect.w=101)
		{
			Powerupred = true;
		}
	}
}