#include "ScenePantallaLose.h"

#include "../../Application/Application.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleTextures.h"
#include "../../Modules/Core/ModuleRender.h"
#include "../../Modules/Core/ModuleAudio.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Core/ModuleInput.h"
#include "../Gameplay/ModuleEnemies.h"
#include "../Gameplay/ModulePlayer.h"

ScenePantallaLose::ScenePantallaLose(bool startEnabled) : Module(startEnabled) {
}

ScenePantallaLose::~ScenePantallaLose() {
}

bool ScenePantallaLose::Start() {
	LOG("Loading background assets SCENE INTRO");

	bool ret = true;


	return ret;
}