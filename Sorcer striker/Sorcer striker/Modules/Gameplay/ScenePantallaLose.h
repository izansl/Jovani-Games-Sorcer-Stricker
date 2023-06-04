#ifndef __SCENE_PANTALLALOSE_H__
#define __SCENE_PANTALLALOSE_H__

#include "../../Modules/Module.h"
#include "../../Utils/Animation.h"

struct SDL_Texture;

class SceneLevel1 : public Module {

public:
	//Constructor
	SceneLevel1(bool startEnabled);

	//Destructor
	~SceneLevel1();

	// Called when the module is activated
	// Loads the necessary textures for the map background
	bool Start() override;

	// Called at the middle of the application loop
	// Updates the scene's background animations
	Update_Status Update() override;

	// Called at the end of the application loop.
	// Performs the render call of all the parts of the scene's background
	Update_Status PostUpdate() override;

	// Disables the player and the enemies
	bool CleanUp();


public:
	// The scene sprite sheet loaded into an SDL_Texture
	/*SDL_Texture* texture_beach = nullptr;
	SDL_Texture* texture_sea = nullptr;
	SDL_Texture* texture_forest1 = nullptr;
	SDL_Texture* texture_forest2 = nullptr;
	SDL_Texture* texture_castle = nullptr;

	Collider* botcoll = nullptr;
	Collider* topcoll = nullptr;
	Collider* leftcoll = nullptr;
	Collider* raightcoll = nullptr;*/

	int velocitatNivell = -8;
};

#endif
