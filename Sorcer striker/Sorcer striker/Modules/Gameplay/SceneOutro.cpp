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


	ArrayImagesStart[0] = App->textures->Load(FI_Start_1.c_str());
	ArrayImagesStart[1] = App->textures->Load(FI_Start_2.c_str());

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	return ret;
}

//NO TOCAR NADA //FadeToBlack de Intro -> primera escena
Update_Status SceneOutro::Update() {
	
	return Update_Status::UPDATE_CONTINUE;
}

// Update: draw background
Update_Status SceneOutro::PostUpdate() {
	//DIBUJADO DE LAS IMAGENES DE LA INTRO

	timer += 1.0f / 60.0f; // Suma 1 segundo//Funciona a 60 fps

	if (timer >= 0.05f) { // Mostramos cada imagen durante 3 segundos
		currentImage++;
		if (currentImage == NUM_IMAGES) {
			currentImage = 0;
		}
		timer = 0.0f;
	}

	App->render->Blit(ArrayImagesStart[currentImage], 0, 0, NULL);



	return Update_Status::UPDATE_CONTINUE;

}