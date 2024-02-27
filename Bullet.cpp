#include "Bullet.h"

Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Bullet")
{
}

void Bullet::Initialize()
{
	hBulletModel = Model::Load("DebugCollision/SphereCollider.fbx");
	collision = new SphereCollider(transform_.position_, 1.2f);
	AddCollider(collision);
}

void Bullet::Update()
{
	transform_.position_.x += move_.x;
	transform_.position_.y += move_.y;
	transform_.position_.z += move_.z;

	if (transform_.position_.z >= 50 || transform_.position_.z <= -50 || transform_.position_.x >= 50 || transform_.position_.x <= -50)
		KillMe();
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
	XMVECTOR shotVec = direction;
	XMStoreFloat3(&move_, XMVector3Normalize(-shotVec) * BULLET_SPEED);
}


