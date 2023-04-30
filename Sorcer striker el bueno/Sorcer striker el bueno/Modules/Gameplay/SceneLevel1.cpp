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
	LOG("Loading background assets");

	bool ret = true;

	texture_beach = App->textures->Load(FI_background_beach.c_str());
	texture_sea = App->textures->Load(FI_background_sea.c_str());
	texture_forest1 = App->textures->Load(FI_background_forest1.c_str());
	texture_forest2 = App->textures->Load(FI_background_forest2.c_str());
	texture_castle = App->textures->Load(FI_background_castle.c_str());

	App->audio->PlayMusic(FTA_Music_stage1.c_str(), 1.0f);

	//Bottomside collider
	App->collisions->AddCollider({ 0, 224, 3930, 16 }, Collider::Type::WALL);

	//First two columns colliders
	App->collisions->AddCollider({ 1375, 0, 111, 96 }, Collider::Type::WALL);
	App->collisions->AddCollider({ 1375, 145, 111, 96 }, Collider::Type::WALL);

	// Enemies ---
	// TODO: Posar tots els enemics que toquin
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
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 10, -500, 1 );
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 10, -530, 1);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 10, -560, 1);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 10, -590, 1);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 10, -620, 1);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 10, -650, 1);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 10, -680, 1);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 10, -710, 1);
	//add red ball 2
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -760, 2);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -790, 2);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -820, 2);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -850, 2);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -880, 2);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -910, 2);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -940, 2);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -970, 2);
	//add red ball 3
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -1600, 3);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -1650, 3);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -1700, 3);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -1750, 3);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -1800, 3);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -1850, 3);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -1900, 3);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -1950, 3);
	//add red ball 4
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -2100, 4);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -2150, 4);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -2200, 4);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -2250, 4);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -2300, 4);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -2350, 4);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -2400, 4);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -2450, 4);
	//add red ball 5
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -2300, 5);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -2350, 5);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -2400, 5);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -2450, 5);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -2500, 5);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -2550, 5);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -2600, 5);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -2650, 5);
	
	//add red ball 6
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -4000, 6);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -4150, 6);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -4200, 6);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -4250, 6);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -4300, 6);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -4350, 6);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -4400, 6);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -4450, 6);
	//add red ball 7
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 10, -4800, 7);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 10, -4850, 7);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 10, -4900, 7);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 10, -4950, 7);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 10, -5000, 7);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 10, -5050, 7);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 10, -5100, 7);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 10, -5150, 7);
	//add red ball 8
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -5300, 8);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -5350, 8);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -5400, 8);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -5450, 8);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -5500, 8);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -5550, 8);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -5600, 8);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -5650, 8);
	//add Wizard
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 170, -2300, 1);
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 215, -2300, 1);
	//add Wizard 2
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 70, -2600, 2);
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 115, -2600, 2);
	//add wizard 3
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 110, -2900, 3);
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 165, -2900, 3);
	//add wizard 4
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 70, -3100, 4);
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 115, -3100, 4);
	//add wizard 5
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 170, -3400, 5);
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 215, -3400, 5);

	//add dragon
	App->enemies->AddEnemy(Enemy_Type::DRAGON, 20, -4000, 1);
	App->enemies->AddEnemy(Enemy_Type::DRAGON, 200, -4700, 2);

	// POSITION INITIAL CAMERA
	App->render->camera.x = 0;
	App->render->camera.y = 0;

	App->player->Enable();
	App->enemies->Enable();

	return ret;
}

Update_Status SceneLevel1::Update() {
	App->render->camera.y -= 3;

	return Update_Status::UPDATE_CONTINUE;
}

// Update: draw background
Update_Status SceneLevel1::PostUpdate() {
	// Draw everything --------------------------------------
	App->render->Blit(texture_beach, 0, (Height_background_beach - SCREEN_HEIGHT) * -1, NULL);
	App->render->Blit(texture_sea, 0, (Height_background_beach + Height_background_sea - SCREEN_HEIGHT) * -1, NULL);
	App->render->Blit(texture_forest1, 0, (Height_background_beach + Height_background_sea + Height_background_forest1 - SCREEN_HEIGHT) * -1, NULL);
	App->render->Blit(texture_forest2, 0, (Height_background_beach + Height_background_sea + Height_background_forest1 + Height_background_forest2 - SCREEN_HEIGHT) * -1, NULL);
	App->render->Blit(texture_castle, 0, (Height_background_beach + Height_background_sea + Height_background_forest1 + Height_background_forest2 + Height_background_castle - SCREEN_HEIGHT) * -1, NULL);

	return Update_Status::UPDATE_CONTINUE;
}

bool SceneLevel1::CleanUp() {
	App->player->Disable();
	App->enemies->Disable();
	return true;
}