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
	if (Input::IsKeyDown(DIK_SPACE)) {
		Bullet* pBullet = Instantiate<Bullet>(this);
		pBullet->Shot(transform_.position_);
	}
}

void Gun::Draw()
{
}

void Gun::Release()
{
}
