#pragma once
#include "Engine/GameObject.h"
#include "SphereTarget.h"

//const int PLACE_SIZE{ 4 };
//const float PLACE_OUTSET{ 2.25f };
//const float PLACE_HEIGHT_OUTSET{ 15 };
//const float PLACE_DEPTH{ 70 };

class TargetManager :
    public GameObject
{
private:
    XMFLOAT3 targetPlace_[PLACE_SIZE][PLACE_SIZE];
    std::array<XMFLOAT3, 3> previousPos;

    SphereTarget* sp[3];
public:
    TargetManager();
    void Initialize()override;
    void Update()override;
    void Draw()override;
    void Release()override;
    void GenerateSphereTarget();
    void ReGenerateSphereTarget();
};

//ここにActionListenerを継承させちゃってもいいかも？
//BrokenPosがわかんないからね
//で、これのインスタンスからGenerateSphereTargetとかをシーンで呼び出す
