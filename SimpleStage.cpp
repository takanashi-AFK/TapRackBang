#include "SimpleStage.h"

SimpleStage::SimpleStage(GameObject* parent)
	: GameObject(parent, "SimpleStage")
{
}

void SimpleStage::Initialize()
{
	hSimpleStage_ = Model::Load("Scenario1Map.fbx");
	assert(hSimpleStage_ > 0);
}

void SimpleStage::Update()
{
}

void SimpleStage::Draw()
{
	Model::SetTransform(hSimpleStage_, transform_);
	Model::Draw(hSimpleStage_);
}

void SimpleStage::Release()
{
}

int SimpleStage::GetModelHandle()
{
	return hSimpleStage_;
}
