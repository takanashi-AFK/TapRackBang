#pragma once

#include "Engine/GameObject.h"
#include "Player.h"
#include "Gun.h"
#include "Engine/Input.h"
#include "SimpleStage.h"
#include "Enemy.h"
#include <vector>
class DepthScenario : public GameObject {

  
    int hDepthStage_;
    Player* pPlayer;
    Gun* pGun;
    XMFLOAT3 pPos;
    XMFLOAT3 enemyPos[4];
    bool isWaveNow_;
    bool isMiniGameNow_;
    bool isEnemyAmount_;
    int frame;
    const float mapSize{ 70 };
    std::vector <Enemy*> enemylist;
    
public:
    DepthScenario(GameObject* parent);
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;
};
