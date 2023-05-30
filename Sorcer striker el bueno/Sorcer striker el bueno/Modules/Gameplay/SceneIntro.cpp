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

	startTime = SDL_GetTicks();
	//Carga de texturas(imagenes)
	// 
	//Carga imagenes carpeta Intro
	ArrayImagesIntro[0] = App->textures->Load(FI_Introimage_1.c_str());
	ArrayImagesIntro[1] = App->textures->Load(FI_Introimage_2.c_str());
	ArrayImagesIntro[2] = App->textures->Load(FI_Introimage_3.c_str());
	ArrayImagesIntro[3] = App->textures->Load(FI_Introimage_4.c_str());
	ArrayImagesIntro[4] = App->textures->Load(FI_Introimage_5.c_str());
	ArrayImagesIntro[5] = App->textures->Load(FI_Introimage_6.c_str());
	ArrayImagesIntro[6] = App->textures->Load(FI_Introimage_7.c_str());
	ArrayImagesIntro[7] = App->textures->Load(FI_Introimage_8.c_str());
	ArrayImagesIntro[8] = App->textures->Load(FI_Introimage_9.c_str());
	ArrayImagesIntro[9] = App->textures->Load(FI_Introimage_10.c_str());
	ArrayImagesIntro[10] = App->textures->Load(FI_Introimage_11.c_str());
	ArrayImagesIntro[11] = App->textures->Load(FI_Introimage_12.c_str());
	ArrayImagesIntro[12] = App->textures->Load(FI_Introimage_13.c_str());
	ArrayImagesIntro[13] = App->textures->Load(FI_Introimage_14.c_str());
	ArrayImagesIntro[14] = App->textures->Load(FI_Introimage_15.c_str());
	ArrayImagesIntro[15] = App->textures->Load(FI_Introimage_16.c_str());
	ArrayImagesIntro[16] = App->textures->Load(FI_Introimage_17.c_str());
	ArrayImagesIntro[17] = App->textures->Load(FI_Introimage_18.c_str());
	//Carga imagenes carpeta sprites-lluc-intro
	ArrayImagesIntro2[0] = App->textures->Load(FI_Introimage_19.c_str());
	ArrayImagesIntro2[1] = App->textures->Load(FI_Introimage_20.c_str());
	ArrayImagesIntro2[2] = App->textures->Load(FI_Introimage_21.c_str());
	ArrayImagesIntro2[3] = App->textures->Load(FI_Introimage_22.c_str());
	ArrayImagesIntro2[4] = App->textures->Load(FI_Introimage_23.c_str());
	ArrayImagesIntro2[5] = App->textures->Load(FI_Introimage_24.c_str());
	ArrayImagesIntro2[6] = App->textures->Load(FI_Introimage_25.c_str());
	ArrayImagesIntro2[7] = App->textures->Load(FI_Introimage_26.c_str());
	ArrayImagesIntro2[8] = App->textures->Load(FI_Introimage_27.c_str());
	//Carga de Audio ////TURMO MUY IMPORTANTE, TIENES QUE CUADRAR EL AUDIO CON LA INTRO SEGUN LAS IMAGENES QUE APAREZCAN///
	App->audio->PlayMusic(FA_Music_introTitle.c_str());//esta musica hay que cambiarla turmo
	
	App->render->camera.x = 0;
	App->render->camera.y = 0;

	return ret;
} 

//NO TOCAR NADA //FadeToBlack de Intro -> Juego
Update_Status SceneIntro::Update() {
	if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN) {
		App->fade->FadeToBlack(this, (Module*)App->sceneStart, 60);
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
	Uint32 currentTime = SDL_GetTicks() - startTime;
	
	if (currentTime >= 3000) {
		
		App->render->Blit(ArrayImagesIntro[0], 0, 0, NULL);//jovani
		/*Blit(SDL_Texture * texture, int x, int y, const SDL_Rect * section, float speed, bool useCamera)*/
	}

	if (currentTime >= 6000) {

		App->render->Blit(ArrayImagesIntro[1], 0, 0, NULL);//Raizing

	}

	if (currentTime >= 9000) {

		App->render->Blit(ArrayImagesIntro2[8], 0, 0, NULL);//fondonegro

	}

	if (currentTime >= 9000 && currentTime < 13000) {

		App->render->Blit(ArrayImagesIntro[2], -10, 0, NULL);//Primertextocolor

	}

	if (currentTime >= 10000) {

		App->render->Blit(ArrayImagesIntro2[7], 0, -20, NULL);//holalluc

	}

	if (currentTime >= 13000) {

		App->render->Blit(ArrayImagesIntro[5], 0, 0, NULL);//segundotextocolor

	}

	if (currentTime >= 15000) {

		App->render->Blit(ArrayImagesIntro2[0], 0, 20, NULL);//alienarribafondo

	}


	return Update_Status::UPDATE_CONTINUE;
	
}