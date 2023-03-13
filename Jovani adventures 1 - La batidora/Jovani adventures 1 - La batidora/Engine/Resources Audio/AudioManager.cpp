#include "AudioManager.h"














/*
// Inicializar SDL
if (SDL_Init(SDL_INIT_AUDIO) < 0) {
	printf("Error al inicializar SDL: %s\n", SDL_GetError());
	return 1;
}

// Inicializar SDL_mixer
if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
	printf("Error al inicializar SDL_mixer: %s\n", Mix_GetError());
	return 1;
}

// Cargar archivo de audio Ogg Vorbis
Mix_Music* music = Mix_LoadMUS("../Assets/Sounds/intro2.ogg");
if (!music) {
	printf("Error al cargar archivo de audio: %s\n", Mix_GetError());
	return 1;
}

// Reproducir archivo de audio
if (Mix_PlayMusic(music, 0) < 0) {
	printf("Error al reproducir archivo de audio: %s\n", Mix_GetError());
	return 1;
}

// Esperar a que el archivo de audio termine de reproducirse
while (Mix_PlayingMusic()) {
	SDL_Delay(100);
}

// Liberar recursos
Mix_FreeMusic(music);
Mix_CloseAudio();
SDL_Quit();

return 0;
*/
