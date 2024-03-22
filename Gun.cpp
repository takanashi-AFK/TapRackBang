#include "Gun.h"

//銃を撃つ、リロード、ADS
Gun::Gun(GameObject* parent):
	GameObject(parent, "Player"),hRailGunModel_(-1)
{
}

void Gun::Initialize()
{
	hRailGunModel_ = Model::Load("RailGun.fbx");
	assert(hRailGunModel_ > 0);
	transform_.position_.y = 1;
	transform_.position_.x = 1;
}

void Gun::Update()
{
	Player* pPlayer = (Player*)FindObject("Player");
	SimpleStage* pStage = (SimpleStage*)FindObject("SimpleStage");
	RootObject* pRoot = (RootObject*)FindObject("RootObject");
	
	int pStageHandle = pStage->GetModelHandle();
	XMVECTOR sightLine = Camera::GetSightLine();
	XMFLOAT3 pPos = pPlayer->GetPosition();
	XMVECTOR vPPos = XMLoadFloat3(&pPos);

	if (Input::IsMouseButtonDown(0) ){
	
		RayCastData shotRay;
		shotRay.start = Camera::GetPosition();
		XMFLOAT3 CamTar = Camera::GetTarget();
		XMVECTOR vCamTarget = XMLoadFloat3(&CamTar);

		XMStoreFloat3(&shotRay.dir , sightLine);
		Model::RayCast(pStageHandle, &shotRay);

		XMVECTOR  vHitPos = XMLoadFloat3(&shotRay.start) + XMLoadFloat3(&shotRay.dir) * shotRay.dist;
		vHitPos = vHitPos - vPPos;
		hitPos; XMStoreFloat3(&hitPos, vHitPos);

		EmitterData bulletHitPos;
		bulletHitPos.textureFileName = "EffectAssets/BulletHit.png";
		bulletHitPos.position = { hitPos.x-1,hitPos.y-17,hitPos.z = 69 };//妥協

		bulletHitPos.direction = { 0,0,0 };
		bulletHitPos.delay =  0;
		bulletHitPos.scale = { 1, 1 };
		VFX::Start(bulletHitPos);
		AudioManager::PlayGunSound();
		Bullet* pBullet = Instantiate<Bullet>(GetParent()->GetParent());
		pBullet->Shot(pPlayer->GetPosition(), -vHitPos);
	}	
}

void Gun::Draw()
{
	Model::SetTransform(hRailGunModel_, transform_);
	Model::Draw(hRailGunModel_);
}

void Gun::Release()
{

}

