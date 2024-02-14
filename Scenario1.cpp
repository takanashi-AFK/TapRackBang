#include "Scenario1.h"

Scenario1::Scenario1(GameObject* parent)
{
}

void Scenario1::Initialize()
{
	Instantiate<SkySphere>(this);
	Instantiate<SimpleStage>(this);
	Instantiate<Player>(this);
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
	
}

void Scenario1::Release()
{
}
