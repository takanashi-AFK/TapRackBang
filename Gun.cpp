#include "Gun.h"

//銃を撃つ、リロード、ADS
Gun::Gun(GameObject* parent):
	GameObject(parent, "Player")
{
}

void Gun::Initialize()
{
	hRailGunModel_ = Model::Load("RailGun.fbx");
	assert(hRailGunModel_ > 0);
}

void Gun::Update()
{
	Player* pPlayer = (Player*)FindObject("Player");

	if (Input::IsKeyDown(DIK_SPACE)) {
		Bullet* pBullet = Instantiate<Bullet>(GetParent()->GetParent());
		pBullet->Shot(pPlayer->GetPosition(), pPlayer->GetForwardVector());
	}

	
	SAFE_RELEASE(pPlayer);
}

void Gun::Draw()
{
	Model::SetTransform(hRailGunModel_, transform_);
	Model::Draw(hRailGunModel_);
}

void Gun::Release()
{

}
