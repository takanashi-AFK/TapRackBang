#pragma once

#include "Engine/GameObject.h"
#include "Player.h"
#include "Gun.h"
#include "Engine/Input.h"
class DepthScenario : public GameObject {
    int hDepthStage_;
    Player* pPlayer;
    Gun* pGun;
    XMFLOAT3 pPos;
public:
    DepthScenario(GameObject* parent);
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;
};
