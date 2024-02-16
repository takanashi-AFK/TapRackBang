#pragma once
#include "Engine/GameObject.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "SimpleStage.h"
#include "Engine/SceneManager.h"
#include "Engine/Camera.h"
#include "ImGuiManager.h"

class Player :
    public GameObject
{
public:
    int hPlayerModel_;
    float speed;
    XMVECTOR vPlayerPos_;
    XMVECTOR vMoveX_;
    XMVECTOR vMoveZ_;

    XMFLOAT3 mouseMove_;
    SceneManager* pSM;
    int hGroundModelHandle_;

    Player(GameObject* parent);
    void Initialize()override;
    void Update()override;
    void Draw()override;
    void Release()override;

    void PlayerMove();
};

