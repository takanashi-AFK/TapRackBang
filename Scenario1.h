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
#include   "ActionListener.h"
class SphereTarget;

const int PLACE_SIZE{ 4 };
const float PLACE_OUTSET{ 2 };

class Scenario1 : public GameObject,public ActionListener {
    Transform MapTransform_;
    XMFLOAT3 targetPlace_[PLACE_SIZE][PLACE_SIZE];
    XMFLOAT3 previousPos[3];
    SphereTarget* sp1;
    SphereTarget* sp2;
    SphereTarget* sp3;
    int xPos, yPos;
    bool isTargetBroken;

public:
    Scenario1(GameObject* parent);
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;
    void onAction() override;
};
