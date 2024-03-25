#include "MenuScene.h"

MenuScene::MenuScene(GameObject* parent)
	: GameObject(parent, "PlayScene"),
	hBackGround_(-1)
{
}

void MenuScene::Initialize()
{
	pPlayer = Instantiate<Player>(this);
	Instantiate<SimpleStage>(this);
	Instantiate<MenuUI>(this);

	hBackGround_ = Image::Load("MenuImage/menu.png");
	assert(hBackGround_ >= 0);	
	
	
	pos = pPlayer->GetPosition();
	
}

void MenuScene::Update()
{
	if (frame >= 5)
		pPlayer->SetCanCamMove(false);

	if (Input::IsKeyDown(DIK_D)) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_DEPTH, TID_BLACKOUT, 1.f);
	}
	frame++;
}

void MenuScene::Draw()
{
	
}

void MenuScene::Release()
{
}

