#pragma once
#include "../Resources Image/ImageManager.h"
#include "../Definitions.h"

struct Xywh
{
	int x;
	int y;
	int w;
	int h;
};


class VideoManager
{
public:
	static VideoManager* getInstance() {
		if (_videoInstance == NULL) _videoInstance = new VideoManager();
		return _videoInstance;
	};

	void renderGraphic(int idTextura, Xywh* srcRect, Xywh* dstRect);
	void clearScreen();
	void UpdateScreen();
	void waitTime(int ms);
	void close();

	SDL_Renderer* getRender() { return _renderer; };
	void setResourceManager(ImageManager* rscManager) { _imageManager = rscManager; }

	~VideoManager();


protected:
	VideoManager();


private:
	static VideoManager* _videoInstance;

	SDL_Window* _window;
	SDL_Surface* _surface;
	SDL_Renderer* _renderer;
	ImageManager* _imageManager;
};