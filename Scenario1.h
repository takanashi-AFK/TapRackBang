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
#include "ActionListener.h"
#include <array>
class SphereTarget;

const int PLACE_SIZE{ 4 };
const float PLACE_OUTSET{ 2.25f };

class Scenario1 : public GameObject,public ActionListener {
    Transform MapTransform_;
    XMFLOAT3 targetPlace_[PLACE_SIZE][PLACE_SIZE];
    std::array<XMFLOAT3,3> previousPos;

    //SphereTarget* sp1;
    //SphereTarget* sp2;
    //SphereTarget* sp3;

    SphereTarget* sp[3];
    int xPos, yPos;
    bool isTargetBroken;
    XMFLOAT3 brokenTargetPos;
    int brokenTarget;

public:
    Scenario1(GameObject* parent);
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;
    void onAction(XMFLOAT3 pos) override;

   
};
