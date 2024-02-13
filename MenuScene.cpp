#include "MenuScene.h"

MenuScene::MenuScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

void MenuScene::Initialize()
{
}

void MenuScene::Update()
{
	ImGui::Begin("rueausu");
	ImGui::Text("menu");

	if (ImGui::Button("ToPlay")) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY, TID_BLACKOUT, 0.5f);
	}
	
	if (ImGui::Button("ToScenario1")) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_SCENARIO1, TID_BLACKOUT, 0.5f);
	}
	ImGui::End();
}

void MenuScene::Draw()
{
}

void MenuScene::Release()
{
}
