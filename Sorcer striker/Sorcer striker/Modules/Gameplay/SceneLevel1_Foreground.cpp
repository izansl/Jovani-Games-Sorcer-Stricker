#include "SceneLevel1_Foreground.h"

#include "../../Application/Application.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleTextures.h"
#include "../../Modules/Core/ModuleRender.h"
#include "../../Modules/Core/ModuleAudio.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Core/ModuleInput.h"
#include "../Gameplay/ModuleEnemies.h"
#include "../Gameplay/ModulePlayer.h"
#include "../Gameplay/SceneLevel1.h"


SceneLevel1_Foreground::SceneLevel1_Foreground(bool startEnabled) : Module(startEnabled){
}

SceneLevel1_Foreground::~SceneLevel1_Foreground() {
}

bool SceneLevel1_Foreground::Start(){
	LOG("Loading background assets SCENE 1");

	bool ret = true;

	velocitatNivell = App->sceneLevel_1->velocitatNivell;

	

	return ret;
}

Update_Status SceneLevel1_Foreground::Update(){
	return Update_Status::UPDATE_CONTINUE;
}

Update_Status SceneLevel1_Foreground::PostUpdate(){
	// Aqui pintem totes les imatges que van sobre de enemics i scena1, pero no de player
	


	return Update_Status::UPDATE_CONTINUE;
}

bool SceneLevel1_Foreground::CleanUp(){
	return true;
}
