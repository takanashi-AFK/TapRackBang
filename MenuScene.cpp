#include "MenuScene.h"

MenuScene::MenuScene(GameObject* parent)
	: GameObject(parent, "PlayScene"),
	hScenario1Button_(-1),
	hBackGround_(-1)
{
}

void MenuScene::Initialize()
{
	hBackGround_ = Image::Load("MenuImage/menu.png");
	assert(hBackGround_ >= 0);

	hScenario1Button_ = Image::Load("MenuImage/Sceneario1.png");
	assert(hScenario1Button_ >= 0);

	buttonTransform_.position_ = { 0.5,-0.7,0 };
	buttonTransform_.scale_ = { 0.7, 0.5, 0.7 };
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

	if (mousePos_.x > 800 && mousePos_.x < 1100 && mousePos_.y > 560 && mousePos_.y < 660) {
		if (Input::IsMouseButtonDown(0)) {
			SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
			pSceneManager->ChangeScene(SCENE_ID_SCENARIO1, TID_BLACKOUT, 0.5f);
		}
	}
}

void MenuScene::Draw()
{
	Image::SetTransform(hBackGround_, transform_);
	Image::Draw(hBackGround_);

	Image::SetTransform(hScenario1Button_, buttonTransform_);
	Image::Draw(hScenario1Button_);

}

void MenuScene::Release()
{
}
