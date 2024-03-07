#pragma once
#include "Engine/GameObject.h"
#include "Player.h"
#include "Engine/Input.h"
#include "Bullet.h"
#include "Engine/Model.h"
class Gun:public GameObject
{
	int hRailGunModel_;
	XMVECTOR sightLine_;
public:
	Gun(GameObject* parent);
	void Initialize()override;
	void Update()override;
	void Draw()override;
	void Release()override;

	enum GunKinds {
		GUN_HANDGUN,
		GUN_FULLAUTO,
		GUN_MAX,
	};
};

