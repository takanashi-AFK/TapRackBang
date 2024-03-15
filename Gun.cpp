#include "Gun.h"

//銃を撃つ、リロード、ADS
Gun::Gun(GameObject* parent):
	GameObject(parent, "Player"),hRailGunModel_(-1)
{
}

void Gun::Initialize()
{
	hRailGunModel_ = Model::Load("RailGun.fbx");
	assert(hRailGunModel_ > 0);
	transform_.position_.y = 1;
	transform_.position_.x = 1;
}

void Gun::Update()
{
	Player* pPlayer = (Player*)FindObject("Player");


	if (Input::IsMouseButtonDown(0) ){
		Bullet* pBullet = Instantiate<Bullet>(GetParent()->GetParent());
		pBullet->Shot(pPlayer->GetPosition(), -Camera::GetSightLine());
	}	
}

void Gun::Draw()
{
	Model::SetTransform(hRailGunModel_, transform_);
	Model::Draw(hRailGunModel_);
}

void Gun::Release()
{

}

