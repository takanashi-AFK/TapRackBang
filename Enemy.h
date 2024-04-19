#pragma once
#include "Engine/GameObject.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"
#include "AudioManager.h"
#include "Global.h"
#include "DepthScenario.h"

class Enemy : public GameObject
{
    int hModel_;
public:
    Enemy(GameObject* parent);
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;
    void NotifyEnemyDead(DepthScenario* d);
    void OnCollision(GameObject* pTarget) override;
};

