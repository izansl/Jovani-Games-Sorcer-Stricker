#pragma once
#ifndef IMAGEMANAGER_H
#define IMAGEMANAGER_H

#include <map>
#include <vector>
#include <string>
#include <iostream>

#include <SDL_image.h>
#include <SDL_render.h>

using namespace std;

// ResourceManager class
// Handles the load and management of the graphics in the game.
class ImageManager
{
public:
	static ImageManager* getInstance() {
		if (_resourceManagerInstance == NULL) _resourceManagerInstance = new ImageManager();
		return _resourceManagerInstance;
	};  // Gets Singleton instance

	Sint32 loadAndGetGraphicID(const char* fitxer);
	string getGraphicPathByID(Sint32 ID);
	SDL_Texture* getGraphicByID(Sint32 ID);
	void getGraphicSize(Sint32 img, int& width, int& height);
	Uint16 getGraphicWidth(Sint32 img);
	Uint16 getGraphicHeight(Sint32 img);
	void setAlphaGraphic(Sint32 ID, Uint8 alpha_value);
	void printLoadedGraphics();	// Print all loaded paths
	void removeGraphic(const char* fitxer);

	void setRender(SDL_Renderer* render) { _render = render; }

	~ImageManager();


protected:
	ImageManager();	// Constructor of an empty ResourceManager.


private:
	static ImageManager* _resourceManagerInstance;	// Singleton instance

	SDL_Renderer* _render;
	vector<SDL_Texture*> _graphicsVector;	// Vector that stores Surfaces. Useful in render methods and sequential access
	map<string, Sint32> _resourceManagerIDMap;	// Map that stores ID. Links strings to ID, Useful for check if graphic is has been loaded previously
	Uint32 _mFirstFreeSlot;	// First free slot in the _graphicsVector

	Sint32 addGraphic(const char* file);
	void updateFirstFreeSlotGraphic();
};

#endif