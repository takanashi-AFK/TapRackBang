#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"
#include "ImGuiManager.h"
#include "Engine/SceneManager.h"
#include "Engine/Model.h"
#include "Engine/Direct3D.h"
#include "SkySphere.h"
#include "Player.h"
class Scenario1 :
    public GameObject
{
    int hStageMap_;
    Transform MapTransform_;
public:

    Scenario1(GameObject* parent);
    void Initialize()override;
    void Update()override;
    void Draw()override;
    void Release()override;
};

