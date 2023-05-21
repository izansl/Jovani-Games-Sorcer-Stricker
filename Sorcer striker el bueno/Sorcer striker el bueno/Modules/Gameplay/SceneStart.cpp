#include "SceneStart.h"
#include <SDL_image.h>

#include "../../Application/Application.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleTextures.h"
#include "../../Modules/Core/ModuleRender.h"
#include "../../Modules/Core/ModuleAudio.h"
#include "../../Modules/Core/ModuleInput.h"
#include "../../Modules/Core/ModuleFadeToBlack.h"

SceneStart::SceneStart(bool startEnabled) : Module(startEnabled) {
}

SceneStart::~SceneStart() {
}

bool SceneStart::Start() {
	LOG("Loading background assets SCENE INTRO");

	bool ret = true;
	//Carga de texturas(imagenes)

	
	Intro[10] = App->textures->Load(FI_Introimage_11.c_str());
	Intro[11] = App->textures->Load(FI_Introimage_12.c_str());

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	return ret;
}

//NO TOCAR NADA //FadeToBlack de Intro -> Juego
Update_Status SceneStart::Update() {
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
Update_Status SceneStart::PostUpdate() {
	//DIBUJADO DE LAS IMAGENES DE LA INTRO

	

	Uint8 alpha = static_cast<Uint8>((timer / 3.0f) * 255);
	SDL_SetTextureAlphaMod(Intro[currentImage], alpha);

	App->render->Blit(Intro[currentImage], 0, 0, NULL);

	SDL_SetTextureAlphaMod(Intro[currentImage], 255);

	return Update_Status::UPDATE_CONTINUE;

}