#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>


using namespace std;


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


	return 0;
}