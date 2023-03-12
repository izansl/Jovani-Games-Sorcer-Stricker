#include <SDL.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "ConsoleControl.h"

using namespace std;

void close(SDL_Window* window)
{
    //Quit SDL subsystems
    Mix_Quit();
    SDL_DestroyWindow(window);
    SDL_Quit();
}


int main(int argc, char* args[]) {

	SDL_Window* window = NULL;	
	SDL_Surface* screenSurface = NULL;
	SDL_Init(SDL_INIT_VIDEO);
	
	window = SDL_CreateWindow("SDL Exemple",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		854, 480,
		SDL_WINDOW_SHOWN);

	screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, NULL, 0xFF0000);
	SDL_UpdateWindowSurface(window);

//TODO: Tot el joc

#pragma region AudioManager
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
	int result = Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
	// Check
	if (result != 0)
		std::cout << "Failed to open audio: " << Mix_GetError() << std::endl;

	Mix_AllocateChannels(128);

	Mix_Chunk* sound1 = Mix_LoadWAV("../Assets/Sounds/salto_2.wav");

	// Check loads
	if (!sound1)
		std::cout << "Failed to load music or sound: " << Mix_GetError() << std::endl;

	int canalActual = 0;
	bool resume = false;
	int tecla = 0;

	std::cout << "Utilitza les fletxes per reproduir els sons" << std::endl;

	while (tecla != KB_ESCAPE)
	{
		tecla = ConsoleInKey();

		switch (tecla)
		{
		case KB_UP:
			canalActual = Mix_PlayChannel(-1, sound1, 0);
			std::cout << "Reproduint so 1." << std::endl;
			break;
		case KB_SPACE:
			if (resume)
			{
				Mix_Pause(canalActual);
				resume = false;
			}
			else {
				Mix_Resume(canalActual);
				resume = true;
			}
			break;
		default:
			break;
		}

	}

	Mix_FreeChunk(sound1);

	Mix_Quit();
	SDL_Quit();
#pragma endregion


	SDL_Delay(5000);
    

    close(window);


	SDL_Quit();


	return 0;
}