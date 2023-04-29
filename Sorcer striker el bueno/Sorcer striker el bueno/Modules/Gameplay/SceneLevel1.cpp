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
	//add dragon
	App->enemies->AddEnemy(Enemy_Type::DRAGON, 20, -4000);
	App->enemies->AddEnemy(Enemy_Type::DRAGON, 200, -4700);
	//add red ball
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 10, -500);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 10, -530);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 10, -560);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 10, -590);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 10, -620);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 10, -650);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 10, -680);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 10, -710);
	//add red ball 2
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -760);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -790);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -820);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -850);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -880);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -910);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -940);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -970);
	//add red ball 3
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -1600);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -1650);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -1700);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -1750);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -1800);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -1850);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -1900);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -1950);
	//add red ball 4
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -2100);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -2150);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -2200);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -2250);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -2300);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -2350);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -2400);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -2450);
	//add red ball 4
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -2300);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -2350);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -2400);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -2450);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -2500);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -2550);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -2600);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -2650);
	//add red ball 4
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 200, -2600);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 200, -2650);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 200, -2700);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 200, -2750);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 200, -2800);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 200, -2850);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 200, -2900);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 200, -2950);
	//add red ball 5
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -4000);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -4150);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -4200);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -4250);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -4300);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -4350);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -4400);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 250, -4450);
	//add red ball 6
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 10, -4800);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 10, -4850);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 10, -4900);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 10, -4950);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 10, -5000);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 10, -5050);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 10, -5100);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 10, -5150);
	//add red ball 4
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -5300);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -5350);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -5400);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -5450);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -5500);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -5550);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -5600);
	App->enemies->AddEnemy(Enemy_Type::RED_BALL, 100, -5650);
	//add Wizard
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 170, -2300);
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 215, -2300);
	//add Wizard 2
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 70, -2600);
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 115, -2600);
	//add wizard 3
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 170, -2900);
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 215, -2900);
	//add wizard 4
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 70, -3100);
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 115, -3100);
	//add wizard 5
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 170, -3400);
	App->enemies->AddEnemy(Enemy_Type::REDWIZARD, 215, -3400);


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