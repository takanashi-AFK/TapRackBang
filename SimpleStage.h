#pragma once
#include "Engine/GameObject.h"
#include "Engine/Model.h"
class SimpleStage :
    public GameObject
{
public:
    int hSimpleStage_;

    SimpleStage(GameObject* parent);
    void Initialize()override;
    void Update()override;
    void Draw()override;
    void Release()override;

    int GetModelHandle();
};
