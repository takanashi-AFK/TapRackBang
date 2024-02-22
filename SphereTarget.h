#pragma once
#include "Engine/GameObject.h"
#include "Engine/Model.h"
class SphereTarget:public GameObject
{
private:
    int hSphereModel_;
public:
	SphereTarget(GameObject* parent);

    void Initialize()override;
    void Update()override;
    void Draw()override;
    void Release()override;

};

