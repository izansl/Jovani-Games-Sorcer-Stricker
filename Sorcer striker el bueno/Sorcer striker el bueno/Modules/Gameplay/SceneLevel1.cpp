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

	fkText = App->textures->Load(FI_HUD_font1.c_str());
	texture_beach = App->textures->Load(FI_background_beach.c_str());
	texture_sea = App->textures->Load(FI_background_sea.c_str());
	texture_forest1 = App->textures->Load(FI_background_forest1.c_str());
	texture_forest2 = App->textures->Load(FI_background_forest2.c_str());
	texture_castle = App->textures->Load(FI_background_castle.c_str());

	App->audio->PlayMusic(FA_Music_stage1.c_str(), 1.0f);

	//First two columns colliders
	int xt = 0;
	int yt = 3000;
	int wt = 400;
	int ht = 10;
	topcoll = App->collisions->AddCollider({ xt, yt, wt, ht }, Collider::Type::WALL_PLAYER);

	int xb = 0;
	int yb = 3590;
	int wb = 400;
	int hb = 10;
	botcoll = App->collisions->AddCollider({ xb, yb, wb, hb }, Collider::Type::WALL_PLAYER);
	leftcoll= App->collisions->AddCollider({ 25, 3000, 10, 600 }, Collider::Type::WALL);
	raightcoll = App->collisions->AddCollider({ 345, 3000, 10, 600 }, Collider::Type::WALL);


#pragma region ENEMIES

	// add chest
	App->enemies->AddEnemy(Enemy_Type::CHEST, 200, -500, 1, 1);

#pragma region Red ball
	//add red ball
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 50, -400, 1, 1);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 50, -460, 1, 2);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 50, -520, 1, 3);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 50, -580, 1, 4);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 50, -640, 1, 5);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 50, -700, 1, 6);
	/*App->enemies->AddEnemy(Enemy_Type::RED_BALL, 50, -680, 1, 7);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 50, -710, 1, 8);*/

	//add red ball 2
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -800, 2, 1);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -860, 2, 2);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -920, 2, 3);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -980, 2, 4);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -1040, 2, 5);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -1100, 2, 6);
	//App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -940, 2, 7);
	//App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -970, 2, 8);

	//add red ball 3
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 110, -1600, 3, 1);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 110, -1660, 3, 2);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 110, -1720, 3, 3);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 110, -1780, 3, 4);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 110, -1840, 3, 5);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 110, -1900, 3, 6);
	/*App->enemies->AddEnemy(Enemy_Type::RED_BALL, 110, -1900, 3, 7);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 110, -1950, 3, 8);*/

	//add red ball 4
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -2200, 4, 1);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -2260, 4, 2);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -2320, 4, 3);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -2380, 4, 4);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -2440, 4, 5);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -2500, 4, 6);
	/*App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -2400, 4, 7);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -2450, 4, 8);*/

	//add red ball 5
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -2900, 5, 1);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -2960, 5, 2);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -3020, 5, 3);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -3080, 5, 4);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -3140, 5, 5);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -3200, 5, 6);
	///*App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -2600, 5, 7);
	//App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -2650, 5, 8);*/

	////add red ball 6
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -5500, 6, 1);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -5560, 6, 2);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -5620, 6, 3);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -5680, 6, 4);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -5740, 6, 5);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -5800, 6, 6);
	///*App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -4400, 6, 7);
	//App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -4450, 6, 8);*/

	////add red ball 7
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 50, -6300, 7, 1);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 50, -6360, 7, 2);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 50, -6420, 7, 3);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 50, -6480, 7, 4);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 50, -6540, 7, 5);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 50, -6600, 7, 6);
	///*App->enemies->AddEnemy(Enemy_Type::RED_BALL, 50, -5100, 7, 7);
	//App->enemies->AddEnemy(Enemy_Type::RED_BALL, 50, -5150, 7, 8);*/

	////add red ball 8
	//App->enemies->AddEnemy(Enemy_Type::RED_BALL, 150, -5500, 8, 1);
	//App->enemies->AddEnemy(Enemy_Type::RED_BALL, 150, -5560, 8, 2);
	//App->enemies->AddEnemy(Enemy_Type::RED_BALL, 150, -5620, 8, 3);
	//App->enemies->AddEnemy(Enemy_Type::RED_BALL, 150, -5680, 8, 4);
	//App->enemies->AddEnemy(Enemy_Type::RED_BALL, 150, -5740, 8, 5);
	//App->enemies->AddEnemy(Enemy_Type::RED_BALL, 150, -5800, 8, 6);
	/*App->enemies->AddEnemy(Enemy_Type::RED_BALL, 150, -5600, 8, 7);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 150, -5650, 8, 8);*/
#pragma endregion

#pragma region Wizard
	//add Wizard
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 170, -2500, 1, 0);
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 215, -2500, 1, 0);

	//add Wizard 2
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 70, -3200, 2, 0);
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 115, -3200, 2, 0);

	//add wizard 3
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 120, -3900, 3, 0);
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 165, -3900, 3, 0);

	//add wizard 4
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 70, -4600, 4, 0);
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 115, -4600, 4, 0);

	//add wizard 5
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 170, -5300, 5, 0);
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 215, -5300, 5, 0);
#pragma endregion

	////add dragon
	App->enemies->AddEnemy(Enemy_Type::DRAGON, 50, -5500, 1, 0);
	App->enemies->AddEnemy(Enemy_Type::DRAGON, 200, -6300, 2, 0);

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
	App->render->camera.y -= 8;

	topcoll->rect.y += -8;
	botcoll->rect.y += -8;
	leftcoll->rect.y += -8;
	raightcoll->rect.y += -8;

	if (App->player->position.y + 50 >= botcoll->rect.y)
	{
		App->player->position.y = botcoll->rect.y - 50;
	}

	if (App->player->position.y - 50 <= topcoll->rect.y)
	{
		App->player->position.y = topcoll->rect.y + 50;
	}

	return Update_Status::UPDATE_CONTINUE;
}

Update_Status SceneLevel1::PostUpdate() {
	// Draw everything --------------------------------------
	App->render->Blit(texture_forest1, +40, - SCREEN_HEIGHT * -1, NULL);
	App->render->Blit(texture_forest1, +40, (Height_background_forest1 - SCREEN_HEIGHT) * -1, NULL);
	App->render->Blit(texture_forest1, +40, (Height_background_forest1 + Height_background_forest1 - SCREEN_HEIGHT) * -1, NULL);
	App->render->Blit(texture_forest2, +40, (Height_background_forest1 + Height_background_forest1 + Height_background_forest2 - SCREEN_HEIGHT) * -1, NULL);
	App->render->Blit(texture_beach, +40, (Height_background_forest1 + Height_background_forest1 + Height_background_forest2 + Height_background_beach - SCREEN_HEIGHT) * -1, NULL);
	App->render->Blit(texture_sea, +40, (Height_background_forest1 + Height_background_forest1 + Height_background_forest2 + Height_background_beach + Height_background_sea - SCREEN_HEIGHT) * -1, NULL);
	App->render->Blit(texture_castle, +40, (Height_background_forest1 + Height_background_forest1 + Height_background_forest2 + Height_background_beach + Height_background_sea + Height_background_castle - SCREEN_HEIGHT) * -1, NULL);

	SDL_Rect rec;
	rec.x = 8;
	rec.y = 0;
	rec.w = 8;
	rec.h = 7;
	App->render->Blit(fkText, App->player->position.x, App->player->position.y, &rec);

	return Update_Status::UPDATE_CONTINUE;
}

bool SceneLevel1::CleanUp() {
	App->player->Disable();
	App->enemies->Disable();
	App->collisions->Disable();
	return true;
}