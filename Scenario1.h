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
#include "TargetManager.h"
#include <array>
class SphereTarget;

//const int PLACE_SIZE{ 4 };
//const float PLACE_OUTSET{ 2.25f };
//const float PLACE_HEIGHT_OUTSET{ 15 };
//const float PLACE_DEPTH{ 70 };

class Scenario1 : public GameObject,public ActionListener {

    Transform MapTransform_;

   // SphereTarget* sp[3];
    int xPos, yPos;
    bool isStart;
    Text* time_;
    int hGroundModelHandle_;
    int speed;

    int frame_;

public:
    Scenario1(GameObject* parent);
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;
    void onAction(XMFLOAT3 pos) override;

    void GenerateSphereTarget();
    void ReGenerateSphereTarget();
};
