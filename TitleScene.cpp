#include "TitleScene.h"

TitleScene::TitleScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

void TitleScene::Initialize()
{
	hBackGround_ = Image::Load("TitleImage/Title.png");
	assert(hBackGround_ >= 0);
	
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

	if (Input::IsKeyDown(DIK_SPACE)){
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_MENU, TID_BLACKOUT, 0.5f);
	}
	ImGui::Text("x = %f,y = %f", mousePos_.x, mousePos_.y);
}

void TitleScene::Draw()
{
	Image::SetTransform(hBackGround_, transform_);
	Image::Draw(hBackGround_);

}

void TitleScene::Release()
{
}
