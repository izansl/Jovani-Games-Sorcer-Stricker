#pragma once
#include <vector>
#include <string>

#include <SDL.h> 
#include <SDL_image.h> 

#include "../Module.h"
#include "../../Utils/p2Point.h"


struct abecedari {
	char lletra;
	int posicio;

};


class ModuleHUD {
public:
	ModuleHUD();
	~ModuleHUD();

	void UpdateScore(int newScore);
	void UpdateHighScore(int newHighScore);
	void Render(SDL_Renderer* renderer);

private:
	int score;
	int highScore;
	std::vector<abecedari> vectorABC[50];


	int poslletra(char lletraBuscar);
	void carregarVector();
	void EscriureString(char* fraseAPintar, iPoint posicioAPintar);

	//IMPRIMEIX ELS CARÀCTER DEL VECTOR 
};