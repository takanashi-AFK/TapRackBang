#pragma once
#include "Engine/GameObject.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"
#include "Gun.h"
#include "Player.h"

const float BULLET_SPEED{ 5.f };
class Bullet :public GameObject
{
public:
	Bullet(GameObject* parent);
	void Initialize()override;
	void Update()override;
	void Draw()override;
	void Release()override;

	void Shot(XMFLOAT3 _playerPos, XMVECTOR direction);
private:
	int frame;
	bool isShot;
	XMFLOAT3 move_;
	SphereCollider* collision;
};

