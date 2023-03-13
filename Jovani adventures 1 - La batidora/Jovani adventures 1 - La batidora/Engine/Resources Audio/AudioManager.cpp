#include "AudioManager.h"

/*
CARREGAR EN CADA ESCENA ELS SEUS PROPIS SONS

void AudioManager::Init()
{
	Mix_Chunk* temporal = Mix_LoadWAV("../Assets/Sounds/salto_2.wav");
	vectorAudio.push_back(temporal);
	Mix_Chunk* temporal = Mix_LoadWAV("../Assets/Sounds/muerte.wav");
	vectorAudio.push_back(temporal);
	Mix_Chunk* temporal = Mix_LoadWAV("../Assets/Sounds/intro.wav");
	vectorAudio.push_back(temporal);
	Mix_Chunk* temporal = Mix_LoadWAV("../Assets/Sounds/gameover.wav");
	vectorAudio.push_back(temporal);
	Mix_Chunk* temporal = Mix_LoadWAV("../Assets/Sounds/gameplay.wav");
	vectorAudio.push_back(temporal);
}

*/

/*
AudioManager::~AudioManager()
{
	SDL_CloseAudioDevice(deviceID);
	SDL_FreeWAV(wavBuffer);
}
void AudioManager::load(const char* filename)
{
	SDL_LoadWAV(filename, &wavSpec, &wavBuffer, &wavLength);
	deviceID = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);

}
void AudioManager::play()
{
	SDL_QueueAudio(deviceID, wavBuffer, wavLength);
	SDL_PauseAudioDevice(deviceID, 0);
}
*/

#pragma region PUBLIC

AudioManager::~AudioManager()
{
}

void AudioManager::removeChunck(const char* fitxer)
{
}

Sint32 AudioManager::loadAndGetChunckID(const char* fitxer)
{
	return Sint32();
}

std::string AudioManager::getChunckPathByID(Sint32 ID)
{
	return std::string();
}

Mix_Chunk* AudioManager::getChunckByID(Sint32 ID)
{
	return nullptr;
}

void AudioManager::printChuncksLoaded()
{
}

#pragma endregion



#pragma region PROTECTED


AudioManager::AudioManager()
{
}

#pragma endregion



#pragma region PRIVATE

Sint32 AudioManager::addChunk(const char* file)
{
	return Sint32();
}

void AudioManager::updateFirstFreeSlotChunk()
{
}

#pragma endregion




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

/*
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
*/