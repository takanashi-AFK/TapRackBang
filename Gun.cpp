#include "Gun.h"

//銃を撃つ、リロード、ADS
Gun::Gun(GameObject* parent):
	GameObject(parent, "Player"),hRailGunModel_(-1)
{
}

void Gun::Initialize()
{
	hRailGunModel_ = Model::Load("blasterM.fbx");
	assert(hRailGunModel_ >= 0);
	transform_.rotate_.y = 180;
	transform_.scale_ = { 0.3,0.3,0.3 };
	transform_.position_.y = 2;
	transform_.position_.x = 1;
}

void Gun::Update()
{
	XMVECTOR sightLine = Camera::GetSightLine();

	if (Input::IsMouseButtonDown(0) ){
	
		AudioManager::PlayGunSound();
		Bullet* pBullet = Instantiate<Bullet>(GetParent()->GetParent());
		pBullet->Shot(Camera::GetPosition(), -sightLine);
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

