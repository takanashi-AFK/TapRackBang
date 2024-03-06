#include "ResultScene.h"

ResultScene::ResultScene(GameObject* parent)
{
}

void ResultScene::Initialize()
{
	hBackGround_ = Image::Load("ResultImage/Result.png");
}

void ResultScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE)) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_MENU, TID_BLACKOUT, 0.5f);
	}
}

void ResultScene::Draw()
{
	Image::SetTransform(hBackGround_, transform_);
	Image::Draw(hBackGround_);
}

void ResultScene::Release()
{
}
