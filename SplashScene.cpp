#include "SplashScene.h"
#include "Transition.h"
#include "Engine/Input.h"

SplashScene::SplashScene(GameObject* parent) 
	: GameObject(parent, "PlayScene")
{
}

void SplashScene::Initialize()
{

	Transition::Initialize();
}

void SplashScene::Update()
{
	static int frame;
	ImGui::Begin("rueausu");
	ImGui::Text("Splash");


	if(ImGui::Button("SceneChange") || frame >60) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TITLE, TID_BLACKOUT, 0.5f);
	}
	ImGui::End();
	frame++;
}

void SplashScene::Draw()
{
}

void SplashScene::Release()
{
}
