#include "SceneOutro.h"
#include <SDL_image.h>

#include "../../Application/Application.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleTextures.h"
#include "../../Modules/Core/ModuleRender.h"
#include "../../Modules/Core/ModuleAudio.h"
#include "../../Modules/Core/ModuleInput.h"
#include "../../Modules/Core/ModuleFadeToBlack.h"

SceneOutro::SceneOutro(bool startEnabled) : Module(startEnabled) {
}

SceneOutro::~SceneOutro() {
}

bool SceneOutro::Start() {
	LOG("Loading background assets SCENE OUTRO");

	bool ret = true;
	//Carga de texturas(imagenes)


	ArrayImagesOutro[0] = App->textures->Load(FI_Outroimage_0.c_str());
	ArrayImagesOutro[1] = App->textures->Load(FI_Outroimage_1.c_str());
	ArrayImagesOutro[2] = App->textures->Load(FI_Outroimage_2.c_str());

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	return ret;
}

//NO TOCAR NADA 
Update_Status SceneOutro::Update() {

	if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN) {
		App->fade->FadeToBlack(this, (Module*)App->sceneStart, 60);
	}

	return Update_Status::UPDATE_CONTINUE;
}

// Update: draw background
Update_Status SceneOutro::PostUpdate() {
	//DIBUJADO DE LAS IMAGENES DE LA INTRO

	timer += 1.0f / 60.0f; // Suma 1 segundo//Funciona a 60 fps

	if (timer >= 3.0f) { // Mostramos cada imagen durante 3 segundos
		currentImage++;
		if (currentImage == NUM_IMAGES) {
			App->fade->FadeToBlack(this, (Module*)App->sceneStart, 60);
		}
		timer = 0.0f;
	}

	App->render->Blit(ArrayImagesOutro[currentImage], 0, 0, NULL);



	return Update_Status::UPDATE_CONTINUE;

}