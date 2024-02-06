#include "SplashScene.h"
#include "Transition.h"
#include "Engine/Input.h"

SplashScene::SplashScene(GameObject* parent)
{
}

void SplashScene::Initialize()
{
	pText = new Text;
	pText->Initialize();
	Transition::Initialize();
}

void SplashScene::Update()
{
	ImGui::Begin("rueausu");
	if(ImGui::Button("SceneChange")) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY, TID_BLACKOUT, 0.5f);
	}
	ImGui::End();
}

void SplashScene::Draw()
{
}

void SplashScene::Release()
{
	SAFE_DELETE(pText);
}
