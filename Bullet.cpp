#include "Bullet.h"

Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Bullet"),frame(0),isShot(false),collision(nullptr)
{
}

void Bullet::Initialize()
{

	collision = new SphereCollider(transform_.position_, 0.05f);
	AddCollider(collision);
	transform_.scale_ = { 0.01f,0.01f,0.01f };
	isShot = false;
}

void Bullet::Update()
{
	transform_.position_.x += move_.x;
	transform_.position_.y += move_.y;
	transform_.position_.z += move_.z;

	if (isShot) {
		frame++;
		if (frame > 1200) {
			KillMe();
			isShot = false;
		}
	}
}

void Bullet::Draw()
{
}

void Bullet::Release()
{
}

void Bullet::Shot(XMFLOAT3 _playerPos, XMVECTOR direction)
{
	transform_.position_ = _playerPos;
	XMVECTOR shotVec = direction;
	XMStoreFloat3(&move_, XMVector3Normalize(-shotVec) * BULLET_SPEED);
	isShot = true;
}


