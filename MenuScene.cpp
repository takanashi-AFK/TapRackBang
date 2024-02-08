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

	if (ImGui::Button("SceneChange")) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY, TID_BLACKOUT, 0.5f);
	}
	ImGui::End();
}

void MenuScene::Draw()
{
}

void MenuScene::Release()
{
}
