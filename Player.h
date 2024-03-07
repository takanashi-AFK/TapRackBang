#pragma once
#include "Engine/GameObject.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "SimpleStage.h"
#include "Engine/SceneManager.h"
#include "Engine/Camera.h"
#include "ImGuiManager.h"
#include "Gun.h"

class Player :
    public GameObject
{
public:
    int hPlayerModel_;
    
    float speed;
    float sensitivity;
    XMFLOAT2 rotateAngle;
    XMVECTOR vPlayerPos_;
    XMVECTOR vMoveX_;
    XMVECTOR vMoveZ_;
    Transform debT;
 

    XMVECTOR playerForward;
    SceneManager* pSM;
    int hGroundModelHandle_;
    XMFLOAT3 newCenter_;

    Player();
    Player(GameObject* parent);
    void Initialize()override;
    void Update()override;
    void Draw()override;
    void Release()override;

    void PlayerMove();
    XMVECTOR GetForwardVector();
};

