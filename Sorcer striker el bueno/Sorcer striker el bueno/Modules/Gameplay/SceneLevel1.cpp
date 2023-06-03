#include "SceneLevel1.h"

#include "../../Application/Application.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleTextures.h"
#include "../../Modules/Core/ModuleRender.h"
#include "../../Modules/Core/ModuleAudio.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Core/ModuleInput.h"

#include "ModuleEnemies.h"
#include "ModulePlayer.h"

SceneLevel1::SceneLevel1(bool startEnabled) : Module(startEnabled) {
}

SceneLevel1::~SceneLevel1() {
}

// Load assets
bool SceneLevel1::Start() {
	LOG("Loading background assets SCENE 1");

	bool ret = true;

	texture_sea = App->textures->Load(FI_background_sea.c_str());
	texture_forest1 = App->textures->Load(FI_background_forest1.c_str());
	texture_castle = App->textures->Load(FI_background_castle.c_str());

	App->audio->PlayMusic(FA_Music_stage1.c_str(), 1.0f);

	//Wall colliders
	int xt = 0;
	int yt = 3000;
	int wt = SCREEN_WIDTH;
	int ht = 10;
	topcoll = App->collisions->AddCollider({ xt, yt, wt, ht }, Collider::Type::WALL_PLAYER);

	int xb = 0;
	int yb = 4070;
	int wb = SCREEN_WIDTH;
	int hb = 10;
	botcoll = App->collisions->AddCollider({ xb, yb, wb, hb }, Collider::Type::WALL_PLAYER);

	int xl = 0;
	int yl = 3000;
	int wl = 10;
	int hl = SCREEN_HEIGHT;
	leftcoll = App->collisions->AddCollider({ xl, yl, wl, hl }, Collider::Type::WALL_PLAYER);

	int xr = SCREEN_WIDTH - 10;
	int yr = 3000;
	int wr = 10;
	int hr = SCREEN_HEIGHT;
	raightcoll = App->collisions->AddCollider({ xr, yr, wr, hr }, Collider::Type::WALL_PLAYER);


	App->enemies->AddEnemy(Enemy_Type::BOSS, 200, -400, 1);

#pragma region ENEMIES
	// add chest
	App->enemies->AddEnemy(Enemy_Type::CHEST_BLUE, 200, -500, 1);

#pragma region Red ball
	//add red ball
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 120, -340, 1);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 120, -440, 1);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 120, -540, 1);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 120, -640, 1);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 120, -740, 1);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 120, -840, 1);
	///*App->enemies->AddEnemy(Enemy_Type::RED_BALL, 50, -680, 1, 7);
	//App->enemies->AddEnemy(Enemy_Type::RED_BALL, 50, -710, 1, 8);*/

	////add red ball 2
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 640, -1680, 2);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 640, -1780, 2);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 640, -1880, 2);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 640, -1980, 2);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 640, -2080, 2);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 640, -2180, 2);
	////App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -940, 2, 7);
	////App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -970, 2, 8);

	////add red ball 3
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 180, -2800, 3);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 180, -2900, 3);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 180, -3000, 3);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 180, -3100, 3);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 180, -3200, 3);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 180, -3300, 3);
	/*App->enemies->AddEnemy(Enemy_Type::RED_BALL, 110, -1900, 3, 7);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 110, -1950, 3, 8);*/

	//add red ball 4
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 710, -3800, 4);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 710, -3900, 4);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 710, -4000, 4);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 710, -4100, 4);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 710, -4200, 4);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 710, -4300, 4);

//	/*App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -2400, 4, 7);
//	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -2450, 4, 8);*/
//
//	//add red ball 5
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -4500, 5);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -4600, 5);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -4700, 5);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -4800, 5);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -4900, 5);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -5000, 5);

//	///*App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -2600, 5, 7);
//	//App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -2650, 5, 8);*/
//
//	//add red ball 6
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 700, -10000, 6);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 700, -10100, 6);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 700, -10200, 6);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 700, -10300, 6);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 700, -10400, 6);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 700, -10500, 6);

//	/*App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -4400, 6, 7);
//	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -4450, 6, 8);*/
//
//	//add red ball 7

	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -12200, 7);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -12300, 7);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -12400, 7);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -12500, 7);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -12600, 7);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -12700, 7);

//	/*App->enemies->AddEnemy(Enemy_Type::RED_BALL, 50, -5100, 7, 7);
//	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 50, -5150, 7, 8);*/
//
//	////add red ball 8

	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 120, -15000, 8);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 120, -15100, 8);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 120, -15200, 8);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 120, -15300, 8);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 120, -15400, 8);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 120, -15500, 8);
//	/*App->enemies->AddEnemy(Enemy_Type::RED_BALL, 150, -5600, 8, 7);
//	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 150, -5650, 8, 8);*/
//	////add red ball 9
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 640, -16000, 8);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 640, -16100, 8);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 640, -16200, 8);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 640, -16300, 8);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 640, -16400, 8);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 640, -16500, 8);
#pragma endregion

#pragma region Wizard
//	//add Wizard
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 450, -3700, 1);
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 510, -3700, 1);

	//add Wizard 2
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 120, -4800, 2);
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 180, -4800, 2);

	//add wizard 3
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 380, -5900, 3);
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 440, -5900, 3);

	//add wizard 4
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 120, -7000, 4);
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 180, -7000, 4);

	//add wizard 5
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 520, -8100, 5);
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 580, -8100, 5);
#pragma endregion

	////add dragon
	App->enemies->AddEnemy(Enemy_Type::DRAGON, 50, -9800, 1);
	App->enemies->AddEnemy(Enemy_Type::DRAGON, 450, -12000, 2);

#pragma endregion
#pragma region goblin
	App->enemies->AddEnemy(Enemy_Type::FLYTANK, 100, -18000, 1);
	App->enemies->AddEnemy(Enemy_Type::FLYTANK, 100, -28000, 1);
	
#pragma endregion

#pragma region tanks
	
	App->enemies->AddEnemy(Enemy_Type::TANK, 800, -100, 2);
	App->enemies->AddEnemy(Enemy_Type::TANK, 0, -19250, 1);
	App->enemies->AddEnemy(Enemy_Type::TANK, -150, -19250, 1);
	App->enemies->AddEnemy(Enemy_Type::TANK, -300, -19250, 1);
	App->enemies->AddEnemy(Enemy_Type::TANK, 800, -19112, 2);
	App->enemies->AddEnemy(Enemy_Type::TANK, 950, -19112, 2);
	App->enemies->AddEnemy(Enemy_Type::TANK, 1100, -19112, 2);
	App->enemies->AddEnemy(Enemy_Type::TANK, -150, -22350, 1);
	App->enemies->AddEnemy(Enemy_Type::TANK, 950, -22350, 2);
	App->enemies->AddEnemy(Enemy_Type::TANK, -150, -22500, 1);
	App->enemies->AddEnemy(Enemy_Type::TANK, 950, -22500, 2);
	App->enemies->AddEnemy(Enemy_Type::TANK, -150, -22650, 1);
	App->enemies->AddEnemy(Enemy_Type::TANK, 950, -22650, 2);
	App->enemies->AddEnemy(Enemy_Type::TANK, -150, -22800, 1);
	App->enemies->AddEnemy(Enemy_Type::TANK, 950, -22800, 2);
	/*App->enemies->AddEnemy(Enemy_Type::TANK, -0, -24600, 1);
	App->enemies->AddEnemy(Enemy_Type::TANK, -150, -24600, 1);
	App->enemies->AddEnemy(Enemy_Type::TANK, -0, -24750, 1);
	App->enemies->AddEnemy(Enemy_Type::TANK, -0, -24900, 1);
	App->enemies->AddEnemy(Enemy_Type::TANK, -0, -25050, 1);*/
	
	
#pragma endregion
#pragma region turtle

	/*App->enemies->AddEnemy(Enemy_Type::TURTLE, 10, -90, 2);*/
	

#pragma endregion
#pragma region goblin
	/*App->enemies->AddEnemy(Enemy_Type::MINIDRAGON, 100, -90, 2);
	App->enemies->AddEnemy(Enemy_Type::MINIDRAGON, 200, -90, 2);
	App->enemies->AddEnemy(Enemy_Type::MINIDRAGON, 300, -90, 2);
	App->enemies->AddEnemy(Enemy_Type::MINIDRAGON, 400, -90, 2);*/

#pragma endregion
	// POSITION INITIAL CAMERA
	App->render->camera.x = 0;
	App->render->camera.y = 3000;

	App->player->Enable();
	App->enemies->Enable();
	App->collisions->Enable();

	return ret;
}

Update_Status SceneLevel1::Update() {
	App->render->camera.y += velocitatNivell;

	topcoll->rect.y += velocitatNivell;
	botcoll->rect.y += velocitatNivell;
	leftcoll->rect.y += velocitatNivell;
	raightcoll->rect.y += velocitatNivell;

	if ((App->player->position.x + 5 + App->player->collider->rect.w) >= raightcoll->rect.x)
	{
		App->player->position.x = raightcoll->rect.x - (5 + App->player->collider->rect.w);
	}

	if (App->player->position.x - 5 <= leftcoll->rect.x)
	{
		App->player->position.x = leftcoll->rect.x + 5;
	}

	if ((App->player->position.y + 5 + App->player->collider->rect.h) >= botcoll->rect.y)
	{
		App->player->position.y = botcoll->rect.y - (5 + App->player->collider->rect.h);
	}

	if (App->player->position.y - 5 <= topcoll->rect.y)
	{
		App->player->position.y = topcoll->rect.y + 5;
	}

	//Spawn cofres
	if (App->input->keys[SDL_SCANCODE_1] == Key_State::KEY_DOWN)
	{
		App->enemies->AddEnemy(Enemy_Type::CHEST_RED, App->player->position.x + 50, App->player->position.y - 800, 1);
	}
	if (App->input->keys[SDL_SCANCODE_2] == Key_State::KEY_DOWN)
	{
		App->enemies->AddEnemy(Enemy_Type::CHEST_GREEN, App->player->position.x + 50, App->player->position.y - 800, 1);
	}
	if (App->input->keys[SDL_SCANCODE_3] == Key_State::KEY_DOWN)
	{
		App->enemies->AddEnemy(Enemy_Type::CHESTBLUE, App->player->position.x + 50, App->player->position.y - 800, 1);
	}
	if (App->input->keys[SDL_SCANCODE_4] == Key_State::KEY_DOWN)
	{
		App->enemies->AddEnemy(Enemy_Type::GOLD, App->player->position.x + 50, App->player->position.y - 800, 1);
	}
	if (App->input->keys[SDL_SCANCODE_4] == Key_State::KEY_DOWN)
	{
		App->enemies->AddEnemy(Enemy_Type::TANK, 400, App->player->position.y - 700, 1);



	}
	if (App->input->keys[SDL_SCANCODE_F5] == Key_State::KEY_DOWN)
	{
		App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 400, App->player->position.y - 700, 1);
	}

	if (App->input->keys[SDL_SCANCODE_Q] == Key_State::KEY_DOWN)
	{
		App->enemies->AddEnemy(Enemy_Type::BOSS, 400, App->player->position.y - 700, 1);
	}

	return Update_Status::UPDATE_CONTINUE;
}

Update_Status SceneLevel1::PostUpdate() {
	// Draw everything --------------------------------------
	App->render->Blit(texture_forest1, 0, -SCREEN_HEIGHT * -1, NULL);
	App->render->Blit(texture_forest1, 0, (Height_background_forest1 - SCREEN_HEIGHT) * -1, NULL);
	App->render->Blit(texture_forest1, 0, (Height_background_forest1 + Height_background_forest1 - SCREEN_HEIGHT) * -1, NULL);
	App->render->Blit(texture_forest1, 0, (Height_background_forest1 + Height_background_forest1 + Height_background_forest1 - SCREEN_HEIGHT) * -1, NULL);
	App->render->Blit(texture_sea, 0, (Height_background_forest1 + Height_background_forest1 + Height_background_forest1 + Height_background_sea - SCREEN_HEIGHT) * -1, NULL);
	App->render->Blit(texture_castle, 0, (Height_background_forest1 + Height_background_forest1 + Height_background_forest1 + Height_background_sea + Height_background_castle - SCREEN_HEIGHT) * -1, NULL);

	return Update_Status::UPDATE_CONTINUE;
}

bool SceneLevel1::CleanUp() {
	App->player->Disable();
	App->enemies->Disable();
	App->collisions->Disable();
	return true;
}