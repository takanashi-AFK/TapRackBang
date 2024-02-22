#pragma once
#include "Engine/GameObject.h"
#include "Engine/Model.h"

const int PLACE_SIZE{4};
const float PLACE_OUTSET{ 3 };

class SphereTarget:public GameObject
{
private:
    int hSphereModel_;
    XMFLOAT3 targetPlace_[PLACE_SIZE][PLACE_SIZE];
public:
	SphereTarget(GameObject* parent);

    void Initialize()override;
    void Update()override;
    void Draw()override;
    void Release()override;

};
