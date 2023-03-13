#include <SDL.h>
#include <SDL_image.h>
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

	SDL_Surface* image;
	SDL_Window* window;
	SDL_Surface* screenSurface;

	// Initialize SDL and SDL_image
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);

	// Create a window for displaying the image
	window = SDL_CreateWindow("Image Viewer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
	screenSurface = SDL_GetWindowSurface(window);

	// Load the image into a surface
	image = IMG_Load("../Assets/Images/Dibujo_2_def.png");

	// Blit the image to the screen
	SDL_BlitSurface(image, NULL, screenSurface, NULL);
	SDL_UpdateWindowSurface(window);

	// Wait for the user to close the window
	bool quit = false;
	SDL_Event event;
	while (!quit) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
		}
	}

	// Clean up and exit
	SDL_FreeSurface(image);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();


/*	SDL_Window* window = NULL;
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

	*/
	return 0;
}