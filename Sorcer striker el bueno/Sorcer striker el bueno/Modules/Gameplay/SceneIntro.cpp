#include "SceneIntro.h"
#include <SDL_image.h>

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

	Intro[0] = App->textures->Load(FI_Introimage_1.c_str());
	Intro[1] = App->textures->Load(FI_Introimage_2.c_str());
	Intro[2] = App->textures->Load(FI_Introimage_3.c_str());
	Intro[3] = App->textures->Load(FI_Introimage_4.c_str());
	Intro[4] = App->textures->Load(FI_Introimage_5.c_str());
	Intro[5] = App->textures->Load(FI_Introimage_6.c_str());
	Intro[6] = App->textures->Load(FI_Introimage_7.c_str());
	Intro[7] = App->textures->Load(FI_Introimage_8.c_str());
	Intro[8] = App->textures->Load(FI_Introimage_9.c_str());
	Intro[9] = App->textures->Load(FI_Introimage_10.c_str());
	Intro[10] = App->textures->Load(FI_Introimage_11.c_str());
	Intro[11] = App->textures->Load(FI_Introimage_12.c_str());

	//Carga de Audio ////TURMO MUY IMPORTANTE, TIENES QUE CUADRAR EL AUDIO CON LA INTRO SEGUN LAS IMAGENES QUE APAREZCAN///
	App->audio->PlayMusic(FA_Music_introTitle.c_str());//esta musica hay que cambiarla turmo
	
	App->render->camera.x = 0;
	App->render->camera.y = 0;

	return ret;
} 

//NO TOCAR NADA //FadeToBlack de Intro -> Juego
Update_Status SceneIntro::Update() {
	if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN) {
		App->fade->FadeToBlack(this, (Module*)App->sceneStart, 90);
	}

	if (App->input->keys[SDL_SCANCODE_LSHIFT] == Key_State::KEY_DOWN)
	{
		tokenFx = App->audio->LoadFx(FA_Fx_token.c_str());
	};
	return Update_Status::UPDATE_CONTINUE;
}

// Update: draw background
Update_Status SceneIntro::PostUpdate() {
	//DIBUJADO DE LAS IMAGENES DE LA INTRO
	
	timer += 1.0f / 60.0f; // Suma 1 segundo//Funciona a 60 fps
	timer2 += 0.1f / 60.0f;
	if (timer >= 3.0f) { // Mostramos cada imagen durante 3 segundos
		currentImage++;
		if (Intro[9])
		{
			App->fade->FadeToBlack((Module*)App->sceneIntro, (Module*)App ->sceneStart, 60); //Menu start no intro
		}
		timer = 0.0f;
	}


	Uint8 alpha = static_cast<Uint8>((timer / 3.0f) * 255);
	SDL_SetTextureAlphaMod(Intro[currentImage], alpha);

	App->render->Blit(Intro[currentImage], 0, 0, NULL);

	SDL_SetTextureAlphaMod(Intro[currentImage], 255);
	
	return Update_Status::UPDATE_CONTINUE;
	
}