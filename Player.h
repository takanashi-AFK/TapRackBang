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
    XMVECTOR vPlayerPos_;
    XMVECTOR vMoveX_;
    XMVECTOR vMoveZ_;
    XMFLOAT3 mouseMove_;
    XMVECTOR upLimit;
    XMVECTOR verticalP;

    float playerCameraDistance;

    SceneManager* pSM;
    int hGroundModelHandle_;

    Player(GameObject* parent);
    void Initialize()override;
    void Update()override;
    void Draw()override;
    void Release()override;

    void PlayerMove();
    XMVECTOR GetForwardVector();
};

