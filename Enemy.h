#pragma once
#include "Engine/GameObject.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

class Enemy : public GameObject
{
    int hModel_;
public:
    Enemy(GameObject* parent);
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;
    //�o�H�T��
    //�ːi�U��
    void OnCollision(GameObject* pTarget) override;
};

