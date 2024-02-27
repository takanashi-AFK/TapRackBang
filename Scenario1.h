#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"
#include "ImGuiManager.h"
#include "Engine/SceneManager.h"
#include "Engine/Model.h"
#include "Engine/Direct3D.h"
#include "SkySphere.h"
#include "Player.h"
#include "SimpleStage.h"
#include "SphereTarget.h"
class Scenario1 :
    public GameObject
{
    Transform MapTransform_;
    XMFLOAT3 targetPlace_[PLACE_SIZE][PLACE_SIZE];
    XMFLOAT3 previousPos[3];
    SphereTarget* sp1;
    SphereTarget* sp2;
    SphereTarget* sp3;
    int xPos, yPos;
public:

    Scenario1(GameObject* parent);
    void Initialize()override;
    void Update()override;
    void Draw()override;
    void Release()override;
};

