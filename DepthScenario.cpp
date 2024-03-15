#include "DepthScenario.h"

DepthScenario::DepthScenario(GameObject* parent):
	GameObject(parent, "DepthScenario")
{
}

void DepthScenario::Initialize()
{
	hDepthStage_ = Model::Load("DepthStage.fbx");
	assert(hDepthStage_ >= 0);
	Instantiate<Player>(this);
	pPlayer = (Player*)FindObject("Player");
	pGun = (Gun*)FindObject("Gun");
	pPlayer->SetPosition(2, 0, 0);
}

void DepthScenario::Update()
{
	pPos = pPlayer->GetPosition();

	pPos.z += 0.1f;

	pPlayer->SetPosition(pPos);

}

void DepthScenario::Draw()
{
	Model::SetTransform(hDepthStage_, transform_);
	Model::Draw(hDepthStage_);
}

void DepthScenario::Release()
{
}

