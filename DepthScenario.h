#pragma once

#include "Engine/GameObject.h"
#include "Player.h"
#include "Gun.h"
#include "Engine/Input.h"
#include "SimpleStage.h"
#include "Enemy.h"
#include <array>
#include "ActionListener.h"
class DepthScenario : public GameObject, public ActionListener {

  
    int hDepthStage_;
    int enemyValue_;
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
    std::array <Enemy*,4> enemylist;
    Enemy* pEnemy[4];
    
public:
    DepthScenario(GameObject* parent);
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;
    void onAction()override;
};
