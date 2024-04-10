#pragma once
#include "Engine/GameObject.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "SimpleStage.h"
#include "Engine/Image.h"
#include "Engine/SceneManager.h"
#include "Engine/Camera.h"
#include "ImGuiManager.h"
#include "Gun.h"
const float MODEL_SIZE{ 1 };
class Player :
    public GameObject
{
    int hPlayerModel_;
    int hCrosshair_;
   
    float speed;
    float sensitivity;

    bool isCamMove;

    XMVECTOR vPlayerPos_;
    XMVECTOR vMoveX_;
    XMVECTOR vMoveZ_;

    XMVECTOR playerForward;
    SceneManager* pSM;
    XMFLOAT3 newCenter_;
    XMFLOAT2 rotateAngle;
    XMFLOAT3 newCenter;

public:
    Player(GameObject* parent);
    void Initialize()override;
    void Update()override;
    void Draw()override;
    void Release()override;

    void PlayerMove();
    void SetCanCamMove(bool can);
    XMVECTOR GetForwardVector();
};

