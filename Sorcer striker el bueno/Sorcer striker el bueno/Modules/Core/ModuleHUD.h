#pragma once
#include <vector>
#include <string>

#include <SDL.h> 
#include <SDL_image.h> 

#include "../Module.h"
#include "../../Utils/p2Point.h"

#define NUM_LETTERS 50


struct abecedari {
	char lletra;
	int posicio;
};


class ModuleHUD : public Module {

public:
	ModuleHUD(bool startEnabled);
	~ModuleHUD();

	void UpdateScore(int newScore);
	void UpdateHighScore(int newHighScore);
	void Render(SDL_Renderer* renderer);
	Update_Status PostUpdate() override;

private:
	int score;
	int highScore;
	std::vector<abecedari> vectorABC;


	int PosLetter(char lletraBuscar);
	void LoadVector();
	void WriteStringToScreen(char* fraseAPintar, iPoint posicioAPintar);

	//IMPRIMEIX ELS CARÀCTER DEL VECTOR 
};