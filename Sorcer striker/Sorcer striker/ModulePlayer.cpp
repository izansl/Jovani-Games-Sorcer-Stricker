#include "ModulePlayer.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "ModuleCollisions.h"	
#include "Enemy_CHEST.h"

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
	collider = App->collisions->AddCollider({ position.x, position.y, 36, 42 }, Collider::Type::PLAYER, this);
	return ret;

	
}

update_status ModulePlayer::Update()
{
	// Moving the player with the camera scroll
	App->player->position.y -= 3;

	if (App->input->keys[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
	{
		position.y -= speed;
	}

	if (App->input->keys[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
	{
		position.y += speed;
	}

	if (App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT && position.x < 300)
	{
		position.x += speed;
		if (currentAnimation != &rightAnim)
		{
			rightAnim.Reset();
			currentAnimation = &rightAnim;
		}
	}

	if (App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT && position.x > 45)
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
		App->particles->AddParticle(App->particles->laser, position.x + 29, position.y-45,Collider::Type::PLAYER_SHOT, 0);
		App->particles->AddParticle(App->particles->laser, position.x + 7, position.y - 45, Collider::Type::PLAYER_SHOT, 0);
	}

	// Spawn explosion particles when pressing B
	if (App->input->keys[SDL_SCANCODE_X] == KEY_STATE::KEY_DOWN)
	{
		App->particles->AddParticle(App->particles->explosion, position.x+15, position.y-50);
		App->particles->AddParticle(App->particles->explosion2, position.x + 5, position.y-200);
	}

	// If no up/down movement detected, set the current animation back to idle
	if (App->input->keys[SDL_SCANCODE_A] == KEY_STATE::KEY_IDLE
		&& App->input->keys[SDL_SCANCODE_D] == KEY_STATE::KEY_IDLE)
		currentAnimation = &idleAnim;
	//update collider
	collider->SetPos(position.x, position.y);
	currentAnimation->Update();

	return update_status::UPDATE_CONTINUE;
}

update_status ModulePlayer::PostUpdate()
{
	SDL_Rect rect = currentAnimation->GetCurrentFrame();
	App->render->Blit(texture, position.x, position.y - rect.h, &rect);

	return update_status::UPDATE_CONTINUE;
}
void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	// TODO 5: Detect collision with a wall. If so, go back to intro screen.
	if (c1 == collider && destroyed == false)
	{
		App->particles->AddParticle(App->particles->explosion, position.x, position.y, Collider::Type::NONE, 9);
		App->particles->AddParticle(App->particles->explosion, position.x + 8, position.y + 11, Collider::Type::NONE, 14);
		App->particles->AddParticle(App->particles->explosion, position.x - 7, position.y + 12, Collider::Type::NONE, 40);
		App->particles->AddParticle(App->particles->explosion, position.x + 5, position.y - 5, Collider::Type::NONE, 28);
		App->particles->AddParticle(App->particles->explosion, position.x - 4, position.y - 4, Collider::Type::NONE, 21);

		

		destroyed = true;
	}
	else if (c1->Intersects(c2->rect) || c2->Intersects(c1->rect))
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
		if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
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
}