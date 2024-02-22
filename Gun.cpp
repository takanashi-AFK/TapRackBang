#include "Gun.h"

//銃を撃つ、リロード、ADS
Gun::Gun(GameObject* parent):
	GameObject(parent, "Player")
{
}

void Gun::Initialize()
{
}

void Gun::Update()
{
	Player* pPlayer = (Player*)FindObject("Player");

	if (Input::IsKeyDown(DIK_SPACE)) {
		Bullet* pBullet = Instantiate<Bullet>(this);
		pBullet->Shot(transform_.position_, pPlayer->GetForwardVector());
	}
	SAFE_RELEASE(pPlayer);
}

void Gun::Draw()
{
}

void Gun::Release()
{

}
