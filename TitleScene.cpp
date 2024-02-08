#include "TitleScene.h"

TitleScene::TitleScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

void TitleScene::Initialize()
{

}

void TitleScene::Update()
{

	ImGui::Begin("rueausu");
	ImGui::Text("Title");
	if (ImGui::Button("SceneChange")) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_MENU,TID_BLACKOUT, 0.5f);

	}
	ImGui::End();
}

void TitleScene::Draw()
{
}

void TitleScene::Release()
{
}
