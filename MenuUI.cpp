#include "MenuUI.h"

MenuUI::MenuUI(GameObject* parent):
	GameObject(parent,"MenuButton"),
	hScenario1ButtonNormal_(-1)
{
}

void MenuUI::Initialize()
{
	hScenario1ButtonNormal_ = Image::Load("MenuImage/Scenario1ButtonNormal.png");
	assert(hScenario1ButtonNormal_ >= 0);
	hScenario1ButtonSelected_ = Image::Load("MenuImage/Scenario1ButtonSelected.png");
	assert(hScenario1ButtonSelected_ >= 0);


	titleImage = Image::Load("MenuImage/Tap-Rack-Bang-2024-3-25.png");
	assert(titleImage >= 0);


	buttonTransform_.position_ = { 0.5,-0.7,0 };
	size = Image::GetSize(hScenario1ButtonNormal_);

	titleTrans.position_.x = -0.7;
	titleTrans.position_.y =0.9;
	titleTrans.scale_ = {0.4,0.4,0.4};
}

void MenuUI::Update()
{
	mousePos_ = Input::GetMousePosition();

	isPushable = IsMouseInRect();
	if (isPushable && Input::IsMouseButtonDown(0)) {
		AudioManager::PlayConfirmSound();
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_SCENARIO1, TID_BLACKOUT, 1.f);
	}
}

void MenuUI::Draw()
{
	if (isPushable) {
		Image::SetTransform(hScenario1ButtonSelected_, buttonTransform_);
		Image::Draw(hScenario1ButtonSelected_);
	}
	else {
		Image::SetTransform(hScenario1ButtonNormal_, buttonTransform_);
		Image::Draw(hScenario1ButtonNormal_);
	}

	Image::SetTransform(titleImage, titleTrans);
	Image::Draw(titleImage);

}

void MenuUI::Release()
{
}

bool MenuUI::IsMouseInRect()
{
	if (mousePos_.x > 840 && mousePos_.x < 1080 && mousePos_.y > 550 && mousePos_.y < 675)
		return true;

	return false;
}
