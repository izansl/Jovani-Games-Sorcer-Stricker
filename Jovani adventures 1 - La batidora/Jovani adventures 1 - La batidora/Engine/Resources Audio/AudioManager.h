#pragma once
#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <SDL_mixer.h>

class AudioManager
{

public:
	~AudioManager();

	void removeChunck(const char* fitxer);
	Sint32 loadAndGetChunckID(const char* fitxer);
	std::string getChunckPathByID(Sint32 ID);
	Mix_Chunk* getChunckByID(Sint32 ID);
	void printChuncksLoaded();	// Print all loaded paths

	static AudioManager* getInstance() {
		if (_soundManagerInstance == NULL) _soundManagerInstance = new AudioManager();
		return _soundManagerInstance;
	};//! Gets Singleton instance	


protected:
	AudioManager();


private:
	Sint32 addChunk(const char* file);
	void updateFirstFreeSlotChunk();

	std::vector<Mix_Chunk*> _chunksVector; // Vector that stores Surfaces. Useful in render methods and sequential access
	std::map<std::string, Sint32> _chunkIDMap; // Map that stores ID. Links strings to ID, Useful for check if graphic is has been loaded previously

	Uint32 _firstFreeSlotChunk; // First free slot in the mSoundVector

	static AudioManager* _soundManagerInstance; // Singleton instance
};

#endif
/*
public:
	~AudioManager();
	void load(const char* filename);
	void play();
	void Init();
private:
	SDL_AudioSpec wavSpec;
	Uint32 wavLength;
	Uint8* wavBuffer;
	SDL_AudioDeviceID deviceID;
	std::vector<Mix_Chunk*> vectorAudio;
	*/