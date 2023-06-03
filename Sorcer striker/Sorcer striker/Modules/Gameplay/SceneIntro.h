#ifndef __SCENE_INTRO_H__
#define __SCENE_INTRO_H__

#include "../../Modules/Module.h"
#include "../../Utils/Animation.h"

struct SDL_Texture;


class SceneIntro : public Module {

public:
	//Constructor
	SceneIntro(bool startEnabled);
	//Destructor
	~SceneIntro();

	// Called when the module is activated
	// Loads the necessary textures for the map background
	bool Start() override;

	// Called at the middle of the application loop
	// Updates the scene's background animations
	Update_Status Update() override;

	// Called at the end of the application loop.
	// Performs the render call of all the parts of the scene's background
	Update_Status PostUpdate() override;


public:
	// The scene sprite sheet loaded into an SDL_Texture

	
	#define NUM_IMAGES 18		
	SDL_Texture* ArrayImagesIntro[NUM_IMAGES];
	float timer = 0.0f;
	float timer2 = 0.0f;
	int currentImage = 0;	
	uint musica = 0;
	//Prueba efecto fade en imagenes
	bool fadingOut = false;
	float fadeTimer = 0.0f;
	const float FADE_TIME = 1.0f;//duraci�n del DESVANECIMIENTO en segundos

	uint tokenFx = 0;
};

#endif