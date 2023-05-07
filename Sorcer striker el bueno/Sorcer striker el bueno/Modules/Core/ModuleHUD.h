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


class ModuleHUD : public Module {

public:
	ModuleHUD(bool startEnabled);
	~ModuleHUD();

	bool Start() override;
	Update_Status Update() override;
	Update_Status PostUpdate() override;
	bool CleanUp();


private:
	int score;
	int highScore;
	int sizeVector;

	std::vector<abecedari> vectorABC;

	std::string player1 = "Player 1";
	std::string player2 = "Player 2";
	std::string hlScore = "Hl-Score";

	SDL_Texture* texture = nullptr;


	int PosLetter(char leterToSearch);
	int LoadVector();
	void PaintSentence(std::string sentenceToPaint, iPoint positionToPaint);

	//IMPRIMEIX ELS CARÀCTER DEL VECTOR 
};