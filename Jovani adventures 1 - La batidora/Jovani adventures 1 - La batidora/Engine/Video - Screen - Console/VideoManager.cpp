#include "VideoManager.h"
#include <iostream>

VideoManager* VideoManager::_videoInstance = NULL;


void VideoManager::renderGraphic(int idTextura, Xywh* src, Xywh* dst)
{
	// Assignar RECTs SRC/DEST
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = src->x;
	srcRect.y = src->y;
	srcRect.w = src->w;
	srcRect.h = src->h;

	destRect.x = dst->x;
	destRect.y = dst->y;
	destRect.w = dst->w;
	destRect.h = dst->h;

	SDL_RenderCopy(_renderer, _imageManager->getGraphicByID(idTextura), &srcRect, &destRect);
}

void VideoManager::clearScreen()
{
	SDL_RenderClear(_renderer);
}

void VideoManager::UpdateScreen()
{
	SDL_RenderPresent(_renderer);
}

void VideoManager::waitTime(int ms)
{
	SDL_Delay(ms);
}

void VideoManager::close()
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}


VideoManager::~VideoManager() {
	close();
}


VideoManager::VideoManager()
{
	_window = NULL;
	_surface = NULL;
	_renderer = NULL;
	_imageManager = NULL;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		std::cerr << "SDL_Init failed: " << SDL_GetError() << "\n";

	_window = SDL_CreateWindow("Jovani adventures 1: La batidora", SIZE_WORLD_W, SIZE_WORLD_H, SIZE_CAMERA_W, SIZE_CAMERA_H, SDL_WINDOW_SHOWN);
	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
}