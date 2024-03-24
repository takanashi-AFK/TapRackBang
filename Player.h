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
public:
    int hPlayerModel_;
    int hCrosshair_;

    float speed;
    float sensitivity;

    bool isCamMove;

    XMFLOAT2 rotateAngle_;
    XMVECTOR vPlayerPos_;
    XMVECTOR vMoveX_;
    XMVECTOR vMoveZ_;
    Transform debT;

    XMVECTOR playerForward;
    SceneManager* pSM;
    XMFLOAT3 newCenter_;

    Player(GameObject* parent);
    void Initialize()override;
    void Update()override;
    void Draw()override;
    void Release()override;

    void PlayerMove();
    void SetCanCamMove(bool can);
    XMVECTOR GetForwardVector();
};

