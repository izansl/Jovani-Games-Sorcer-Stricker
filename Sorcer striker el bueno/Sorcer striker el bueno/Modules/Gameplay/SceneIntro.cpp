#include "SceneIntro.h"

#include "../../Application/Application.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleTextures.h"
#include "../../Modules/Core/ModuleRender.h"
#include "../../Modules/Core/ModuleAudio.h"
#include "../../Modules/Core/ModuleInput.h"
#include "../../Modules/Core/ModuleFadeToBlack.h"

SceneIntro::SceneIntro(bool startEnabled) : Module(startEnabled) {
}

SceneIntro::~SceneIntro() {
}

// Load assets
bool SceneIntro::Start() {
	LOG("Loading background assets SCENE INTRO");

	bool ret = true;
	//Carga de texturas(imagenes)
	bgTexture = App->textures->Load(FI_Introimage_1.c_str());
	SecondTexture = App->textures->Load(FI_Introimage_1.c_str());

	//Carga de Audio ////TURMO MUY IMPORTANTE, TIENES QUE CUADRAR EL AUDIO CON LA INTRO SEGUN LAS IMAGENES QUE APAREZCAN///
	App->audio->PlayMusic(FA_Music_introTitle.c_str(), 1.0f);//esta musica hay que cambiarla turmo

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	return ret;
} 

//NO TOCAR NADA
Update_Status SceneIntro::Update() {
	if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN) {
		App->fade->FadeToBlack(this, (Module*)App->sceneLevel_1, 90);
	}
	if (App->input->keys[SDL_SCANCODE_LSHIFT] == Key_State::KEY_DOWN)
	{
		tokenFx = App->audio->LoadFx(FA_Fx_token.c_str());
	};
	return Update_Status::UPDATE_CONTINUE;
}

// Update: draw background
Update_Status SceneIntro::PostUpdate() {
	// Draw everything --------------------------------------
	float timer = 0.0f;

	App->render->Blit(bgTexture, 0, 0, NULL);
	if (timer < 3.0f) {
		App->render->Blit(SecondTexture, 0, 0, NULL);
	}
	//A CONTINUAR
	timer += App->getdeltatime();

	return Update_Status::UPDATE_CONTINUE;
}