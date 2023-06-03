#include "Boss_BreathDragon.h"

#include "../../Application/Application.h"
#include "../../Modules/Core/ModuleCollisions.h"
#include "../../Modules/Gameplay/ModuleEnemies.h"
#include "../../Modules/Gameplay/SceneLevel1.h"
#include "../../Application/FileNames.h"
#include "../../Modules/Core/ModuleRender.h"
#include"../../Modules/Core/ModuleTextures.h"


Boss_BreathDragon::Boss_BreathDragon(int x, int y, int wave) : Enemy(x, y) {

	vides[0] = 15; // Cuerpo 0
	vides[1] = 5; // Cabeza 1
	vides[2] = 5; // Cabeza 2
	vides[3] = 5; // Cabeza 2

	texturaBoss = App->textures->Load(FI_spriteEnemy_boss.c_str());

	animationFan.PushBack({ 0, 230, 115, 115 });
	animationFan.PushBack({ 116, 230, 115, 115 });
	animationFan.speed = 0.2;
	animationFan.loop = true;
	pathFan.PushBack({ 0, (float)App->sceneLevel_1->velocitatNivell }, 20, &animationFan);

	animationHead.PushBack({ 0, 502, 180, 180 });
	animationHead.PushBack({ 180 * 2, 502, 180, 180 });
	animationHead.PushBack({ 180 * 4, 502, 180, 180 });
	animationHead.speed = 0.1f;
	animationHead.loop = true;
	pathCabeza.PushBack({ 0,(float)App->sceneLevel_1->velocitatNivell }, 20, &animationHead);


	animationHeadDamaged.PushBack({ 180 * 1, 502, 180, 180 });
	animationHeadDamaged.PushBack({ 180 * 3, 502, 180, 180 });
	animationHeadDamaged.PushBack({ 180 * 5, 502, 180, 180 });
	animationHeadDamaged.speed = 0.1f;
	animationHeadDamaged.loop = true;

	animationBody.PushBack({ 0, 1045, 1200, 400 });
	animationBody.speed = 0.1f;
	animationBody.loop = true;
	pathCuerpo.PushBack({ 0,(float)App->sceneLevel_1->velocitatNivell }, 20, &animationBody);

	particleFire.anim.PushBack({ 0, 690, 157, 157 });
	particleFire.anim.PushBack({ 157, 690, 157, 157 });
	particleFire.anim.PushBack({ 157 * 2, 690, 157, 157 });
	particleFire.anim.PushBack({ 157 * 3, 690, 157, 157 });
	particleFire.anim.PushBack({ 157 * 4, 690, 157, 157 });
	particleFire.anim.PushBack({ 157 * 5, 690, 157, 157 });
	particleFire.anim.PushBack({ 157 * 6, 690, 157, 157 });
	particleFire.speed = iPoint(0, -12);
	particleFire.anim.speed = 0.05f;
	particleFire.lifetime = 115;

	//collider = App->collisions->AddCollider({ 0, 0,1200, 400 }, Collider::Type::ENEMY, (Module*)App->enemies);
	//colliderCabeza1 = App->collisions->AddCollider({ 0, 0,180, 180 }, Collider::Type::ENEMY, (Module*)App->enemies);
	//colliderCabeza2 = App->collisions->AddCollider({ 0, 0,180, 180 }, Collider::Type::ENEMY, (Module*)App->enemies);
	//colliderCabeza3 = App->collisions->AddCollider({ 0, 0,180, 180 }, Collider::Type::ENEMY, (Module*)App->enemies);
}

void Boss_BreathDragon::Update() {

	/*if (currentAnim != nullptr)
		currentAnim->Update();

	if (collider != nullptr)
		collider->SetPos(position.x, position.y);*/


	if (pathFan.GetCurrentAnimation() != nullptr) pathFan.Update();
	if (pathCabeza.GetCurrentAnimation() != nullptr) pathCabeza.Update();
	if (pathCuerpo.GetCurrentAnimation() != nullptr) pathCuerpo.Update();

	position = spawnPos + pathCuerpo.GetRelativePosition();
}

void Boss_BreathDragon::Draw() {
	/*if (currentAnim != nullptr)
		App->render->Blit(texture, position.x, position.y, &(currentAnim->GetCurrentFrame()));*/

	if (pathCuerpo.GetCurrentAnimation() != nullptr) {
		App->render->Blit(texturaBoss, position.x - 600, position.y, &(pathCuerpo.GetCurrentAnimation()->GetCurrentFrame()));
	}


	if (pathCabeza.GetCurrentAnimation() != nullptr) {
		App->render->Blit(texturaBoss, position.x - 300, position.y + 200, &(pathCabeza.GetCurrentAnimation()->GetCurrentFrame()));
		App->render->Blit(texturaBoss, position.x - 85, position.y + 230, &(pathCabeza.GetCurrentAnimation()->GetCurrentFrame()));
		App->render->Blit(texturaBoss, position.x + 130, position.y + 200, &(pathCabeza.GetCurrentAnimation()->GetCurrentFrame()));
	}

	if (pathFan.GetCurrentAnimation() != nullptr) {
		App->render->Blit(texturaBoss, position.x - 400, position.y + 250, &(pathFan.GetCurrentAnimation()->GetCurrentFrame()));
		App->render->Blit(texturaBoss, position.x - 150, position.y + 200, &(pathFan.GetCurrentAnimation()->GetCurrentFrame()));
		App->render->Blit(texturaBoss, position.x + 40, position.y + 200, &(pathFan.GetCurrentAnimation()->GetCurrentFrame()));
		App->render->Blit(texturaBoss, position.x + 270, position.y + 230, &(pathFan.GetCurrentAnimation()->GetCurrentFrame()));
	}
}

void Boss_BreathDragon::OnCollisionGeneral(Collider* c1) {
	if (c1->type == Collider::Type::PLAYER_SHOT)
	{
		// Si cuerpo tiene 0 vidas muere || las tres cabezas tienen 0 vidas muere
		if ((vides[0] <= 0) || (vides[1] <= 0 && vides[2] <= 0 && vides[3] <= 0))
			this->SetToDelete();
		else
			vides[0] -= 1;
	}
}

void Boss_BreathDragon::OnCollisionHead1(Collider* c1) {
	if (c1->type == Collider::Type::PLAYER_SHOT && !headDestroy) {

		if ((vides[0] <= 0) || (vides[1] <= 0 && vides[2] <= 0 && vides[3] <= 0))
			this->SetToDelete();
		else {
			if (vides[1] <= 0) headDestroy = true;
			else vides[1] -= 1;
		}
	}
}

void Boss_BreathDragon::OnCollisionHead2(Collider* c1) {
	if (c1->type == Collider::Type::PLAYER_SHOT && !headDestroy2) {

		if ((vides[0] <= 0) || (vides[1] <= 0 && vides[2] <= 0 && vides[3] <= 0))
			this->SetToDelete();
		else {
			if (vides[2] <= 0) headDestroy2 = true;
			else vides[2] -= 1;
		}
	}
}

void Boss_BreathDragon::OnCollisionHead3(Collider* c1)
{
	if (c1->type == Collider::Type::PLAYER_SHOT && !headDestroy3) {

		if ((vides[0] <= 0) || (vides[1] <= 0 && vides[2] <= 0 && vides[3] <= 0))
			this->SetToDelete();
		else {
			if (vides[3] <= 0) headDestroy3 = true;
			else vides[3] -= 1;
		}
	}
}
