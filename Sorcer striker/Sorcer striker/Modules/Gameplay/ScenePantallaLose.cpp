#include "ScenePantallaLose.h"

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
	if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN) {//continua partida
		/*App->fade->FadeToBlack(this, (Module*)App->sceneLevel_1, 60);*/
		App->player->lives = 1;
		App->sceneLevel_1->velocitatNivell = -8;
	}

	

	if (App->input->keys[SDL_SCANCODE_C] == Key_State::KEY_DOWN)
	{
		/*tokenFx = App->audio->LoadFx(FA_Fx_token.c_str());*/
	};


	return Update_Status::UPDATE_CONTINUE;

}

Update_Status ScenePantallaLose::PostUpdate() {
	
	//App->render->Blit(ArrayImagesContinue[0], 0, 0, NULL);//1
	timer += 1.0f / 60.0f; // Suma 1 segundo//Funciona a 60 fps

	if (timer >= 1.0f) { // Mostramos cada imagen durante 3 segundos
		currentImage++;
		if (currentImage == NUM_IMAGES) {
			currentImage = 0;
		}
		timer = 0.0f;
	}

	App->render->Blit(ArrayImagesContinue[currentImage], 0, 0, NULL);
	

	return Update_Status::UPDATE_CONTINUE;

}