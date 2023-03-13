// ENGINE
#include "Engine/Video - Screen - Console/VideoManager.h"
#include "Engine/Resources Image/ImageManager.h"
#include "Engine/Resources Audio/AudioManager.h"
#include "Engine/Input/ControlManager.h"

// GAME
//#include "../Game/Scenes/SceneDirector.h"
#include "Game/Player.h"

int main(int argc, char* args[]) {


#pragma region Inits

	VideoManager* video = VideoManager::getInstance();
	ImageManager* imageManager = ImageManager::getInstance();
	video->setResourceManager(imageManager);
	imageManager->setRender(video->getRender());

	Player* player = new Player(video, imageManager);
	//SceneDirector* sceneDirector = SceneDirector::getInstance(video, imageManager, player);

	/*ControlManager* controlManager = new ControlManager();
	Keyboard* keyboard = new Keyboard();
	controlManager->InitControls(keyboard);

	Timer* timer = new Timer();*/

#pragma endregion


#pragma region Game loop

	bool goexit = false;
	bool key_escena1 = false;	// F1
	bool key_escena2 = false;	// F2
	bool key_escena3 = false;	// F3
	bool key_escena4 = false;	// F4
	bool key_escena5 = false;	// F5
	bool key_escena6 = false;	// F6
	bool key_escena7 = false;	// F7
	bool key_escena8 = false;	// F8
	bool key_escena9 = false;	// F9
	bool key_escena10 = false;	// F10
	bool key_escena11 = false;	// F11
	bool key_escena12 = false;	// F12

	do {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {

			case SDL_QUIT:
				goexit = true;
				break;

			case SDL_KEYUP:
				if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) { goexit = true; }
				if (event.key.keysym.scancode == SDL_SCANCODE_F1) { if (!key_escena1) key_escena1 = true; }
				if (event.key.keysym.scancode == SDL_SCANCODE_F2) { if (!key_escena2) key_escena2 = true; }
				if (event.key.keysym.scancode == SDL_SCANCODE_F3) { if (!key_escena3) key_escena3 = true; }
				if (event.key.keysym.scancode == SDL_SCANCODE_F4) { if (!key_escena4) key_escena4 = true; }
				if (event.key.keysym.scancode == SDL_SCANCODE_F5) { if (!key_escena5) key_escena5 = true; }
				if (event.key.keysym.scancode == SDL_SCANCODE_F6) { if (!key_escena6) key_escena6 = true; }
				if (event.key.keysym.scancode == SDL_SCANCODE_F7) { if (!key_escena7) key_escena7 = true; }
				if (event.key.keysym.scancode == SDL_SCANCODE_F8) { if (!key_escena8) key_escena8 = true; }
				if (event.key.keysym.scancode == SDL_SCANCODE_F9) { if (!key_escena9) key_escena9 = true; }
				if (event.key.keysym.scancode == SDL_SCANCODE_F10) { if (!key_escena10)	key_escena10 = true; }
				if (event.key.keysym.scancode == SDL_SCANCODE_F11) { if (!key_escena11)	key_escena11 = true; }
				if (event.key.keysym.scancode == SDL_SCANCODE_F12) { if (!key_escena12)	key_escena12 = true; }
				break;

			default:
				break;
			}
		}

		// Manual change scenes
		/*if (key_escena1) { sceneDirector->ChangeScene(INTRO); key_escena1 = false; }
		else if (key_escena2) { sceneDirector->ChangeScene(MAINMENU); key_escena2 = false; }
		else if (key_escena3) { sceneDirector->ChangeScene(FARM); key_escena3 = false; }
		else if (key_escena4) { sceneDirector->ChangeScene(TOWN); key_escena4 = false; }
		else if (key_escena5) { sceneDirector->ChangeScene(HOUSE); key_escena5 = false; }
		else if (key_escena6) { sceneDirector->ChangeScene(BARN_CHICKEN); key_escena6 = false; }
		else if (key_escena7) { sceneDirector->ChangeScene(BARN_COW); key_escena7 = false; }
		else if (key_escena8) { sceneDirector->ChangeScene(TOOL_SHED); key_escena8 = false; }*/

	} while (!goexit);

#pragma endregion


#pragma region Free, delete and exit

	imageManager->~ImageManager();
	video->~VideoManager();

	delete imageManager;
	delete video;

	SDL_Quit();

#pragma endregion

	return 0;
}