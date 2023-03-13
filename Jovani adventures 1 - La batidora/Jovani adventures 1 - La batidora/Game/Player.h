#include "../Engine/Resources Image/ImageManager.h"
#include "../Engine/Video - Screen - Console/VideoManager.h"
#include "Directions.h"

class Player
{
public:
	Player(VideoManager* video, ImageManager* imageManager);

	// GET-SET
	void setPositionX(int posX) { _posPlayerX = posX; }
	void setPositionY(int posY) { _posPlayerY = posY; }
	int getIdRscManager() { return _idImageMngPlayer; }
	void setIdRscManager(int id) { _idImageMngPlayer = id; }

	// Functions
	void Draw(int posX, int posY);
	void Update();
	bool IsAlive();
	void Jump();	
	
	~Player();

private:
	VideoManager* _video;
	ImageManager* _imageManager;
	Xywh _actualDraw;
	int _posPlayerX;
	int _posPlayerY;
	Direction _actualDirection;
	int _numFrameAnimation;
	int _idImageMngPlayer; // id of the graph to our ImageManager (player, ...)
};