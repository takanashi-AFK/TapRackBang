#include "SimpleStage.h"

SinpleStage::SinpleStage(GameObject* parent)
{
}

void SinpleStage::Initialize()
{
	hSimpleStage_ = Model::Load("Scenario1Map.fbx");
	assert(hSimpleStage_ > 0);
}

void SinpleStage::Update()
{
}

void SinpleStage::Draw()
{
	Model::SetTransform(hSimpleStage_, transform_);
	Model::Draw(hSimpleStage_);
}

void SinpleStage::Release()
{
}

int SinpleStage::GetModelHandle()
{
	return hSimpleStage_;
}
