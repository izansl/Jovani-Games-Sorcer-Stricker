#include "SceneLevel1.h"

#include "../../Application/Application.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleTextures.h"
#include "../../Modules/Core/ModuleRender.h"
#include "../../Modules/Core/ModuleAudio.h"
#include "../../Modules/Core/ModuleCollisions.h"

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

	texture_beach = App->textures->Load(FI_background_beach.c_str());
	texture_sea = App->textures->Load(FI_background_sea.c_str());
	texture_forest1 = App->textures->Load(FI_background_forest1.c_str());
	texture_forest2 = App->textures->Load(FI_background_forest2.c_str());
	texture_castle = App->textures->Load(FI_background_castle.c_str());

	App->audio->PlayMusic(FA_Music_stage1.c_str(), 1.0f);

	////Bottomside collider
	//App->collisions->AddCollider({ 0, 200, 300, 10 }, Collider::Type::WALL);

	if (texture_forest2 != nullptr) {
		int x = 0; // posición x del collider
		int y = -11000;
		int w = 300;
		int h = 10;	
		Collider* collider_castle = App->collisions->AddCollider({ x, y, w, h }, Collider::Type::WALL);
	}

	//First two columns colliders
	int xt = 0;
	int yt = 0;
	int wt = 400;
	int ht = 10;
	topcoll = App->collisions->AddCollider({ xt, yt, wt, ht }, Collider::Type::WALL_PLAYER);
	int xb = 0;
	int yb = 590;
	int wb = 400;
	int hb = 10;
	botcoll = App->collisions->AddCollider({ xb, yb, wb, hb }, Collider::Type::WALL_PLAYER);

	// Enemies ---
	// TODO: ---> Posar tots els enemics que toquin
	/*App->enemies->AddEnemy(Enemy_Type::REDBIRD, 600, 80);
	App->enemies->AddEnemy(Enemy_Type::REDBIRD, 625, 80);
	App->enemies->AddEnemy(Enemy_Type::REDBIRD, 640, 80);
	App->enemies->AddEnemy(Enemy_Type::REDBIRD, 665, 80);

	App->enemies->AddEnemy(Enemy_Type::REDBIRD, 735, 120);
	App->enemies->AddEnemy(Enemy_Type::REDBIRD, 750, 120);
	App->enemies->AddEnemy(Enemy_Type::REDBIRD, 775, 120);
	App->enemies->AddEnemy(Enemy_Type::REDBIRD, 790, 120);

	App->enemies->AddEnemy(Enemy_Type::BROWNSHIP, 830, 100);
	App->enemies->AddEnemy(Enemy_Type::BROWNSHIP, 850, 100);
	App->enemies->AddEnemy(Enemy_Type::BROWNSHIP, 870, 100);
	App->enemies->AddEnemy(Enemy_Type::BROWNSHIP, 890, 100);

	App->enemies->AddEnemy(Enemy_Type::MECH, 900, 195);*/
	
	//add red ball
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 50, -500, 1, 1);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 50, -530, 1, 2);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 50, -560, 1, 3);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 50, -590, 1, 4);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 50, -620, 1, 5);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 50, -650, 1, 6);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 50, -680, 1, 7);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 50, -710, 1, 8);
	//add red ball 2
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -760, 2, 1);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -790, 2, 2);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -820, 2, 3);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -850, 2, 4);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -880, 2, 5);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -910, 2, 6);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -940, 2, 7);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -970, 2, 8);
	//add red ball 3
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 110, -1600, 3, 1);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 110, -1650, 3, 2);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 110, -1700, 3, 3);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 110, -1750, 3, 4);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 110, -1800, 3, 5);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 110, -1850, 3, 6);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 110, -1900, 3, 7);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 110, -1950, 3, 8);
	//add red ball 4
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -2100, 4, 1);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -2150, 4, 2);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -2200, 4, 3);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -2250, 4, 4);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -2300, 4, 5);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -2350, 4, 6);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -2400, 4, 7);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -2450, 4, 8);
	//add red ball 5
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -2300, 5, 1);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -2350, 5, 2);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -2400, 5, 3);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -2450, 5, 4);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -2500, 5, 5);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -2550, 5, 6);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -2600, 5, 7);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -2650, 5, 8);
	
	//add red ball 6
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -4100, 6, 1);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -4150, 6, 2);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -4200, 6, 3);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -4250, 6, 4);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -4300, 6, 5);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -4350, 6, 6);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -4400, 6, 7);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 290, -4450, 6, 8);
	//add red ball 7
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 50, -4800, 7, 1);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 50, -4850, 7, 2);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 50, -4900, 7, 3);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 50, -4950, 7, 4);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 50, -5000, 7, 5);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 50, -5050, 7, 6);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 50, -5100, 7, 7);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 50, -5150, 7, 8);
	//add red ball 8
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 150, -5300, 8, 1);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 150, -5350, 8, 2);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 150, -5400, 8, 3);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 150, -5450, 8, 4);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 150, -5500, 8, 5);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 150, -5550, 8, 6);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 150, -5600, 8, 7);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 150, -5650, 8, 8);
	//add Wizard
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 170, -2300, 1, 0);
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 215, -2300, 1, 0);
	//add Wizard 2
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 70, -2600, 2, 0);
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 115, -2600, 2, 0);
	//add wizard 3
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 120, -2900, 3, 0);
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 165, -2900, 3, 0);
	//add wizard 4
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 70, -3100, 4, 0);
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 115, -3100, 4, 0);
	//add wizard 5
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 170, -3400, 5, 0);
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 215, -3400, 5, 0);

	//add dragon
	App->enemies->AddEnemy(Enemy_Type::DRAGON, 50, -4000, 1, 0);
	App->enemies->AddEnemy(Enemy_Type::DRAGON, 200, -4700, 2, 0);

	// POSITION INITIAL CAMERA
	App->render->camera.x = 0;
	App->render->camera.y = 0;

	App->player->Enable();
	App->enemies->Enable();

	return ret;
}

Update_Status SceneLevel1::Update() {
	App->render->camera.y -= 8;
	
	topcoll->rect.y += -8;
	botcoll->rect.y += -8;

	return Update_Status::UPDATE_CONTINUE;
}

// Update: draw background
Update_Status SceneLevel1::PostUpdate() {
	// Draw everything --------------------------------------
	App->render->Blit(texture_forest1, +40, (Height_background_forest1 - SCREEN_HEIGHT) * -1, NULL);
	App->render->Blit(texture_beach, +40, (Height_background_forest1 + Height_background_beach - SCREEN_HEIGHT) * -1, NULL);
	App->render->Blit(texture_sea, +40, (Height_background_forest1 + Height_background_beach + Height_background_sea - SCREEN_HEIGHT) * -1, NULL);
	App->render->Blit(texture_castle, +40, (Height_background_forest1 + Height_background_beach + Height_background_sea + Height_background_castle - SCREEN_HEIGHT) * -1, NULL);

	return Update_Status::UPDATE_CONTINUE;
}

bool SceneLevel1::CleanUp() {
	App->player->Disable();
	App->enemies->Disable();
	return true;
}