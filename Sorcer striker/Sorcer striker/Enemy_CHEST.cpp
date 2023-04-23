#include "Enemy_CHEST.h"
#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleEnemies.h"


Enemy_CHESS::Enemy_CHESS(int x, int y) : Enemy(x, y)
{
    blue.PushBack({ 59, 51, 96, 84 });
    blue.PushBack({ 53, 120, 96, 84 });
    blue.PushBack({ 51, 197, 96, 84 });
    currentAnim = &blue;

    // Path 1
    path1.PushBack({ -1.0f, -0.5f }, 100);
    path1.PushBack({ -1.0f, 0.0f }, 30);
    path1.PushBack({ -0.5f, 0.5f }, 30);
    path1.PushBack({ 0.0f, 1.0f }, 30);
    path1.PushBack({ 0.5f, 0.5f }, 30);
    path1.PushBack({ 1.0f, 0.0f }, 30);
    path1.PushBack({ 1.0f, -0.5f }, 30);
    path1.PushBack({ 1.0f, -1.0f }, 50);

    // Path 2
    path2.PushBack({ -0.5f, -1.0f }, 100);
    path2.PushBack({ -0.5f, -0.5f }, 30);
    path2.PushBack({ -0.5f, -0.3f }, 20);
    path2.PushBack({ -0.5f, -0.1f }, 20);
    path2.PushBack({ -0.5f, 0.1f }, 20);
    path2.PushBack({ -0.5f, 0.3f }, 20);
    path2.PushBack({ -0.5f, 0.5f }, 20);
    path2.PushBack({ -0.5f, 1.5f }, 20);
    path2.PushBack({ -0.5f, 3.0f }, 50);

    currentPath = &path1;
    collider = App->collisions->AddCollider({ 0, 0, 96, 84 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Enemy_CHESS::Update()
{
    path1.Update();
    position = spawnPos + currentPath->GetRelativePosition();

    // Call to the base class. It must be called at the end
    // It will update the collider depending on the position 
    Enemy::Update();


}
//void ModuleEnemies::OnCollision(Collider* c1, Collider* c2)

void Enemy_CHESS::OnCollision(Collider* c1, Collider* c2)
{
    if (c1->Intersects(c2->rect) || c2->Intersects(c1->rect)) {
        // Change sprite
        red.PushBack({ 155, 268, 32, 41 });
        red.PushBack({ 186, 268, 32, 41 });
        currentAnim = &red;

        //Change collider
        collider->rect.x = 32;
        collider->rect.w = 41;

        // Change path
        if (currentPath == &path1)
        {
            currentPath = &path2;
        }
        else
        {
            currentPath = &path1;
        }
    }
}
