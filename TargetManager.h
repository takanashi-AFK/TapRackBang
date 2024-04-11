#pragma once
#include "Engine/GameObject.h"
#include "SphereTarget.h"
#include "ActionListener.h"
#include <array>
const int PLACE_SIZE{ 4 };
const float PLACE_OUTSET{ 2.25f };
const float PLACE_HEIGHT_OUTSET{ 15 };
const float PLACE_DEPTH{ 70 };

class TargetManager :
    public GameObject,public ActionListener
{
private:
    SphereTarget* sp[3];
    XMFLOAT3 targetPlace_[PLACE_SIZE][PLACE_SIZE];
    std::array<XMFLOAT3, 3> previousPos;
    int xPos, yPos;
    bool isTargetBroken;
    XMFLOAT3 brokenTargetPos;
    int brokenTarget;
public:
    TargetManager(GameObject* parent);
    void Initialize()override;
    void Update()override;
    void Draw()override;
    void Release()override;
    void GenerateSphereTarget();
    void ReGenerateSphereTarget();
    void onAction(XMFLOAT3 pos)override;
};

//ここにActionListenerを継承させちゃってもいいかも？
//BrokenPosがわかんないからね
//で、これのインスタンスからGenerateSphereTargetとかをシーンで呼び出す
