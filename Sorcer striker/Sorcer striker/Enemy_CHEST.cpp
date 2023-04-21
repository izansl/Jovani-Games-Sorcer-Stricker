#include "Enemy_CHEST.h"

#include "Application.h"
#include "ModuleCollisions.h"

Enemy_CHESS::Enemy_CHESS(int x, int y) : Enemy(x, y)
{

}

void Enemy_CHESS::Update()
{
	path.Update();
	position = spawnPos + path.GetRelativePosition();

	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
