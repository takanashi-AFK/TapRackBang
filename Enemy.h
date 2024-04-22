#pragma once
#include "SimpleStage.h";

#include "Engine/GameObject.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"
#include "AudioManager.h"
#include "Global.h"
#include "DepthScenario.h"


//XMFLOAT3{}
class Enemy : public GameObject
{
    int hModel_;
    XMVECTOR originToPos_;
    XMVECTOR originToCenter_;
    XMVECTOR pEnemyVec_;
public:
    Enemy(GameObject* parent);
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;
    void NotifyEnemyDead(DepthScenario* d);
    void OnCollision(GameObject* pTarget) override;
};

