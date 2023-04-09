#include "ModulePlayer.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"

#include "../SDLs/SDL/include/SDL_scancode.h"


ModulePlayer::ModulePlayer()
{
	position.x = 150;
	position.y = 120;

	// idle animation - just one sprite
	idleAnim.PushBack({ 245, 309, 42, 45 });

	// move right
	rightAnim.PushBack({ 285, 308, 35, 49});
	rightAnim.loop = false;
	rightAnim.speed = 0.1f;

	// Move left
	leftAnim.PushBack({ 210, 307, 37, 50});
	leftAnim.loop = false;
	leftAnim.speed = 0.1f;
}

ModulePlayer::~ModulePlayer()
{

}

bool ModulePlayer::Start()
{
	LOG("Loading player textures");

	bool ret = true;

	texture = App->textures->Load("../Assets/sprites.png"); // arcade version
	currentAnimation = &idleAnim;

	return ret;
}

update_status ModulePlayer::Update()
{
	// Moving the player with the camera scroll
	App->player->position.x += 1;

	if (App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
	{
		position.y -= speed;
	}

	if (App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
	{
		position.y += speed;
	}

	if (App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
	{
		position.x += speed;
		if (currentAnimation != &rightAnim)
		{
			rightAnim.Reset();
			currentAnimation = &rightAnim;
		}
	}

	if (App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
	{
		position.x -= speed;
		if (currentAnimation != &leftAnim)
		{
			leftAnim.Reset();
			currentAnimation = &leftAnim;
		}
	}

	if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		App->particles->AddParticle(App->particles->laser, position.x + 29, position.y-45, 0);
		App->particles->AddParticle(App->particles->laser, position.x+7, position.y-45, 0);
	}

	// Spawn explosion particles when pressing B
	if (App->input->keys[SDL_SCANCODE_X] == KEY_STATE::KEY_DOWN)
	{
		App->particles->AddParticle(App->particles->explosion, position.x+15, position.y-50);
	}

	// If no up/down movement detected, set the current animation back to idle
	if (App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE)
		currentAnimation = &idleAnim;

	currentAnimation->Update();

	return update_status::UPDATE_CONTINUE;
}

update_status ModulePlayer::PostUpdate()
{
	SDL_Rect rect = currentAnimation->GetCurrentFrame();
	App->render->Blit(texture, position.x, position.y - rect.h, &rect);

	return update_status::UPDATE_CONTINUE;
}