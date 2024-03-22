#pragma once
#include "Engine/GameObject.h"
#include "Player.h"
#include "Engine/Input.h"
#include "Bullet.h"
#include "Engine/Model.h"
#include "SphereTarget.h"
#include "Engine/RootObject.h"
#include <list>
#include "Engine/VFX.h"
#include "AudioManager.h"
class Gun:public GameObject
{
	int hRailGunModel_;
	XMVECTOR sightLine_;
	XMFLOAT3 hitPos;
public:
	Gun(GameObject* parent);
	void Initialize()override;
	void Update()override;
	void Draw()override;
	void Release()override;
	void GunShot(XMFLOAT3 pos);


	enum GunKinds {
		GUN_HANDGUN,
		GUN_FULLAUTO,
		GUN_MAX,
	};
};

