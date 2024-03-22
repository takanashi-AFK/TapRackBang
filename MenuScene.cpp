#include "MenuScene.h"

MenuScene::MenuScene(GameObject* parent)
	: GameObject(parent, "PlayScene"),
	hScenario1ButtonNormal_(-1),
	hBackGround_(-1)
{
}

void MenuScene::Initialize()
{
	hBackGround_ = Image::Load("MenuImage/menu.png");
	assert(hBackGround_ >= 0);

	hScenario1ButtonNormal_ = Image::Load("MenuImage/Scenario1ButtonNormal.png");
	assert(hScenario1ButtonNormal_ >= 0);

	hScenario1ButtonSelected_ = Image::Load("MenuImage/Scenario1ButtonSelected.png");
	assert(hScenario1ButtonSelected_ >= 0);

	buttonTransform_.position_ = { 0.5,-0.7,0 };
	size = Image::GetSize(hScenario1ButtonNormal_);

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

	mousePos_ = Input::GetMousePosition();
	ImGui::Text("%f,%f", mousePos_.x, mousePos_.y);

	isPushable = IsMouseInRect();
		if (isPushable && Input::IsMouseButtonDown(0)) {
			AudioManager::PlayConfirmSound();
			SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
			pSceneManager->ChangeScene(SCENE_ID_SCENARIO1, TID_BLACKOUT, 0.5f);
		}
	

	


	if (Input::IsKeyDown(DIK_D)) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_DEPTH, TID_BLACKOUT, 0.5f);
	}
}

void MenuScene::Draw()
{
	Image::SetTransform(hBackGround_, transform_);
	Image::Draw(hBackGround_);


	if (isPushable) {
		Image::SetTransform(hScenario1ButtonSelected_, buttonTransform_);
		Image::Draw(hScenario1ButtonSelected_);
	}
	else {
		Image::SetTransform(hScenario1ButtonNormal_, buttonTransform_);
		Image::Draw(hScenario1ButtonNormal_);
	}

}

void MenuScene::Release()
{
}

bool MenuScene::IsMouseInRect()
{
	if (mousePos_.x > 800 && mousePos_.x < 1100 && mousePos_.y > 560 && mousePos_.y < 660)
		return true;

	return false;
}
