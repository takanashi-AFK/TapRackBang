    #pragma once
    #include "Engine/GameObject.h"
    #include "Engine/Model.h"
    #include "Engine/SphereCollider.h"
    #include "Bullet.h"
    #include "Scenario1.h"
    #include "ActionListener.h"
    #include "Global.h"
    #include "AudioManager.h"
#include <array>

    class Scenario1;
    class SphereTarget:public GameObject
    {
    private:
        int hSphereModel_;
        int xPos, yPos;
        XMFLOAT3 pos;
        bool isBroken;
        SphereTarget* sp[3];
        XMFLOAT3 targetPlace_[4][4];
        std::array<XMFLOAT3, 3> previousPos;

    public:
        SphereTarget(GameObject* parent);
        void Initialize()override;
        void Update()override;
        void Draw()override;
        void Release()override;
        void OnCollision(GameObject* pTarget) override;

        void NotifyTargetDestroy(Scenario1* sc);
        XMFLOAT3 ReturnBreakPos();
        int GetHandle() {return hSphereModel_; };
    };

