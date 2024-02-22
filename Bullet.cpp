#include "Bullet.h"

Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Gun")
{
}

void Bullet::Initialize()
{
	hBulletModel = Model::Load("DebugCollision/SphereCollider.fbx");

}

void Bullet::Update()
{
	transform_.position_.x += move_.x;
	transform_.position_.y += move_.y;
	transform_.position_.z += move_.z;
}

void Bullet::Draw()
{
	Model::SetTransform(hBulletModel, transform_);
	Model::Draw(hBulletModel);
}

void Bullet::Release()
{
}

void Bullet::Shot(XMFLOAT3 _playerPos, XMVECTOR direction)
{
	transform_.position_ = _playerPos;
	XMStoreFloat3(&move_, XMVector3Normalize(direction) * BULLET_SPEED);
}
