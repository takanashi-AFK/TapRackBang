#include "TitleScene.h"

TitleScene::TitleScene(GameObject* parent)
	: GameObject(parent, "PlayScene"), hBackGround_(-1)
{
}

void TitleScene::Initialize()
{
	hBackGround_ = Image::Load("TitleImage/Title.png");
	assert(hBackGround_ >= 0);
	pressSpaceKey = Image::Load("Press-Space-Key-2024-3-24.png");
	assert(pressSpaceKey >= 0);
	uiTransform.position_.y = -0.75;
	uiTransform.scale_ = {0.7,0.7,0.7};
	opacity = 0;
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
		AudioManager::PlayConfirmSound();
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_MENU, TID_BLACKOUT, 0.5f);
	}
	ImGui::Text("x = %f,y = %f", mousePos_.x, mousePos_.y);

	
		
	if (increasing) {
		opacity+=5;
		if (opacity >= 255)increasing = false;
	}
	else {
		opacity-=5;
		if (opacity <= 0)increasing = true;
	}
	Image::SetAlpha(pressSpaceKey, opacity);

}

void TitleScene::Draw()
{
	Image::SetTransform(hBackGround_, transform_);
	Image::Draw(hBackGround_);

	Image::SetTransform(pressSpaceKey, uiTransform);
	Image::Draw(pressSpaceKey);

	

	

		

}

void TitleScene::Release()
{
}
