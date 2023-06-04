#include "SceneLevel1.h"

#include "../../Application/Application.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleTextures.h"
#include "../../Modules/Core/ModuleRender.h"
#include "../../Modules/Core/ModuleAudio.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Core/ModuleInput.h"
#include "../Gameplay/ModuleEnemies.h"
#include "../Gameplay/ModulePlayer.h"


#include <SDL_timer.h>



SceneLevel1::SceneLevel1(bool startEnabled) : Module(startEnabled) {
}

SceneLevel1::~SceneLevel1() {
}

// Load assets
bool SceneLevel1::Start() {
	LOG("Loading background assets SCENE 1");

	bool ret = true;

	texture_sea = App->textures->Load(FI_background_sea.c_str());
	texture_sea2 = App->textures->Load(FI_background_sea2.c_str());
	texture_forest1 = App->textures->Load(FI_background_forest1.c_str());
	texture_castle = App->textures->Load(FI_background_castle.c_str());
	texture_colum = App->textures->Load(FI_background_precolumnas.c_str());
	texture_start = App->textures->Load(FI_background_pre.c_str());
	texture_arboles = App->textures->Load(FI_background_arboles.c_str());

	App->audio->PlayMusic(FA_Music_stage1.c_str(), 1.0f);

	//Wall colliders
	int xt = 0;
	int yt = 2850;
	int wt = SCREEN_WIDTH;
	int ht = 10;
	topcoll = App->collisions->AddCollider({ xt, yt, wt, ht }, Collider::Type::WALL_PLAYER);

	int xb = 0;
	int yb = 3920;
	int wb = SCREEN_WIDTH;
	int hb = 10;
	botcoll = App->collisions->AddCollider({ xb, yb, wb, hb }, Collider::Type::WALL_PLAYER);

	int xl = 0;
	int yl = 2850;
	int wl = 10;
	int hl = SCREEN_HEIGHT;
	leftcoll = App->collisions->AddCollider({ xl, yl, wl, hl }, Collider::Type::WALL_PLAYER);

	int xr = SCREEN_WIDTH - 10;
	int yr = 2850;
	int wr = 10;
	int hr = SCREEN_HEIGHT;
	raightcoll = App->collisions->AddCollider({ xr, yr, wr, hr }, Collider::Type::WALL_PLAYER);

	start_time = SDL_GetTicks();

#pragma region ENEMIES
	App->enemies->AddEnemy(Enemy_Type::FLAG, 500, -400, 1);
	// add chest
	//App->enemies->AddEnemy(Enemy_Type::CHESTBLUE, 200, -500, 1);
	App->enemies->AddEnemy(Enemy_Type::ANGEL, 200, -500, 1);

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

	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, -100, -20500, 6);
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 800, -20650, 7);
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, -100, -20800, 6);
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 800, -20950, 7);

	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, -100, -23750, 6);
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 800, -23950, 7);
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, -100, -24150, 6);
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 800, -24350, 7);
#pragma endregion
#pragma region dragon
	////add dragon
	App->enemies->AddEnemy(Enemy_Type::DRAGON, 50, -9800, 1);
	App->enemies->AddEnemy(Enemy_Type::DRAGON, 450, -12000, 2);

#pragma endregion
#pragma region goblin
	App->enemies->AddEnemy(Enemy_Type::FLYTANK, 100, -15500, 1);
	App->enemies->AddEnemy(Enemy_Type::FLYTANK, 100, -26000, 1);
	
#pragma endregion

#pragma region tanks
	
	
	App->enemies->AddEnemy(Enemy_Type::TANK, 0, -17250, 1);
	App->enemies->AddEnemy(Enemy_Type::TANK, -150, -17250, 1);
	App->enemies->AddEnemy(Enemy_Type::TANK, -300, -17250, 1);
	App->enemies->AddEnemy(Enemy_Type::TANK, 800, -17112, 2);
	App->enemies->AddEnemy(Enemy_Type::TANK, 950, -17112, 2);
	App->enemies->AddEnemy(Enemy_Type::TANK, 1100, -17112, 2);

	App->enemies->AddEnemy(Enemy_Type::TANK, -150, -20350, 3);
	App->enemies->AddEnemy(Enemy_Type::TANK, 950, -20350, 4);
	App->enemies->AddEnemy(Enemy_Type::TANK, -150, -20500, 3);
	App->enemies->AddEnemy(Enemy_Type::TANK, 950, -20500, 4);
	App->enemies->AddEnemy(Enemy_Type::TANK, -150, -20650, 3);
	App->enemies->AddEnemy(Enemy_Type::TANK, 950, -20650, 4);
	App->enemies->AddEnemy(Enemy_Type::TANK, -150, -20800, 3);
	App->enemies->AddEnemy(Enemy_Type::TANK, 950, -20800, 4);

	App->enemies->AddEnemy(Enemy_Type::TANK, -0, -21600, 5);
	App->enemies->AddEnemy(Enemy_Type::TANK, -100, -21600, 5);
	App->enemies->AddEnemy(Enemy_Type::TANK, -0, -21750, 5);
	App->enemies->AddEnemy(Enemy_Type::TANK, -0, -21900, 5);
	App->enemies->AddEnemy(Enemy_Type::TANK, -800, -22050, 5);
	App->enemies->AddEnemy(Enemy_Type::TANK, -100, -22550, 7);
	App->enemies->AddEnemy(Enemy_Type::TANK, -100, -23050, 6);
	App->enemies->AddEnemy(Enemy_Type::TANK, -100, -24350, 6);
	App->enemies->AddEnemy(Enemy_Type::TANK, -250, -24350, 6);
	

#pragma endregion
#pragma region turtle

	App->enemies->AddEnemy(Enemy_Type::TURTLE, -100, -22650, 1);
	App->enemies->AddEnemy(Enemy_Type::TURTLE, -100, -22850, 1);
	App->enemies->AddEnemy(Enemy_Type::TURTLE, 100, -23750, 2);
	App->enemies->AddEnemy(Enemy_Type::TURTLE, 400, -23750, 2);

#pragma endregion
#pragma region goblin
	App->enemies->AddEnemy(Enemy_Type::MINIDRAGON, 150, -18350, 1);
	App->enemies->AddEnemy(Enemy_Type::MINIDRAGON, 540, -18350, 1);
	App->enemies->AddEnemy(Enemy_Type::MINIDRAGON, 240, -18550, 1);
	App->enemies->AddEnemy(Enemy_Type::MINIDRAGON, 630, -18550, 1);
	App->enemies->AddEnemy(Enemy_Type::MINIDRAGON, 150, -18750, 1);
	App->enemies->AddEnemy(Enemy_Type::MINIDRAGON, 540, -18750, 1);
	App->enemies->AddEnemy(Enemy_Type::MINIDRAGON, 240, -18950, 1);
	App->enemies->AddEnemy(Enemy_Type::MINIDRAGON, 630, -18950, 1);
	App->enemies->AddEnemy(Enemy_Type::MINIDRAGON, 150, -19150, 1);
	App->enemies->AddEnemy(Enemy_Type::MINIDRAGON, 540, -19150, 1);
	App->enemies->AddEnemy(Enemy_Type::MINIDRAGON, 240, -19350, 1);
	App->enemies->AddEnemy(Enemy_Type::MINIDRAGON, 630, -19350, 1);
	App->enemies->AddEnemy(Enemy_Type::MINIDRAGON, 150, -19550, 1);
	App->enemies->AddEnemy(Enemy_Type::MINIDRAGON, 540, -19550, 1);
	App->enemies->AddEnemy(Enemy_Type::MINIDRAGON, 240, -19750, 1);
	App->enemies->AddEnemy(Enemy_Type::MINIDRAGON, 630, -19750, 1);
	App->enemies->AddEnemy(Enemy_Type::MINIDRAGON, 150, -19950, 1);
	App->enemies->AddEnemy(Enemy_Type::MINIDRAGON, 540, -19950, 1);
	App->enemies->AddEnemy(Enemy_Type::MINIDRAGON, 240, -20150, 1);
	App->enemies->AddEnemy(Enemy_Type::MINIDRAGON, 630, -20350, 1);
	

	App->enemies->AddEnemy(Enemy_Type::MINIDRAGON, 720, -23550, 1);
	App->enemies->AddEnemy(Enemy_Type::MINIDRAGON, 630, -23550, 1);
	App->enemies->AddEnemy(Enemy_Type::MINIDRAGON, 540, -23550, 1);
	App->enemies->AddEnemy(Enemy_Type::MINIDRAGON, 720, -23700, 1);
	App->enemies->AddEnemy(Enemy_Type::MINIDRAGON, 630, -23700, 1);
	App->enemies->AddEnemy(Enemy_Type::MINIDRAGON, 540, -23700, 1);
	App->enemies->AddEnemy(Enemy_Type::MINIDRAGON, 720, -23850, 1);
	App->enemies->AddEnemy(Enemy_Type::MINIDRAGON, 630, -23850, 1);
	App->enemies->AddEnemy(Enemy_Type::MINIDRAGON, 540, -23850, 1);
	App->enemies->AddEnemy(Enemy_Type::MINIDRAGON, 720, -24000, 1);
	App->enemies->AddEnemy(Enemy_Type::MINIDRAGON, 630, -24000, 1);
	App->enemies->AddEnemy(Enemy_Type::MINIDRAGON, 540, -24000, 1);
	App->enemies->AddEnemy(Enemy_Type::MINIDRAGON, 720, -24150, 1);
	App->enemies->AddEnemy(Enemy_Type::MINIDRAGON, 630, -24150, 1);
	App->enemies->AddEnemy(Enemy_Type::MINIDRAGON, 540, -24150, 1);
	

#pragma endregion
#pragma region bigtank
	App->enemies->AddEnemy(Enemy_Type::BIGTANK, 0, -23250, 1);
	App->enemies->AddEnemy(Enemy_Type::BIGTANK, -277, -25550, 2);
	App->enemies->AddEnemy(Enemy_Type::BIGTANK, 1000, -25550, 3);
#pragma endregion
#pragma region redbat
	App->enemies->AddEnemy(Enemy_Type::REDBAT, 600, -22050, 1);
	App->enemies->AddEnemy(Enemy_Type::REDBAT, 600, -22050, 1);
	App->enemies->AddEnemy(Enemy_Type::REDBAT, 550, -22250, 1);
	App->enemies->AddEnemy(Enemy_Type::REDBAT, 500, -22450, 1);

	App->enemies->AddEnemy(Enemy_Type::REDBAT, 50, -25850, 1);
	App->enemies->AddEnemy(Enemy_Type::REDBAT, 250, -25850, 1);
	App->enemies->AddEnemy(Enemy_Type::REDBAT, 450, -25850, 1);
	App->enemies->AddEnemy(Enemy_Type::REDBAT, 650, -25850, 1);
#pragma endregion
	// POSITION INITIAL CAMERA
	App->render->camera.x = 0;
	App->render->camera.y = 2850;

	App->player->Enable();
	App->enemies->Enable();
	App->collisions->Enable();

	return ret;
}

Update_Status SceneLevel1::Update() {
	GamePad& pad = App->input->pads[0];

	App->render->camera.y += velocitatNivell;

	topcoll->rect.y += velocitatNivell;
	botcoll->rect.y += velocitatNivell;
	leftcoll->rect.y += velocitatNivell;
	raightcoll->rect.y += velocitatNivell;

	if (SDL_GetTicks() - start_time >= 600 )
	{
		velocitatNivell = -4;
	}
	if (SDL_GetTicks() - start_time >= 2600)
	{
		velocitatNivell = -6;
	}
	if (SDL_GetTicks() - start_time >= 4600)
	{
		velocitatNivell = -10;
	}
	if (SDL_GetTicks() - start_time >= 6600)
	{
		velocitatNivell = -15;
	}
	if (SDL_GetTicks() - start_time >= 46000)
	{
		velocitatNivell = -8;
	}
	if (SDL_GetTicks() - start_time >= 48000)
	{
		velocitatNivell = -4;
	}
	if (SDL_GetTicks() - start_time >= 89500)
	{
		velocitatNivell = -15;
	}

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
	if (App->input->keys[SDL_SCANCODE_1] == Key_State::KEY_DOWN || pad.up==true)
	{
		App->enemies->AddEnemy(Enemy_Type::CHEST_RED, App->player->position.x + 50, App->player->position.y - 800, 1);
	}
	if (App->input->keys[SDL_SCANCODE_2] == Key_State::KEY_DOWN || pad.down == true)
	{
		App->enemies->AddEnemy(Enemy_Type::CHEST_GREEN, App->player->position.x + 50, App->player->position.y - 800, 1);
	}
	if (App->input->keys[SDL_SCANCODE_3] == Key_State::KEY_DOWN || pad.right == true)
	{
		App->enemies->AddEnemy(Enemy_Type::CHEST_BLUE, App->player->position.x + 50, App->player->position.y - 800, 1);
	}
	if (App->input->keys[SDL_SCANCODE_4] == Key_State::KEY_DOWN || pad.left == true)
	{
		App->enemies->AddEnemy(Enemy_Type::ANGEL, App->player->position.x + 50, App->player->position.y - 800, 1);
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
	App->render->Blit(texture_start, 0, -SCREEN_HEIGHT * -1, NULL);
	App->render->Blit(texture_colum, 0, -SCREEN_HEIGHT * -1, NULL);
	App->render->Blit(texture_forest1, 0, (Height_background_forest1 - SCREEN_HEIGHT) * -1, NULL);
	App->render->Blit(texture_forest1, 0, (Height_background_forest1 + Height_background_forest1 - SCREEN_HEIGHT) * -1, NULL);
	App->render->Blit(texture_forest1, 0, (Height_background_forest1 + Height_background_forest1 + Height_background_forest1 - SCREEN_HEIGHT) * -1, NULL);
	App->render->Blit(texture_forest1, 0, (Height_background_forest1 + Height_background_forest1 + Height_background_forest1 + Height_background_forest1 - SCREEN_HEIGHT) * -1, NULL);
	App->render->Blit(texture_forest1, 0, (Height_background_forest1 + Height_background_forest1 + Height_background_forest1 + Height_background_forest1 + Height_background_forest1 - SCREEN_HEIGHT) * -1, NULL);
	App->render->Blit(texture_sea, 0, (Height_background_forest1 + Height_background_forest1 + Height_background_forest1 + Height_background_forest1 + Height_background_forest1 + Height_background_sea - SCREEN_HEIGHT) * -1, NULL);
	App->render->Blit(texture_sea2, 0, (Height_background_forest1 + Height_background_forest1 + Height_background_forest1 + Height_background_forest1 + Height_background_forest1 + Height_background_sea + Height_background_sea - SCREEN_HEIGHT) * -1, NULL);
	App->render->Blit(texture_forest1, 0, (Height_background_forest1 + Height_background_forest1 + Height_background_forest1 + Height_background_forest1 + Height_background_forest1 + Height_background_sea + Height_background_sea + Height_background_castle - SCREEN_HEIGHT) * -1, NULL);
	App->render->Blit(texture_castle, 0, (Height_background_forest1 + Height_background_forest1 + Height_background_forest1 + Height_background_forest1 + Height_background_forest1 + Height_background_sea + Height_background_sea + Height_background_castle - SCREEN_HEIGHT) * -1, NULL);
	App->render->Blit(texture_arboles, 0, (Height_background_forest1 + Height_background_forest1 + Height_background_forest1 + Height_background_forest1 + Height_background_forest1 + Height_background_sea + Height_background_sea + Height_background_castle - SCREEN_HEIGHT) * -1, NULL);
	App->render->Blit(texture_forest1, 0, (Height_background_forest1 + Height_background_forest1 + Height_background_forest1 + Height_background_forest1 + Height_background_forest1 + Height_background_sea + Height_background_sea + Height_background_castle + Height_background_forest1 - SCREEN_HEIGHT) * -1, NULL);
	App->render->Blit(texture_forest1, 0, (Height_background_forest1 + Height_background_forest1 + Height_background_forest1 + Height_background_forest1 + Height_background_forest1 + Height_background_sea + Height_background_sea + Height_background_castle + Height_background_forest1 + Height_background_forest1 - SCREEN_HEIGHT) * -1, NULL);
	App->render->Blit(texture_forest1, 0, (Height_background_forest1 + Height_background_forest1 + Height_background_forest1 + Height_background_forest1 + Height_background_forest1 + Height_background_sea + Height_background_sea + Height_background_castle + Height_background_forest1 + Height_background_forest1 + Height_background_forest1 - SCREEN_HEIGHT) * -1, NULL);
	App->render->Blit(texture_forest1, 0, (Height_background_forest1 + Height_background_forest1 + Height_background_forest1 + Height_background_forest1 + Height_background_forest1 + Height_background_sea + Height_background_sea + Height_background_castle + Height_background_forest1 + Height_background_forest1 + Height_background_forest1 + Height_background_forest1 - SCREEN_HEIGHT) * -1, NULL);

	return Update_Status::UPDATE_CONTINUE;
}

bool SceneLevel1::CleanUp() {
	App->player->Disable();
	App->enemies->Disable();
	App->collisions->Disable();
	return true;
}