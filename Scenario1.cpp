#include "Scenario1.h"

Scenario1::Scenario1(GameObject* parent)
{
}

void Scenario1::Initialize()
{
	Instantiate<SkySphere>(this);

	hStageMap_ = Model::Load("Scenario1Map.fbx");
	assert(hStageMap_ >= 0);
}

void Scenario1::Update()
{
	ImGui::Begin("rueausu");
	ImGui::Text("Scenario1");

	if (ImGui::Button("SceneChange")) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_MENU, TID_BLACKOUT, 0.5f);
	}
	ImGui::End();
}

void Scenario1::Draw()
{
	Model::SetTransform(hStageMap_, MapTransform_);
	Model::Draw(hStageMap_);
}

void Scenario1::Release()
{
}
