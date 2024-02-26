#pragma once
#include "Engine/GameObject.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

const int PLACE_SIZE{4};
const float PLACE_OUTSET{ 2 };

class SphereTarget:public GameObject
{
private:
    int hSphereModel_;
    XMFLOAT3 targetPlace_[PLACE_SIZE][PLACE_SIZE];
    int xPos, yPos;

public:
	SphereTarget(GameObject* parent);
    struct targetData {
        Transform targetTrans;
        bool isHit ;
    };

    targetData t[PLACE_SIZE * PLACE_SIZE];
    void Initialize()override;
    void Update()override;
    void Draw()override;
    void Release()override;
    void OnCollision(GameObject* pTarget) override;

};

