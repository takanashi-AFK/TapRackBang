#include "SplashScene.h"
#include "Transition.h"

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
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
		delete pText;
		Transition::Blackout();
	}
	ImGui::End();
}

void SplashScene::Draw()
{
	pText->Draw(30, 30, "Splash");
}

void SplashScene::Release()
{
}
