#include "ScenePantallaLose.h"
#include <SDL_image.h>

#include "../../Application/Application.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleTextures.h"
#include "../../Modules/Core/ModuleRender.h"
#include "../../Modules/Core/ModuleAudio.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Core/ModuleInput.h"
#include "../../Modules/Core/ModuleFadeToBlack.h"
#include "../Gameplay/ModuleEnemies.h"
#include "../Gameplay/ModulePlayer.h"
#include "../../Modules/Gameplay/SceneLevel1.h"

ScenePantallaLose::ScenePantallaLose(bool startEnabled) : Module(startEnabled) {
}

ScenePantallaLose::~ScenePantallaLose() {
}

bool ScenePantallaLose::Start() {
	LOG("Loading assets SCENE PantallaLose");

	bool ret = true;


	startTime = SDL_GetTicks();

	ArrayImagesContinue[0] = App->textures->Load(FI_continue_1.c_str());
	ArrayImagesContinue[1] = App->textures->Load(FI_continue_2.c_str());
	ArrayImagesContinue[2] = App->textures->Load(FI_continue_3.c_str());
	ArrayImagesContinue[3] = App->textures->Load(FI_continue_4.c_str());
	ArrayImagesContinue[4] = App->textures->Load(FI_continue_5.c_str());
	ArrayImagesContinue[5] = App->textures->Load(FI_continue_6.c_str());
	ArrayImagesContinue[6] = App->textures->Load(FI_continue_7.c_str());
	ArrayImagesContinue[7] = App->textures->Load(FI_continue_8.c_str());
	ArrayImagesContinue[8] = App->textures->Load(FI_continue_9.c_str());

	App->render->camera.x = 0;
	App->render->camera.y = 0;


	return ret;
}

Update_Status ScenePantallaLose::Update() {
	if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN) {//continuar partida

		App->player->lives = 1;
		App->sceneLevel_1->velocitatNivell = -8;
	};


	if (App->input->keys[SDL_SCANCODE_C] == Key_State::KEY_DOWN)
	{
		/*tokenFx = App->audio->LoadFx(FA_Fx_token.c_str());*/
	};


	return Update_Status::UPDATE_CONTINUE;

}

Update_Status ScenePantallaLose::PostUpdate() {
	
	Uint32 currentTime = SDL_GetTicks() - startTime;
	
	if (currentTime >= 1000 && currentTime < 2000) {

		App->render->Blit(ArrayImagesContinue[0], 0, 0, NULL);//1

	}

	if (currentTime >= 2000 && currentTime < 3000) {

		App->render->Blit(ArrayImagesContinue[1], 0, 0, NULL);//1

	}

	if (currentTime >= 3000 && currentTime < 4000) {

		App->render->Blit(ArrayImagesContinue[2], 0, 0, NULL);//1

	}

	if (currentTime >= 4000 && currentTime < 5000) {

		App->render->Blit(ArrayImagesContinue[3], 0, 0, NULL);//1

	}

	if (currentTime >= 5000 && currentTime < 6000) {

		App->render->Blit(ArrayImagesContinue[4], 0, 0, NULL);//1

	}

	if (currentTime >= 6000 && currentTime < 7000) {

		App->render->Blit(ArrayImagesContinue[5], 0, 0, NULL);//1

	}

	if (currentTime >= 7000 && currentTime < 8000) {

		App->render->Blit(ArrayImagesContinue[6], 0, 0, NULL);//1

	}

	if (currentTime >= 8000 && currentTime < 9000) {

		App->render->Blit(ArrayImagesContinue[7], 0, 0, NULL);//1

	}

	if (currentTime >= 9000 && currentTime < 10000) {

		App->render->Blit(ArrayImagesContinue[8], 0, 0, NULL);//1

	}
	
	

	return Update_Status::UPDATE_CONTINUE;

}