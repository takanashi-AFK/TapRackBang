#pragma once

class Enemy;
#include "Engine/GameObject.h"
#include "Player.h"
#include "Gun.h"
#include "Engine/Input.h"
#include "SimpleStage.h"
#include "SkySphere.h"
#include "ActionListener.h"
#include <array>
class DepthScenario : public GameObject, public ActionListener {

  
    int hDepthStage_;
    int enemyCount_;
    int generateCount_;
    Player* pPlayer;
    Gun* pGun;
    XMFLOAT3 pPos;
    XMFLOAT3 enemyPos[4];
    bool isWaveNow_;
    bool isMiniGameNow_;
    bool isEnemyAmount_;
    bool isEnemyDead_;
    int frame;
    const float mapSize{ 70 };
    std::array<Enemy*,4> enemyList_;
    
public:
    DepthScenario(GameObject* parent);
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;
    void GenerateEnemy();
    void ReGenerateEnemy();
    void onAction()override;
};
