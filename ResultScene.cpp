#include "ResultScene.h"

ResultScene::ResultScene(GameObject* parent) :
	GameObject(parent, "ResultScene"), hBackGround_(-1)
{
}

void ResultScene::Initialize()
{
	hBackGround_ = Image::Load("ResultImage/Result.png");
	pScore = new Text;
	pScore->Initialize("number.png", 64, 68, 15);
	score = g_Point;
	
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

	pScore->Draw(500, 300, score);

}

void ResultScene::Release()
{
}
