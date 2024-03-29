#include "SplashScene.h"
#include "Transition.h"
#include "Engine/Input.h"

SplashScene::SplashScene(GameObject* parent) 
	: GameObject(parent, "PlayScene"), hSplash_(-1)
{
}

void SplashScene::Initialize()
{
	Transition::Initialize();

	//画像データのロード
	hSplash_ = Image::Load("Splash.png");
	assert(hSplash_ >= 0);
}

void SplashScene::Update()
{
	static int frame;

#ifdef _DEBUG
	ImGui::Begin("rueausu");
	ImGui::Text("Splash");

	if (ImGui::Button("SceneChange") || frame > 120) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TITLE, TID_BLACKOUT, 0.5f);
	}
	ImGui::End();
#endif // _DEBUG

	if (frame > 120) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TITLE, TID_BLACKOUT, 0.5f);
	}
	Image::SetAlpha(hSplash_, frame*10);
	frame++;


}

void SplashScene::Draw()
{
	Image::SetTransform(hSplash_, transform_);
	Image::Draw(hSplash_);
}

void SplashScene::Release()
{
}
