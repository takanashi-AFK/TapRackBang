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

    class TargetManager;
    class SphereTarget:public GameObject
    {
    private:
        int hSphereModel_;
        XMFLOAT3 pos;
    public:
        SphereTarget(GameObject* parent);
        void Initialize()override;
        void Update()override;
        void Draw()override;
        void Release()override;
        void OnCollision(GameObject* pTarget) override;

        void NotifyTargetDestroy(TargetManager* t);
        XMFLOAT3 ReturnBreakPos();
        int GetHandle() {return hSphereModel_; };
    };

